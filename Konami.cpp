#include "Konami.h"
#include "Game.h"

const glm::ivec2 Konami::kNumSprites = glm::ivec2(500, 1000);
const glm::ivec2 Konami::kBoundariesX = glm::ivec2(-700, -64);
const glm::ivec2 Konami::kBoundariesY = glm::ivec2(-64, 420);

Konami::Konami(ShaderProgram& mTexProgram)
	: mTexProgram(mTexProgram) {
	
}

Konami::~Konami() {
	for (Sprite* sprite : mSprites)
		if (sprite != nullptr)
			delete sprite;

	mSprites.clear();
}

void Konami::init() {
	mTexKonami.loadFromFile("images/konami.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mSequenceState = 0;
	mActive = false;
}

void Konami::update(int deltaTime) {
	updateSequence();

	Sprite* sprite;
	std::list<Sprite*>::iterator it = mSprites.begin();

	glm::vec2 position;

	if (mActive) {
		while (it != mSprites.end()) {
			sprite = *it;

			sprite->update(deltaTime);

			position = sprite->getPosition();
			position.x += 0.1 * deltaTime;
			sprite->setPosition(position);

			if (outOfBounds(sprite)) {
				delete sprite;
				mSprites.erase(it++);
			}

			int random = rand()%800;
			if (random == 0)
				Game::instance().playSoundEffect("sfx/konami.ogg");

			it++;
		}

		mActive = (mSprites.size() != 0);
	}
}

void Konami::render() {
	for (Sprite* sprite : mSprites)
		if (sprite != nullptr)
			sprite->render();
}

Sprite* Konami::initOneSprite() {
	Sprite* sprite = Sprite::createSprite(
		glm::ivec2(32, 32),
		glm::vec2(32.0f/256.0f, 1),
		&mTexKonami,
		&mTexProgram
	);

	sprite->setNumberAnimations(1);
	sprite->setAnimationSpeed(0, 10);
		for (int i = 0; i < 6; ++i)
			sprite->addKeyframe(0, glm::vec2(32.0f/256.0f * i, 0.0f));
	sprite->changeAnimation(0);
	sprite->setRepeat(true);

	glm::ivec2 position;
	position.x = randomInt(kBoundariesX.x, kBoundariesX.y);
	position.y = randomInt(kBoundariesY.x, kBoundariesY.y);
	sprite->setPosition(position);

	return sprite;
}

void Konami::initSprites() {
	int instances = randomInt(kNumSprites.x, kNumSprites.y);

	for (int i = 0; i < instances; ++i)
		mSprites.push_back(initOneSprite());
}

int Konami::randomInt(int min, int max) {
	return
		min + static_cast <int> (rand()) /( static_cast <int> (RAND_MAX/(max-min)));
}

float Konami::randomFloat(float min, float max) {
	return
		min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
}

bool Konami::outOfBounds(Sprite* sprite) {
	glm::vec2 position = sprite->getPosition();
	const float margin = 32.0f;

	return
		position.x < 0 - 1000 ||
		position.x > 240 + 500 ||
		position.y < 0 - 1000 ||
		position.y > 320 + 1000;
}

void Konami::updateSequence() {
	if (Game::instance().getSpecialKeyPressed(GLUT_KEY_UP)) {
		if (mSequenceState == 0 || mSequenceState == 1)
			++mSequenceState;
		else
			mSequenceState = 0;
	}
	if (Game::instance().getSpecialKeyPressed(GLUT_KEY_DOWN)) {
		if (mSequenceState == 2 || mSequenceState == 3)
			++mSequenceState;
		else
			mSequenceState = 0;
	}
	if (Game::instance().getSpecialKeyPressed(GLUT_KEY_LEFT)) {
		if (mSequenceState == 4 || mSequenceState == 6)
			++mSequenceState;
		else
			mSequenceState = 0;
	}
	if (Game::instance().getSpecialKeyPressed(GLUT_KEY_RIGHT)) {
		if (mSequenceState == 5 || mSequenceState == 7)
			++mSequenceState;
		else
			mSequenceState = 0;
	}
	if (Game::instance().getKeyPressed('b')) {
		if (mSequenceState == 8)
			++mSequenceState;
		else
			mSequenceState = 0;
	}
	if (Game::instance().getKeyPressed('a')) {
		if (mSequenceState == 9)
			++mSequenceState;
		else
			mSequenceState = 0;
	}
	if (Game::instance().getKeyPressed('\n')) {
		if (mSequenceState == 10) 
			++mSequenceState;
		else
			mSequenceState = 0;
	}

	if (mSequenceState == 10 && !mActive) {
		mActive = true;
		mSequenceState = 0;
		initSprites();
	}
}