#include "Text.h"

const float Text::kFontSize =   8.0f;
const float Text::kCharNum  = 128.0f;

Text::Text(ShaderProgram& program, Texture& font)
	: mTexProgram(program), mTexFont(font), mString("") {

	initSprite();
}

Text::Text(ShaderProgram& program, Texture& font, const std::string& string)
	: mTexProgram(program), mTexFont(font), mString(string) {

	initSprite();
}

Text::~Text() {
	for (int i = 0; i < kCharNum; ++i) {
		if (mCharacters[i] != nullptr)
			delete mCharacters[i];
	}
}

void Text::setPosition(const glm::vec2& position) {
	mPosition = position;	
}

void Text::setString(const std::string& string) {
	mString = string;
}

void Text::update(int deltaTime) {
	for (int i = 0; i < kCharNum; ++i) {
		if (mCharacters[i] != nullptr)
			mCharacters[i]->update(deltaTime);
	}
}

void Text::render() {
	glm::vec2 spritePosition;

	for (unsigned int i = 0; i < mString.size(); ++i) {
		spritePosition = mPosition;
		spritePosition.x += i * kFontSize;

		int animationIndex = static_cast<int>(mString[i]);

		if (mCharacters[animationIndex] != nullptr) { 
			//std::cout << "Rendering " << animationIndex << " at " << spritePosition.x << " " << spritePosition.y << std::endl;
			mCharacters[animationIndex]->setPosition(spritePosition);
			mCharacters[animationIndex]->render();
		}
	}
}

void Text::initSprite() {
	const float sizeInSpritesheet = 1.0f / kCharNum;

	for (int i = 0; i < kCharNum; ++i) {
		mCharacters[i] = Sprite::createSprite(
			glm::ivec2(kFontSize, kFontSize),
			glm::vec2(sizeInSpritesheet, 1),
			&mTexFont,
			&mTexProgram
		);

		mCharacters[i]->setNumberAnimations(1);
		mCharacters[i]->setAnimationSpeed(0, 0);
		mCharacters[i]->addKeyframe(0, glm::vec2(sizeInSpritesheet * i, 0));
		mCharacters[i]->setPosition(glm::vec2(3000.0f, 3000.0f));
	}
}