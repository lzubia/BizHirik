#include "grafikoak.h"
#include "ebentuak.h"
#include "ourTypes.h"
#include "menua.h"
#include "textua.h"

POSIZIOA saguPos;

void menua()
{

    SDL_Renderer* renderer = getRenderer();
    int ebentua = 1;


    if (Mix_PlayingMusic() == 0 && !muted) //musika hasteko
    {
        Mix_HaltMusic();
        Mix_PlayMusic(musicamenu, -1);
    }
    else if (muted)  //musika gelditzeko
    {
        Mix_PauseMusic();
    }

    while (ebentua != 0 && egoera == MENUA)  //menuko bukle nagusia
    {
        ebentua = ebentuakJaso();

        SDL_RenderClear(renderer);

        SDL_Texture* texture = texturaKargatu("data/1menuPantaila.png");    //Atzealdea kargau
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_DestroyTexture(texture);

        botoiakMarraztu(renderer);

        saguPos = saguarenPosizioa();

        if (ebentua == SAGU_BOTOIA_EZKERRA_BEHERA)   //menuko botoiak
        {
            if (saguPos.x > nolajokatu_botoia.draw_rect.x && saguPos.x < nolajokatu_botoia.draw_rect.x + nolajokatu_botoia.draw_rect.w && saguPos.y > nolajokatu_botoia.draw_rect.y && saguPos.y < nolajokatu_botoia.draw_rect.y + nolajokatu_botoia.draw_rect.h)
            {
                egoera = NOLAJOKATU;
            }
            else if (saguPos.x > jokatu_botoia.draw_rect.x && saguPos.x < jokatu_botoia.draw_rect.x + jokatu_botoia.draw_rect.w && saguPos.y > jokatu_botoia.draw_rect.y && saguPos.y < jokatu_botoia.draw_rect.y + jokatu_botoia.draw_rect.h)
            {
                egoera = JOLASTEN;
            }
            else if (saguPos.x > kredituak_botoia.draw_rect.x && saguPos.x < kredituak_botoia.draw_rect.x + kredituak_botoia.draw_rect.w && saguPos.y > kredituak_botoia.draw_rect.y && saguPos.y < kredituak_botoia.draw_rect.y + kredituak_botoia.draw_rect.h)
            {
                egoera = KREDITUAK;
            }
            else if (saguPos.x > ezarpenak_botoia.draw_rect.x && saguPos.x < ezarpenak_botoia.draw_rect.x + ezarpenak_botoia.draw_rect.w && saguPos.y > ezarpenak_botoia.draw_rect.y && saguPos.y < ezarpenak_botoia.draw_rect.y + ezarpenak_botoia.draw_rect.h)
            {
                egoera = EZARPENAK;
            }
        }
    }
}


void nolajokatu()
{

    SDL_Renderer* renderer = getRenderer();
    int ebentua = 1;
    while (ebentua != 0 && egoera == NOLAJOKATU)
    {
        ebentua = ebentuakJaso();

        SDL_RenderClear(renderer);

        SDL_Texture* texture = texturaKargatu("data/nolajokatu.png");
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_DestroyTexture(texture);
        botoiakMarraztu(renderer);


        saguPos = saguarenPosizioa();  //atzera boroia
        if (ebentua == SAGU_BOTOIA_EZKERRA_BEHERA)
        {
            if (saguPos.x > atzera_botoia.draw_rect.x && saguPos.x < atzera_botoia.draw_rect.x + atzera_botoia.draw_rect.w && saguPos.y > atzera_botoia.draw_rect.y && saguPos.y < atzera_botoia.draw_rect.y + atzera_botoia.draw_rect.h)
            {
                egoera = MENUA;
            }
        }
    }
}

void kredituak()
{
    SDL_Renderer* renderer = getRenderer();
    int ebentua = 1;
    while (ebentua != 0 && egoera == KREDITUAK)
    {
        ebentua = ebentuakJaso();

        SDL_RenderClear(renderer);

        SDL_Texture* texture = texturaKargatu("data/kredituak.png");
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_DestroyTexture(texture);

        botoiakMarraztu(renderer);

        saguPos = saguarenPosizioa();

        if (ebentua == SAGU_BOTOIA_EZKERRA_BEHERA)
        {
            if (saguPos.x > atzera_botoia.draw_rect.x && saguPos.x < atzera_botoia.draw_rect.x + atzera_botoia.draw_rect.w && saguPos.y > atzera_botoia.draw_rect.y && saguPos.y < atzera_botoia.draw_rect.y + atzera_botoia.draw_rect.h)
            {
                egoera = MENUA;
            }
        }
    }
}


void ezarpenak()
{

    int ebentua = 1;
    textuaGaitu();

    while (ebentua != 0 && egoera == EZARPENAK)
    {
        ebentua = ebentuakJaso();

        SDL_RenderClear(getRenderer());

        SDL_Texture* texture = texturaKargatu("data/ezarpenak.png");
        SDL_RenderCopy(getRenderer(), texture, NULL, NULL);
        SDL_DestroyTexture(texture);

        botoiakMarraztu(getRenderer());

        soinuBotoiakMarraztu();

        SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 255);

        saguPos = saguarenPosizioa();

        if (ebentua == SAGU_BOTOIA_EZKERRA_BEHERA)
        {
            if (saguPos.x > atzera_botoia.draw_rect.x && saguPos.x < atzera_botoia.draw_rect.x + atzera_botoia.draw_rect.w && saguPos.y > atzera_botoia.draw_rect.y && saguPos.y < atzera_botoia.draw_rect.y + atzera_botoia.draw_rect.h)
            {
                egoera = MENUA;
            }
            else if (saguPos.x >= textRect.x && saguPos.x <= textRect.x + textRect.w && saguPos.y >= textRect.y && saguPos.y <= textRect.y + textRect.h)
            {
                // Musika ixildu edo martxan jarri
                if (muted)
                {
                    Mix_ResumeMusic();
                    muted = 0;
                }
                else
                {
                    Mix_PauseMusic();
                    muted = 1;
                }
            }
            //Bolumena ajustatzeko
            else if (saguPos.x >= sliderRect.x && saguPos.x <= sliderRect.x + sliderRect.w && saguPos.y >= sliderRect.y && saguPos.y <= sliderRect.y + sliderRect.h)
            {
                int newVolume = (saguPos.x - sliderRect.x) * MIX_MAX_VOLUME / 600;
                volume = newVolume;
                Mix_VolumeMusic(volume);
            }
        }
        SDL_RenderPresent(getRenderer());
    }
    textuaDesgaitu();
}


void soinuBotoiakMarraztu()
{

    SDL_Surface* txtSurface;
    //Isiltzeko edo martxan jartzeko botoia marraztu

    textRect.x = 300;
    textRect.y = 450;
    textRect.w = 80;
    textRect.h = 30;

    if (muted)
    {
        SDL_SetRenderDrawColor(getRenderer(), 252, 86, 88, 255);
        txtSurface = TTF_RenderText_Solid(font, "Music Off", textColor);
    }
    else
    {
        SDL_SetRenderDrawColor(getRenderer(), 135, 181, 66, 255);
        txtSurface = TTF_RenderText_Solid(font, "Music On", textColor);
    }
    SDL_RenderFillRect(getRenderer(), &textRect);

    SDL_Texture* texture3 = SDL_CreateTextureFromSurface(getRenderer(), txtSurface);
    SDL_RenderCopy(getRenderer(), texture3, NULL, &textRect);
    SDL_FreeSurface(txtSurface);
    SDL_DestroyTexture(texture3);

    //Barra mugikorra marraztu

    sliderRect.x = 300;
    sliderRect.y = 750;
    sliderRect.w = 600;
    sliderRect.h = 40;
    SDL_SetRenderDrawColor(getRenderer(), 252, 86, 88, 255);
    SDL_RenderFillRect(getRenderer(), &sliderRect);

    //Bolumen adierazlea marraztu
    indicatorRect.x = sliderRect.x + (volume * 600 / MIX_MAX_VOLUME);
    indicatorRect.y = sliderRect.y;
    indicatorRect.w = sliderRect.w / 30;
    indicatorRect.h = sliderRect.h;
    SDL_SetRenderDrawColor(getRenderer(), 135, 181, 66, 255);
    SDL_RenderFillRect(getRenderer(), &indicatorRect);
}

void botoiakMarraztu(SDL_Renderer* renderer)
{

    SDL_Texture* t1 = texturaKargatu(nolajokatu_botoia.path);       //botoien irudiak kargatu
    SDL_Texture* t2 = texturaKargatu(jokatu_botoia.path);
    SDL_Texture* t3 = texturaKargatu(kredituak_botoia.path);
    SDL_Texture* t4 = texturaKargatu(atzera_botoia.path);
    SDL_Texture* t5 = texturaKargatu(ezarpenak_botoia.path);

    if (egoera == MENUA)
    {
        SDL_RenderCopy(renderer, t1, NULL, &nolajokatu_botoia.draw_rect);       //botoiak erakutsi 
        SDL_RenderCopy(renderer, t2, NULL, &jokatu_botoia.draw_rect);
        SDL_RenderCopy(renderer, t3, NULL, &kredituak_botoia.draw_rect);
        SDL_RenderCopy(renderer, t5, NULL, &ezarpenak_botoia.draw_rect);
    }
    else if (egoera == NOLAJOKATU || egoera == KREDITUAK || egoera == EZARPENAK)
    {
        SDL_RenderCopy(renderer, t4, NULL, &atzera_botoia.draw_rect);
    }

    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(t1);    //botoiak ezabatu
    SDL_DestroyTexture(t2);
    SDL_DestroyTexture(t3);
    SDL_DestroyTexture(t4);
    SDL_DestroyTexture(t5);
}
