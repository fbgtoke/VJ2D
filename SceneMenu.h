#ifndef _SCENE_MENU_INCLUDE
#define _SCENE_MENU_INCLUDE

class SceneMenu : public Scene {
public:
	SceneMenu();
	~SceneMenu() final;

	void init();
	void update(int deltaTime);
	void render();

private:
};

#endif