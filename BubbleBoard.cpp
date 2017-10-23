#include "BubbleBoard.h"

BubbleBoard::BubbleBoard(ShaderProgram &program)
	: mTexProgram(program) {}

BubbleBoard::~BubbleBoard() {
	mBubbles.clear();
}

void BubbleBoard::init(const glm::vec2& offset, unsigned int w, unsigned int h) {
	// Init board
	mOffset = offset;
	mBoardWidth  = w;
	mBoardHeight = h;
	mBubbles = bubble_matrix_t(mBoardHeight, bubble_row_t(mBoardWidth, BUBBLE_NONE));

	// Init textures
	mTexBubbles.loadFromFile("images/bubbles.png", TEXTURE_PIXEL_FORMAT_RGBA);

	// Init sprite
	const float sizeInSpritesheet = 1.f / float(NUM_BUBBLES);
	mSprite = Sprite::createSprite(
		glm::ivec2(16, 16), 
		glm::vec2(sizeInSpritesheet, 1), 
		&mTexBubbles, 
		&mTexProgram
	);

	mSprite->setNumberAnimations(NUM_BUBBLES);
	for (unsigned int i = 0; i < static_cast<unsigned int>(NUM_BUBBLES); ++i) {
		mSprite->setAnimationSpeed(i, 0);
		mSprite->addKeyframe(i, glm::vec2(sizeInSpritesheet * i, 0));
	}
	mSprite->changeAnimation(BUBBLE_NONE);
}

void BubbleBoard::update(int deltaTime) {}

void BubbleBoard::render() {
	glm::vec2 position;
	for (int i = 0; i < mBoardHeight; ++i) {
		for (int j = 0; j < mBoardWidth; ++j) {
			if (mBubbles[i][j] == BUBBLE_NONE)
				continue;

			if (i % 2 == 0)
				position = glm::vec2(j * 16.0f, i * 16.0f) + mOffset;
			else
				position = glm::vec2(j * 16.0f + 8.0f, i * 16.0f) + mOffset;

			if (i % 2 == 0 || j < mBoardWidth - 1) {
				mSprite->setPosition(position);
				mSprite->changeAnimation(mBubbles[i][j]);
				mSprite->render();
			}
		}
	}
}

void BubbleBoard::generate() {
	for (int i = 0; i < mBoardHeight; ++i) {
		for (int j = 0; j < mBoardWidth; ++j) {
			mBubbles[i][j] = static_cast<BubbleType>(rand()%(NUM_BUBBLES - 1));
		}
	}
}

void BubbleBoard::loadFromFile(const std::string& filename) {
	std::ifstream stream;
	stream.open(filename);

	if (stream.is_open()) {
		unsigned int i = 0;
		unsigned int j = 0;
		unsigned int t;
		while (!stream.eof() && i < mBoardHeight) {
			stream >> t;
			mBubbles[i][j] = static_cast<BubbleType>(t);
			++j;

			if ((i%2 == 0 && j >= mBoardWidth) || (i%2 != 0 && j >= mBoardWidth-1)) {
				j = 0;
				++i;
			}
		}
		stream.close();
	} else {
		cout << "Unable to open file " << filename << std::endl;
	}
}

glm::vec2 BubbleBoard::getOffset() const {
	return mOffset;
}

unsigned int BubbleBoard::getWidth() const {
	return mBoardWidth;
}

unsigned int BubbleBoard::getHeight() const {
	return mBoardHeight;
}

void BubbleBoard::setBubbleType(unsigned int x, unsigned int y, BubbleType type) {
	if (x >= mBoardWidth || y >= mBoardHeight) return;

	mBubbles[y][x] = type;
}

BubbleType BubbleBoard::getBubbleType(unsigned int x, unsigned int y) const {
	if (x >= mBoardWidth || y >= mBoardHeight) return BUBBLE_NONE;

	return mBubbles[y][x];
}

void BubbleBoard::getNeighbors(const glm::ivec2& pos, std::list<glm::ivec2>& neighbors) const {
	neighbors.clear();

	if (pos.y % 2 == 0) {
		if (pos.x != 0 && pos.y != 0)
			neighbors.push_back(glm::ivec2(pos.x - 1, pos.y - 1));
		if (pos.y != 0)
			neighbors.push_back(glm::ivec2(pos.x, pos.y - 1));
		if (pos.x != 0)
			neighbors.push_back(glm::ivec2(pos.x - 1, pos.y));
		if (pos.x < mBoardWidth - 1)
			neighbors.push_back(glm::ivec2(pos.x + 1, pos.y));
		if (pos.x != 0 && pos.y < mBoardHeight - 1)
			neighbors.push_back(glm::ivec2(pos.x - 1, pos.y + 1));
		if (pos.y < mBoardHeight - 1)
			neighbors.push_back(glm::ivec2(pos.x, pos.y + 1));
	} else {
		if (pos.y != 0)
			neighbors.push_back(glm::ivec2(pos.x, pos.y - 1));
		if (pos.x < mBoardWidth - 1 && pos.y != 0)
			neighbors.push_back(glm::ivec2(pos.x + 1, pos.y - 1));
		if (pos.x != 0)
			neighbors.push_back(glm::ivec2(pos.x - 1, pos.y));
		if (pos.x < mBoardWidth - 1)
			neighbors.push_back(glm::ivec2(pos.x + 1, pos.y));
		if (pos.y < mBoardHeight - 1)
			neighbors.push_back(glm::ivec2(pos.x, pos.y + 1));
		if (pos.x < mBoardWidth - 1 && mBoardHeight - 1)
			neighbors.push_back(glm::ivec2(pos.x + 1, pos.y + 1));
	}
}

void BubbleBoard::getNeighbors(const glm::ivec2& pos, std::list<glm::ivec2>& neighbors, BubbleType type) const {
	getNeighbors(pos, neighbors);

	std::list<glm::ivec2>::iterator it = neighbors.begin();
	while (it != neighbors.end()) {
		BubbleType bubbleType = mBubbles[it->y][it->x];

		if (bubbleType != type) {
			neighbors.erase(it++);
		} else {
			it++;
		}
	}
}

glm::vec2 BubbleBoard::getBubbleOrigin(unsigned int x, unsigned int y) const {
	if (x >= mBoardWidth || y >= mBoardHeight)
		return glm::vec2(-1.0f, -1.0f);

	if (y % 2 == 0)
		return glm::vec2(x * 16.0f, y * 16.0f) + mOffset;
	
	return glm::vec2(x * 16.0f + 8.0f, y * 16.0f) + mOffset;
}

glm::vec2 BubbleBoard::getBubbleCentroid(unsigned int x, unsigned int y) const {
	if (x >= mBoardWidth || y >= mBoardHeight) return glm::vec2(-1.0f, -1.0f);

	return getBubbleOrigin(x, y) + glm::vec2(8.0f, 8.0f);
}

void BubbleBoard::checkIntegrity(unsigned int x, unsigned int y) {
	if (y >= mBoardHeight || x >= mBoardWidth) return;
	if (mBubbles[y][x] == BUBBLE_NONE) return;

	BubbleType startType = mBubbles[y][x];

	std::queue<glm::ivec2> queue;
	queue.push(glm::ivec2(x, y));

	std::vector<std::vector<bool>> visited(
		mBoardHeight,
		std::vector<bool>(mBoardWidth, false)
	);

	std::list<glm::ivec2> toErase;
	std::list<glm::ivec2> neighbors;

	while (!queue.empty()) {
		glm::ivec2 current = queue.front();
		queue.pop();

		visited[current.y][current.x] = true;

		if (mBubbles[current.y][current.x] == startType) {
			toErase.push_back(current);

			getNeighbors(current, neighbors);
			for (glm::ivec2& neighbor : neighbors) {
				if (visited[neighbor.y][neighbor.x] == false)
					if (mBubbles[neighbor.y][neighbor.x] != BUBBLE_NONE)
						queue.push(neighbor);
			}
		}
	}

	if (toErase.size() >= 3) {
		for (glm::ivec2& pos : toErase) {
			mBubbles[pos.y][pos.x] = BUBBLE_NONE;
		}
	}
}

void BubbleBoard::checkFloatingBubbles() {
	std::vector<std::vector<bool>> visited(
		mBoardHeight,
		std::vector<bool>(mBoardWidth, false)
	);
	std::queue<glm::ivec2> queue;
	std::list<glm::ivec2> neighbors;

	glm::ivec2 current;

	// Visit connected bubbles
	for (int i = 0; i < mBoardWidth; ++i) {
		if (visited[0][i] || mBubbles[0][i] == BUBBLE_NONE) continue;

		queue.push(glm::ivec2(i, 0));
		while (!queue.empty()) {
			current = queue.front();
			queue.pop();

			visited[current.y][current.x] = true;

			getNeighbors(current, neighbors);
			for (glm::ivec2& neighbor : neighbors) {
				if (visited[neighbor.y][neighbor.x] == false)
					if (mBubbles[neighbor.y][neighbor.x] != BUBBLE_NONE)
						queue.push(neighbor);
			}
		}
	}

	// Remove floating bubbles
	for (int i = 0; i < mBoardHeight; ++i) {
		for (int j = 0; j < mBoardWidth; ++j) {
			if (!visited[i][j]) {
				mBubbles[i][j] = BUBBLE_NONE;
			}
		}
	}
}

void BubbleBoard::getPossibleBubbleTypes(std::vector<BubbleType>& types) const {
	types.clear();

	bool alreadyExists;
	int i, j, k;

	for (i = 0; i < mBoardHeight; ++i) {
		for (j = 0; j < mBoardWidth; ++j) {
			if (mBubbles[i][j] != BUBBLE_NONE) {
				alreadyExists = false;
				k = 0;

				while (k < types.size() && !alreadyExists) {
					alreadyExists = (types[k] == mBubbles[i][j]);
					++k;
				}

				if (!alreadyExists)
					types.push_back(mBubbles[i][j]);
			}
		}
	}
}