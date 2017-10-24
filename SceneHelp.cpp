#include "SceneHelp.h"
#include "Game.h"

SceneHelp::SceneHelp() {}

SceneHelp::~SceneHelp() {
	if (mBackground != nullptr)
		delete mBackground;
}

void SceneHelp::init() {
	Scene::init();

	mTexBackground.loadFromFile("images/help.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mBackground = Sprite::createSprite(glm::ivec2(240, 320), glm::vec2(1, 1), &mTexBackground, &texProgram);
	mBackground->setNumberAnimations(1);
		mBackground->setAnimationSpeed(0, 0);
		mBackground->addKeyframe(0, glm::vec2(0, 0));
	mBackground->changeAnimation(0);
}

void SceneHelp::update(int deltaTime) {
	Scene::update(deltaTime);
	
	if (Game::instance().getKey('z') && currentTime > 500) {
		Game::instance().changeScene(SCENE_MENU);
	}
}

void SceneHelp::render() {
	Scene::render();

	mBackground->render();
}