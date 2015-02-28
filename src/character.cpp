#include <character.h>

#define FRAMERATE 100
#define FRAME_WIDTH 32 
#define FRAME_HEIGHT 32 

Character::Character(Window* window, int xPos, int yPos, int speed)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->maxSpeed 	= speed;

	SDL_Texture* texture = window->loadTexture("../graphics/character.bmp");
	sprite1 = new Sprite(window, texture, 32, 32);
	sprite2 = new Sprite(window, texture, 32, 32);
	sprite3 = new Sprite(window, texture, 32, 32);
	sprite4 = new Sprite(window, texture, 32, 32);
	sprite5 = new Sprite(window, texture, 32, 32);
	sprite6 = new Sprite(window, texture, 32, 32);

	Animation* tmp;
	tmp = new Animation(sprite1, 1, FRAMERATE, FRAME_WIDTH, FRAME_HEIGHT, 
			0, 2, ANIMATION_LOOP_LEFT);
	animation[STILL_LEFT] = tmp;

	tmp = new Animation(sprite2, 1, FRAMERATE, FRAME_WIDTH, FRAME_HEIGHT, 
			0, 3, ANIMATION_LOOP_RIGHT);
	animation[STILL_RIGHT] = tmp;

	tmp = new Animation(sprite3, 3, FRAMERATE, FRAME_WIDTH, FRAME_HEIGHT, 
			1, 2, ANIMATION_LOOP_LEFT);
	animation[RUN_LEFT] = tmp;

	tmp = new Animation(sprite4, 3, FRAMERATE, FRAME_WIDTH, FRAME_HEIGHT, 
			1, 3, ANIMATION_LOOP_RIGHT);
	animation[RUN_RIGHT] = tmp;

	tmp = new Animation(sprite5, 1, FRAMERATE, FRAME_WIDTH, FRAME_HEIGHT, 
			2, 2, ANIMATION_LOOP_LEFT);
	animation[JUMP_LEFT] = tmp;

	tmp = new Animation(sprite6, 1, FRAMERATE, FRAME_WIDTH, FRAME_HEIGHT, 
			2, 3, ANIMATION_LOOP_RIGHT);
	animation[JUMP_RIGHT] = tmp;

	curAnimation = animation[STILL_RIGHT];
}


Character::~Character()
{
}

void Character::jump()
{
	jumpDirection = JUMP_DIRECTION_UP;

	if (curAnimation == animation[RUN_RIGHT]  ||
			curAnimation == animation[STILL_RIGHT]){
		curAnimation = animation[JUMP_RIGHT];
	}
	else if (curAnimation == animation[RUN_LEFT]  ||
			curAnimation == animation[STILL_LEFT]){
		curAnimation = animation[JUMP_LEFT];
	}
}

void Character::stopJump()
{
	jumpDirection = 0;
	if (curAnimation == animation[JUMP_RIGHT]){
		curAnimation = animation[STILL_RIGHT];
	}
	else if (curAnimation == animation[JUMP_LEFT]){
		curAnimation = animation[STILL_LEFT];
	}
}

void Character::runRight()
{
	speed = +maxSpeed;
	curAnimation = animation[RUN_RIGHT];
}

void Character::runLeft()
{
	speed = -maxSpeed;
	curAnimation = animation[RUN_LEFT];
}

void Character::stopRunning()
{
	speed = 0;

	if (curAnimation == animation[RUN_RIGHT]){
		curAnimation = animation[STILL_RIGHT];
	} 
	else if (curAnimation == animation[RUN_LEFT]) 
	{
		curAnimation = animation[STILL_LEFT];
	}
}

void Character::update(float deltaTime)
{
	curAnimation->update();
	deltaTime = deltaTime/1000;

	xPos += speed * deltaTime;

	if (isJumping()){
		if (jumpDirection == JUMP_DIRECTION_UP){
			if (curJumpHeight >= maxJumpHeight){
				jumpDirection = JUMP_DIRECTION_DOWN;
			}
			else{
				// y top = 0 
				curJumpHeight += jumpSpeed * deltaTime;
				yPos 			+= -jumpSpeed * deltaTime;
			}
		}
		else if (jumpDirection == JUMP_DIRECTION_DOWN){
			if (curJumpHeight <= 0){
				if (curAnimation == animation[JUMP_RIGHT]){
					curAnimation = animation[RUN_RIGHT];
				} 
				else if (curAnimation == animation[JUMP_LEFT]) 
				{
					curAnimation = animation[RUN_LEFT];
				}
				stopJump();
			}
			else{
				curJumpHeight -= jumpSpeed * deltaTime;
				yPos += jumpSpeed * deltaTime;
			}
		}
	}
}

bool Character::isJumping() const
{
	if (jumpDirection)
		return true;
	else
		return false;
}


void Character::draw()
{
	curAnimation->draw(xPos, yPos);
}
