#ifndef _SCENE_WIN_INCLUDE
#define _SCENE_WIN_INCLUDE

#include "Scene.h"

class SceneWin : public Scene {
public:
	SceneWin();
	~SceneWin() final;

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

	static const int kFreezeInputAmount;
	int mFreezeInput;

	enum MenuOption {
		MENU_NEXT,
		MENU_REPEAT,
		MENU_MAIN_MENU,
		NUM_OPTIONS
	};
	MenuOption mMenuOption;
};


#endif // _SCENE_MENU_INCLUDE

