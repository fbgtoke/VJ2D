#ifndef _SCENE_GAME_OVER_INCLUDE
#define _SCENE_GAME_OVER_INCLUDE

#include "Scene.h"

class SceneGameOver : public Scene {
public:
	SceneGameOver();
	~SceneGameOver() final;

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
		MENU_YES,
		MENU_NO,
		NUM_OPTIONS
	};
	MenuOption mMenuOption;
};


#endif // _SCENE_MENU_INCLUDE

