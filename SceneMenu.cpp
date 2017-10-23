#include "SceneMenu.h"
#include "Game.h"

SceneMenu::SceneMenu() {}

SceneMenu::~SceneMenu() {
	if (mBackground != nullptr)
		delete mBackground;
}


void SceneMenu::init() {
	initShaders();
	projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
	currentTime = 0.0f;

	mTexBackground.loadFromFile("images/bg1.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mBackground = Sprite::createSprite(glm::ivec2(240, 320), glm::vec2(1, 1), &mTexBackground, &texProgram);
	mBackground->setNumberAnimations(1);
		mBackground->setAnimationSpeed(0, 0);
		mBackground->addKeyframe(0, glm::vec2(0, 0));
	mBackground->changeAnimation(0);
}

void SceneMenu::update(int deltaTime) {
	currentTime += deltaTime;

	if (Game::instance().getKey('z')) {
		Game::instance().changeScene(SCENE_PLAY);
	}
}

void SceneMenu::render() {
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
}