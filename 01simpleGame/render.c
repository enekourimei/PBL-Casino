#include "render.h"
void renderMenu(SDL_Window *win, SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer);
    renderBackground("./img/fondo.bmp", renderer);
    SDL_RenderPresent(renderer);
}
void renderBackground(char *path, SDL_Renderer *renderer)
{
    SDL_Surface *backgroundSurface = IMG_Load(path);
    if (!backgroundSurface)
    {
        fprintf(stderr, "Error al cargar la imagen '%s': %s\n", path, IMG_GetError());
    }
    SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);
    if (!backgroundTexture)
    {
        printf("Error al crear la textura de fondo: %s\n", SDL_GetError());
    }
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
    SDL_DestroyTexture(backgroundTexture);
}