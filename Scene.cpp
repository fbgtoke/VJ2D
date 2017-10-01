#include <iostream>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include "Scene.h"
#include "Game.h"


#define SCREEN_X 32
#define SCREEN_Y 16

#define INIT_PLAYER_X_TILES 5
#define INIT_PLAYER_Y_TILES 25

const unsigned int Scene::kNumBubblesX = 11;
const unsigned int Scene::kNumBubblesY = 5;

Scene::Scene()
	: mBoard(texProgram)
{
}

Scene::~Scene() {
}


void Scene::init() {
	initShaders();
	projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
	currentTime = 0.0f;

	mTexBackground.loadFromFile("images/bg0.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mTexArrow.loadFromFile("images/arrow.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mBackground = Sprite::createSprite(glm::ivec2(240, 320), glm::vec2(1, 1), &mTexBackground, &texProgram);
	mBackground->setNumberAnimations(1);
		mBackground->setAnimationSpeed(0, 0);
		mBackground->addKeyframe(0, glm::vec2(0, 0));
	mBackground->changeAnimation(0);

	const glm::vec2 boardOffset = glm::vec2(32, 36);
	mBoard.init(boardOffset, kNumBubblesX, kNumBubblesX);
	mBoard.generate();

	mArrow = Sprite::createSprite(glm::ivec2(64, 64), glm::vec2(64.0f/8128.0f, 1), &mTexArrow, &texProgram);
	mArrow->setNumberAnimations(1);
		mArrow->setAnimationSpeed(0, 0);
		for (int i = 0; i < 127; ++i)
			mArrow->addKeyframe(0, glm::vec2(64.0f/8128.0f * i, 0));
	mArrow->changeAnimation(0);
	mArrow->setPosition(glm::vec2(88, 243));
	mArrow->setRepeat(false);
	mArrow->setKeyFrame(0, 65);
}

void Scene::update(int deltaTime) {
	currentTime += deltaTime;

	mBoard.update(deltaTime);
	mArrow->update(deltaTime);

	if (Game::instance().getSpecialKey(GLUT_KEY_LEFT))
		mArrow->setAnimationSpeed(0, 40);
	else if (Game::instance().getSpecialKey(GLUT_KEY_RIGHT))
		mArrow->setAnimationSpeed(0, -40);
	else
		mArrow->setAnimationSpeed(0, 0);
}

void Scene::render() {
	glm::mat4 modelview;

	texProgram.use();
	texProgram.setUniformMatrix4f("projection", projection);
	texProgram.setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);
	
	modelview = glm::mat4(1.0f);
	texProgram.setUniformMatrix4f("modelview", modelview);
	texProgram.setUniform2f("texCoordDispl", 0.f, 0.f);

	mBackground->render();
	mBoard.render();
	mArrow->render();
}

void Scene::initShaders() {
	Shader vShader, fShader;

	vShader.initFromFile(VERTEX_SHADER, "shaders/texture.vert");
	if(!vShader.isCompiled())
	{
		cout << "Vertex Shader Error" << endl;
		cout << "" << vShader.log() << endl << endl;
	}
	fShader.initFromFile(FRAGMENT_SHADER, "shaders/texture.frag");
	if(!fShader.isCompiled())
	{
		cout << "Fragment Shader Error" << endl;
		cout << "" << fShader.log() << endl << endl;
	}
	texProgram.init();
	texProgram.addShader(vShader);
	texProgram.addShader(fShader);
	texProgram.link();
	if(!texProgram.isLinked())
	{
		cout << "Shader Linking Error" << endl;
		cout << "" << texProgram.log() << endl << endl;
	}
	texProgram.bindFragmentOutput("outColor");
	vShader.free();
	fShader.free();
}

