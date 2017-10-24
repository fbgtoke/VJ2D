#ifndef _PARTICLE_INCLUDE
#define _PARTICLE_INCLUDE

#include <glm/glm.hpp>
#include "Texture.h"
#include "Sprite.h"

class Particle {
public:
	Particle();
	virtual ~Particle();

	virtual void init() = 0;
	virtual void update(int deltaTime);
	virtual void render();

	void setPosition(const glm::vec2& position);
	void setVelocity(const glm::vec2& velocity);

	glm::vec2 getPosition() const;
	glm::vec2 getVelocity() const;

protected:
	Texture mTexure;
	Sprite* mSprite;

	glm::vec2 mPosition;
	glm::vec2 mVelocity;
};

#endif