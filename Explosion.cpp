#include "Explosion.h"

Explosion::Explosion(ShaderProgram& program)
	: mTexProgram(program) {}

Explosion::~Explosion() {}

void Explosion::init() {
	mTexture.loadFromFile("images/explosion.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mSprite = Sprite::createSprite(
		glm::ivec2(32, 64),
		glm::vec2(32.0f/512.0f, 64.0f/128.0f),
		&mTexture,
		&mTexProgram
	);

	mSprite->setNumberAnimations(1);
		mSprite->setAnimationSpeed(0, 40);
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 16; ++j)
				mSprite->addKeyframe(0, glm::vec2(32.0f/512.0f * j, 64.0f/128.0f * i));
	mSprite->changeAnimation(0);
	mSprite->setRepeat(false);

	mAliveTime = 0;
}

void Explosion::update(int deltaTime) {
	Particle::update(deltaTime);

	mAliveTime += deltaTime;
	if (mAliveTime > 3000)
		setPosition(glm::vec2(50000, 50000));
}