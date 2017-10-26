#ifndef _SCENE_PLAY_INCLUDE
#define _SCENE_PLAY_INCLUDE

#include "Scene.h"

#include "BubbleBoard.h"
#include "Cannon.h"
#include "MovingBubble.h"
#include "BubbleLevel.h"
#include "Text.h"

#include <string>

class ScenePlay : public Scene {
public:
	ScenePlay();
	~ScenePlay() final;

	void init() final;
	void update(int deltaTime) final;
	void render() final;

	void receiveInteger(int integer) final;

private:
	// Textures
	Texture mTexBackground;

	// Background
	Sprite* mBackground;

	// Bubble sheet
	BubbleBoard mBoard;

	// Cannon
	Cannon mCannon;

	// Moving bubble
	void initMovingBubbles();
	BubbleType getRandomBubbleType() const;
	void swapMovingBubbles();
	MovingBubble* mCurrentMovingBubble;
	MovingBubble* mNextMovingBubble;

	// Level def
	static const int kMaxLevelNumber;
	int mLevelNumber;
	BubbleLevel mBubbleLevel;

	// Clossapsing wall
	unsigned int mTurnsUnitlCollapse;

	// Score
	Texture mTexFont;
	Text mTextScore;
	
	static const int kStartingScore;
	static const int kTurnPenalty;
	int mScore;
	void updateScore();
};


#endif // _SCENE_PLAY_INCLUDE

