#include <sprite.h>

//TODO PNG should be supported
//should take a texture instead.
//texture should be freed by window
//Error Handling/Log error messages not much to do on error
Sprite::Sprite(Window* window, SDL_Texture* texture)
{
	spriteRect = {0, 0, 0, 0};
	this->window = window;
	this->spriteTexture = texture;

	//if (!loadTexture(filename)){};
}

Sprite::Sprite(Window* window,  SDL_Texture* texture,
		int width, int height)
{
	spriteRect = {0, 0, width, height};
	this->window = window;
	this->spriteTexture = texture;

	//if (!loadTexture(filename)){};
}

Sprite::Sprite(Window* window, SDL_Texture* texture,
		int width, int height, int xPos, int yPos)
{
	spriteRect = {xPos, yPos, width, height};
	this->window = window;
	this->spriteTexture = texture;

	//if (!loadTexture(filename)){};
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(spriteTexture);
}

void Sprite::draw(SDL_Rect* dstRect)
{
	window->drawTexture(spriteTexture, &spriteRect, dstRect);
}

// TODO check input
void Sprite::setX(int x) {this->spriteRect.x = x;}
void Sprite::setY(int y) {this->spriteRect.y = y;}
void Sprite::setW(int w) {this->spriteRect.w = w;}
void Sprite::setH(int h) {this->spriteRect.h = h;}
