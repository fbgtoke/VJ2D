#include "BubbleBoard.h"
#include "Game.h"

const float BubbleBoard::kShakeSequence[4] = { -1.0f, 0.0f, 1.0f , 0.0f };

BubbleBoard::BubbleBoard(ShaderProgram &program)
	: mTexProgram(program) {}

BubbleBoard::~BubbleBoard() {
	mBubbles.clear();
}

void BubbleBoard::init(const BubbleLevel& level, unsigned int turnsBetweenCollapse) {
	// Init board
	mOffset = level.getOffset();
	mBoardWidth  = level.getBubblesWidth();
	mBoardHeight = level.getBubblesHeight();
	level.getBubbles(mBubbles);

	// Init textures
	mTexBubbles.loadFromFile("images/bubbles2.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mTexWall.loadFromFile("images/collapsing.png", TEXTURE_PIXEL_FORMAT_RGBA);

	// Init collapsing wall sprite
	mTurnsBetweenCollapse = turnsBetweenCollapse;
	mTurnsUntilCollapse = turnsBetweenCollapse;
	mNumberOfCollapse = 0;

	initBubbles();

	mWall = Sprite::createSprite(
		glm::ivec2(176, 16),
		glm::vec2(1, 1),
		&mTexWall,
		&mTexProgram
	);

	mWall->setNumberAnimations(1);
		mWall->setAnimationSpeed(0, 0);
		mWall->addKeyframe(0, glm::vec2(0, 0));
	mWall->changeAnimation(0);

	mShaking = false;
	mShakeFrame = 0;
}

void BubbleBoard::update(int deltaTime) {
	++mShakeFrame;

	for (int i = 0; i < mBoardHeight; ++i) {
		for (int j = 0; j < mBoardWidth; ++j) {
			if (mBubbles[i][j] != BUBBLE_NONE) {
				if (i % 2 == 0 || j < mBoardWidth - 1) {
					mSprites[i][j]->update(deltaTime);
					mSprites[i][j]->setPosition(getBubbleOrigin(j, i));
				}
			}
		}
	}
}

void BubbleBoard::render() {
	for (int i = 0; i < mBoardHeight; ++i) {
		for (int j = 0; j < mBoardWidth; ++j) {
			if (mBubbles[i][j] != BUBBLE_NONE) {
				if (i % 2 == 0 || j < mBoardWidth - 1) {
					mSprites[i][j]->render();
				}
			}
		}
	}

	if (mNumberOfCollapse != 0)
		mWall->render();
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
	mSprites[y][x]->changeAnimation(mBubbles[y][x]);
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

	glm::vec2 position;

	if (y % 2 == 0)
		position.x = x * 16.0f;
	else
		position.x = x * 16.0f + 8.0f;

	position.x += getShakeOffset();

	position.y = y * 16.0f + (mNumberOfCollapse) * 16.0f;
	
	return position + mOffset;
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
			makeBubbleExplode(pos.x, pos.y);
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
				makeBubbleFall(j, i);
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

void BubbleBoard::decTurnsUntilCollapse() {
	--mTurnsUntilCollapse;

	if (mTurnsUntilCollapse == 0)
		collapseWall();

	mShaking = (mTurnsUntilCollapse == 1);
}

void BubbleBoard::collapseWall() {
	mTurnsUntilCollapse = mTurnsBetweenCollapse;
	mNumberOfCollapse++;

	mWall->setPosition(glm::vec2(mOffset.x, mOffset.y + (mNumberOfCollapse-1) * 16.0f));
}

unsigned int BubbleBoard::getNumberOfCollapse() const {
	return mNumberOfCollapse;
}

float BubbleBoard::getWallBottom() const {
	return getOffset().y + getNumberOfCollapse() * 16.0f;
}

void BubbleBoard::initBubbles() {
	mSprites = std::vector<std::vector<Sprite*>> (
		mBoardHeight,
		std::vector<Sprite*>(mBoardWidth, nullptr)
	);

	glm::vec2 position;
	for (unsigned int i = 0; i < mBoardHeight; ++i) {
		for (unsigned int j = 0; j < mBoardWidth; ++j) {
			position = getBubbleOrigin(j, i);

			mSprites[i][j] = new SpriteBubble(&mTexBubbles, &mTexProgram);
			mSprites[i][j]->changeAnimation(mBubbles[i][j]);
			mSprites[i][j]->setPosition(position);
		}
	}

}

void BubbleBoard::makeBubbleFall(unsigned int x, unsigned int y) {
	if (mBubbles[y][x] == BUBBLE_NONE) return;
	
	FallingBubble* falling = new FallingBubble(mTexProgram);
	falling->init();
	falling->setPosition(getBubbleOrigin(x, y));

	Game::instance().getScene()->addParticle(falling);

	mBubbles[y][x] = BUBBLE_NONE;
}

void BubbleBoard::makeBubbleExplode(unsigned int x, unsigned int y) {
	if (mBubbles[y][x] == BUBBLE_NONE) return;

	makeBubbleFall(x, y);
	//mBubbles[y][x] = BUBBLE_NONE;
}

float BubbleBoard::getShakeOffset() const {
	if (mShaking)
		return kShakeSequence[(mShakeFrame/2)%4];
	return 0.f;
}