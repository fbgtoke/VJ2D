#include "Scene.h"
#include "SceneMenu.h"
#include "ScenePlay.h"
#include "SceneGameOver.h"
#include "SceneWin.h"

#include "Game.h"

Scene::~Scene() {
	for (Particle* particle : mParticles)
		if (particle != nullptr) {
			delete particle;
			particle = nullptr;
		}

	mParticles.clear();
}

Scene* Scene::create(SceneType type) {
	switch(type) {
	case SCENE_MENU:
		return new SceneMenu();
	case SCENE_PLAY:
		return new ScenePlay();
	case SCENE_GAME_OVER:
		return new SceneGameOver();
	case SCENE_WON:
		return new SceneWin();
	default:
		return nullptr;
	}
}

void Scene::init() {
	initShaders();
	projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
	currentTime = 0.0f;
}

void Scene::update(int deltaTime) {
	currentTime += deltaTime;
	
	std::list<Particle*>::iterator it = mParticles.begin();

	Particle* particle;
	while (it != mParticles.end()) {
		particle = (*it);

		if (particle != nullptr)
			particle->update(deltaTime);

		if (particle == nullptr || outOfBounds(particle->getPosition())) {
			delete particle;
			particle = nullptr;

			mParticles.erase(it++);
		} else {
			++it;
		}
	}
}

void Scene::render() {
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

void Scene::addParticle(Particle* particle) {
	if (particle != nullptr)
		mParticles.push_back(particle);
}

bool Scene::outOfBounds(const glm::vec2& position) {
	return
		position.x < -300.0f || position.x > 240 + 300 ||
		position.y < -300.0f || position.y > 320 + 300;
}