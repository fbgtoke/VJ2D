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

	checkIntegrity(3, 4);
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