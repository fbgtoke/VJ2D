#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE


#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GL/glut.h>
#include "ShaderProgram.h"

#include "Texture.h"
#include "Sprite.h"
#include "BubbleBoard.h"

// Scene contains all the entities of our game.
// It is responsible for updating and render them.


class Scene
{

public:
	Scene();
	~Scene();

	void init();
	void update(int deltaTime);
	void render();

private:
	void initShaders();

private:
	ShaderProgram texProgram;
	float currentTime;
	glm::mat4 projection;

	// Textures
	Texture mTexBackground;
	Texture mTexArrow;

	// Background
	Sprite* mBackground;

	// Bubble sheet
	static const unsigned int kNumBubblesX;
	static const unsigned int kNumBubblesY;
	BubbleBoard mBoard;

	// Arrow
	Sprite* mArrow;
};


#endif // _SCENE_INCLUDE

