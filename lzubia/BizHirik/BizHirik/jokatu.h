#ifndef JOKATU_H
#define JOKATU_H
#include "ourTypes.h"


//Funtzioen definizioak

void jolasten();
void mugimendua();
void mapaMarraztu(char* tilePath[]);
void eguneratu();
void abisuaAzaldu(SDL_Renderer* renderer);
void ondorioaAgertu(int neurgailua, SDL_Renderer* renderer);
void dataAldatu(int* hilabetea, int* urtea);
void jokoaReseteatu();


int azpimenuaMarraztu(SDL_Renderer* renderer, char* botoiPath[]);
int ehunekoaKalkulatu(int ronda);

SDL_Rect laukizuzenak(int neurgailua);




#endif
