#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL.h>

int main() {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "Failed to initialize SDL2!\n" << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("GPU-Bugger", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (!window) {
		std::cerr << "Cannot create a window!\n" << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		std::cerr << "cannot create a renderer!\n" << SDL_GetError() << std::endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	int w_w = 800, w_h = 600, x = 0, y = 0;
	SDL_Event event;
	bool loop = true;
	while (loop) {
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
		SDL_RenderClear(renderer);

		for (y = 1; y <= w_h; y++) {
			for (x = 1; x <= w_w; x++) {
				SDL_SetRenderDrawColor(renderer, rand() % 256, rand() % 256, rand() % 256, 0x00);
				SDL_RenderDrawPoint(renderer, x, y);
			}
		}

		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				loop = false;
			} else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) {
				w_w = event.window.data1, w_h = event.window.data2;
			}
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}
