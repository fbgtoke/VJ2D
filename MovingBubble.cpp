#include "MovingBubble.h"
#include "Game.h"
#include "Scene.h"

MovingBubble::MovingBubble(ShaderProgram& shaderProgram, BubbleType type, BubbleBoard& board, int levelNumber)
	: mTexProgram(shaderProgram), mBubbleType(type), mBoard(board), mLevelNumber(levelNumber) {}

MovingBubble::~MovingBubble() {
	if (mSprite != nullptr)
		delete mSprite;
}

void MovingBubble::init() {
	mTexBubbles.loadFromFile("images/bubbles2.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mPosition = glm::vec2(0, 0);
	mVelocity = glm::vec2(0, 0);

	// Init sprite
	setBubbleType(mBubbleType);

	mBubbleState = BUBBLE_STOPPED;
}

void MovingBubble::update(int deltaTime) {
	mPosition.x += deltaTime * mVelocity.x;
	mPosition.y += deltaTime * mVelocity.y;

	if (mPosition.x < 40 || mPosition.x > 186)
		mVelocity.x *= (-1.0f);
	if (mPosition.y < 0)
		mPosition.y = 320;

	mSprite->setPosition(mPosition);
	mSprite->update(deltaTime);

	if (mBubbleState == BUBBLE_MOVING)
		checkCollision();
}

void MovingBubble::render() const {
	mSprite->render();
}

void MovingBubble::setBubbleType(BubbleType type) {
	mSprite = new SpriteBubble(&mTexBubbles, &mTexProgram);
	mSprite->changeAnimation(type);

	mBubbleType = type;
}

BubbleType MovingBubble::getBubbleType() const {
	return mBubbleType;
}

void MovingBubble::setPosition(const glm::vec2& pos) {
	mPosition = pos;
	mSprite->setPosition(mPosition);
}

void MovingBubble::setVelocity(const glm::vec2& vel) {
	mVelocity = vel;
}

void MovingBubble::setBubbleState(BubbleState state) {
	mBubbleState = state;
}

MovingBubble::BubbleState MovingBubble::getBubbleState() const {
	return mBubbleState;
}

void MovingBubble::checkCollision() {
	glm::vec2 pos;
	glm::ivec2 collidedBubble;
	std::list<glm::ivec2> neighbors;

	bool hasCollided = false;
	unsigned int i = 0;
	unsigned int j = 0;

	if (mPosition.y < mBoard.getWallBottom()) {
		hasCollided = true;
		for (j = 0; j < mBoard.getWidth(); ++j)
			if (mBoard.getBubbleType(j, 0) == BUBBLE_NONE)
				neighbors.push_back(glm::ivec2(j, 0));
		collidedBubble = getClosestNeighbor(neighbors);
	}

	while (!hasCollided && i < mBoard.getHeight()) {
		while (!hasCollided && j < mBoard.getWidth()) {
			if (mBoard.getBubbleType(j, i) != BUBBLE_NONE) {
				pos = mBoard.getBubbleOrigin(j, i);
				hasCollided = collide(pos, mPosition, 16.0f);

				if (hasCollided) {
					mBoard.getNeighbors(glm::ivec2(j, i), neighbors, BUBBLE_NONE);
					collidedBubble = getClosestNeighbor(neighbors);
				}
			}
			++j;
		}
		j = 0;
		++i;
	}

	if (hasCollided) {
		mBoard.setBubbleType(collidedBubble.x, collidedBubble.y, mBubbleType);
		mBoard.checkIntegrity(collidedBubble.x, collidedBubble.y);
		mBoard.checkFloatingBubbles();

		if (collidedBubble.y >= 14 - mBoard.getNumberOfCollapse()) {
			Game::instance().changeScene(Scene::SCENE_GAME_OVER);
			Game::instance().getBufferedScene()->receiveInteger(mLevelNumber);
		}

		mBubbleState = BUBBLE_DEAD;
	}
}

glm::ivec2 MovingBubble::getClosestNeighbor(const std::list<glm::ivec2>& neighbors) const {
	glm::vec2 myCentroid = mPosition + glm::vec2(8.0f, 8.0f);

	glm::ivec2 index, closestIndex;
	glm::vec2 centroid, closestCentroid;
	float distance, closestDistance;

	std::list<glm::ivec2>::const_iterator it = neighbors.begin();
	closestIndex = (*it++);
	closestCentroid = mBoard.getBubbleCentroid(closestIndex.x, closestIndex.y);
	closestDistance = dist(myCentroid, closestCentroid);

	while (it != neighbors.end()) {
		index = (*it);
		centroid = mBoard.getBubbleCentroid(index.x, index.y);
		distance = dist(myCentroid, centroid);

		if (distance < closestDistance) {
			closestIndex = index;
			closestCentroid = centroid;
			closestDistance = distance;
		}

		++it;
	}

	return closestIndex;
}

bool MovingBubble::collide(const glm::vec2& pos1, const glm::vec2& pos2, float size) {
	size -= 4.0f;

	glm::vec2 pos1_ = pos1 + glm::vec2(size/2.0f, size/2.0f);
	glm::vec2 pos2_ = pos2 + glm::vec2(size/2.0f, size/2.0f);

	return
		pos1.x < pos2.x + size && pos1.x + size > pos2.x &&
    	pos1.y < pos2.y + size && pos1.y + size > pos2.y;
}

float MovingBubble::dist(const glm::vec2& pos1, const glm::vec2& pos2) {
	return sqrt(
		(pos1.x - pos2.x) * (pos1.x - pos2.x) +
		(pos1.y - pos2.y) * (pos1.y - pos2.y)
	);
}