#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>

class Log{
	public:
	// turn on/off debug mode default off.
	static void setDebugMode(bool debugMode); 		 	
	// turn on/off verbose mode default off.
	static void setVerboseMode(bool verboseMode);

	// logging functions
	static void log(std::string msg);
	static void error(std::string msg);
	static void warning(std::string msg);
	static void debug(std::string msg);
	static void verbose(std::string msg);

	private:
	static bool isDebugMode;
	static bool isVerboseMode; 
};

#endif
