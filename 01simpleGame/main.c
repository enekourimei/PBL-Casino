#include "main.h"

SDL_Window *win;
SDL_Renderer *renderer;

int main(int argc, char *argv[])
{

    quit = 0;
    win = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                           SDL_WINDOW_FULLSCREEN_DESKTOP);

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    initialize(win, renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Event event;
    while (!quit)
    {

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }
    cleanup(win, renderer);

    return 0;
}