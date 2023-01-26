#include "grafikoak.h"
#include "ebentuak.h"
#include "ourTypes.h"
#include "menua.h"

SDL_Event event;
POSIZIOA saguPos;
POSIZIOA saguarenPosizioa() { return saguPos; }


int  ebentuakJaso()
{
    int ret = 1;
    while (SDL_PollEvent(&event))
    { //Ebentuen bukle nagusia
        switch (event.type)
        {
        case SDL_QUIT:
            ret = 0;
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:   //Esc- botoiari ematean ixteko
                ret = 0;
                break;
            case SDLK_m:  //m botoiari ematean menura itzultzeko
                if (egoera == JOLASTEN)
                {
                    ret = SDLK_m;
                }
                break;
            default:
                break;
            }
            break;
        case SDL_MOUSEWHEEL:
            if (event.wheel.y < 0) // scroll gora
            {
                ret = MOUSEWHEEL_GORA;
            }
            else if (event.wheel.y > 0) // scroll behera
            {
                ret = MOUSEWHEEL_BEHERA;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch (event.button.button)
            {
            case SDL_BUTTON_LEFT:
                ret = SAGU_BOTOIA_EZKERRA_BEHERA;
                break;
            default:
                ret = event.button.button;
                break;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            switch (event.button.button)
            {
            case SDL_BUTTON_LEFT:
                ret = SAGU_BOTOIA_EZKERRA_GORA;
                break;
            default:
                ret = event.button.button;
                break;
            }
            break;
        case SDL_MOUSEMOTION:
            saguPos.x = event.motion.x;
            saguPos.y = event.motion.y;
            ret = SAGUA_MUGIMENDUAN;
            break;
        default:
            break;
        }
    }

    return ret;
}