#include "BubbleLevel.h"

const std::string BubbleLevel::kPathToLevels = "./levels/";
const std::string BubbleLevel::kPathToBackgrounds = "./images/";

BubbleLevel::BubbleLevel() {}

BubbleLevel::BubbleLevel(const std::string& filename) {
	loadFromFile(filename);
}

BubbleLevel::~BubbleLevel() {}

void BubbleLevel::loadFromFile(const std::string& filename) {
	std::ifstream stream;
	stream.open(kPathToLevels + filename);

	if (!stream.is_open()) {
		std::cout << "Could not load level from file " + filename << std::endl;
		return;
	}

	std::string title;
	std::string backgroundName;
	unsigned int turnsBetweenCollapse;
	bool allowBubbleBomb;
	glm::vec2 offset;

	std::getline(stream, title);
	std::getline(stream, backgroundName);
	stream >> turnsBetweenCollapse;
	stream >> allowBubbleBomb;
	stream >> offset.x >> offset.y;

	setTitle(title);
	setBackgroundName(backgroundName);
	setTurnsBetweenCollapse(turnsBetweenCollapse);
	setAllowBubbleBomb(allowBubbleBomb);
	setOffset(offset);

	readBubbles(stream);

	stream.close();
}

void BubbleLevel::saveToFile(const std::string& filename) const {
	// TODO
}

void BubbleLevel::setTitle(const std::string& title) {
	mTitle = title;
}

void BubbleLevel::setBackgroundName(const std::string& background) {
	mBackgroundName = kPathToBackgrounds + background;
}

void BubbleLevel::setTurnsBetweenCollapse(unsigned int turns) {
	mTurnsBetweenCollapse = turns;
}

void BubbleLevel::setOffset(const glm::vec2& offset) {
	mOffset = offset;
}

std::string BubbleLevel::getTitle() const {
	return mTitle;
}

std::string BubbleLevel::getBackgroundName() const {
	return mBackgroundName;
}

unsigned int BubbleLevel::getTurnsBetweenCollapse() const {
	return mTurnsBetweenCollapse;
}

glm::vec2 BubbleLevel::getOffset() const {
	return mOffset;
}

unsigned int BubbleLevel::getBubblesWidth() const {
	return mBubblesWidth;
}

unsigned int BubbleLevel::getBubblesHeight() const {
	return mBubblesHeight;
}

void BubbleLevel::setBubbles(const std::vector<std::vector<BubbleType>>& bubbles) {
	mBubblesWidth = bubbles[0].size();
	mBubblesHeight = bubbles.size();

	mBubbles = bubbles;
}

void BubbleLevel::getBubbles(std::vector<std::vector<BubbleType>>& bubbles) const {
	bubbles = mBubbles;
}

void BubbleLevel::setAllowBubbleBomb(bool allow) {
	mAllowBubbleBomb = allow;
}

bool BubbleLevel::getAllowBubbleBomb() const {
	return mAllowBubbleBomb;
}

void BubbleLevel::readBubbles(std::ifstream& stream) {
	stream >> mBubblesWidth;
	stream >> mBubblesHeight;

	mBubbles = std::vector<std::vector<BubbleType>> (
		mBubblesHeight, std::vector<BubbleType>(mBubblesWidth, BUBBLE_NONE)
	);

	unsigned int index;
	for (unsigned int i = 0; i < mBubblesHeight; ++i) {
		for (unsigned int j = 0; j < mBubblesWidth; ++j) {
			if (i % 2 != 0 && j == mBubblesWidth - 1)
				continue;

			stream >> index;
			mBubbles[i][j] = static_cast<BubbleType>(index);
		}
	}
}