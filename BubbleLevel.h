#ifndef _BUBBLE_LEVEL_INCLUDE
#define _BUBBLE_LEVEL_INCLUDE

#include <glm/glm.hpp>

#include "BubbleType.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class BubbleLevel {
public:
	BubbleLevel();
	BubbleLevel(const std::string& filename);
	~BubbleLevel();

	void loadFromFile(const std::string& filename);
	void saveToFile(const std::string& filename) const;

	void setTitle(const std::string& title);
	void setBackgroundName(const std::string& background);
	void setTurnsBetweenCollapse(unsigned int turns);
	void setOffset(const glm::vec2& offset);

	std::string getTitle() const;
	std::string getBackgroundName() const;
	unsigned int getTurnsBetweenCollapse() const;
	glm::vec2 getOffset() const;

	unsigned int getBubblesWidth() const;
	unsigned int getBubblesHeight() const;

	void setBubbles(const std::vector<std::vector<BubbleType>>& bubbles);
	void getBubbles(std::vector<std::vector<BubbleType>>& bubbles) const;

	void setAllowBubbleBomb(bool allow);
	bool getAllowBubbleBomb() const;

	void setSeed(unsigned int seed);
	unsigned int getSeed() const;
private:
	static const std::string kPathToLevels;
	static const std::string kPathToBackgrounds;

	std::string mTitle;
	std::string mBackgroundName;
	unsigned int mTurnsBetweenCollapse;
	glm::vec2 mOffset;

	unsigned int mBubblesWidth;
	unsigned int mBubblesHeight;
	std::vector<std::vector<BubbleType>> mBubbles;
	void readBubbles(std::ifstream& stream);

	bool mAllowBubbleBomb;
	unsigned int mSeed;
};

#endif // _BUBBLE_LEVEL_INCLUDE