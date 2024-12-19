#include "orokorrak.h"

#include "events.h"
#include "init.h"
#include "pain.h"

int main(int argc, char *argv[])
{
    int posx = (SCREEN_WIDTH / 2) - 50;
    int posy = (SCREEN_HEIGHT / 2) - 50;
    int speed = 15;
    int quit = 0;
    int key_w = 0, key_a = 0, key_s = 0, key_d = 0;

    SDL_Window *win = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                                       SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);

    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    initialize(win, renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Event event;
    while (!quit)
    {

        SDL_RenderClear(renderer);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = TRUE;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    quit = TRUE;
                }
                switch (event.key.keysym.sym)
                {
                case SDLK_w:
                    key_w = 1;
                    break;
                case SDLK_s:
                    key_s = 1;
                    break;
                case SDLK_a:
                    key_a = 1;
                    break;
                case SDLK_d:
                    key_d = 1;
                    break;
                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDLK_w:
                    key_w = 0;
                    break;
                case SDLK_s:
                    key_s = 0;
                    break;
                case SDLK_a:
                    key_a = 0;
                    break;
                case SDLK_d:
                    key_d = 0;
                    break;
                }

                break;
            default:
                break;
            }
        }
        if (key_w)
        {
            posy -= speed;
        }
        if (key_s)
        {
            posy += speed;
        }
        if (key_a)
        {
            posx -= speed;
        }
        if (key_d)
        {
            posx += speed;
        }
        paint_square(posx, posy, 100, 100, 255, 0, 0, 255, renderer);

        SDL_RenderPresent(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }
    cleanup(win, renderer);

    return 0;
}