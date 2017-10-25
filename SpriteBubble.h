#ifndef _SPRITE_BUBBLE_INCLUDE
#define _SPRITE_BUBBLE_INCLUDE

#include "Sprite.h"
#include "BubbleType.h"

class SpriteBubble : public Sprite {
public:
	SpriteBubble(Texture *spritesheet, ShaderProgram *program);

private:
	static const glm::ivec2 kQuadSize;
	static const glm::vec2 kSizeInSpriteSheet;
	static const unsigned int kNumFrames;
	static const unsigned int kAnimationSpeed;
};

#endif // _SPRITE_BUBBLE_INCLUDE