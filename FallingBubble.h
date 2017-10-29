#ifndef _FALLING_BUBBLE_INCLUDE
#define _FALLING_BUBBLE_INCLUDE

#include <glm/glm.hpp>

#include "Particle.h"
#include "SpriteBubble.h"
#include "BubbleType.h"

class FallingBubble : public Particle {
public:
	FallingBubble(ShaderProgram& program);
	~FallingBubble();

	void init() final;
	void update(int deltaTime) final;

	void setBubbleType(BubbleType type);

private:
	static const float kAcceleration;

	// Shader program
	ShaderProgram& mTexProgram;
	
	static float randomFloat(float min, float max);
};

#endif // _FALLING_BUBBLE_INCLUDE