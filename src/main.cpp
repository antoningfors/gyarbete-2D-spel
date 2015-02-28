#include <state_manager.h>

int main(int argc, char* argv[])
{
	SDL::init();
		StateManager stateManger;
		stateManger.run();	
	SDL::quit();
}
