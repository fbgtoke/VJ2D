#include "SceneMenu.h"
#include "Game.h"

const glm::ivec2 SceneMenu::kBobbleOffset = glm::ivec2(64, 176);

const int SceneMenu::kFreezeInputAmount = 300;

SceneMenu::SceneMenu() {}

SceneMenu::~SceneMenu() {
	if (mBackground != nullptr)
		delete mBackground;
	if (mBobble != nullptr)
		delete mBobble;
}

void SceneMenu::init() {
	Scene::init();

	mTexBackground.loadFromFile("images/menuprincipal.png", TEXTURE_PIXEL_FORMAT_RGBA);
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

	mMenuOption = MENU_PLAY;
	mFreezeInput = 0;
}

void SceneMenu::update(int deltaTime) {
	Scene::update(deltaTime);

	mBobble->update(deltaTime);

	glm::ivec2 booblePosition = kBobbleOffset;
	booblePosition.y += static_cast<unsigned int>(mMenuOption) * 16.0f;
	mBobble->setPosition(booblePosition);

	if (Game::instance().getKey('z') && currentTime > 300) {
		switch(mMenuOption) {
		case MENU_PLAY:
			Game::instance().changeScene(SCENE_PLAY);
			break;
		case MENU_HELP:
			Game::instance().changeScene(SCENE_HELP);
			break;
		case MENU_CREDITS:
			Game::instance().changeScene(SCENE_CREDITS);
			break;
		case MENU_CLOSE:
			Game::instance().stop();
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

void SceneMenu::render() {
	Scene::render();
	
	mBackground->render();
	mBobble->render();
}