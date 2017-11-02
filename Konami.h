#ifndef _KONAMI_INCLUDE
#define _KONAMI_INCLUDE

#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "Sprite.h"

#include <list>

class Konami {
public:
	Konami(ShaderProgram& mTexProgram);
	~Konami();

	void init();
	void update(int deltaTime);
	void render();

private:
	ShaderProgram& mTexProgram;
	Texture mTexKonami;
	std::list<Sprite*> mSprites;

	unsigned int mSequenceState;
	bool mActive;

	static const glm::ivec2 kNumSprites;
	static const glm::ivec2 kBoundariesX;
	static const glm::ivec2 kBoundariesY;
	static int randomInt(int min, int max);
	static float randomFloat(float min, float max);
	static bool outOfBounds(Sprite* sprite);

	Sprite* initOneSprite();
	void initSprites();
	void updateSequence();
};

#endif // _KNAMI_INCLUDE