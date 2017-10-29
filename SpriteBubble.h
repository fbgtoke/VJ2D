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
	static const unsigned int kStallingFrames;
	static const unsigned int kNumFrames;
	static const unsigned int kAnimationSpeed;

	void addRegularFrames(unsigned int animation);
	void addBombFrames(unsigned int animation);
};

#endif // _SPRITE_BUBBLE_INCLUDE