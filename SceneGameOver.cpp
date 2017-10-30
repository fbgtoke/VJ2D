#include "SceneGameOver.h"
#include "Game.h"

const glm::ivec2 SceneGameOver::kBobbleOffset = glm::ivec2(80, 192);

SceneGameOver::SceneGameOver()
	: mLevelNumber(0) {}

SceneGameOver::~SceneGameOver() {
	if (mBobble != nullptr)
		delete mBobble;
}

void SceneGameOver::init() {
	Scene::init();

	setBackground("images/youlost.png");
	mTexBobble.loadFromFile("images/bobblemenu.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mBobble = new SpriteBobble(&mTexBobble, &mTexProgram);
	mBobble->setPosition(kBobbleOffset);

	mMenuOption = MENU_YES;

	Game::instance().changeBackgroundMusic("music/game-over.ogg");
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
			Game::instance().getBufferedScene()->receiveInteger(mLevelNumber);
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
		Game::instance().playSoundEffect("sfx/tick.ogg");
	} else if (Game::instance().getSpecialKeyPressed(GLUT_KEY_DOWN)) {
		mMenuOption = static_cast<MenuOption>((curOption + numOptions + 1)%numOptions);
		Game::instance().playSoundEffect("sfx/tick.ogg");

	}
}

void SceneGameOver::render() {
	Scene::render();
	mBobble->render();
}

void SceneGameOver::receiveInteger(int integer) {
	mLevelNumber = integer;
}