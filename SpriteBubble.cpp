#include "SpriteBubble.h"

const glm::ivec2 SpriteBubble::kQuadSize = glm::ivec2(16, 16);
const glm::vec2 SpriteBubble::kSizeInSpriteSheet = glm::vec2(1.0f/8.0f, 1.0f/16.0f);
const unsigned int SpriteBubble::kStallingFrames = 5;
const unsigned int SpriteBubble::kNumFrames = 8;
const unsigned int SpriteBubble::kAnimationSpeed = 5;

SpriteBubble::SpriteBubble(Texture *spritesheet, ShaderProgram *program)
	: Sprite(kQuadSize, kSizeInSpriteSheet, spritesheet, program)
{
	setNumberAnimations(NUM_BUBBLES + kStallingFrames);

	for (unsigned int i = 0; i < NUM_BUBBLES; ++i) {
		if (i != BUBBLE_BOMB)
			addRegularFrames(i);	
		else
			addBombFrames(i);
	}
	changeAnimation(BUBBLE_NONE);
}

void SpriteBubble::addRegularFrames(unsigned int animation) {
	setAnimationSpeed(animation, kAnimationSpeed);

	glm::vec2 frame;
	for (unsigned int j = 0; j < kStallingFrames; ++j) {
		frame.x = kSizeInSpriteSheet.x * 0;
		frame.y = kSizeInSpriteSheet.y * animation;
		addKeyframe(animation, frame);
	}

	for (unsigned int j = 0; j < kNumFrames; ++j) {
		frame.x = kSizeInSpriteSheet.x * j;
		frame.y = kSizeInSpriteSheet.y * animation;
		addKeyframe(animation, frame);
	}
}

void SpriteBubble::addBombFrames(unsigned int animation) {
	setAnimationSpeed(animation, kAnimationSpeed * 2);

	glm::vec2 frame;
	for (unsigned int j = 0; j < kNumFrames; ++j) {
		frame.x = kSizeInSpriteSheet.x * j;
		frame.y = kSizeInSpriteSheet.y * animation;
		addKeyframe(animation, frame);
	}
}