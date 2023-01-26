#ifndef GRAFIKOAK_H
#define GRAFIKOAK_H

#include "ourTypes.h"

//Funtzioak definitu

int hasieratu();
void amaitu();


SDL_Texture* texturaKargatu(char path[50]);
SDL_Renderer* getRenderer();
SDL_Window* getWindow();
Mix_Music* musicamenu;
Mix_Music* musicajolasa;
Mix_Chunk* clicksoinua;
Mix_Chunk* abisuasoinua;



#endif
