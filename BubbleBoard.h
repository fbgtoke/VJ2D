#ifndef _BUBBLE_BOARD_INCLUDE
#define _BUBBLE_BOARD_INCLUDE

#include <glm/glm.hpp>
#include "ShaderProgram.h"

#include "Texture.h"
#include "Sprite.h"
#include "SpriteBubble.h"
#include "FallingBubble.h"

#include "BubbleType.h"
#include "BubbleLevel.h"

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

	void init(const BubbleLevel& level);
	void update(int deltaTime);
	void render();

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

	void getPossibleBubbleTypes(std::vector<BubbleType>& types) const;

	void collapseWall();
	unsigned int getNumberOfCollapse() const;

private:
	// Shader program
	ShaderProgram& mTexProgram;

	// Bubbles
	glm::vec2 mOffset;
	unsigned int mBoardWidth;
	unsigned int mBoardHeight;

	void initBubbles();
	Sprite* createBubbleAtPosition(unsigned int x, unsigned int y);
	bubble_matrix_t mBubbles;
	std::vector<std::vector<Sprite*>> mSprites;

	// Textures
	Texture mTexBubbles;
	Texture mTexWall;

	// Sprite
	// Use a single sprite for all the bubble types
	Sprite* mSprite;

	// Collapsing wall
	unsigned int mNumberOfCollapse;
	Sprite* mWall;

	void makeBubbleFall(unsigned int x, unsigned int y);
	void makeBubbleExplode(unsigned int x, unsigned int y);
};

#endif