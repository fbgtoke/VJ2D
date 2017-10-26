#include "Text.h"

const float Text::kFontSize =   8.0f;
const float Text::kCharNum  = 128.0f;

Text::Text(ShaderProgram& program, Texture& font)
	: mTexProgram(program), mTexFont(font), mString("") {}

Text::~Text() {
	if (mSprite != nullptr)
		delete mSprite;
}

void Text::init() {
	const float sizeInSpritesheet = 1.0f / kCharNum;

	mSprite = Sprite::createSprite(
		glm::ivec2(kFontSize, kFontSize),
		glm::vec2(sizeInSpritesheet, 1),
		&mTexFont,
		&mTexProgram
	);

	mSprite->setNumberAnimations(kCharNum);
	for (int i = 0; i < kCharNum; ++i) {
		mSprite->setAnimationSpeed(i, 0);
		mSprite->addKeyframe(i, glm::vec2(sizeInSpritesheet * i, 0));
	}

	mSprite->setPosition(glm::vec2(3000.0f, 3000.0f));
}

void Text::setPosition(const glm::vec2& position) {
	mPosition = position;	
}

void Text::setString(const std::string& string) {
	mString = string;
}

void Text::update(int deltaTime) {
	if (mSprite != nullptr)
		mSprite->update(deltaTime);
}

void Text::render() {
	glm::vec2 spritePosition;

	for (unsigned int i = 0; i < mString.size(); ++i) {
		spritePosition = mPosition;
		spritePosition.x += i * kFontSize;

		int animationIndex = static_cast<int>(mString[i]);

		if (mSprite != nullptr) {
			mSprite->changeAnimation(animationIndex);
			mSprite->setPosition(spritePosition);
			mSprite->render();
		}
	}
}