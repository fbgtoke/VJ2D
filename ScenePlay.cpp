#include "ScenePlay.h"
#include "Game.h"

const int ScenePlay::kMaxLevelNumber = 1;

const int ScenePlay::kStartingScore = 100;
const int ScenePlay::kTurnPenalty = 10;

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
	mTurnsUnitlCollapse = mBubbleLevel.getTurnsBetweenCollapse();
	setBackground(mBubbleLevel.getBackgroundName());

	mBoard.init(mBubbleLevel);
	mCannon.init();

	initMovingBubbles();

	mTexFont.loadFromFile("images/font.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mTextScore.init();
	mTextScore.setPosition(glm::vec2(0.0f, 0.0f));
}

void ScenePlay::update(int deltaTime) {
	Scene::update(deltaTime);

	MovingBubble::BubbleState state = mCurrentMovingBubble->getBubbleState();
	if (Game::instance().getKeyPressed('z') && state == MovingBubble::BUBBLE_STOPPED)
		fireCannon();

	mBoard.update(deltaTime);
	mCannon.update(deltaTime);
	mTextScore.update(deltaTime);

	updateMovingBubbles(deltaTime);
	updateScore();
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
}

void ScenePlay::initMovingBubbles() {
	BubbleType type;

	type = getRandomBubbleType();
	mCurrentMovingBubble = new MovingBubble(mTexProgram, type, mBoard, mLevelNumber);
	mCurrentMovingBubble->init();
	
	type = getRandomBubbleType();
	mNextMovingBubble = new MovingBubble(mTexProgram, type, mBoard, mLevelNumber);
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

		if (mNextMovingBubble->getBubbleType() == BUBBLE_NONE) {
			if (mLevelNumber < kMaxLevelNumber) {
				Game::instance().changeScene(Scene::SCENE_WON);
				Game::instance().getBufferedScene()->receiveInteger(mLevelNumber);
			} else {
				Game::instance().changeScene(Scene::SCENE_MENU);
			}
		}

		--mTurnsUnitlCollapse;
		if (mTurnsUnitlCollapse == 0) {
			mBoard.collapseWall();
			mTurnsUnitlCollapse = mBubbleLevel.getTurnsBetweenCollapse();
		}
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
	mTextScore.setString("Score " + std::to_string(mScore));
}