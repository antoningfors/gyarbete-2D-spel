CC 		= g++
CFLAGS 	= -g -Wall -O3 -std=c++11 

OS 		:= $(shell uname -s)
SRC 	= src
BUILD 	= build
INCLUDE = include
OBJDIR = obj
_OBJS = character.o window.o sprite.o animation.o input_manager.o sdl.o log.o ingame_state.o state_manager.o
OBJS = $(patsubst %, $(OBJDIR)/%, $(_OBJS))

ifeq ($(OS),Darwin)

# Directories
PRODIR 	:= $(shell pwd)
FRAMEWORK := framework
LIBRARY := lib/$(OS)

main: sdl.o log.o state_manager.o character.o window.o sprite.o animation.o input_manager.o ingame_state.o
	$(CC) $(CFLAGS) $(OBJS) "$(SRC)/main.cpp" -I $(INCLUDE) -framework SDL2 -o "$(BUILD)/app"

sdl.o: 
	$(CC) $(CFLAGS) -c "$(SRC)/sdl.cpp" -I $(INCLUDE) -o "$(OBJDIR)/sdl.o"

log.o: 
	$(CC) $(CFLAGS) -c "$(SRC)/log.cpp" -I $(INCLUDE) -o "$(OBJDIR)/log.o"

state_manager.o:
	$(CC) $(CFLAGS) -c "$(SRC)/state_manager.cpp" -I $(INCLUDE) -o "$(OBJDIR)/state_manager.o"

ingame_state.o:
	$(CC) $(CFLAGS) -c "$(SRC)/ingame_state.cpp" -I $(INCLUDE) -o "$(OBJDIR)/ingame_state.o"

character.o: 
	$(CC) $(CFLAGS) -c "$(SRC)/character.cpp" -I $(INCLUDE) -o "$(OBJDIR)/character.o"

sprite.o: 
	$(CC) $(CFLAGS) -c "$(SRC)/sprite.cpp" -I $(INCLUDE) -o "$(OBJDIR)/sprite.o"

window.o: 
	$(CC) $(CFLAGS) -c "$(SRC)/window.cpp" -I $(INCLUDE) -o "$(OBJDIR)/window.o"

animation.o: 
	$(CC) $(CFLAGS) -c "$(SRC)/animation.cpp" -I $(INCLUDE) -o "$(OBJDIR)/animation.o"

input_manager.o: 
	$(CC) $(CFLAGS) -c "$(SRC)/input_manager.cpp" -I $(INCLUDE) -o "$(OBJDIR)/input_manager.o"
endif

ifeq ($(OS),Windows)

# Directories
PRODIR 	:= $(shell cd)
SRC 	:= $(PRODIR)\src
BUILD 	:= $(PRODIR)\build
INCLUDE := $(PRODIR)\include
FRAMEWORK := $(PRODIR)\framework
LIBRARY := $(PRODIR)\lib\$(OS)

main: character.o window.o sprite.o animation.o input_manager.o
	$(CC) $(CFLAGS) $(OBJS) "$(SRC)/main.cpp" -I $(INCLUDE) -L $(LIBRARY) -lmingw32 -lSDL2main -lSDL2 -static-libstdc++ -static-libgcc -o "$(BUILD)/app"

character.o: 
	$(CC) $(CFLAGS) -c "$(SRC)/character.cpp" -I $(INCLUDE) -lmingw32 -o "$(OBJDIR)/character.o"

sprite.o: 
	$(CC) $(CFLAGS) -c "$(SRC)/sprite.cpp" -I $(INCLUDE) -lmingw32 -o "$(OBJDIR)/sprite.o"

window.o: 
	$(CC) $(CFLAGS) -c "$(SRC)/window.cpp" -I $(INCLUDE) -L $(OBJDIR) -lmingw32 -lSDL2main -lSDL2 -o "$(OBJDIR)/window.o"

animation.o: 
	$(CC) $(CFLAGS) -c "$(SRC)/animation.cpp" -I $(INCLUDE) -lmingw32 -o "$(OBJDIR)/animation.o"

log.o: 
	$(CC) $(CFLAGS) -c "$(SRC)/log.cpp" -I $(INCLUDE) -lmingw32 -o "$(OBJDIR)/log.o"

input_manager.o: 
	$(CC) $(CFLAGS) -c "$(SRC)/input_manager.cpp" -I $(INCLUDE) -lmingw32 -o "$(OBJDIR)/input_manager.o"
endif

