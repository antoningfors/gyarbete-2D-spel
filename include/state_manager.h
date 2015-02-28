#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#define WINDOW_WIDTH 	500
#define WINDOW_HEIGHT 	500
#define WINDOW_TITLE	"TITLE"

#include <sdl.h>
#include <state.h>
#include <ingame_state.h>
//#include <state_menu.h> not yet implemented

class StateManager{
public:
	StateManager();
	~StateManager();
	void run();
private:
	State* curState;
	Window* window;

	// temporary before we have a timer
	int currentTime = 0;
	int lastTime	= 0;
	int deltaTime	= 0;
};
#endif
