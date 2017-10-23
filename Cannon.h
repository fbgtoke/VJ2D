#ifndef _CANNON_INCLUDE
#define _CANNON_INCLUDE

#include "Texture.h"
#include "Sprite.h"

#include "BubbleType.h"

class Cannon {
public:
	Cannon(ShaderProgram &shaderProgram);
	~Cannon();

	void init();
	void update(int deltaTime);
	void render();

	unsigned int getCurrentFrame() const;

	glm::vec2 getCurrentBubblePosition();
	glm::vec2 getBufferedBubblePosition();

private:
	// Shader program
	ShaderProgram& mTexProgram;

	// Textures
	Texture mTexArrow;
	Texture mTexBubbles;

	// Bubbles
	BubbleType mCurrentBubbleType;
	BubbleType mNextBubbleType;

	// Sprites
	Sprite* mArrow;
	Sprite* mCurrentBubble;
	Sprite* mNextBubble;
};

#endif