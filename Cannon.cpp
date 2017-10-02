#include "Cannon.h"
#include "Game.h"

Cannon::Cannon(ShaderProgram &shaderProgram)
	: mTexProgram(shaderProgram) {}

Cannon::~Cannon() {
	if (mArrow != nullptr)
		delete mArrow;
	if (mCurrentBubble != nullptr)
		delete mCurrentBubble;
	if (mNextBubble != nullptr)
		delete mNextBubble;
}

void Cannon::init() {
	mTexArrow.loadFromFile("images/arrow.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mTexBubbles.loadFromFile("images/bubbles.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mArrow = Sprite::createSprite(glm::ivec2(64, 64), glm::vec2(64.0f/8128.0f, 1), &mTexArrow, &mTexProgram);
	mArrow->setNumberAnimations(1);
		mArrow->setAnimationSpeed(0, 0);
		for (int i = 0; i < 127; ++i)
			mArrow->addKeyframe(0, glm::vec2(64.0f/8128.0f * i, 0));
	mArrow->changeAnimation(0);
	mArrow->setPosition(glm::vec2(88, 243));
	mArrow->setRepeat(false);
	mArrow->setKeyFrame(0, 65);
}

void Cannon::update(int deltaTime) {
	mArrow->update(deltaTime);

	if (Game::instance().getSpecialKey(GLUT_KEY_LEFT))
		mArrow->setAnimationSpeed(0, 40);
	else if (Game::instance().getSpecialKey(GLUT_KEY_RIGHT))
		mArrow->setAnimationSpeed(0, -40);
	else
		mArrow->setAnimationSpeed(0, 0);
}

void Cannon::render() {
	mArrow->render();
}