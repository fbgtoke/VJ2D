#include <GL/glew.h>
#include <GL/glut.h>
#include "Game.h"


void Game::init() {
	bPlay = true;
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

	scene = Scene::create(Scene::SCENE_MENU);
	scene->init();

	bufferedScene = nullptr;
}

bool Game::update(int deltaTime) {
	scene->update(deltaTime);

	if (bufferedScene != nullptr) {
		if (scene != nullptr) {
			delete scene;
		}

		scene = bufferedScene;
		scene->init();

		bufferedScene = nullptr;
	}

	checkSounds();

	return bPlay;
}

void Game::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	scene->render();
}

void Game::keyPressed(int key) {
	if(key == 27) // Escape code
		bPlay = false;
	keys[key] = true;
}

void Game::keyReleased(int key) {
	keys[key] = false;
}

void Game::specialKeyPressed(int key) {
	specialKeys[key] = true;
}

void Game::specialKeyReleased(int key) {
	specialKeys[key] = false;
}

void Game::mouseMove(int x, int y) {}

void Game::mousePress(int button) {}

void Game::mouseRelease(int button) {}

bool Game::getKey(int key) const {
	return keys[key];
}

bool Game::getSpecialKey(int key) const {
	return specialKeys[key];
}

void Game::scanKeys() {
	for (int i = 0; i < 256; ++i) {
		mKeysPrevious[i] = mKeysCurrent[i];
		mKeysCurrent[i] = getKey(i);

		mSpecialKeysPrevious[i] = mSpecialKeysCurrent[i];
		mSpecialKeysCurrent[i] = getSpecialKey(i);
	}
}

bool Game::getKeyPressed(int key) const {
	return !mKeysPrevious[key] && mKeysCurrent[key];
}

bool Game::getKeyReleased(int key) const {
	return mKeysPrevious[key] && !mKeysCurrent[key];
}

bool Game::getSpecialKeyPressed(int key) const {
	return !mSpecialKeysPrevious[key] && mSpecialKeysCurrent[key];
}

bool Game::getSpecialKeyReleased(int key) const {
	return mSpecialKeysPrevious[key] && !mSpecialKeysCurrent[key];
}

void Game::changeScene(Scene::SceneType type) {
	if (bufferedScene != nullptr)
		delete bufferedScene;

	bufferedScene = Scene::create(type);
}

Scene* Game::getScene() {
	return scene;
}

Scene* Game::getBufferedScene() {
	return bufferedScene;
}

void Game::stop() {
	bPlay = false;
}

void Game::changeBackgroundMusic(const std::string& filename) {
	if (filename != mCurrentMusic) {
		mBackgroundMusic.openFromFile(filename);
		mBackgroundMusic.play();
		mBackgroundMusic.setVolume(50);
	}

	mCurrentMusic = filename;
}

sf::Music& Game::getBackgroundMusic() {
	return mBackgroundMusic;
}

void Game::playSoundEffect(const std::string& filename) {
	sf::SoundBuffer* buffer;
	sf::Sound* sound;

	buffer = new sf::SoundBuffer();
	buffer->loadFromFile(filename);
	sound = new sf::Sound(*buffer);
	sound->setVolume(300);
	sound->play();

	mSounds.push_back(std::make_pair(sound, buffer));
}

void Game::checkSounds() {
	std::list<std::pair<sf::Sound*, sf::SoundBuffer*>>::iterator it = mSounds.begin();

	sf::Sound* sound;
	while (it != mSounds.end()) {
		sound = (*it).first;
		if (sound->getStatus() != sf::Sound::Playing) {
			delete (*it).first;
			delete (*it).second;
			mSounds.erase(it++);
		} else {
			it++;
		}
	}
}