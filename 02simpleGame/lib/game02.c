#include "game02.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "soinua.h"
#include "text.h"
#include <stdio.h>

#define ONGI_ETORRI_MEZUA "Sakatu return hasteko..."
#define JOKOA_SOUND "./sound/132TRANCE_02.wav"
#define JOKOA_PLAYER_IMAGE "./img/invader.bmp"
#define JOKOA_SOUND_WIN "./sound/BugleCall.wav"
#define JOKOA_SOUND_LOOSE "./sound/terminator.wav"
#define BUKAERA_SOUND_1 "./sound/128NIGHT_01.wav"
#define BUKAERA_IMAGE "./img/gameOver.bmp"
#define BACKGROUND_IMAGE "./img/background.bmp"
#define ZIRKULUAREN_TAMAINA 40

EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa);
int BUKAERA_irudiaBistaratu();

void jokoaAurkeztu(void)
{
    int ebentu = 0;

    pantailaGarbitu();
    textuaIdatzi((SCREEN_WIDTH / 2) - 100, (SCREEN_HEIGHT / 2) - 20, ONGI_ETORRI_MEZUA);
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);
}

EGOERA jokatu(void)
{
    int mugitu = 0; // boolean
    EGOERA egoera = JOLASTEN;
    int ebentu = 0;
    JOKO_ELEMENTUA zirkulua, jokalaria;
    int backgroundId;

    zirkulua.pos.x = SCREEN_WIDTH / 2;
    zirkulua.pos.y = SCREEN_HEIGHT;

    jokalaria.pos.x = 0;
    jokalaria.pos.y = SCREEN_HEIGHT / 2;

    loadTheMusic(JOKOA_SOUND);
    toggleMusic();
    backgroundId = irudiaKargatu(BACKGROUND_IMAGE);
    jokalaria.id = irudiaKargatu(JOKOA_PLAYER_IMAGE);
    arkatzKoloreaEzarri(0, 0, 0xFF);
    do
    {
        SDL_Delay(10);
        pantailaGarbitu();
        irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
        irudiakMarraztu();
        zirkuluaMarraztu(zirkulua.pos.x, zirkulua.pos.y, ZIRKULUAREN_TAMAINA);
        pantailaBerriztu();
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_ESKUMA || ebentu == SAGU_BOTOIA_EZKERRA)
        {
            mugitu = 1; // true
        }
        zirkulua.pos.y = zirkulua.pos.y + 5;
        if (zirkulua.pos.y > SCREEN_HEIGHT)
        {
            zirkulua.pos.y = 0;
        }
        if (mugitu)
        {
            jokalaria.pos.x = jokalaria.pos.x + 5;
        }
        egoera = JOKOA_egoera(jokalaria, zirkulua);
    } while (egoera == JOLASTEN);
    irudiaKendu(jokalaria.id);
    irudiaKendu(backgroundId);
    toggleMusic();
    return egoera;
}

EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa)
{
    EGOERA ret = JOLASTEN;
    if (jokalaria.pos.x > oztopoa.pos.x - ZIRKULUAREN_TAMAINA &&
        jokalaria.pos.x < oztopoa.pos.x + ZIRKULUAREN_TAMAINA &&
        jokalaria.pos.y > oztopoa.pos.y - ZIRKULUAREN_TAMAINA && jokalaria.pos.y < oztopoa.pos.y + ZIRKULUAREN_TAMAINA)
    {
        ret = GALDU;
    }
    else if (jokalaria.pos.x > SCREEN_WIDTH)
    {
        ret = IRABAZI;
    }
    return ret;
}

int jokoAmaierakoa(EGOERA egoera)
{
    int ebentu = 0, id;
    int idAudioGame;

    loadTheMusic(BUKAERA_SOUND_1);
    toggleMusic();
    if (egoera == IRABAZI)
    {
        idAudioGame = loadSound(JOKOA_SOUND_WIN);
        playSound(idAudioGame);
    }
    else
    {
        idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
        playSound(idAudioGame);
    }
    id = BUKAERA_irudiaBistaratu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while ((ebentu != TECLA_RETURN) && (ebentu != SAGU_BOTOIA_ESKUMA));
    toggleMusic();
    irudiaKendu(id);
    return (ebentu != TECLA_RETURN) ? 1 : 0;
}

int BUKAERA_irudiaBistaratu()
{
    int id = -1;
    id = irudiaKargatu(BUKAERA_IMAGE);
    pantailaGarbitu();
    irudiaMugitu(id, (SCREEN_WIDTH / 2) - 125, (SCREEN_HEIGHT / 2) - 20);
    irudiakMarraztu();
    pantailaBerriztu();
    return id;
}
