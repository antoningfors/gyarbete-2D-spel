#ifndef SPRITE_H
#define SPRITE_H

#define WINDOWS
#ifdef WINDOWS
	#include <sdl_windows/SDL.h>
#endif

#ifdef OSX
	#include <SDL2/SDL.H>
#endif
#include <string>
#include <window.h>
#include <iostream>

/* This class handles loading and rendering of a image file.
 * 
 * Usage:
 *
 * */

class Sprite{
	public:
		Sprite(Window* window, SDL_Texture* texture);

		Sprite(Window* window, SDL_Texture* texture, 
				int width, int height);

		Sprite(Window* window, SDL_Texture* texture, 
				int width, int height, int xPos, int yPos);

		~Sprite();

		// where on screen to draw
		void draw(SDL_Rect* dstRect); 

		void setX(int x);
		void setY(int y);
		void setW(int w);
		void setH(int h);

	private:

		Window* window;
		SDL_Rect spriteRect;
		SDL_Texture* spriteTexture;
};
#endif
