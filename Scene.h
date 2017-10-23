#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GL/glew.h>
#include <GL/glut.h>

#include <iostream>
#include <cmath>

#include "ShaderProgram.h"
#include "Texture.h"
#include "Sprite.h"

class Scene {
public:
	Scene() {};
	virtual ~Scene() {};

	virtual void init() {};
	virtual void update(int deltaTime) {};
	virtual void render() {};

	enum SceneType {
		SCENE_MENU,
		SCENE_PLAY,
		SCENE_HELP,
		SCENE_CREDITS,
		SCENE_WON,
		SCENE_GAME_OVER
	};
	static Scene* create(SceneType type);

	void initShaders();

protected:
	ShaderProgram texProgram;
	float currentTime;
	glm::mat4 projection;
};

#endif // _SCENE_INCLUDE