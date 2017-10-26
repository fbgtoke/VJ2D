#ifndef _SCENE_WIN_INCLUDE
#define _SCENE_WIN_INCLUDE

#include "Scene.h"
#include "SpriteBobble.h"

class SceneWin : public Scene {
public:
	SceneWin();
	~SceneWin() final;

	void init() final;
	void update(int deltaTime) final;
	void render() final;

	void receiveInteger(int integer) final;

private:
	static const glm::ivec2 kBobbleOffset;

	Texture mTexBobble;
	SpriteBobble* mBobble;

	enum MenuOption {
		MENU_NEXT,
		MENU_REPEAT,
		MENU_MAIN_MENU,
		NUM_OPTIONS
	};
	MenuOption mMenuOption;

	int mLevelNumber;
};


#endif // _SCENE_MENU_INCLUDE

