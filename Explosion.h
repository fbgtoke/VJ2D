#ifndef _EXPLOSION_INCLUDE
#define _EXPLOSION_INCLUDE

#include <glm/glm.hpp>

#include "Particle.h"
#include "SpriteBubble.h"
#include "BubbleType.h"

class Explosion : public Particle {
public:
	Explosion(ShaderProgram& program);
	~Explosion();

	void init() final;
	void update(int deltaTime) final;

private:
	// Shader program
	ShaderProgram& mTexProgram;

	int mAliveTime;
};

#endif // _EXPLOSION_INCLUDE