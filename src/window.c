/**
 * this file define some function for display different menu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <fmod/fmod.h>
#include "define.h"
#include "utilities.h"


/**
 * Display accueil image and play a music
 * @param pRootWin SDL_Surface The main window
 * @param pFSys FMOD_SYSTEM the system variable for fmod
 */
void displayAccueil(SDL_Surface *pRootWin, FMOD_SYSTEM *pFSys){

    // variable
    SDL_Surface *sBg = NULL, *sText = NULL;
    SDL_Event event;
    SDL_Rect textPos, bgPos;
    SDL_Color orange = {239, 159, 0};

    FMOD_SOUND *fMusic = NULL;
    FMOD_RESULT fRes;

    TTF_Font *font = NULL;

    int stayIn = 1, currentTime = 0, backTime = 0;
    char musicPath[MEDIUM_ARRAY] = MUSIC_PATH, fontPath[MEDIUM_ARRAY] = FONTS_PATH, bgPath[MEDIUM_ARRAY] = IMG_DIVERS_PATH;
    char textToDisplay[] = "Tapez enter pour jouer";

    // load data in var
    sBg = IMG_Load(strcat(bgPath, "menu01.png"));
    checkPointer(sBg, "Can't load bg image in displayAccueil");

    font = TTF_OpenFont(strcat(fontPath, "SuperMario.ttf"), 40);
    checkPointer(font, "Can't load font in displayAccueil");

    TTF_SetFontStyle(font, TTF_STYLE_ITALIC);

    fRes = FMOD_System_CreateSound(pFSys, strcat(musicPath, "ambiant00.mp3"), FMOD_2D | FMOD_CREATESTREAM, 0, &fMusic);
    if (fRes != FMOD_OK){
        fprintf(stderr, "Can't load ambiant00.mp3 in displayAccueil");
        exit(EXIT_FAILURE);
    }

    sText = TTF_RenderUTF8_Solid(font, textToDisplay, orange);
    checkPointer(sText, "Can't create text surface in displayAccueil");

    textPos.x = (u_int16_t) (pRootWin->w / 2 - sText->w / 2);
    textPos.y = 600;

    bgPos.x = (u_int16_t) (pRootWin->w / 2 - sBg->w / 2);
    bgPos.y = 0;

    FMOD_Sound_SetLoopCount(fMusic, -1);

    FMOD_System_PlaySound(pFSys, fMusic, 0, 0, NULL);

    // event while
    while (stayIn){
        SDL_PollEvent(&event);
        switch (event.type){
            case SDL_QUIT:
                SDL_FreeSurface(sBg);
                SDL_FreeSurface(sText);
                TTF_CloseFont(font);
                FMOD_Sound_Release(fMusic);
                FMOD_System_Close(pFSys);
                FMOD_System_Release(pFSys);
                TTF_Quit();
                SDL_Quit();
                exit(EXIT_SUCCESS);

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                    case SDLK_KP_ENTER:
                        stayIn = 0;
                        break;
                    case SDLK_RETURN:
                        stayIn = 0;
                        break;
                }

        }
        currentTime = SDL_GetTicks();
        if (currentTime - backTime > 500){
            SDL_FillRect(pRootWin, NULL, SDL_MapRGB(pRootWin->format, 206, 255, 109));
            SDL_BlitSurface(sBg, NULL, pRootWin, &bgPos);
            backTime = currentTime;
        } else{
            SDL_FillRect(pRootWin, NULL, SDL_MapRGB(pRootWin->format, 206, 255, 109));
            SDL_BlitSurface(sBg, NULL, pRootWin, &bgPos);
            SDL_BlitSurface(sText, NULL, pRootWin, &textPos);
        }

        SDL_Flip(pRootWin);
    }


    SDL_FreeSurface(sBg);
    SDL_FreeSurface(sText);
    TTF_CloseFont(font);
    FMOD_Sound_Release(fMusic);

}


/**
 * Display the name selection menu .It allow to choose a name for the player by using an alphabet .
 * @param pRootWin SDL_Surface A pointer to the main window .
 * @param pFSys FMOD_SYSTEM A variable system for fmod
 * @param playerName char A variable where put the player name .
 */
void displayNameSelection(SDL_Surface *pRootWin, FMOD_SYSTEM *pFSys, char playerName[]){

    // variable
    SDL_Surface *psOverlay = NULL, **psLetter = NULL, *psName = NULL;
    SDL_Color greenBg = {206, 255, 109}, whiteBg = {255, 255, 255}, txtBlack = {0, 0, 0};
    SDL_Rect overlayPos, letterPos, namePos;
    SDL_Event event;

    FMOD_SOUND *soMove = NULL, *soSelect = NULL;
    FMOD_RESULT fRes;

    TTF_Font *font = NULL;

    int stayIn = 1, currentLetter = 0, sizeAlphabet = 0, currentPlayerNameLetter = 0;

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", alphabetLetter[] = "";
    // path
    char overlayPath[MEDIUM_ARRAY] = IMG_DIVERS_PATH, moveSoundPath[MEDIUM_ARRAY] = SOUNDS_PATH;
    char selectSoundPath[MEDIUM_ARRAY] = SOUNDS_PATH, fontPath[MEDIUM_ARRAY] = FONTS_PATH, arrayAlphabet[37] = "";

    // load data in var

    font = TTF_OpenFont(strcat(fontPath, "SourceCodePro-Black.ttf"), 40);
    checkPointer(font, "Can't load font in displayNameSelection");

    fRes = FMOD_System_CreateSound(pFSys, strcat(moveSoundPath, "menu_name_move.wav"), FMOD_CREATESAMPLE, 0, &soMove);
    if(fRes != FMOD_OK){
        fprintf(stderr, "Can't load move sound in displayNameSelection");
        exit(EXIT_FAILURE);
    }

    fRes = FMOD_System_CreateSound(pFSys, strcat(selectSoundPath, "menu_name_select.wav"), FMOD_CREATESAMPLE, 0, &soSelect);
    if(fRes != FMOD_OK){
        fprintf(stderr, "Can't load select sound in displayNameSelection");
        exit(EXIT_FAILURE);
    }

    sizeAlphabet = (int) strlen(alphabet);

    initPlayerName(playerName);

    psOverlay = IMG_Load(strcat(overlayPath, "overlay_name_selection.png"));
    checkPointer(psOverlay, "Can't load overlay image in displayNameSelection");


    // alloc alphabet surface
    psLetter = malloc(sizeAlphabet * sizeof(SDL_Surface*));
    if(psLetter == NULL){
        fprintf(stderr, "Can't alloc memory in displayNameSelection");
        exit(EXIT_FAILURE);
    }

    createArrayAlphabet(arrayAlphabet, alphabet);

    overlayPos.x = 0;
    overlayPos.y = 0;
    // event while
    while (stayIn){
        SDL_WaitEvent(&event);
        switch (event.type){
            case SDL_QUIT:
                free(psLetter);
                SDL_FreeSurface(psOverlay);
                TTF_CloseFont(font);
                FMOD_Sound_Release(soMove);
                FMOD_Sound_Release(soSelect);
                FMOD_System_Close(pFSys);
                FMOD_System_Release(pFSys);
                TTF_Quit();
                SDL_Quit();
                exit(EXIT_SUCCESS);
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                    case SDLK_RIGHT:
                        // move next letter
                        if (arrayAlphabet[currentLetter +1] != '\0'){
                            currentLetter++;
                            FMOD_System_PlaySound(pFSys, soMove, 0, 0, NULL);
                        } else {
                            FMOD_System_PlaySound(pFSys, soMove, 0, 0, NULL);
                            currentLetter = 0;
                        }
                        break;
                    case SDLK_LEFT:
                        // move previous letter
                        if (arrayAlphabet[currentLetter] != 'A'){
                            currentLetter--;
                            FMOD_System_PlaySound(pFSys, soMove, 0, 0, NULL);
                        } else {
                            FMOD_System_PlaySound(pFSys, soMove, 0, 0, NULL);
                            currentLetter = sizeAlphabet - 1;
                        }
                        break;
                    case SDLK_b:
                        // wipe off the the last letter in playerName
                        if (currentPlayerNameLetter > 0){
                            currentPlayerNameLetter--;
                            playerName[currentPlayerNameLetter] = '_';
                        } else if (currentPlayerNameLetter == 0){
                            playerName[currentPlayerNameLetter] = '_';
                        }
                        break;
                    case SDLK_v:
                        // select the current letter and put them in playerName
                        if(playerName[currentPlayerNameLetter] != '\0'){
                            playerName[currentPlayerNameLetter] = arrayAlphabet[currentLetter];
                            currentPlayerNameLetter++;
                            FMOD_System_PlaySound(pFSys, soSelect, 0, 0, NULL);
                        }
                        break;
                    case SDLK_RETURN:
                        // if player name is empty we put player1 for name
                        // and remove all _
                        if(playerName[0] == '_'){
                            for(int i = 0; i < 10; i++){
                                playerName[i] = '\0';
                            }
                            strcpy(playerName, "player1");
                        } else{
                            // we finalize the playerName variable with the name enter by the user
                            while (playerName[currentPlayerNameLetter] != '\0'){
                                playerName[currentPlayerNameLetter] = '\0';
                                currentPlayerNameLetter++;
                            }
                        }
                        stayIn = 0;
                        break;
                }
                break;
        }
        // create and blit surface
        cleanWindow(pRootWin);
        SDL_BlitSurface(psOverlay, NULL, pRootWin, &overlayPos);

        // create letter surface

        for(int i = 0; i < sizeAlphabet; i++){

            if (i == currentLetter){
                //sprintf(alphabetLetter, "%c", arrayAlphabet[i]);
                psLetter[i] = TTF_RenderUTF8_Shaded(font, &arrayAlphabet[i], txtBlack, whiteBg);
            } else{

                //sprintf(alphabetLetter, "%c", arrayAlphabet[i]);
                psLetter[i] = TTF_RenderUTF8_Shaded(font, &arrayAlphabet[i], txtBlack, greenBg);
            }
            if(i == 0){
                letterPos.x = 250;
                letterPos.y = 350;
                SDL_BlitSurface(psLetter[i], NULL, pRootWin, &letterPos);
            } else{
                letterPos.x = letterPos.x + 25;
                SDL_BlitSurface(psLetter[i], NULL, pRootWin, &letterPos);
            }
        }

        psName = TTF_RenderUTF8_Shaded(font, playerName, txtBlack, greenBg);
        namePos.x = (u_int16_t) (pRootWin->w / 2 - psName->w / 2);
        namePos.y = (u_int16_t) 400;
        SDL_BlitSurface(psName, NULL, pRootWin, &namePos);
        SDL_Flip(pRootWin);
    }

    // free memory
    for (int i = 0; i < sizeAlphabet; i++){
        SDL_FreeSurface(psLetter[i]);
    }
    free(psLetter);
    SDL_FreeSurface(psOverlay);
    SDL_FreeSurface(psName);
    TTF_CloseFont(font);
    FMOD_Sound_Release(soMove);
    FMOD_Sound_Release(soSelect);


}


/**
 * DEPRECIED
 * Loading and display the loading page to show what level we will play .
 * @param pRootWin SDL_Surface A pointer to the main window .
 * @param level int An flag to tell what image we need to load .
 */
void displayLoadingScreen(SDL_Surface *pRootWin, int level){
    // variable
    SDL_Surface *psOverlay = NULL, *psLevelImg = NULL;
    SDL_Rect overlayPos, levelImgPos;
    SDL_Event event;

    int stayIn = 1, backTime = 0, currentTime = 0, timer = 0;
    char overlayPath[MEDIUM_ARRAY] = IMG_DIVERS_PATH, levelPath[MEDIUM_ARRAY] = IMG_LEVELS_MINI_PATH;

    // load overlay
    psOverlay = IMG_Load(strcat(overlayPath, "loading.png"));
    checkPointer(psOverlay, "Can't load overlay image in displayLoadingScreen");

    // load levelImg , we use the parameter "level" to tell what image we need to load
    switch (level){
        case 1:
            psLevelImg = IMG_Load(strcat(levelPath, "castle_mini.png"));
            break;
        case 2:
            psLevelImg = IMG_Load(strcat(levelPath, "ville_mini.png"));
            break;
        case 3:
            psLevelImg = IMG_Load(strcat(levelPath, "city_mini.png"));
            break;
        case 4:
            psLevelImg = IMG_Load(strcat(levelPath, "forest_mini.png"));
            break;
    }
    checkPointer(psLevelImg, "Can't load level mini image in displayLoadingScreen");

    overlayPos.x = 0;
    overlayPos.y = 0;

    levelImgPos.x = (u_int16_t) (pRootWin->w / 2 - psLevelImg->w / 2);
    levelImgPos.y = (u_int16_t) (pRootWin->h / 2 - psLevelImg->h / 2);

    // event while
    while (stayIn){
        SDL_PollEvent(&event);
        switch (event.type){
            case SDL_QUIT:
                SDL_FreeSurface(psOverlay);
                SDL_FreeSurface(psLevelImg);
                SDL_Quit();
                exit(EXIT_SUCCESS);
        }

        currentTime = SDL_GetTicks();
        // if 1 sec is passed
        if(currentTime - backTime >= 1000){
            timer++;
            backTime = currentTime;
        }

        cleanWindow(pRootWin);
        SDL_BlitSurface(psOverlay, NULL, pRootWin, &overlayPos);
        SDL_BlitSurface(psLevelImg, NULL, pRootWin, &levelImgPos);
        SDL_Flip(pRootWin);

        if(timer == 10){
            stayIn = 0;
        }

    }

    SDL_FreeSurface(psOverlay);
    SDL_FreeSurface(psLevelImg);
}














