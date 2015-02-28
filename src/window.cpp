
#include <window.h>

Window::Window(std::string title, int posX, int posY, 
		int width, int height)
{
	window = SDL_CreateWindow(title.c_str(), posX, posY, 
			width, height, 0);
	if (window == NULL) {/* failed to create window*/}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {/* failed to create renderer*/}

	setBackgroundColor(0x00, 0x00, 0x00);
}

Window::Window(std::string title, int width, int height)
{
	window = SDL_CreateWindow(title.c_str(), 
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			width, height, 0);
	if (window == NULL) {/* failed to create window*/}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {/* failed to create renderer*/}

	setBackgroundColor(0x00, 0x00, 0x00);
}

void Window::setBackgroundColor(int r, int b, int g)
{
	SDL_SetRenderDrawColor(this->renderer, r, b, g, 0xFF);
}

void Window::beginScene()
{
	SDL_RenderClear(renderer);
}

void Window::endScene()
{
	SDL_RenderPresent(renderer);
}

void Window::drawTexture(SDL_Texture* texture, 
		SDL_Rect* srcRect, SDL_Rect* dstRect)
{
	SDL_RenderCopy(renderer, texture, srcRect, dstRect);
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

SDL_Texture* Window::loadTexture(std::string filename)
{
	SDL_Surface* tempSurface;
	// Return NULL on failure
	if ((tempSurface = SDL_LoadBMP(filename.c_str())) == NULL){
		std::cout << "Failed to read bitmap from disk" << std::endl <<
			"File: " << filename.c_str() << std::endl <<
			"SDL Error: " << SDL_GetError() << std::endl;
	}

	// Return 0 on failure
	SDL_Texture* spriteTexture; 
	spriteTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	if (!spriteTexture) return nullptr;

	return spriteTexture;
}
