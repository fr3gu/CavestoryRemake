#include <SDL.h>
#include <algorithm>

#include "game.h"
#include "input.h"

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;
	
	this->_player = Sprite(graphics, "MyChar.png", 0, 0, 16, 16, 100, 100);

	int lastUpdateTime = SDL_GetTicks();

	//--[ Main loop ] ----------------------------------------------------
	while (true) {
		input.beginNewFrame();
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT) { 
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) return;

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int elapsedTime = CURRENT_TIME_MS - lastUpdateTime;
		this->update((float)std::min(elapsedTime, MAX_FRAME_TIME));

		lastUpdateTime = CURRENT_TIME_MS;

		this->draw(graphics);

	}
	//--[ /Main loop ] ---------------------------------------------------

}

void Game::draw(Graphics & graphics) {
	graphics.clear();
	this->_player.draw(graphics, 150, 150);
	graphics.flip();
}

void Game::update(float elapsedTime) {
	
}
