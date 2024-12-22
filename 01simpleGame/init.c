#include "init.h"
int initialize(SDL_Window *win, SDL_Renderer *renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error al iniciaizar sdl...");
        return 1;
    }
    else
    {
        printf("Inicialilzacion competada...");
    }
    if (!win)
    {
        printf("Error al inciailzar ventana...");
        return 1;
    }
    else
    {
        printf("Ventana Iinicializada...");
    }
    if (!renderer)
    {
        printf("Error al crear renderizador...");
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    
    return 0;
}
void cleanup(SDL_Window *win, SDL_Renderer *renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
