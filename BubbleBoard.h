#ifndef _BUBBLE_BOARD_INCLUDE
#define _BUBBLE_BOARD_INCLUDE

#include <glm/glm.hpp>
#include "ShaderProgram.h"

#include "Texture.h"
#include "Sprite.h"

#include <queue>
#include <list>
#include <iostream>

class BubbleBoard {
public:
	enum BubbleType : unsigned int {
		BUBBLE_RED = 0,
		BUBBLE_GREEN,
		BUBBLE_BLUE,
		BUBBLE_ORANGE,
		BUBBLE_PURPLE,
		BUBBLE_GREY,
		BUBBLE_YELLOW,
		BUBBLE_BLACK,
		BUBBLE_NONE,
		NUM_BUBBLES
	};

	typedef std::vector<BubbleType> bubble_row_t;
	typedef std::vector<bubble_row_t> bubble_matrix_t;

	BubbleBoard(ShaderProgram &shaderProgram);
	~BubbleBoard();

	void init(const glm::vec2& offset, unsigned int w, unsigned int h);
	void update(int deltaTime);
	void render();

	void generate();

private:
	// Shader program
	ShaderProgram& mTexProgram;

	// Bubbles
	glm::vec2 mOffset;
	unsigned int mBoardWidth;
	unsigned int mBoardHeight;
	bubble_matrix_t mBubbles;

	// Textures
	Texture mTexBubbles;

	// Sprite
	// Use a single sprite for all the bubble types
	Sprite* mSprite;

	void getNeighbors(const glm::ivec2& pos, std::list<glm::ivec2>& neighbors) const;
	void checkIntegrity(unsigned int x, unsigned int y);
};

#endif