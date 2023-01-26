#ifndef MENUA_H
#define MENUA_H
#include "ourTypes.h"

//Menuko botoi guztien definizioak

static button_t nolajokatu_botoia = {
    .draw_rect = {.x = 650, .y = 100, .w = 300, .h = 100 },
    .path = "data/nolajokatubot.png",
};

static button_t jokatu_botoia = {
    .draw_rect = {.x = 650, .y = 350, .w = 300, .h = 100 },
    .path = "data/jokatubot.png",
};

static button_t kredituak_botoia = {
    .draw_rect = {.x = 650, .y = 600, .w = 300, .h = 100 },
    .path = "data/kredituakbot.png",
};

static button_t atzera_botoia = {
    .draw_rect = {.x = 30, .y = 30, .w = 100, .h = 100 },
    .path = "data/atzerabot.png",
};

static button_t ezarpenak_botoia = {
    .draw_rect = {.x = 30, .y = 30, .w = 150, .h = 150 },
    .path = "data/ezarpenakbot.png",
};

//Funtzioen definizioak
void botoiakMarraztu(SDL_Renderer* renderer);
void soinuBotoiakMarraztu();
void menua();


//Beste definizioak
static SDL_Rect textRect4 = { 730, 810, 400, 100 };
static SDL_Rect buttonRect;
static SDL_Surface* textSurface;
static SDL_Rect textRect;
static SDL_Rect sliderRect;
static SDL_Rect indicatorRect;

static int volume = 2 * MIX_MAX_VOLUME / 3;


#endif // !MENUA_H
