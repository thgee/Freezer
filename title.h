#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "sdl.h"
#include "display.h"


int keyinputTitle() {
	
	SDL_Event event;
	while (1) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_SPACE) {
					return 1;
					break;
				}
			}
		}
	}
}

void title() {
	// Ÿ��Ʋ ȭ��
	SDL_RenderClear(renderer);
	drawTexture(title_img, 0, 0);
	SDL_RenderPresent(renderer);

	if (keyinputTitle() == 1) {
		title_img = loadTexture("./assets/giudeScreen1.jpg");
		SDL_RenderClear(renderer);
		drawTexture(title_img, 0, 0);
		SDL_RenderPresent(renderer);
	}

	if (keyinputTitle() == 1) {
		title_img = loadTexture("./assets/giudeScreen2.jpg");
		SDL_RenderClear(renderer);
		drawTexture(title_img, 0, 0);
		SDL_RenderPresent(renderer);
	}

	if (keyinputTitle() == 1) {
		title_img = loadTexture("./assets/giudeScreen3.jpg");
		SDL_RenderClear(renderer);
		drawTexture(title_img, 0, 0);
		SDL_RenderPresent(renderer);
	}

	if (keyinputTitle() == 1) {
		title_img = loadTexture("./assets/giudeScreen4.jpg");
		SDL_RenderClear(renderer);
		drawTexture(title_img, 0, 0);
		SDL_RenderPresent(renderer);
	}

	if (keyinputTitle() == 1) {
		return;
	}
}
