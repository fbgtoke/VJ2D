#ifndef _SCENE_FINAL_INCLUDE
#define _SCENE_FINAL_INCLUDE

#include "Scene.h"

class SceneFinal : public Scene {
public:
	SceneFinal();
	~SceneFinal() final;

	void init() final;
	void update(int deltaTime) final;
	void render() final;

private:
	bool mMusicInit;

	Texture mTexFrame;
	Sprite* mSpriteFrame;

	Texture mTex;
	Sprite* mSprite;

	glm::vec2 mPosition;
};


#endif // _SCENE_FINAL_INCLUDE