#include "SceneWin.h"
#include "Game.h"

const glm::ivec2 SceneWin::kBobbleOffset = glm::ivec2(64, 176);

SceneWin::SceneWin()
	: mLevelNumber(0) {}

SceneWin::~SceneWin() {
	if (mBobble != nullptr)
		delete mBobble;
}

void SceneWin::init() {
	Scene::init();

	setBackground("images/youwon.png");
	mTexBobble.loadFromFile("images/bobblemenu.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mBobble = new SpriteBobble(&mTexBobble, &mTexProgram);
	mBobble->setPosition(kBobbleOffset);

	mMenuOption = MENU_NEXT;
}

void SceneWin::update(int deltaTime) {
	Scene::update(deltaTime);

	mBobble->update(deltaTime);

	glm::ivec2 booblePosition = kBobbleOffset;
	booblePosition.y += static_cast<unsigned int>(mMenuOption) * 16.0f;
	mBobble->setPosition(booblePosition);

	if (Game::instance().getKeyPressed('z')) {
		switch(mMenuOption) {
		case MENU_NEXT:
			Game::instance().changeScene(SCENE_PLAY);
			Game::instance().getBufferedScene()->receiveInteger(mLevelNumber + 1);
			break;
		case MENU_REPEAT:
			Game::instance().changeScene(SCENE_PLAY);
			Game::instance().getBufferedScene()->receiveInteger(mLevelNumber);
			break;
		case MENU_MAIN_MENU:
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

void SceneWin::render() {
	Scene::render();
	mBobble->render();
}

void SceneWin::receiveInteger(int integer) {
	mLevelNumber = integer;
}