#ifndef _SCENE_MENU_INCLUDE
#define _SCENE_MENU_INCLUDE

#include "Scene.h"

class SceneMenu : public Scene {
public:
	SceneMenu();
	~SceneMenu() final;

	void init() final;
	void update(int deltaTime) final;
	void render() final;

private:
	// Textures
	Texture mTexBackground;

	// Background
	Sprite* mBackground;
};


#endif // _SCENE_MENU_INCLUDE

