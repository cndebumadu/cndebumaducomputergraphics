#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("New Window", 800, 800, 0); //Now window parameters in bracket
	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

	SDL_Surface* surface = IMG_Load("C:/Users/Ndebu/OneDrive/Bilder");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_DestroySurface(surface);
	SDL_FRect  imgrect = { 300, 50, 200, 200 };

	SDL_Surface* surface1 = IMG_Load("C:/Users/Ndebu/OneDrive/Bilder");
	SDL_Texture* texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
	SDL_DestroySurface(surface1);
	SDL_FRect  imgrect1 = { 50, 300, 200, 200 };

	SDL_Surface* surface2 = IMG_Load("C:/Users/Ndebu/OneDrive/Bilder");
	SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
	SDL_DestroySurface(surface2);
	SDL_FRect  imgrect2 = { 550, 300, 200, 200 };

	SDL_Surface* surface3 = IMG_Load("C:/Users/Ndebu/OneDrive/Bilder");
	SDL_Texture* texture3 = SDL_CreateTextureFromSurface(renderer, surface3);
	SDL_DestroySurface(surface3);
	SDL_FRect  imgrect3 = { 300, 550, 200, 200 };

	/*
	SDL_SetRenderDrawColor(renderer, 120, 100, 190, 200);
	SDL_RenderClear(renderer);

	SDL_FPoint points[] = {

		{400,300}, {400,301},{400,302}, {400,303}
	};

	SDL_SetRenderDrawColor(renderer, 255, 100, 190, 200);
	SDL_RenderPoints(renderer, points, 3);


	SDL_FPoint lines[] = {

		{0,300}, {800,300}, {400,0}, {400,600}
	};
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderLines(renderer, lines, 3);


	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_FRect outline = { 100,100,150,150};
	SDL_RenderRect(renderer, &outline);
	SDL_RenderPresent(renderer);

	// To let the user close window when x is pressed create a new event
	SDL_Event event;
	*/


	SDL_Event e;

	bool running = true;

	while (running) {

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT)
				running = false;
		}

		SDL_RenderClear(renderer);
		SDL_RenderTexture(renderer, texture, NULL, &imgrect);
		SDL_RenderTexture(renderer, texture1, NULL, &imgrect1);
		SDL_RenderTexture(renderer, texture2, NULL, &imgrect2);
		SDL_RenderTexture(renderer, texture3, NULL, &imgrect3);
		SDL_RenderPresent(renderer);

	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}




//#include <SDL3/SDL.h>
//#include <SDL3/SDL_main.h>
////#define SDL_MAIN_HANDLED
//
//
//int main(int argc, char* argv[]) {
//	SDL_Init(SDL_INIT_VIDEO);
//
//	SDL_Window* window = SDL_CreateWindow("Connected Lines", 800, 600, 0);
//	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
//
//	float rectx = 0.0f;
//	float recty = 250.0f;
//	float speed = 200.0f;
//
//	Uint64 lastTime = SDL_GetTicks();
//
//
//	bool running = true;
//	SDL_Event e;
//
//	while (running) {
//		Uint64 currentTime = SDL_GetTicks();
//		float deltaTime = (currentTime - lastTime) / 1000.0f;
//		lastTime = currentTime;
//
//		while (SDL_PollEvent(&e)) {
//			if (e.type == SDL_EVENT_QUIT) running = false;
//		}
//
//		rectx += speed * deltaTime;
//		if (rectx > 800) {
//			rectx = 0;
//		}
//
//		SDL_FRect rect = { rectx, recty, 100, 200 };
//
//		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//		SDL_RenderClear(renderer);
//
//		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
//		SDL_RenderFillRect(renderer, &rect);
//
//		SDL_RenderPresent(renderer);
//
//	}
//
//
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(window);
//	SDL_Quit();
//	return 0;
//}