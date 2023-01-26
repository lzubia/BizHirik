#include "grafikoak.h"
#include "ebentuak.h"
#include "textua.h"
#include "menua.h"
#include "jokatu.h"
#include "ourTypes.h"
#define MAP_WIDTH 20
#define MAP_HEIGHT 20


POSIZIOA saguPos;

int map[MAP_WIDTH][MAP_HEIGHT] = {  //Mapa matrizea
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

//Aldagaiak

int tile_size = 32;
int scrollX = 700;
int scrollY = 0;
int ebentua = 1;
int tPos = 0;
int botoiPos = 0;
int is_dragging = 0;
int ronda = 1;
int aukera = 1;
int packzenbakia = 1;
int rondaLaburtua = 0;
int neurgailua = 0;
int hilabetea = 02;
int urtea = 26;
int muted = 0;
int aldiunekoneurgailua = 0;
int puntubalioa[5] = { 0,1,2,3,4 };
int preziobalioa[5] = { 0,100,200,300,400 };

extern int dirua = 1000;
extern int puntukop = 0;

float ehunekoa = 0;

SDL_Rect rect[5] = {
{ 20,650,1500,200 }, //fondoa
{ 150,630,230,200 }, //botoia 1
{ 500,630,230,200},  //botoia 2
{ 850,630,230,200 }, //botoia 3
{ 1200,630,230,200}, //botoia 4
};


void jolasten()
{
    char* tilePath[11] = { NULL, "data/fabrikat.png", "data/etxeat.png", "data/eskolat.png", "data/parkeat.png", "data/mguneat.png", "data/museoat.png", "data/gpublikoat.png", "data/zentralat.png", "data/lakuat.png", "data/ospitaleat.png" };
    char* botoiPath[4] = { NULL, NULL, NULL, NULL };
    SDL_Renderer* renderer = getRenderer();
    SDL_Rect hasiera;
    SDL_Texture* barra;
    SDL_Texture* texture;

    if (!muted) //musika hasteko
    {
        Mix_HaltMusic();
        Mix_PlayMusic(musicajolasa, -1);
    }
    else
    { //musika gelditzeko
        Mix_PauseMusic();
    }

    textuaGaitu();

    while (ebentua != 0 && egoera == JOLASTEN && ronda <= 24 && aukera >= 0)
    {   //jokatzeko bukle nagusia

        barra = texturaKargatu("data/spritesheet1.png"); //barra neurtzaileen argazkia

        mugimendua();

        ebentua = ebentuakJaso();

        if (ebentua == SDLK_m)  //m-ri ematean menura itzultzea eta jokoko musika gelditzea
        {
            egoera = MENUA;
            Mix_PauseMusic();
        }

        aldiunekoneurgailua = ehunekoaKalkulatu(ronda) / 10;

        SDL_RenderClear(renderer);

        texture = texturaKargatu("data/fondo.png");
        SDL_RenderCopy(getRenderer(), texture, NULL, NULL);
        SDL_DestroyTexture(texture);

        mapaMarraztu(tilePath);
        azpimenuaMarraztu(renderer, botoiPath);

        //Dirua pantailaratzeko
        snprintf(diruatext, 50, "Dirua: %d EUR", dirua);
        textuaIdatzi(10, 40, diruatext);

        //Data pantailaratzeko
        if (hilabetea < 10)
        {
            snprintf(data, 50, "Data: 20%d/0%d", urtea, hilabetea);
        }
        else
        {
            snprintf(data, 50, "Data: 20%d/%d", urtea, hilabetea);
        }

        textuaIdatzi(10, 10, data);


        hasiera = laukizuzenak(aldiunekoneurgailua); //barra neurtzailearen laukizuzena hautatu
        SDL_Rect dRect = { 1000, 10, 288, 96 };
        SDL_RenderCopy(renderer, barra, &hasiera, &dRect, 0, NULL);

        SDL_RenderPresent(renderer);

        SDL_DestroyTexture(barra);
    }
    textuaDesgaitu();

    if (egoera == JOLASTEN && ebentua != 0)
    {
        ondorioaAgertu(aldiunekoneurgailua * 10, renderer);

        jokoaReseteatu();

        egoera = MENUA;
    }

    Mix_HaltMusic();
}


int azpimenuaMarraztu(SDL_Renderer* renderer, char* botoiPath[])
{

    SDL_Texture* texture[5];

    if (ronda == 4 * packzenbakia - 3)
    {
        botoiPath[0] = "data/fabrikap.png";
        botoiPath[1] = "data/etxeap.png";
        botoiPath[2] = "data/eskolap.png";
        botoiPath[3] = "data/parkeap.png";
        rondaLaburtua = 1;
    }
    else if (ronda == 4 * packzenbakia - 2)
    {
        botoiPath[0] = "data/mguneap.png";
        botoiPath[1] = "data/museoap.png";
        botoiPath[2] = "data/gpublikoap.png";
        botoiPath[3] = "data/zentralap.png";
        rondaLaburtua = 2;
    }
    else if (ronda == 4 * packzenbakia - 1)
    {
        botoiPath[0] = "data/fabrikap.png";
        botoiPath[1] = "data/lakuap.png";
        botoiPath[2] = "data/eskolap.png";
        botoiPath[3] = "data/ospitaleap.png";
        rondaLaburtua = 3;
    }
    else if (ronda == 4 * packzenbakia)
    {
        botoiPath[0] = "data/mguneap.png";
        botoiPath[1] = "data/etxeap.png";
        botoiPath[2] = "data/gpublikoap.png";
        botoiPath[3] = "data/parkeap.png";
        rondaLaburtua = 4;
    }
    //fondoko argazkia
    char* pathAzpimenuBotoiak[] = { "data/fondoa.png", botoiPath[0], botoiPath[1], botoiPath[2], botoiPath[3] };

    for (int i = 0; i < 5; i++)
    {
        texture[i] = texturaKargatu(pathAzpimenuBotoiak[i]);
        SDL_RenderCopy(renderer, texture[i], NULL, &rect[i]);
        SDL_DestroyTexture(texture[i]);
    }

    saguPos = saguarenPosizioa();

    if (ebentua == SAGU_BOTOIA_EZKERRA_BEHERA)
    {
        for (int i = 1; i < 5; i++)
        {
            if (saguPos.x >= rect[i].x && saguPos.x < rect[i].x + rect[i].w && saguPos.y >= rect[i].y && saguPos.y < rect[i].y + rect[i].h)
            {   //azpimenuko 4 botoietako batian klik itxian
                is_dragging = 1;
                botoiPos = i;
                if (rondaLaburtua == 1)
                {
                    tPos = i;
                }
                else if (rondaLaburtua == 2)
                {
                    tPos = i + 4;
                }
                else if (rondaLaburtua == 3)
                {
                    if (i == 2)
                    {
                        tPos = 9;
                    }
                    else if (i == 4)
                    {
                        tPos = 10;
                    }
                    else
                    {
                        tPos = i;
                    }
                }
                else if (rondaLaburtua == 4)
                {
                    if (i == 1 || i == 3)
                    {
                        tPos = i + 4;
                    }
                    else
                    {
                        tPos = i;
                    }
                }
            }
        }
    }
    else if (ebentua == SAGUA_MUGIMENDUAN && is_dragging == 1)
    {
        rect[botoiPos].x = saguPos.x - rect[botoiPos].w / 2;
        rect[botoiPos].y = saguPos.y - rect[botoiPos].h / 2;

        if (saguPos.y < rect[0].y)
        {        //irudia redimensionau tile-an tamaina eukitzeko
            rect[botoiPos].w = tile_size * 2;
            rect[botoiPos].h = tile_size * 2;
        }
    }
}

void mugimendua()
{
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    int mapScrolllSpeed = 5;

    if (keystate[SDL_SCANCODE_W]) //Tekla zapalduta eukitzean mapa mugitzeko
    {
        scrollY += mapScrolllSpeed;
    }
    if (keystate[SDL_SCANCODE_A])
    {
        scrollX += mapScrolllSpeed;
    }
    if (keystate[SDL_SCANCODE_S])
    {
        scrollY -= mapScrolllSpeed;
    }
    if (keystate[SDL_SCANCODE_D])
    {
        scrollX -= mapScrolllSpeed;
    }

    if (ebentua == MOUSEWHEEL_GORA && tile_size > 32)
    {     //saguan scroll-a erabiltzean tamaina handitu edo txikitzeko
        tile_size *= 0.7;
    }
    else if (ebentua == MOUSEWHEEL_BEHERA && tile_size < 150)
    {
        tile_size *= 1.3;
    }
}

void mapaMarraztu(char* tilePath[])
{

    SDL_Texture* texture[11];


    if (ronda == 5 * packzenbakia - 3)
    {
        tilePath[0] = "data/udaberria.png";
    }
    else if (ronda == 5 * packzenbakia - 2 || ronda == 5 * packzenbakia - 1)
    {
        tilePath[0] = "data/uda.png";
    }
    else if (ronda == 5 * packzenbakia - 4)
    {
        tilePath[0] = "data/negua.png";
    }
    else if (ronda == 5 * packzenbakia - 5)
    {
        tilePath[0] = "data/udazkena.png";
    }

    for (int i = 0; i < 11; i++)
    {
        texture[i] = texturaKargatu(tilePath[i]);
    }

    //mapa marraztu
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            // 2D matrizearen koordenatuak koordenatu isometrikoetara pasa
            int isoX = (x - y) * (tile_size)+scrollX; // scrollX aldatuz gero scroll laterala
            int isoY = (x + y) * (tile_size / 2) + scrollY;

            POSIZIOA sagPos = saguarenPosizioa();
            if (ebentua == SAGU_BOTOIA_EZKERRA_BEHERA)
            {

                for (int i = 1; i < 5; i++)
                {
                    rect[1].x = 150;
                    rect[2].x = 500;
                    rect[3].x = 850;
                    rect[4].x = 1200;
                    rect[i].y = 630;
                    rect[i].w = 230;
                    rect[i].h = 200;
                }

                if (sagPos.x >= isoX && sagPos.x <= isoX + tile_size &&
                    sagPos.y >= isoY && sagPos.y <= isoY + tile_size && map[y][x] == 0 && saguPos.y < rect[0].y && is_dragging == 1)
                {

                    //maparen irudia aldatu
                    map[y][x] = tPos;
                    eguneratu();
                    is_dragging = 0;
                    dataAldatu(&hilabetea, &urtea);

                }

            }

            SDL_Rect rect = { isoX, isoY, tile_size * 2, tile_size * 2 };
            SDL_RenderCopy(getRenderer(), texture[map[y][x]], NULL, &rect);

        }
    }

    for (int i = 0; i < 11; i++)
    {
        SDL_DestroyTexture(texture[i]);
    }
}

int ehunekoaKalkulatu(int ronda)
{
    //packzenbakia = 4 ronda
    int packzenb = 0, i = 0;
    float batura = 0;
    int puntumax[6] = { 10,8,7,6,5,4 };
    float ehunekoa = 0, itzuli = 0;

    packzenb = ronda / 4;
    for (i = 0; i < packzenb; i++)
    {
        batura = batura + puntumax[i];
    }
    ehunekoa = puntukop / batura;
    return ehunekoa * 100;
}


void eguneratu()
{
    dirua -= preziobalioa[botoiPos];
    puntukop += puntubalioa[botoiPos];
    ronda++;

    //Elementua eraikitzean entzuten den soinua erreproduzitu
    Mix_PlayChannel(-1, clicksoinua, 0);

    // 4 ronda pasa direla konprobatu
    if ((ronda - 1) % 4 == 0)
    {
        if (ronda < 24 && dirua >= 0) //Diruarekin iritsi bada
        {
            dirua = dirua + 1000 - 100 * packzenbakia;   //packzenbakiarekiko proportzionala den balio bat emango zaio

        }
        else if (dirua < 0 && aukera >= 0)  //Dirurik gabe iritsi bada
        {
            if (aukera == 1 && ronda != 25) //Aukera erabili eta 500 sartuko zaizkio
            {
                abisuaAzaldu(getRenderer());

                dirua = 500;
                puntukop /= 2;
                aukera--;
            }
            else
            {
                aukera--;
                dirua = 0;
                puntukop = 0;
            }
        }
        packzenbakia++;
    }

}

void abisuaAzaldu(SDL_Renderer* renderer)
{

    SDL_Texture* abisua = texturaKargatu("data/abisua.png");

    Mix_PlayChannel(-1, abisuasoinua, 0);

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, abisua, NULL, NULL, 0, NULL, SDL_FLIP_NONE);

    while (ebentuakJaso() != 0) //Esc ematen ez den bitartean agertuko da
    {
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(abisua);

}

void ondorioaAgertu(int neurgailua, SDL_Renderer* renderer)
{
    SDL_Texture* ondorioa = NULL;
    if (aukera <= 0)
    {
        ondorioa = texturaKargatu("data/ondorioa6.png");  //Diru gabe gelditzearen ondorioa
    }
    else
    {
        if (0 <= neurgailua && neurgailua <= 20)   //%0 - %20
        {
            ondorioa = texturaKargatu("data/ondorioa1.png");
        }
        else if (20 < neurgailua && neurgailua <= 40)   //%20 - %40
        {
            ondorioa = texturaKargatu("data/ondorioa2.png");
        }
        else if (40 < neurgailua && neurgailua <= 60)   //%40 - %60
        {
            ondorioa = texturaKargatu("data/ondorioa3.png");
        }
        else if (60 < neurgailua && neurgailua <= 80)   //%60 - %80
        {
            ondorioa = texturaKargatu("data/ondorioa4.png");
        }
        else if (80 < neurgailua && neurgailua <= 100)  //%80 - %100
        {
            ondorioa = texturaKargatu("data/ondorioa5.png");
        }
    }

    SDL_RenderCopy(renderer, ondorioa, NULL, NULL, 0, NULL);

    while (ebentuakJaso() != 0) //Esc eman bitartean azalduko da
    {
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(ondorioa);
}

void dataAldatu(int* hilabetea, int* urtea)
{
    *hilabetea += 2;
    if (*hilabetea > 12)
    {
        (*urtea)++;
        *hilabetea = 2;
    }
}

void jokoaReseteatu() //Partida bat baino gehiago jokatu ahal izateko
{
    tile_size = 32;
    scrollX = 700;
    scrollY = 0;
    ronda = 1;
    dirua = 1000;
    tPos = 0;
    botoiPos = 0;
    is_dragging = 0;
    ronda = 1;
    aukera = 1;
    packzenbakia = 1;
    puntukop = 0;
    aldiunekoneurgailua = 0;
    ehunekoa = 0;
    rondaLaburtua = 0;
    neurgailua = 0;
    hilabetea = 02;
    urtea = 26;

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            map[y][x] = 0;
        }
    }
}

SDL_Rect laukizuzenak(int neurgailua)
{
    //Barra neurgailua hautatzeko
    SDL_Rect hasiera = { NULL,NULL,NULL,NULL };
    switch (neurgailua)
    {
    case 0:   //%0
        if (neurgailua == 0)
        {
            hasiera.x = 288;
            hasiera.y = 480;
            hasiera.w = 288;
            hasiera.h = 96;
            break;
        }

    case 1:   //%10
        if (neurgailua == 1)
        {
            hasiera.x = 0;
            hasiera.y = 0;
            hasiera.w = 288;
            hasiera.h = 96;
            break;
        }

    case 2:   //%20
        if (neurgailua == 2)
        {
            hasiera.x = 0;
            hasiera.y = 96;
            hasiera.w = 288;
            hasiera.h = 96;
            break;
        }

    case 3: //%30
        if (neurgailua == 3)
        {
            hasiera.x = 0;
            hasiera.y = 192;
            hasiera.w = 288;
            hasiera.h = 96;
            break;
        }

    case 4:   //%40
        if (neurgailua == 4)
        {
            hasiera.x = 0;
            hasiera.y = 288;
            hasiera.w = 288;
            hasiera.h = 96;
            break;
        }

    case 5:   //%50
        if (neurgailua == 5)
        {
            hasiera.x = 0;
            hasiera.y = 384;
            hasiera.w = 288;
            hasiera.h = 96;
            break;
        }

    case 6:   //%60
        if (neurgailua == 6)
        {
            hasiera.x = 288;
            hasiera.y = 1;
            hasiera.w = 288;
            hasiera.h = 96;
            break;
        }

    case 7:   //%70
        if (neurgailua == 7)
        {
            hasiera.x = 288;
            hasiera.y = 96;
            hasiera.w = 288;
            hasiera.h = 96;
            break;
        }

    case 8:  //%80
        if (neurgailua == 8)
        {
            hasiera.x = 288;
            hasiera.y = 192;
            hasiera.w = 288;
            hasiera.h = 96;
            break;
        }

    case 9:   //%90
        if (neurgailua == 9)
        {
            hasiera.x = 288;
            hasiera.y = 288;
            hasiera.w = 288;
            hasiera.h = 96;
            break;
        }

    case 10:  //%100
        if (neurgailua == 10)
        {
            hasiera.x = 288;
            hasiera.y = 384;
            hasiera.w = 288;
            hasiera.h = 96;
            break;
        }
    }

    return hasiera;
}
