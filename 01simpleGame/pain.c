#include "pain.h"

void paint_square(int x, int y, int w, int h, int r, int g, int b, int o, SDL_Renderer *renderer)
{

    SDL_Rect rect = {x, y, w, h};
    SDL_SetRenderDrawColor(renderer, r, g, b, o);
    SDL_RenderFillRect(renderer, &rect);
}