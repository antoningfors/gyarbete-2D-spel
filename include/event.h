
#define WINDOWS
#ifdef WINDOWS
	#include <sdl_windows/sdl.h>
#endif

#ifdef OSX
	#include <SDL2/SDL.H>
#endif

class Event {
	char read();
}
