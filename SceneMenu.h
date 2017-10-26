#ifndef _SCENE_MENU_INCLUDE
#define _SCENE_MENU_INCLUDE

#include "Scene.h"
#include "SpriteBobble.h"

class SceneMenu : public Scene {
public:
	SceneMenu();
	~SceneMenu() final;

	void init() final;
	void update(int deltaTime) final;
	void render() final;

private:
	static const glm::ivec2 kBobbleOffset;

	Texture mTexBobble;
	SpriteBobble* mBobble;

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

