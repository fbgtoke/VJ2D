#include "SceneFinal.h"
#include "Game.h"

SceneFinal::SceneFinal() {}

SceneFinal::~SceneFinal() {
	if (mSprite != nullptr)
		delete mSprite;
}

void SceneFinal::init() {
	Scene::init();
	setBackground("images/youwonthegame.png");

	Game::instance().getBackgroundMusic().setVolume(0);

	Game::instance().changeBackgroundMusic("music/final.ogg");
	Game::instance().getBackgroundMusic().setVolume(50);

	mTex.loadFromFile("images/credits-roll.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mTexFrame.loadFromFile("images/frame.png", TEXTURE_PIXEL_FORMAT_RGBA);
	
	mSprite = Sprite::createSprite(
		glm::ivec2(240, 1340), 
		glm::vec2(1, 1), 
		&mTex, 
		&mTexProgram
	);
	mSprite->setNumberAnimations(1);
	mSprite->setAnimationSpeed(0, 0);
	mSprite->addKeyframe(0, glm::vec2(0, 0));

	mPosition = glm::vec2(0, 0);
	mSprite->setPosition(mPosition);

	mSpriteFrame = Sprite::createSprite(
		glm::ivec2(240, 320),
		glm::vec2(1.0f, 1.0f),
		&mTexFrame,
		&mTexProgram
	);
	mSpriteFrame->setNumberAnimations(1);
	mSpriteFrame->addKeyframe(0, glm::vec2(0, 0));
}

void SceneFinal::update(int deltaTime) {
	Scene::update(deltaTime);
	
	if (Game::instance().getKeyPressed('z')) {
		Game::instance().changeScene(SCENE_MENU);
	}

	if (currentTime >= 7000) {
		mPosition.y -= 0.03f * deltaTime;
		mPosition.y = std::max(-1024.0f, mPosition.y);
		mSprite->setPosition(mPosition);
	}
}

void SceneFinal::render() {
	Scene::render();

	mSprite->render();
	mSpriteFrame->render();
}