#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <map>
#include <sdl.h>

class InputManager{
	public:
		static void update();
		static bool isKeyDown(int key);
	private:
		static std::map<int, bool> keyboard; 
};
#endif
