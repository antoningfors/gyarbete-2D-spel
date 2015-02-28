#ifndef STATE_INGAME_H
#define STATE_INGAME_H

#include <state.h>
#include <window.h>
#include <character.h>
#include <input_manager.h>
#include <log.h>

class StateInGame: public State{
public:
	StateInGame(Window &window);
	~StateInGame();
	StateStatus	update(int dt);
	void render();
private:
	StateStatus processInput();

	Window &window;
	Character* bob;
};
#endif
