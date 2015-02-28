#include <sdl.h>
//TODO check if sdl init and quit correctly

namespace SDL 
{
	bool init()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		return true;
	}

	bool quit()
	{
		SDL_Quit();
		return true;
	}
}
