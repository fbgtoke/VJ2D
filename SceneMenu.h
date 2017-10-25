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
	static const glm::ivec2 kBobbleOffset;

	// Textures
	Texture mTexBackground;
	Texture mTexBobble;

	// Background
	Sprite* mBackground;
	Sprite* mBobble;

	enum MenuOption {
		MENU_PLAY,
		MENU_HELP,
		MENU_CREDITS,
		MENU_CLOSE,
		NUM_OPTIONS
	};
	MenuOption mMenuOption;
};


#endif // _SCENE_MENU_INCLUDE

