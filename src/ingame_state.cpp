#include <ingame_state.h>

StateInGame::StateInGame(Window &window):
	window(window)
{
	this->window = window;	
	bob = new Character(&window, 0, 100, 100);
}

StateInGame::~StateInGame()
{
	delete this->bob;	
}

StateStatus StateInGame::update(int dt)
{
	StateStatus status;
	status = processInput();
	bob->update(dt);
	return status;
}

StateStatus StateInGame::processInput()
{
	InputManager::update();
	if (InputManager::isKeyDown(SDLK_ESCAPE)){
		return QUIT;		
		//running = false;
	}
	else if (InputManager::isKeyDown(SDLK_a)){
		bob->runLeft();
	}
	else if (InputManager::isKeyDown(SDLK_d)){
		bob->runRight();
	}
	else if (InputManager::isKeyDown(SDLK_w)){
		bob->jump();
	}
	else{
		bob->stopRunning();
	}
	return CONTINUE;
}

void StateInGame::render(){
	window.beginScene();
		bob->draw();
	window.endScene();
}
