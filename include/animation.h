#ifndef ANIMATION_H
#define ANIMATION_H

#define WINDOWS
#ifdef WINDOWS
	#include <sdl_windows/sdl.h>
#endif

#ifdef OSX
	#include <SDL2/SDL.H>
#endif

#include <sprite.h>

enum AnimationLoops{
	ANIMATION_LOOP_RIGHT = 0,
	ANIMATION_LOOP_LEFT
};


class Animation{
	public:
	Animation(Sprite* sprite, int frames, int framerate, 
			int frameWidth, int frameHeight, 
			int startRow, int StartCol, int loopType);
	~Animation();

	// update frame if framerate time has passed
	void update();
	// update sprite and draw sprite to screen
	void draw(int posX, int posY);

	// set current frame to first frame and reset timer
	void reset();

 	void firstFrame();

 	void nextFrame();

	private:
	Sprite* sprite;
	int totalFrames;
	int frameWidth;
	int frameHeight;
	int startCol;
	int startRow;
	int currentFrame;
	int framerate;
	int loopType;
	Uint32 lastTime;
};
#endif
