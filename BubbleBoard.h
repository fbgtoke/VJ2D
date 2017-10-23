#ifndef _BUBBLE_BOARD_INCLUDE
#define _BUBBLE_BOARD_INCLUDE

#include <glm/glm.hpp>
#include "ShaderProgram.h"

#include "Texture.h"
#include "Sprite.h"

#include "BubbleType.h"

#include <queue>
#include <list>
#include <iostream>
#include <fstream>

class BubbleBoard {
public:
	typedef std::vector<BubbleType> bubble_row_t;
	typedef std::vector<bubble_row_t> bubble_matrix_t;

	BubbleBoard(ShaderProgram &shaderProgram);
	~BubbleBoard();

	void init(const glm::vec2& offset, unsigned int w, unsigned int h);
	void update(int deltaTime);
	void render();

	void generate();
	void loadFromFile(const std::string& filename);

	glm::vec2 getOffset() const;
	unsigned int getWidth() const;
	unsigned int getHeight() const;

	void setBubbleType(unsigned int x, unsigned int y, BubbleType type);
	BubbleType getBubbleType(unsigned int x, unsigned int y) const;

	void getNeighbors(const glm::ivec2& pos, std::list<glm::ivec2>& neighbors) const;
	void getNeighbors(const glm::ivec2& pos, std::list<glm::ivec2>& neighbors, BubbleType type) const;

	glm::vec2 getBubbleOrigin(unsigned int x, unsigned int y) const;
	glm::vec2 getBubbleCentroid(unsigned int x, unsigned int y) const;

	void checkIntegrity(unsigned int x, unsigned int y);
	void checkFloatingBubbles();

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
};

#endif