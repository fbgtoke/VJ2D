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

Scene::Scene() {
}

Scene::~Scene() {
}


void Scene::init() {
	initShaders();
	projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
	currentTime = 0.0f;

	mTexBalls.loadFromFile("images/bubbles.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mTexBackground.loadFromFile("images/bg0.png", TEXTURE_PIXEL_FORMAT_RGBA);
	mTexArrow.loadFromFile("images/arrow.png", TEXTURE_PIXEL_FORMAT_RGBA);

	mBackground = Sprite::createSprite(glm::ivec2(240, 320), glm::vec2(1, 1), &mTexBackground, &texProgram);
	mBackground->setNumberAnimations(1);
		mBackground->setAnimationSpeed(0, 0);
		mBackground->addKeyframe(0, glm::vec2(0, 0));
	mBackground->changeAnimation(0);

	mBubbles = std::vector<std::vector<Sprite*>> (kNumBubblesY, std::vector<Sprite*>(kNumBubblesX, nullptr));

	float frame;
	const glm::vec2 ballsOffset = glm::vec2(32, 36);
	const float sizeInSpritesheet = 16.0f / (8.0f * 16.0f);

	for (int i = 0; i < kNumBubblesY; ++i) {
		for (int j = 0; j < kNumBubblesX; ++j) {
			if (i%2 == 0 || j < kNumBubblesX - 1) {
				frame = sizeInSpritesheet * (rand() % 7);

				mBubbles[i][j] = Sprite::createSprite(glm::ivec2(16, 16), glm::vec2(sizeInSpritesheet, 1), &mTexBalls, &texProgram);
				mBubbles[i][j]->setNumberAnimations(1);
					mBubbles[i][j]->setAnimationSpeed(0, 0);
					mBubbles[i][j]->addKeyframe(0, glm::vec2(frame, 0));
				mBubbles[i][j]->changeAnimation(0);

				if (i % 2 == 0) {
					mBubbles[i][j]->setPosition(glm::vec2(j * 16, i * 16) + ballsOffset);
				} else {
					mBubbles[i][j]->setPosition(glm::vec2(j * 16 + 8, i * 16) + ballsOffset);
				}
			}
		}
	}

	mArrow = Sprite::createSprite(glm::ivec2(64, 64), glm::vec2(64.0f/8256.0f, 1), &mTexArrow, &texProgram);
	mArrow->setNumberAnimations(1);
		mArrow->setAnimationSpeed(0, 30);
		for (int i = 0; i < 129; ++i)
			mArrow->addKeyframe(0, glm::vec2(64.0f/8256.0f * i, 0));
	mArrow->changeAnimation(0);
	mArrow->setPosition(glm::vec2(88, 243));
}

void Scene::update(int deltaTime) {
	currentTime += deltaTime;

	for (int i = 0; i < kNumBubblesY; ++i) {
		for (int j = 0; j < kNumBubblesX; ++j) {
			if (i%2 == 0 || j < kNumBubblesX - 1) {
				mBubbles[i][j]->update(deltaTime);
			}
		}
	}

	mArrow->update(deltaTime);
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

	for (int i = 0; i < kNumBubblesY; ++i) {
		for (int j = 0; j < kNumBubblesX; ++j) {
			if (i%2 == 0 || j < kNumBubblesX - 1) {
				mBubbles[i][j]->render();
			}
		}
	}

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



