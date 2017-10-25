#ifndef _MOVING_BUBBLE_INCLUDE
#define _MOVING_BUBBLE_INCLUDE

#include <glm/glm.hpp>
#include "ShaderProgram.h"

#include "Texture.h"
#include "SpriteBubble.h"

#include "BubbleType.h"
#include "BubbleBoard.h"

class MovingBubble {
public:
	MovingBubble(ShaderProgram& shaderProgram, BubbleType type, BubbleBoard& board);
	~MovingBubble();

	void init();
	void update(int deltaTime);
	void render() const;

	void setBubbleType(BubbleType type);
	BubbleType getBubbleType() const;

	void setPosition(const glm::vec2& pos);
	void setVelocity(const glm::vec2& vel);

	enum BubbleState {
		BUBBLE_STOPPED,
		BUBBLE_MOVING,
		BUBBLE_DEAD,
		BUBBLE_BUFFERED
	};
	void setBubbleState(BubbleState state);
	BubbleState getBubbleState() const;

private:
	// Shader program
	ShaderProgram& mTexProgram;

	// Texture & Sprite
	Texture mTexBubbles;
	SpriteBubble* mSprite;

	// Type
	BubbleType mBubbleType;

	// Physics
	glm::vec2 mPosition;
	glm::vec2 mVelocity;

	// Current state
	BubbleState mBubbleState;

	// Other bubbles
	BubbleBoard& mBoard;
	void checkCollision();
	glm::ivec2 getClosestNeighbor(const std::list<glm::ivec2>& neighbors) const;

	static bool collide(const glm::vec2& pos1, const glm::vec2& pos2, float size);
	static float dist(const glm::vec2& pos1, const glm::vec2& pos2);
};

#endif