#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cartas
{
    char PALO;
    int VALOR;
    char TEXTURA[20];
} CARTAS;

void init_cartas(CARTAS baraja[])
{
    char palos[] = {'C', 'D', 'T', 'P'};
    int palo, valor, i = 0;

    for (palo = 0; palo < 4; palo++)
    {
        for (valor = 1; valor <= 13; valor++)
        {
            baraja[i].PALO = palos[palo];
            baraja[i].VALOR = valor;
            sprintf(baraja[i].TEXTURA, "carta_%c_%d.png", palos[palo], valor);
            i++;
        }
    }
}
void game(CARTAS baraja[])
{

}
int main(int argc, char *argv[])
{
    CARTAS baraja[52];
    init_cartas(baraja);
    game(baraja);
}
