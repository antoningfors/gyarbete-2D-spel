#include <input_manager.h>

std::map<int, bool> InputManager::keyboard; 

void InputManager::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_KEYDOWN:
				keyboard[event.key.keysym.sym] = true;
				break;
			case SDL_KEYUP:
				keyboard[event.key.keysym.sym] = false;
				break;
		}
	}
}

bool InputManager::isKeyDown(int key)
{
	if (InputManager::keyboard[key] == true) 
		return true;
	else 
		return false;
}
