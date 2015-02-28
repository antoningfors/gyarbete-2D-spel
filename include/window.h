#ifndef WINDOW_H
#define WINDOW_H
 
#define WINDOWS
#ifdef WINDOWS
	#include <sdl_windows/SDL.h>
#endif

#ifdef OSX
	#include <SDL2/SDL.H>
#endif

#include <iostream>
#include <string>

class Window {
	public:
		Window(std::string title, int posY, int posX, 
				int width, int height);

		// no position specified will apppear at center of the screen 
		Window(std::string title, int width, int height);
		~Window();

		void beginScene();
		void endScene();

		void drawTexture(SDL_Texture* texture, 
				SDL_Rect* srcRect, SDL_Rect* dstRect);
		void setBackgroundColor(int r, int b, int g);

		SDL_Texture* loadTexture(std::string filenmane);

	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
};
#endif
