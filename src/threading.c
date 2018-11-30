/**
 * this file contain the thread function .
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "define.h"
#include "utilities.h"


/**
 * This thread display the loading image and wait 10 sec .
 * @param arg void A structure with the data level and pRootWin .
 * @return NULL
 */
void *thread_1(void *arg){

    // variable

    SDL_Surface *psOverlay = NULL, *psLvlMini = NULL;
    SDL_Rect overlayPos, lvlPos;

    char overlayPath[MEDIUM_ARRAY] = IMG_DIVERS_PATH, levelPath[MEDIUM_ARRAY] = IMG_LEVELS_MINI_PATH;

    Thread1Data *data = arg;

    // load data in var
    psOverlay = IMG_Load(strcat(overlayPath, "loading.png"));
    checkPointer(psOverlay, "Can't load overlay image in thread_1");

    // load levelImg, we use the parameter data->level to tell what image we need to load
    switch (data->level){
        case 1:
            psLvlMini = IMG_Load(strcat(levelPath, "castle_mini.png"));
            break;
        case 2:
            psLvlMini = IMG_Load(strcat(levelPath, "ville_mini.png"));
            break;
        case 3:
            psLvlMini = IMG_Load(strcat(levelPath, "city_mini.png"));
            break;
        case 4:
            psLvlMini = IMG_Load(strcat(levelPath, "forest_mini.png"));
            break;
    }

    checkPointer(psLvlMini, "Can't load level mini image in thread_1");

    overlayPos.x = 0;
    overlayPos.y = 0;

    lvlPos.x = (u_int16_t) (data->pRootWin->w / 2 - psLvlMini->w / 2);
    lvlPos.y = (u_int16_t) (data->pRootWin->h / 2 - psLvlMini->h / 2);

    // display the loading image and wait 10 sec
    cleanWindow(data->pRootWin);
    SDL_BlitSurface(psOverlay, NULL, data->pRootWin, &overlayPos);
    SDL_BlitSurface(psLvlMini, NULL, data->pRootWin, &lvlPos);
    SDL_Flip(data->pRootWin);
    sleep(5);

    SDL_FreeSurface(psOverlay);
    SDL_FreeSurface(psLvlMini);
    pthread_exit(NULL);

}
