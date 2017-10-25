#include "SceneCredits.h"
#include "Game.h"

SceneCredits::SceneCredits() {}

SceneCredits::~SceneCredits() {
	if (mBackground != nullptr)
		delete mBackground;
}

void SceneCredits::init() {
	Scene::init();

	mTexBackground.loadFromFile("images/credits.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mBackground = Sprite::createSprite(glm::ivec2(240, 320), glm::vec2(1, 1), &mTexBackground, &mTexProgram);
	mBackground->setNumberAnimations(1);
		mBackground->setAnimationSpeed(0, 0);
		mBackground->addKeyframe(0, glm::vec2(0, 0));
	mBackground->changeAnimation(0);
}

void SceneCredits::update(int deltaTime) {
	Scene::update(deltaTime);
	
	if (Game::instance().getKeyPressed('z')) {
		Game::instance().changeScene(SCENE_MENU);
	}
}

void SceneCredits::render() {
	Scene::render();

	mBackground->render();
}