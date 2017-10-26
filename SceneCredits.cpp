#include "SceneCredits.h"
#include "Game.h"

SceneCredits::SceneCredits() {}

SceneCredits::~SceneCredits() {}

void SceneCredits::init() {
	Scene::init();
	setBackground("images/credits.png");
}

void SceneCredits::update(int deltaTime) {
	Scene::update(deltaTime);
	
	if (Game::instance().getKeyPressed('z')) {
		Game::instance().changeScene(SCENE_MENU);
	}
}