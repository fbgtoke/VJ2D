#include "FallingBubble.h"
#include "Game.h"

const float FallingBubble::kAcceleration = 0.002f;

FallingBubble::FallingBubble(ShaderProgram& program)
	: mTexProgram(program) {}

FallingBubble::~FallingBubble() {}

void FallingBubble::init() {
	mVelocity.x = randomFloat(0.02f, 0.1f) * ((rand()%2 == 0)? -1.0f : 1.0f);
	mVelocity.y = randomFloat(0.5f, 0.8f) * -1.0f;

	mTexture.loadFromFile("images/bubbles2.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mSprite = new SpriteBubble(&mTexture, &mTexProgram);
}

void FallingBubble::setBubbleType(BubbleType type) {
	if (type == BUBBLE_BOMB) {
		mSprite->changeAnimation(BUBBLE_NONE);
		mSprite->setAnimationSpeed(BUBBLE_NONE, 0);
	} else if (type == BUBBLE_BOX) {
		mSprite->changeAnimation(BUBBLE_BOX);
		mSprite->setAnimationSpeed(BUBBLE_BOX, 0);
	} else {
		mSprite->changeAnimation(BUBBLE_BLACK);
		mSprite->setAnimationSpeed(BUBBLE_BLACK, 0);
	}
}

void FallingBubble::update(int deltaTime) {
	mVelocity.y += kAcceleration * deltaTime;
	Particle::update(deltaTime);
}

float FallingBubble::randomFloat(float min, float max) {
	return
		min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
}