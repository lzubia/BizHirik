#include "grafikoak.h"
#include "ebentuak.h"
#include "ourTypes.h"
#include "menua.h"
#include "jokatu.h"
#include "textua.h"



void atzealdeaEzarri();

EGOERAK egoera;


int main(int argc, char* argv[])
{
    SDL_Renderer* renderer = getRenderer();

    int isRunning = 1;
    int ebentua = 1;

    if (hasieratu() == -1)
    {
        fprintf(stderr, "Ezin izan da bideoa ezarri: %s\n", SDL_GetError());
        return 0;
    }

    atzealdeaEzarri();

    egoera = MENUA;

    while (ebentua != 0)    //programan bukle nagusia
    {
        if (egoera == MENUA)
        {
            menua();

            if (egoera == MENUA)
            {
                ebentua = 0;
            }
        }
        else if (egoera == JOLASTEN)
        {
            jolasten();
            if (egoera != MENUA)
            {
                ebentua = 0;
            }
        }
        else if (egoera == NOLAJOKATU)
        {

            nolajokatu();
            if (egoera != MENUA)
            {
                ebentua = 0;
            }

        }
        else if (egoera == KREDITUAK)
        {
            kredituak();
            if (egoera != MENUA)
            {
                ebentua = 0;
            }

        }
        else if (egoera == EZARPENAK)
        {
            ezarpenak();
            if (egoera != MENUA)
            {
                ebentua = 0;
            }

        }

        SDL_DestroyRenderer(renderer);
    }

    amaitu();

    return 0;
}


void atzealdeaEzarri()  //Karga pantaila agertzeko
{
    SDL_Rect ruletarect = { NULL,NULL,NULL,NULL };
    SDL_Texture* kargapantaila = texturaKargatu("data/kargafondo.png");
    SDL_Texture* ruleta = texturaKargatu("data/ruleta.png");

    int i = 0;
    int angle = 0;
    ruletarect.x = 680;
    ruletarect.y = 550;
    ruletarect.h = 200;
    ruletarect.w = 200;

    for (i = 0; i < 360; i++)
    {
        SDL_RenderClear(getRenderer());
        SDL_RenderCopy(getRenderer(), kargapantaila, NULL, NULL);
        SDL_RenderCopyEx(getRenderer(), ruleta, NULL, &ruletarect, angle, NULL, SDL_FLIP_NONE);
        SDL_RenderPresent(getRenderer());
        SDL_Delay(10);
        angle += 1;
    }

    SDL_DestroyTexture(kargapantaila);
    SDL_DestroyTexture(ruleta);
}


