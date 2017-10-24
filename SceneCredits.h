#ifndef _SCENE_CREDITS_INCLUDE
#define _SCENE_CREDITS_INCLUDE

#include "Scene.h"

class SceneCredits : public Scene {
public:
	SceneCredits();
	~SceneCredits() final;

	void init() final;
	void update(int deltaTime) final;
	void render() final;

private:
	// Textures
	Texture mTexBackground;

	// Background
	Sprite* mBackground;
};


#endif // _SCENE_CREDITS_INCLUDE