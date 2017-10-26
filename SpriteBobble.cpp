#include "SpriteBobble.h"

const glm::ivec2 SpriteBobble::kQuadSize = glm::ivec2(16, 32);
const glm::vec2 SpriteBobble::kSizeInSpriteSheet = glm::vec2(1.0f/4.0f, 1.0f);
const unsigned int SpriteBobble::kAnimationSpeed = 3;

SpriteBobble::SpriteBobble(Texture *spritesheet, ShaderProgram *program)
	: Sprite(kQuadSize, kSizeInSpriteSheet, spritesheet, program)
{
	setNumberAnimations(1);
		setAnimationSpeed(0, kAnimationSpeed);
		addKeyframe(0, glm::vec2(0.00f, 0));
		addKeyframe(0, glm::vec2(0.25f, 0));
		addKeyframe(0, glm::vec2(0.00f, 0));
		addKeyframe(0, glm::vec2(0.25f, 0));
		addKeyframe(0, glm::vec2(0.00f, 0));
		addKeyframe(0, glm::vec2(0.25f, 0));
		addKeyframe(0, glm::vec2(0.50f, 0));
	changeAnimation(0);
}