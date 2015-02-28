char Event::read()
{
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		if (event.type == SDL_KEYDOWN){
			event.key.keysym
		}
	}
}
