#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"

#include "Texture.h"
#include "Sprite.h"

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
	Texture mTexBalls;
	Texture mTexBackground;
	Texture mTexArrow;

	// Background
	Sprite* mBackground;

	// Bubble sheet
	static const unsigned int kNumBubblesX;
	static const unsigned int kNumBubblesY;
	std::vector<std::vector<Sprite*>> mBubbles;

	// Arrow
	Sprite* mArrow;
};


#endif // _SCENE_INCLUDE

