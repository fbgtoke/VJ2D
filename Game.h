#ifndef _GAME_INCLUDE
#define _GAME_INCLUDE

#include "Scene.h"
#include <SFML/Audio.hpp>

#define SCREEN_WIDTH 240*3
#define SCREEN_HEIGHT 320*3


// Game is a singleton (a class with a single instance) that represents our whole application


class Game
{

public:
	Game() {}
	
	
	static Game &instance()
	{
		static Game G;
	
		return G;
	}
	
	void init();
	bool update(int deltaTime);
	void render();
	
	// Input callback methods
	void keyPressed(int key);
	void keyReleased(int key);
	void specialKeyPressed(int key);
	void specialKeyReleased(int key);
	void mouseMove(int x, int y);
	void mousePress(int button);
	void mouseRelease(int button);
	
	bool getKey(int key) const;
	bool getSpecialKey(int key) const;

	void scanKeys();
	bool getKeyPressed(int key) const;
	bool getKeyReleased(int key) const;
	bool getSpecialKeyPressed(int key) const;
	bool getSpecialKeyReleased(int key) const;

	void changeScene(Scene::SceneType type);
	Scene* getScene();
	Scene* getBufferedScene();
	
	void stop();

	void changeBackgroundMusic(const std::string& filename);
	sf::Music& getBackgroundMusic();
	void playSoundEffect(const std::string& filename);

private:
	bool bPlay;                       // Continue to play game?
	Scene* scene;                     // Scene to render
	Scene* bufferedScene;
	bool keys[256], specialKeys[256]; // Store key states so that 
	                                  // we can have access at any time

	bool mKeysCurrent[256];
	bool mKeysPrevious[256];

	bool mSpecialKeysCurrent[256];
	bool mSpecialKeysPrevious[256];

	std::string mCurrentMusic;
	sf::Music mBackgroundMusic;

	void checkSounds();
	std::list<std::pair<sf::Sound*, sf::SoundBuffer*>> mSounds;
};


#endif // _GAME_INCLUDE


