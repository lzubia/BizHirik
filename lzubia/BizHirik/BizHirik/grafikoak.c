#include "grafikoak.h"
#include "textua.h"
#include "ourTypes.h"
#include "menua.h"

SDL_Renderer* renderer;
SDL_Window* window;
SDL_Texture* texture;



int hasieratu()
{
    // SDL inizializau
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        fprintf(stderr, "Ezin SDL hasieratu: %s\n", SDL_GetError());
        return -1;
    }
    // Mixer hasieratu
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        fprintf(stderr, "Error al inicializar SDL_mixer: %s\n", Mix_GetError());
        return -1;
    }

    // Menuko musika kargatu
    musicamenu = Mix_LoadMUS("audioak/Game Menu Music.mp3");
    if (!musicamenu)
    {
        fprintf(stderr, "Error al cargar m�sica de fondo: %s\n", Mix_GetError());
        return -1;
    }

    // Jolaseko musika kargatu
    musicajolasa = Mix_LoadMUS("audioak/Videogame Music_.mp3");
    if (!musicajolasa)
    {
        fprintf(stderr, "Error al cargar m�sica de fondo: %s\n", Mix_GetError());
        return -1;
    }

    // Elementu berria eraikitzearen soinua kargatu
    clicksoinua = Mix_LoadWAV("audioak/clicksound.wav");
    if (!clicksoinua)
    {
        fprintf(stderr, "Error al cargar sonido de clic: %s\n", Mix_GetError());
        return -1;
    }

    //Abisuaren soinua kargatu
    abisuasoinua = Mix_LoadWAV("audioak/abisua.wav");
    if (!abisuasoinua)
    {
        fprintf(stderr, "Error al cargar sonido de clic: %s\n", Mix_GetError());
        return -1;
    }

    //TTF hasieratu
    if (TTF_Init() < 0)
    {
        fprintf(stderr, "Ezin TTF hasieratu: %s\n", SDL_GetError());
        return -1;
    }

    //Image hasieratu
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        fprintf(stderr, "SDL_image error:%s\n", IMG_GetError());
        return -1;
    }

    //leihoa sortu
    window = SDL_CreateWindow("Bizhirik", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0,
        0, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (window == NULL)
    {
        fprintf(stderr, "Ezin lehioa sortu: %s\n", SDL_GetError());
        return -1;
    }

    //rendererra sortu
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL)
    {
        fprintf(stderr, "Ezin renderer sortu: %s\n", SDL_GetError());
        return -1;
    }

    return 0;
}

SDL_Texture* texturaKargatu(char path[50])
{
    SDL_Surface* surface = IMG_Load(path);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void amaitu()
{
    // Dena itxi
    Mix_FreeMusic(musicamenu);
    Mix_FreeMusic(musicajolasa);
    Mix_FreeChunk(clicksoinua);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    SDL_Quit();
}

SDL_Renderer* getRenderer()  //rendererra eskuratzeko funtzioa
{
    return renderer;
}

SDL_Window* getWindow()   //leihoa eskuratzeko funtzioa
{
    return window;
}

