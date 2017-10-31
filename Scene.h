#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GL/glew.h>
#include <GL/glut.h>

#include <iostream>
#include <list>
#include <cmath>

#include "ShaderProgram.h"
#include "Texture.h"
#include "Sprite.h"
#include "Particle.h"

class Scene {
public:
	Scene() {};
	virtual ~Scene();

	virtual void init();
	virtual void update(int deltaTime);
	virtual void render();

	virtual void receiveInteger(int integer) {};
	virtual void receiveString(const std::string& string) {};

	enum SceneType {
		SCENE_MENU,
		SCENE_PLAY,
		SCENE_HELP,
		SCENE_CREDITS,
		SCENE_WON,
		SCENE_GAME_OVER,
		SCENE_FINAL
	};
	static Scene* create(SceneType type);

	void initShaders();
	void setBackground(const std::string& filename);

	void lockInput(bool lock);
	bool isInputLocked() const;

	void addParticle(Particle* particle);

	static bool outOfBounds(const glm::vec2& position);

protected:
	ShaderProgram mTexProgram;
	float currentTime;
	glm::mat4 projection;

	// Background
	Texture mTexBackground;
	Sprite* mBackground;

	// Input
	bool mLockInput;	

	std::list<Particle*> mParticles;
};

#endif // _SCENE_INCLUDE