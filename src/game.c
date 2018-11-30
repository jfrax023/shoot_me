/**
 * define fonction to manage the game .
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <fmod/fmod.h>
#include <utilities.h>
#include "define.h"
#include "threading.h"
#include "target_helper.h"



void loadingGame(SDL_Surface *pRootWin, Target target[], int level, int loadTarget){

    // variable
    Thread1Data data = {level, pRootWin};
    pthread_t thread1;

    if(pthread_create(&thread1, NULL, thread_1, &data)){
        fprintf(stderr, "Can't launch thread_1 in loadingGame");
        exit(EXIT_FAILURE);
    }

    //  load target if loadTarget = 1
    if(loadTarget == 1){
        for(int i = 0; i < NB_TARGET; i++){
            switch (i){
                case 0:
                    createTargetList(&target[i], RED_BIRD_ID);
                    break;
                case 1:
                    createTargetList(&target[i], DRAGON_ID);
                    break;
                case 2:
                    createTargetList(&target[i], GREY_BIRD_ID);
                    break;
                case 3:
                    createTargetList(&target[i], PURPLE_BIRD_ID);
                    break;
                case 4:
                    createTargetList(&target[i], SMALL_RED_BIRD_ID);
                    break;
                case 5:
                    createTargetList(&target[i], BLUE_BIRD_ID);
                    break;
            }

        }
    }


    if(pthread_join(thread1, NULL)){
        fprintf(stderr, "Error pthread_join in loadingGame");
        exit(EXIT_FAILURE);
    }

    /* ici on n'a donc notre structure target qui contient toute les cibles que nous avons charger en mêmoire dans
     *  une list chainée . On ne s'interesse pas au classement de ses cibles l'idée et de pouvoir y acceder et obtenire les
     *  surface definie dans la liste chainée .*/
    /*
    targetDestroy(target[5].list);
    cleanWindow(pRootWin);
    SDL_Flip(pRootWin);
    myPause();
     */
}
