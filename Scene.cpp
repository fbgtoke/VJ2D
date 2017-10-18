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
	: mBoard(texProgram), mCannon(texProgram), mMovingBubble(texProgram, BUBBLE_RED, mBoard) {}

Scene::~Scene() {
	if (mBackground != nullptr)
		delete mBackground;
}


void Scene::init() {
	initShaders();
	projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
	currentTime = 0.0f;

	mTexBackground.loadFromFile("images/bg0.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mBackground = Sprite::createSprite(glm::ivec2(240, 320), glm::vec2(1, 1), &mTexBackground, &texProgram);
	mBackground->setNumberAnimations(1);
		mBackground->setAnimationSpeed(0, 0);
		mBackground->addKeyframe(0, glm::vec2(0, 0));
	mBackground->changeAnimation(0);

	const glm::vec2 boardOffset = glm::vec2(32, 36);
	mBoard.init(boardOffset, kNumBubblesX, kNumBubblesX);
	mBoard.generate();

	mCannon.init();

	mMovingBubble.init();
	mMovingBubble.setPosition(glm::vec2(112, 264));
	mMovingBubble.setVelocity(glm::vec2(0, 0));
}

void Scene::update(int deltaTime) {
	currentTime += deltaTime;

	if (Game::instance().getKey('x')) {
		mMovingBubble.setPosition(glm::vec2(112, 264));
		mMovingBubble.setVelocity(glm::vec2(0, 0));
		mMovingBubble.setBubbleState(MovingBubble::BUBBLE_STOPPED);
	}


	if (Game::instance().getKey('z')) {
		const float minAngle = 2.5f;
		const float alpha = M_PI / 128;
		float angle = alpha * (mCannon.getCurrentFrame() + 1);
		std::cout << "frame " << mCannon.getCurrentFrame() << std::endl;
		std::cout << "angle " << angle << std::endl;

		glm::vec2 ballVel;
		ballVel.x = cos(angle);
		ballVel.y = (-1) * sin(angle);
		glm::normalize(ballVel);
		ballVel *= 0.3;
		std::cout << "vel " << ballVel.x << " " << ballVel.y << std::endl;

		mMovingBubble.setVelocity(ballVel);
		mMovingBubble.setBubbleState(MovingBubble::BUBBLE_MOVING);
	}

	mBoard.update(deltaTime);
	mCannon.update(deltaTime);
	mMovingBubble.update(deltaTime);

	if (MovingBubble::BUBBLE_DEAD == mMovingBubble.getBubbleState()) {
		mMovingBubble.setPosition(glm::vec2(112, 264));
		mMovingBubble.setVelocity(glm::vec2(0, 0));
		mMovingBubble.setBubbleState(MovingBubble::BUBBLE_STOPPED);

		std::cout << "It happened" << std::endl;
	}
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
	mCannon.render();
	mMovingBubble.render();
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

