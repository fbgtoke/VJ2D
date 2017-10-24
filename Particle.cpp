#include "Particle.h"

Particle::Particle()
	: mSprite(nullptr), mPosition(0.f, 0.f), mVelocity(0.f, 0.f) {}

Particle::~Particle() {
	if (mSprite != nullptr)
		delete mSprite;
}

void Particle::update(int deltaTime) {
	mPosition.x += mVelocity.x * deltaTime;
	mPosition.y += mVelocity.y * deltaTime;

	if (mSprite != nullptr) {
		mSprite->setPosition(mPosition);
		mSprite->update(deltaTime);
	}
}

void Particle::render() {
	if (mSprite != nullptr) {
		mSprite->render();
	}
}

void Particle::setPosition(const glm::vec2& position) {
	mPosition = position;
}

void Particle::setVelocity(const glm::vec2& velocity) {
	mVelocity = velocity;
}

glm::vec2 Particle::getPosition() const {
	return mPosition;
}

glm::vec2 Particle::getVelocity() const {
	return mVelocity;
}