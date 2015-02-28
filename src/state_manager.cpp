#include <state_manager.h>
StateManager::StateManager()
{
	window = new Window (WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
	// Starting state
	curState = new StateInGame(*window);
}

StateManager::~StateManager()
{
}

void StateManager::run()
{
	bool running = true;
	while (running)
	{
		// temporary before we have a timer
		currentTime = SDL_GetTicks();
		deltaTime = currentTime - lastTime; 
		lastTime = currentTime;

		StateStatus status = curState->update(deltaTime);
		/* Perform different actions depending on the return value
		 * from the current state */
		switch(status){ 
			case CONTINUE: // Continue as usual
				curState->render();
				break;
			case QUIT: // Quit everything
				running = false;
				delete curState;
				break;
			case MAIN_MENU:	// switch current state to main menu
				delete curState;
				//curState = new StateMenu; not yet implemented
				break;
			case IN_GAME:	// switch current state to in game
				delete curState;
				curState = new StateInGame(*window);
				break;
			default:
				break;
		}
	}
}
