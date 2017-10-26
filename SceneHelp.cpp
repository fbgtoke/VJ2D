#include "SceneHelp.h"
#include "Game.h"

SceneHelp::SceneHelp() {}

SceneHelp::~SceneHelp() {}

void SceneHelp::init() {
	Scene::init();
	setBackground("images/help.png");
}

void SceneHelp::update(int deltaTime) {
	Scene::update(deltaTime);
	
	if (Game::instance().getKeyPressed('z')) {
		Game::instance().changeScene(SCENE_MENU);
	}
}