#include "Cannon.h"
#include "Game.h"

Cannon::Cannon(ShaderProgram &shaderProgram)
	: mTexProgram(shaderProgram) {}

Cannon::~Cannon() {
	if (mArrow != nullptr)
		delete mArrow;
}

void Cannon::init() {
	mTexArrow.loadFromFile("images/arrow.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mTexBubbles.loadFromFile("images/bubbles2.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mTexBase.loadFromFile("images/base_machine.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mTexWheel.loadFromFile("images/wheel_machine.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mArrow = Sprite::createSprite(
		glm::ivec2(64, 64), 
		glm::vec2(64.0f/8128.0f, 1), 
		&mTexArrow, 
		&mTexProgram
	);

	mArrow->setNumberAnimations(1);
		mArrow->setAnimationSpeed(0, 0);
		for (int i = 0; i < 127; ++i)
			mArrow->addKeyframe(0, glm::vec2(64.0f/8128.0f * i, 0));
	mArrow->changeAnimation(0);
	mArrow->setPosition(glm::vec2(88, 250));
	mArrow->setRepeat(false);

	mArrow->setKeyFrame(0, 128/2 - 1);
	mArrow->setAnimationSpeed(0, 40);
	mArrow->update(0);
	mArrow->setAnimationSpeed(0, 0);

	mBase = Sprite::createSprite(
		glm::ivec2(64, 32),
		glm::vec2(64.0f/256.0f, 32.0f/128.0f),
		&mTexBase,
		&mTexProgram
	);
	mBase->setNumberAnimations(1);
		mBase->setAnimationSpeed(0, 50);
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 4; ++j)
				mBase->addKeyframe(0, glm::vec2(64.0f/256.0f * j, 32.0f/128.0f * i));
	mBase->changeAnimation(0);
	mBase->setPosition(glm::vec2(88.0f, 278.0f));

	mWheel = Sprite::createSprite(
		glm::ivec2(64, 16),
		glm::vec2(64.0f/128.0f, 16.0f/16.0f),
		&mTexWheel,
		&mTexProgram
	);
	mWheel->setNumberAnimations(1);
		mWheel->setAnimationSpeed(0, 50);
		for (int i = 0; i < 2; ++i)
			mWheel->addKeyframe(0, glm::vec2(64.0f/128.0f * i, 0.0f));
	mWheel->changeAnimation(0);
	mWheel->setPosition(glm::vec2(103.0f, 262.0f));
}

void Cannon::update(int deltaTime) {
	mArrow->update(deltaTime);
	mBase->update(deltaTime);
	mWheel->update(deltaTime);

	bool inputLocked = Game::instance().getScene()->isInputLocked();

	if (Game::instance().getSpecialKey(GLUT_KEY_LEFT) && !inputLocked) {
		mArrow->setAnimationSpeed(0, 40);
		mBase->setAnimationSpeed(0, 50);
		mWheel->setAnimationSpeed(0, 50);
	} else if (Game::instance().getSpecialKey(GLUT_KEY_RIGHT) && !inputLocked) {
		mArrow->setAnimationSpeed(0, -40);
		mBase->setAnimationSpeed(0, -50);
		mWheel->setAnimationSpeed(0, -50);
	} else {
		mArrow->setAnimationSpeed(0, 0);
		mBase->setAnimationSpeed(0, 0);
		mWheel->setAnimationSpeed(0, 0);
	}
}

void Cannon::render() {
	mBase->render();
	mWheel->render();
	mArrow->render();
}

unsigned int Cannon::getCurrentFrame() const {
	return mArrow->getKeyFrame();
}

glm::vec2 Cannon::getCurrentBubblePosition() { return glm::vec2(112.0f, 270.0f); }
glm::vec2 Cannon::getBufferedBubblePosition() { return glm::vec2(56.0f, 287.f); }