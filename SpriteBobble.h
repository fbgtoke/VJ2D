#ifndef _SPRITE_BOBBLE_INCLUDE
#define _SPRITE_BOBBLE_INCLUDE

#include "Sprite.h"

class SpriteBobble : public Sprite {
public:
	SpriteBobble(Texture *spritesheet, ShaderProgram *program);

private:
	static const glm::ivec2 kQuadSize;
	static const glm::vec2 kSizeInSpriteSheet;
	static const unsigned int kStallingFrames;
	static const unsigned int kNumFrames;
	static const unsigned int kAnimationSpeed;
};

#endif // _SPRITE_BOBBLE_INCLUDE