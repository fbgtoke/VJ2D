#include "ScenePlay.h"
#include "Game.h"

ScenePlay::ScenePlay()
	: mBoard(texProgram), mCannon(texProgram),
	mBackground(nullptr),
	mCurrentMovingBubble(nullptr), mNextMovingBubble(nullptr) {}

ScenePlay::~ScenePlay() {
	if (mBackground != nullptr)
		delete mBackground;
	if (mCurrentMovingBubble != nullptr)
		delete mCurrentMovingBubble;
	if (mNextMovingBubble != nullptr)
		delete mNextMovingBubble;
}


void ScenePlay::init() {
	Scene::init();

	mBubbleLevel.loadFromFile("level00.txt");
	mTurnsUnitlCollapse = mBubbleLevel.getTurnsBetweenCollapse();

	mTexBackground.loadFromFile(mBubbleLevel.getBackgroundName(), TEXTURE_PIXEL_FORMAT_RGBA);

	mBackground = Sprite::createSprite(
		glm::ivec2(240, 320), 
		glm::vec2(1, 1), 
		&mTexBackground, 
		&texProgram
	);
	mBackground->setNumberAnimations(1);
		mBackground->setAnimationSpeed(0, 0);
		mBackground->addKeyframe(0, glm::vec2(0, 0));
	mBackground->changeAnimation(0);

	mBoard.init(mBubbleLevel);
	mCannon.init();

	initMovingBubbles();
}

void ScenePlay::update(int deltaTime) {
	Scene::update(deltaTime);

	if (Game::instance().getKey('z') && currentTime > 500) {
		if (mCurrentMovingBubble->getBubbleState() == MovingBubble::BUBBLE_STOPPED) {
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
		}
	}

	mBoard.update(deltaTime);
	mCannon.update(deltaTime);

	if (mCurrentMovingBubble != nullptr)
		mCurrentMovingBubble->update(deltaTime);
	if (mNextMovingBubble != nullptr)
		mNextMovingBubble->update(deltaTime);

	if (mCurrentMovingBubble->getBubbleState() == MovingBubble::BUBBLE_DEAD) {
		swapMovingBubbles();

		if (mNextMovingBubble->getBubbleType() == BUBBLE_NONE)
			Game::instance().changeScene(Scene::SCENE_WON);

		--mTurnsUnitlCollapse;
		if (mTurnsUnitlCollapse == 0) {
			mBoard.collapseWall();
			mTurnsUnitlCollapse = mBubbleLevel.getTurnsBetweenCollapse();
		}
	}
}

void ScenePlay::render() {
	Scene::render();

	mBackground->render();
	mBoard.render();
	mCannon.render();

	if (mCurrentMovingBubble != nullptr)
		mCurrentMovingBubble->render();
	if (mNextMovingBubble != nullptr)
		mNextMovingBubble->render();

	for (Particle* particle : mParticles) {
		if (particle != nullptr)
			particle->render();
	}
}

void ScenePlay::initMovingBubbles() {
	BubbleType type;

	type = getRandomBubbleType();
	mCurrentMovingBubble = new MovingBubble(texProgram, type, mBoard);
	mCurrentMovingBubble->init();
	
	type = getRandomBubbleType();
	mNextMovingBubble = new MovingBubble(texProgram, type, mBoard);
	mNextMovingBubble->init();

	swapMovingBubbles();
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