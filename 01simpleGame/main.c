#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char PALO;
    int VALOR;
    char TEXTURA[20];
} cartas;

void init_cartas(cartas baraja[])
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
int main(int argc, char *argv[])
{
    init_cartas(baraja);
}
