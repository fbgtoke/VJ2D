#ifndef _TEXT_INCLUDE
#define _TEXT_INCLUDE

#include <glm/glm.hpp>
#include <iostream>

#include "ShaderProgram.h"
#include "Texture.h"
#include "Sprite.h"

class Text {
public:
	Text(ShaderProgram& program, Texture& font);
	Text(ShaderProgram& program, Texture& font, const std::string& string);
	~Text();

	void setPosition(const glm::vec2& position);
	void setString(const std::string& string);

	void update(int deltaTime);
	void render();

private:
	static const float kFontSize;
	static const float kCharNum;

	ShaderProgram& mTexProgram;
	Texture& mTexFont;

	Sprite* mSprite;
	Sprite* mCharacters[128];
	void initSprite();

	glm::vec2 mPosition;
	std::string mString;
};

#endif // _TEXT_INCLUDE