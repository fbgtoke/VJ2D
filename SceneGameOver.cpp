#include "SceneGameOver.h"
#include "Game.h"

const glm::ivec2 SceneGameOver::kBobbleOffset = glm::ivec2(80, 192);

SceneGameOver::SceneGameOver() {}

SceneGameOver::~SceneGameOver() {
	if (mBackground != nullptr)
		delete mBackground;
	if (mBobble != nullptr)
		delete mBobble;
}

void SceneGameOver::init() {
	Scene::init();

	mTexBackground.loadFromFile("images/youlost.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mTexBobble.loadFromFile("images/bobblemenu.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mBackground = Sprite::createSprite(glm::ivec2(240, 320), glm::vec2(1, 1), &mTexBackground, &mTexProgram);
	mBackground->setNumberAnimations(1);
		mBackground->setAnimationSpeed(0, 0);
		mBackground->addKeyframe(0, glm::vec2(0, 0));
	mBackground->changeAnimation(0);

	mBobble = Sprite::createSprite(glm::ivec2(16, 32), glm::vec2(0.25f, 1.0f), &mTexBobble, &mTexProgram);
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
}

void SceneGameOver::update(int deltaTime) {
	Scene::update(deltaTime);

	mBobble->update(deltaTime);

	glm::ivec2 booblePosition = kBobbleOffset;
	booblePosition.y += static_cast<unsigned int>(mMenuOption) * 16.0f;
	mBobble->setPosition(booblePosition);

	if (Game::instance().getKeyPressed('z')) {
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

	const int curOption = static_cast<unsigned int>(mMenuOption);
	const int numOptions = static_cast<unsigned int>(NUM_OPTIONS);

	if (Game::instance().getSpecialKeyPressed(GLUT_KEY_UP)) {
		mMenuOption = static_cast<MenuOption>((curOption + numOptions - 1)%numOptions);

	} else if (Game::instance().getSpecialKeyPressed(GLUT_KEY_DOWN)) {
		mMenuOption = static_cast<MenuOption>((curOption + numOptions + 1)%numOptions);

	}
}

void SceneGameOver::render() {
	Scene::render();

	mBackground->render();
	mBobble->render();
}