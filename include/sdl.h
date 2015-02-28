#define WINDOWS
#ifdef WINDOWS
	#include <sdl_windows/SDL.h>
#endif

#ifdef OSX
	#include <sdl_osx/SDL.h>
#endif

namespace SDL 
{
	bool init();
	bool quit();
}
