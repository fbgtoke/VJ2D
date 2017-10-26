#ifndef _SCENE_HELP_INCLUDE
#define _SCENE_HELP_INCLUDE

#include "Scene.h"

class SceneHelp : public Scene {
public:
	SceneHelp();
	~SceneHelp() final;

	void init() final;
	void update(int deltaTime) final;

private:
};


#endif // _SCENE_HELP_INCLUDE