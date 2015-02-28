#include <log.h>

bool Log::isDebugMode = false;
bool Log::isVerboseMode = false;

void Log::log(std::string msg)
{
	std::cout << msg << std::endl;
}

void Log::error(std::string msg)
{
	std::cerr << "Error: " << msg << std::endl;
}

void Log::warning(std::string msg)
{
	std::cout << "Warning: " << msg << std::endl;
}

void Log::debug(std::string msg)
{
	if(isDebugMode){
		std::cout << "Debug: " << msg << std::endl;
	}
}

void Log::verbose(std::string msg)
{
	if(isVerboseMode){
		std::cout << "Verbose: " << msg << std::endl;
	}
}
