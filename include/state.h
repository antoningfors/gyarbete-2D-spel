#ifndef STATE_H
#define STATE_H

enum StateStatus{
	CONTINUE = 0, 	// Continue as usual and draw next frame
	QUIT, 			// Quit everything	
	MAIN_MENU,		// Switch state to main menu
	IN_GAME,		// Switch state to in game
};

/* Each state should have at lease these member functions 
 *
 * Update: should update the internal data depending on delta time and 
 * return a StateStatus to the StateManager.
 *
 * Render: Should draw to the current frame.
 */

class State{
public:
	virtual ~State(){}
	virtual StateStatus update(int dt) = 0;
	virtual void render() = 0;
private:
};

#endif
