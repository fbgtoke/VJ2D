#include "FallingBubble.h"

const float FallingBubble::kAcceleration = 0.002f;

FallingBubble::FallingBubble(ShaderProgram& program)
	: mTexProgram(program) {}

FallingBubble::~FallingBubble() {}

void FallingBubble::init() {
	mVelocity.x = randomFloat(0.02f, 0.1f) * ((rand()%2 == 0)? -1.0f : 1.0f);
	mVelocity.y = randomFloat(0.5f, 0.8f) * -1.0f;

	mTexure.loadFromFile("images/falling-bubble.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mSprite = Sprite::createSprite(
		glm::ivec2(16, 16), 
		glm::vec2(1.0f, 1.0f), 
		&mTexure, 
		&mTexProgram
	);

	mSprite->setNumberAnimations(1);
		mSprite->setAnimationSpeed(0, 0);
		mSprite->addKeyframe(0, glm::vec2(0, 0));
	mSprite->changeAnimation(0);
}

void FallingBubble::update(int deltaTime) {
	mVelocity.y += kAcceleration * deltaTime;
	Particle::update(deltaTime);
}

float FallingBubble::randomFloat(float min, float max) {
	return
		min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
}