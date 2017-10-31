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
	
	mSprite = Sprite::createSprite(
		glm::ivec2(240, 800), 
		glm::vec2(1, 1), 
		&mTex, 
		&mTexProgram
	);
	mSprite->setNumberAnimations(1);
	mSprite->setAnimationSpeed(0, 0);
	mSprite->addKeyframe(0, glm::vec2(0, 0));

	mPosition = glm::vec2(0, 0);
	mSprite->setPosition(mPosition);
}

void SceneFinal::update(int deltaTime) {
	Scene::update(deltaTime);
	
	if (Game::instance().getKeyPressed('z')) {
		Game::instance().changeScene(SCENE_MENU);
	}

	if (currentTime >= 6000) {
		mPosition.y -= 0.05f * deltaTime;
		mPosition.y = std::max(-96.0f - 12 * 16.0f, mPosition.y);
		mSprite->setPosition(mPosition);
	}
}

void SceneFinal::render() {
	Scene::render();

	mSprite->render();
}