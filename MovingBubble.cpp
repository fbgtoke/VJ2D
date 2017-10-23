#include "MovingBubble.h"

MovingBubble::MovingBubble(ShaderProgram& shaderProgram, BubbleType type, BubbleBoard& board)
	: mTexProgram(shaderProgram), mBubbleType(type), mBoard(board) {}

MovingBubble::~MovingBubble() {
	if (mSprite != nullptr)
		delete mSprite;
}

void MovingBubble::init() {
	mTexBubbles.loadFromFile("images/bubbles.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mPosition = glm::vec2(0, 0);
	mVelocity = glm::vec2(0, 0);

	// Init sprite
	setBubbleType(static_cast<BubbleType>(rand()%(NUM_BUBBLES - 1)));

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
	const float sizeInSpritesheet = 1.f / float(NUM_BUBBLES);
	mSprite = Sprite::createSprite(
		glm::ivec2(16, 16), 
		glm::vec2(sizeInSpritesheet, 1), 
		&mTexBubbles, 
		&mTexProgram
	);

	mSprite->setNumberAnimations(1);
		mSprite->setAnimationSpeed(0, 0);
		mSprite->addKeyframe(0, glm::vec2(sizeInSpritesheet * type, 0));
	mSprite->changeAnimation(0);

	mBubbleType = type;
}

void MovingBubble::setPosition(const glm::vec2& pos) {
	mPosition = pos;
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

	if (mPosition.y < mBoard.getOffset().y) {
		hasCollided = true;
		for (j = 0; j < mBoard.getWidth(); ++j)
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