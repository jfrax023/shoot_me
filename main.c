#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <fmod/fmod.h>
#include "define.h"
#include "utilities.h"
#include "window.h"
#include "game.h"


int main() {

    // variable sdl
    SDL_Surface *pRootWin = NULL;
    // fmod var
    FMOD_SYSTEM *pFSys = NULL;
    // divers
    char iconPath[100] = IMG_DIVERS_PATH, playerName[10] = "";
    int level = 1, stayIn = 1;

    Target target[NB_TARGET] = {0, NULL};


    /********************
     *  INITIALISATION  *
     *******************/
    // sdl
    if (SDL_Init(SDL_INIT_VIDEO) == -1){
        fprintf(stderr, "Can't initialize SDL => %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // ttf
    if (TTF_Init() == - 1){
        fprintf(stderr, "Can't initialize TTF => %s", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    // fmod
    FMOD_System_Create(&pFSys);
    if ( FMOD_System_Init(pFSys, 32, FMOD_INIT_NORMAL, NULL)!= FMOD_OK){
        fprintf(stderr, "Can't initialize FMOD");
        exit(EXIT_FAILURE);
    }

    /*******************
     *    MAIN CODE    *
     ******************/
    // hide cursor
    SDL_ShowCursor(SDL_DISABLE);
    // set icon
    SDL_WM_SetIcon(IMG_Load(strcat(iconPath, "viseur.bmp")), NULL);

    pRootWin = SDL_SetVideoMode(ROOT_WINDOW_WIDTH, ROOT_WINDOW_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    checkPointer(pRootWin, "Can't load main windows .");

    SDL_FillRect(pRootWin, NULL, SDL_MapRGB(pRootWin->format, 255, 255, 255));


    displayAccueil(pRootWin, pFSys);
    displayNameSelection(pRootWin, pFSys, playerName);

    // main game code
    while (level <= NB_LEVEL){
        if(level == 1){
            loadingGame(pRootWin, target, level, 1);
        } else{
            loadingGame(pRootWin, target, level, 0);
        }
        cleanWindow(pRootWin);
        SDL_Flip(pRootWin);
        level++;
    }

    myPause();


    /*****************
     *     FREE      *
     ****************/

    FMOD_System_Close(pFSys);
    FMOD_System_Release(pFSys);

    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}