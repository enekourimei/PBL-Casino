#include "main.h"
#include <SDL_image.h>

SDL_Window *win = NULL;
SDL_Renderer *renderer = NULL;

bool quit = false;
enum {MENU, HELP, CONFIG, GAME} state = MENU;
int egoera = 0;

void renderMenu(SDL_Window *win, SDL_Renderer *renderer);
void processEvents(SDL_Window *win);

int main(int argc, char *argv[])
{
    win = SDL_CreateWindow("Casino", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                           SDL_WINDOW_FULLSCREEN_DESKTOP);
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    initialize(win, renderer);

    while (!quit)
    {
        processEvents(win);
        switch (egoera)
        {
        case MENU:
            renderMenu(win, renderer);
            break;
        case HELP:

            break;
        case CONFIG:

            break;
        case GAME:
        
            break;  
        default:
            break;
        }
        
    }

    cleanup(win, renderer);

    return 0;
}
