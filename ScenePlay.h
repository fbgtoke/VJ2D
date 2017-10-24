#ifndef _SCENE_PLAY_INCLUDE
#define _SCENE_PLAY_INCLUDE

#include "Scene.h"

#include "BubbleBoard.h"
#include "Cannon.h"
#include "MovingBubble.h"
#include "BubbleLevel.h"

class ScenePlay : public Scene {
public:
	ScenePlay();
	~ScenePlay() final;

	void init() final;
	void update(int deltaTime) final;
	void render() final;

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
	BubbleLevel mBubbleLevel;

	// Clossapsing wall
	unsigned int mTurnsUnitlCollapse;
};


#endif // _SCENE_PLAY_INCLUDE

