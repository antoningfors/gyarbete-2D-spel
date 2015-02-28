#include <animation.h>
#include <iostream>

Animation::Animation(Sprite* sprite, int frames, int framerate,
		int frameWidth, int frameHeight, 
		int startRow, int startCol, int loopType)
{
	this->sprite = sprite;
	this->totalFrames = frames;
	this->frameWidth = frameWidth;
	this->frameHeight = frameHeight;
	this->startRow = startRow;
	this->startCol = startCol;
	this->currentFrame = 0;
	this->lastTime = 0;
	this->framerate = framerate;
	this->loopType = loopType;

	this->sprite->setW(frameWidth);
	this->sprite->setH(frameHeight);
	this->sprite->setX(startCol * frameWidth);
	this->sprite->setY(startRow * frameHeight);
}

void Animation::draw(int xPos, int yPos)
{

	SDL_Rect dstRect {xPos, yPos, frameWidth, frameHeight};
	this->sprite->draw(&dstRect);
}

void Animation::update()
{
	//std::cout << "Current Frame: " << this->currentFrame << std::endl;
	Uint32 currentTime = SDL_GetTicks();
	Uint32 deltaTime = currentTime - this->lastTime;
	
	if (deltaTime > this->framerate){   
		this->lastTime = currentTime;

		//Time to update frame
		
		//-1 because first frame = 0
		if (this->currentFrame ==  this->totalFrames-1){
			firstFrame();
		}
		else{
			nextFrame();
		}
	}
}

void Animation::firstFrame()
{
	this->currentFrame = 0;
	this->sprite->setX(frameWidth * startCol);
}

void Animation::nextFrame()
{
	currentFrame++;
	switch(loopType)
	{
		case ANIMATION_LOOP_RIGHT:
			this->sprite->setX(frameWidth*(startCol + (currentFrame)));
			break;
		case ANIMATION_LOOP_LEFT:
			this->sprite->setX(frameWidth*(startCol - (currentFrame)));
			break;
	}
}

Animation::~Animation()
{
}


