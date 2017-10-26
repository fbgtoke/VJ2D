#ifndef _SCENE_CREDITS_INCLUDE
#define _SCENE_CREDITS_INCLUDE

#include "Scene.h"

class SceneCredits : public Scene {
public:
	SceneCredits();
	~SceneCredits() final;

	void init() final;
	void update(int deltaTime) final;
};


#endif // _SCENE_CREDITS_INCLUDE