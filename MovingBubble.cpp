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
	const float sizeInSpritesheet = 1.f / float(NUM_BUBBLES);
	mSprite = Sprite::createSprite(
		glm::ivec2(16, 16), 
		glm::vec2(sizeInSpritesheet, 1), 
		&mTexBubbles, 
		&mTexProgram
	);

	mSprite->setNumberAnimations(1);
		mSprite->setAnimationSpeed(0, 0);
		mSprite->addKeyframe(0, glm::vec2(sizeInSpritesheet * 0, 0));
	mSprite->changeAnimation(BUBBLE_RED);

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

	checkCollision();
}

void MovingBubble::render() const {
	mSprite->render();
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

	for (int i = 0; i < mBoard.getHeight(); ++i) {
		for (int j = 0; j < mBoard.getWidth(); ++j) {
			if (i % 2 == 0)
				pos.x = mBoard.getOffset().x + 16.0f * j;
			else if (j < mBoard.getWidth() - 1)
				pos.x = mBoard.getOffset().x + 16.0f * j + 8.0f;
			else
				continue;

			if (mBoard.getBubbleType(j, i) == BUBBLE_NONE)
				continue;
					
			pos.y = mBoard.getOffset().y + 16.0f * i;

			if (collide(pos, mPosition, 16.0f)) {

				std::list<glm::ivec2> neighbors;

				mBoard.getNeighbors(glm::ivec2(j, i), neighbors, BUBBLE_NONE);

				glm::ivec2 closest = getClosestNeighbor(neighbors);
				
				closest.x = (closest.x - 8) / 16 - mBoard.getOffset().x;
				closest.y = (closest.y - 8) / 16 - mBoard.getOffset().y;

				std::cout << "closest " << closest.x << "," << closest.y << std::endl;

				mBoard.setBubbleType(closest.x, closest.y, mBubbleType);
				mBubbleState = BUBBLE_DEAD;
			}
		}
	}
}

// neighbors es una lista de los indices en la array de los neighbors
// hay que calcular el closest pasando los indices a pixeles
// la funcion debe devolver el indice de la burbuja con posicion mas proxima
glm::ivec2 MovingBubble::getClosestNeighbor(std::list<glm::ivec2>& neighbors) {
	std:list<glm::vec2> neighborsPosition;

	for (glm::ivec2& neighbor : neighbors) {
		glm::vec2 pos;

		if (neighbor.y % 2 == 0)
			pos.x = mBoard.getOffset().x + neighbor.x * 16.0f + 8.0f;
		else
			pos.x = mBoard.getOffset().x + neighbor.x * 16.0f + 8.0f + 8.0f;

		pos.y = mBoard.getOffset().y + neighbor.y * 16.0f + 8.0f;
		
		neighborsPosition.push_back(pos)
	}

	std::list<glm::vec2>::iterator it = neighborsPosition.begin();

	glm::ivec2 closestPosition = (*it++);
	float minDistance = dist(mPosition, closestPosition);

	while (it != neighborsPosition.end()) {
		float distance = dist(mPosition, (*it));
		if (distance < minDistance) {
			minDistance = distance;
			closestPosition = (*it);
		}

		++it;
	}

	return 
}

bool MovingBubble::collide(const glm::vec2& pos1, const glm::vec2& pos2, float size) {
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