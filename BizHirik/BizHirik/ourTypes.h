#ifndef OURTYPES_H
#define OURTYPES_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>  
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "textua.h"
#include "grafikoak.h"

typedef struct
{
    SDL_Rect draw_rect;    // botoian dimentsioak
    char path[50];  //irudia

} button_t;

typedef enum  //egoera bakoitza, guretzat izango die pantalla diferentiak
{
    MENUA, //0
    JOLASTEN, //1
    NOLAJOKATU,//2
    KREDITUAK, //3
    EZARPENAK, //4

}EGOERAK;

void ezarpenak();
void nolajokatu();
void kredituak();
extern EGOERAK egoera;
static SDL_Color textColor = { 255,255,255 };
static TTF_Font* font;


extern int muted;

#endif
