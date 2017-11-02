#include "ScenePlay.h"
#include "Game.h"

const int ScenePlay::kMaxLevelNumber = 4;

const int ScenePlay::kStartingScore = 1000;
const int ScenePlay::kTurnPenalty = 10;

const int ScenePlay::kTimeToNextScene = 2000;

ScenePlay::ScenePlay()
	: mBoard(mTexProgram), mCannon(mTexProgram),
	mCurrentMovingBubble(nullptr), mNextMovingBubble(nullptr),
	mLevelNumber(0),
	mTextScore(mTexProgram, mTexFont), mScore(kStartingScore) {}

ScenePlay::~ScenePlay() {
	if (mCurrentMovingBubble != nullptr)
		delete mCurrentMovingBubble;
	if (mNextMovingBubble != nullptr)
		delete mNextMovingBubble;
}


void ScenePlay::init() {
	Scene::init();

	mBubbleLevel.loadFromFile("level" + std::to_string(mLevelNumber) + ".txt");
	setBackground(mBubbleLevel.getBackgroundName());

	unsigned int turnsBetweenCollapse = mBubbleLevel.getTurnsBetweenCollapse();
	bool allowBubbleBomb = mBubbleLevel.getAllowBubbleBomb(); 
	mBoard.init(mBubbleLevel, turnsBetweenCollapse, allowBubbleBomb);
	mCannon.init();

	initMovingBubbles();

	mTexFont.loadFromFile("images/font.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mTextScore.init();
	mTextScore.setPosition(glm::vec2(4.0f, 2.0f));
	mTitle = mBubbleLevel.getTitle();

	mTimeToNextScene = -1;

	Game::instance().changeBackgroundMusic("music/play.ogg");
	Game::instance().getBackgroundMusic().setLoop(true);
}

void ScenePlay::update(int deltaTime) {
	Scene::update(deltaTime);

	input();

	mBoard.update(deltaTime);
	mCannon.update(deltaTime);
	mTextScore.update(deltaTime);

	updateMovingBubbles(deltaTime);
	updateScore();

	if (mTimeToNextScene != -1) {
		mTimeToNextScene -= deltaTime;
		if (mTimeToNextScene <= 0)
			goToNextScene();
	} else if (mBoard.checkWin()) {
		winLevel();
	} else if (mBoard.checkGameOver()) {
		looseLevel();
	}
}

void ScenePlay::input() {
	if (isInputLocked()) return;

	MovingBubble::BubbleState state = mCurrentMovingBubble->getBubbleState();
	if (Game::instance().getKeyPressed('z') && state == MovingBubble::BUBBLE_STOPPED)
		fireCannon();

	if (Game::instance().getKeyPressed('n'))
		winLevel();
}

void ScenePlay::render() {
	Scene::render();

	mBoard.render();
	mCannon.render();
	mTextScore.render();

	if (mCurrentMovingBubble != nullptr)
		mCurrentMovingBubble->render();
	if (mNextMovingBubble != nullptr)
		mNextMovingBubble->render();

	for (Particle* particle : mParticles) {
		if (particle != nullptr)
			particle->render();
	}
}

void ScenePlay::fireCannon() {
	const float minAngle = 2.5f;
	const float alpha = M_PI / 128;
	float angle = alpha * (mCannon.getCurrentFrame() + 1);

	glm::vec2 ballVel;
	ballVel.x = cos(angle);
	ballVel.y = (-1) * sin(angle);
	glm::normalize(ballVel);
	ballVel *= 0.3;

	mCurrentMovingBubble->setVelocity(ballVel);
	mCurrentMovingBubble->setBubbleState(MovingBubble::BUBBLE_MOVING);

	mScore = std::max(mScore - kTurnPenalty, 0);

	Game::instance().playSoundEffect("sfx/piu.ogg");
}

void ScenePlay::initMovingBubbles() {
	BubbleType type;

	type = getRandomBubbleType();
	mCurrentMovingBubble = new MovingBubble(mTexProgram, type, mBoard);
	mCurrentMovingBubble->init();
	
	type = getRandomBubbleType();
	mNextMovingBubble = new MovingBubble(mTexProgram, type, mBoard);
	mNextMovingBubble->init();

	swapMovingBubbles();
}

void ScenePlay::updateMovingBubbles(int deltaTime) {
	if (mCurrentMovingBubble != nullptr)
		mCurrentMovingBubble->update(deltaTime);
	if (mNextMovingBubble != nullptr)
		mNextMovingBubble->update(deltaTime);

	if (mCurrentMovingBubble->getBubbleState() == MovingBubble::BUBBLE_DEAD) {
		swapMovingBubbles();
		mBoard.decTurnsUntilCollapse();
	}
}

BubbleType ScenePlay::getRandomBubbleType() const {
	std::vector<BubbleType> types;
	mBoard.getPossibleBubbleTypes(types);

	if (types.size() > 0) {
		unsigned int index = rand()%(types.size());
		return static_cast<BubbleType>(types[index]);
	}

	return BUBBLE_NONE;
}

void ScenePlay::swapMovingBubbles() {
	mNextMovingBubble->setPosition(mCannon.getCurrentBubblePosition());
	mNextMovingBubble->setVelocity(glm::vec2(0.f, 0.f));
	mNextMovingBubble->setBubbleState(MovingBubble::BUBBLE_STOPPED);

	mCurrentMovingBubble->setPosition(mCannon.getBufferedBubblePosition());
	mCurrentMovingBubble->setVelocity(glm::vec2(0.f, 0.f));
	mCurrentMovingBubble->setBubbleState(MovingBubble::BUBBLE_BUFFERED);
	mCurrentMovingBubble->setBubbleType(getRandomBubbleType());

	MovingBubble* aux = mNextMovingBubble;
	mNextMovingBubble = mCurrentMovingBubble;
	mCurrentMovingBubble = aux;
}

void ScenePlay::receiveInteger(int integer) {
	mLevelNumber = integer;
}

void ScenePlay::updateScore() {
	mTextScore.setString(
		"Score " + std::to_string(mScore) +
		"   " + mTitle
	);
}

void ScenePlay::winLevel() {
	lockInput(true);

	Game::instance().getBackgroundMusic().setVolume(0);

	if (mLevelNumber < kMaxLevelNumber) {
		mTimeToNextScene = kTimeToNextScene;
		mNextScene = Scene::SCENE_WON;
		Game::instance().playSoundEffect("sfx/win.ogg");
	} else {
		mTimeToNextScene = kTimeToNextScene * 4;
		mNextScene = Scene::SCENE_FINAL;
		Game::instance().playSoundEffect("sfx/win-final.ogg");
	}
}

void ScenePlay::looseLevel() {
	lockInput(true);
	mTimeToNextScene = kTimeToNextScene;
	mNextScene = Scene::SCENE_GAME_OVER;

	Game::instance().getBackgroundMusic().setVolume(0);
	Game::instance().playSoundEffect("sfx/death.ogg");
}

void ScenePlay::goToNextScene() {
	Game::instance().getBackgroundMusic().setVolume(50);
	Game::instance().changeScene(mNextScene);
	Game::instance().getBufferedScene()->receiveInteger(mLevelNumber);
}