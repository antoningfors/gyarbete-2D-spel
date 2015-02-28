#ifndef CHARACTER_H
#define CHARACTER_H

#define WINDOWS
#ifdef WINDOWS
	#include <sdl_windows/sdl.h>
#endif

#ifdef OSX
	#include <SDL2/SDL.H>
#endif

#include <sprite.h>
#include <animation.h>
#include <window.h>
#include <iostream>

class Character{
	public:
		Character(Window* window, int xPos, int yPos, int speed);
		~Character();

		void update(float deltaTime);
		void draw();

		// Movement
		void runLeft();
		void runRight();
		void stopRunning();

		void jump();
		void stopJump();
		bool isJumping() const;

	private:
		enum Animations{
			STILL_LEFT=1, STILL_RIGHT,
			RUN_LEFT, RUN_RIGHT,
			JUMP_LEFT, JUMP_RIGHT,
			TOTAL_ANIMATIONS
		};

		Sprite* sprite1;
		Sprite* sprite2;
		Sprite* sprite3;
		Sprite* sprite4;
		Sprite* sprite5;
		Sprite* sprite6;

		Animation* animation[TOTAL_ANIMATIONS];
		Animation* curAnimation;

		// Position
		float xPos;
		float yPos;

		int speed;
		int maxSpeed;
		
		int jumpSpeed = 100;
		int maxJumpHeight = 20;
		float curJumpHeight = 0;
		short jumpDirection;

		enum jumpDirection{
			JUMP_DIRECTION_UP = 1,
			JUMP_DIRECTION_DOWN = 2
		};
};
#endif
