#include "SceneGameOver.h"
#include "Game.h"

const glm::ivec2 SceneGameOver::kBobbleOffset = glm::ivec2(80, 192);

const int SceneGameOver::kFreezeInputAmount = 300;

SceneGameOver::SceneGameOver() {}

SceneGameOver::~SceneGameOver() {
	if (mBackground != nullptr)
		delete mBackground;
	if (mBobble != nullptr)
		delete mBobble;
}

void SceneGameOver::init() {
	initShaders();
	projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
	currentTime = 0.0f;

	mTexBackground.loadFromFile("images/youlost.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mTexBobble.loadFromFile("images/bobblemenu.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mBackground = Sprite::createSprite(glm::ivec2(240, 320), glm::vec2(1, 1), &mTexBackground, &texProgram);
	mBackground->setNumberAnimations(1);
		mBackground->setAnimationSpeed(0, 0);
		mBackground->addKeyframe(0, glm::vec2(0, 0));
	mBackground->changeAnimation(0);

	mBobble = Sprite::createSprite(glm::ivec2(16, 32), glm::vec2(0.25f, 1.0f), &mTexBobble, &texProgram);
	mBobble->setNumberAnimations(1);
		mBobble->setAnimationSpeed(0, 3);
		mBobble->addKeyframe(0, glm::vec2(0.00f, 0));
		mBobble->addKeyframe(0, glm::vec2(0.25f, 0));
		mBobble->addKeyframe(0, glm::vec2(0.00f, 0));
		mBobble->addKeyframe(0, glm::vec2(0.25f, 0));
		mBobble->addKeyframe(0, glm::vec2(0.00f, 0));
		mBobble->addKeyframe(0, glm::vec2(0.25f, 0));
		mBobble->addKeyframe(0, glm::vec2(0.50f, 0));
	mBobble->changeAnimation(0);
	mBobble->setPosition(kBobbleOffset);

	mMenuOption = MENU_YES;
	mFreezeInput = 0;
}

void SceneGameOver::update(int deltaTime) {
	currentTime += deltaTime;

	mBobble->update(deltaTime);

	glm::ivec2 booblePosition = kBobbleOffset;
	booblePosition.y += static_cast<unsigned int>(mMenuOption) * 16.0f;
	mBobble->setPosition(booblePosition);

	if (Game::instance().getKey('z') && currentTime > 500) {
		switch(mMenuOption) {
		case MENU_YES:
			Game::instance().changeScene(SCENE_PLAY);
			break;
		case MENU_NO:
			Game::instance().changeScene(SCENE_MENU);
			break;
		default:
			break;
		}
	}

	mFreezeInput -= deltaTime;

	const int curOption = static_cast<unsigned int>(mMenuOption);
	const int numOptions = static_cast<unsigned int>(NUM_OPTIONS);

	if (mFreezeInput <= 0) {
		if (Game::instance().getSpecialKey(GLUT_KEY_UP)) {
			mMenuOption = static_cast<MenuOption>((curOption + numOptions - 1)%numOptions);
			mFreezeInput = kFreezeInputAmount;
		} else if (Game::instance().getSpecialKey(GLUT_KEY_DOWN)) {
			mMenuOption = static_cast<MenuOption>((curOption + numOptions + 1)%numOptions);
			mFreezeInput = kFreezeInputAmount;
		}
	}
}

void SceneGameOver::render() {
	glm::mat4 viewmatrix;
	glm::mat4 modelview;

	texProgram.use();
	texProgram.setUniformMatrix4f("projection", projection);
	texProgram.setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);

	viewmatrix = glm::mat4(1.0f);
	viewmatrix = glm::scale(viewmatrix, glm::vec3(2.0f, 2.0f, 2.0f));
	texProgram.setUniformMatrix4f("VM", viewmatrix);
	
	modelview = glm::mat4(1.0f);
	texProgram.setUniformMatrix4f("modelview", modelview);
	texProgram.setUniform2f("texCoordDispl", 0.f, 0.f);

	mBackground->render();
	
	mBobble->render();

}