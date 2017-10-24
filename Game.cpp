#include <GL/glew.h>
#include <GL/glut.h>
#include "Game.h"


void Game::init()
{
	bPlay = true;
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

	scene = Scene::create(Scene::SCENE_MENU);
	scene->init();

	bufferedScene = nullptr;
}

bool Game::update(int deltaTime)
{
	scene->update(deltaTime);

	if (bufferedScene != nullptr) {
		if (scene != nullptr) {
			delete scene;
		}

		scene = bufferedScene;
		scene->init();

		bufferedScene = nullptr;
	}

	return bPlay;
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	scene->render();
}

void Game::keyPressed(int key)
{
	if(key == 27) // Escape code
		bPlay = false;
	keys[key] = true;
}

void Game::keyReleased(int key)
{
	keys[key] = false;
}

void Game::specialKeyPressed(int key)
{
	specialKeys[key] = true;
}

void Game::specialKeyReleased(int key)
{
	specialKeys[key] = false;
}

void Game::mouseMove(int x, int y)
{
}

void Game::mousePress(int button)
{
}

void Game::mouseRelease(int button)
{
}

bool Game::getKey(int key) const
{
	return keys[key];
}

bool Game::getSpecialKey(int key) const
{
	return specialKeys[key];
}

void Game::changeScene(Scene::SceneType type) {
	if (bufferedScene != nullptr)
		delete bufferedScene;

	bufferedScene = Scene::create(type);
}

void Game::stop() {
	bPlay = false;
}