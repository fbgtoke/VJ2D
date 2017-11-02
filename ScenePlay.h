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
	void input();
	void render() final;

	void receiveInteger(int integer) final;

private:
	// Bubble sheet
	BubbleBoard mBoard;

	// Cannon
	void fireCannon();
	Cannon mCannon;

	// Moving bubble
	void initMovingBubbles();
	void updateMovingBubbles(int deltaTime);
	BubbleType getRandomBubbleType() const;
	void swapMovingBubbles();
	MovingBubble* mCurrentMovingBubble;
	MovingBubble* mNextMovingBubble;

	// Level def
	static const int kMaxLevelNumber;
	int mLevelNumber;
	BubbleLevel mBubbleLevel;

	// Score
	Texture mTexFont;
	Text mTextScore;
	
	static const int kStartingScore;
	static const int kTurnPenalty;
	int mScore;
	std::string mTitle;
	void updateScore();

	// Win condition
	static const int kTimeToNextScene;
	int mTimeToNextScene;
	SceneType mNextScene;
	
	void winLevel();
	void looseLevel();

	void goToNextScene();
};


#endif // _SCENE_PLAY_INCLUDE

