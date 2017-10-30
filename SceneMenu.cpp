#include "SceneMenu.h"
#include "Game.h"

const glm::ivec2 SceneMenu::kBobbleOffset = glm::ivec2(64, 176);

SceneMenu::SceneMenu() {}

SceneMenu::~SceneMenu() {
	if (mBobble != nullptr)
		delete mBobble;
}

void SceneMenu::init() {
	Scene::init();

	setBackground("images/menuprincipal.png");
	mTexBobble.loadFromFile("images/bobblemenu.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mBobble = new SpriteBobble(&mTexBobble, &mTexProgram);
	mBobble->setPosition(kBobbleOffset);

	mMenuOption = MENU_PLAY;

	Game::instance().changeBackgroundMusic("music/menu.ogg");
	Game::instance().getBackgroundMusic().setLoop(true);
	Game::instance().getBackgroundMusic().setVolume(75);
}

void SceneMenu::update(int deltaTime) {
	Scene::update(deltaTime);

	mBobble->update(deltaTime);

	glm::ivec2 booblePosition = kBobbleOffset;
	booblePosition.y += static_cast<unsigned int>(mMenuOption) * 16.0f;
	mBobble->setPosition(booblePosition);

	if (Game::instance().getKeyPressed('z')) {
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

void SceneMenu::render() {
	Scene::render();
	mBobble->render();
}