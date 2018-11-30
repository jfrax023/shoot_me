/**
 * this file define some function for display different menu
 *
 * function :
 *  void displayAccueil(SDL_Surface *pRootWin, FMOD_SYSTEM *pFSys) => display the accueil image .
 * void displayNameSelection(SDL_Surface *pRootWin, FMOD_SYSTEM *pFSys, char playerName[]) => display the name selection menu .
 * void displayLoadingScreen(SDL_Surface *pRootWin, int level) => display the loading page .
 */

#ifndef SHOOT_ME_WINDOW_H
#define SHOOT_ME_WINDOW_H

#include <SDL/SDL.h>
#include <fmod/fmod.h>

/**
 * Display accueil image and play a music
 * @param pRootWin SDL_Surface The main window
 * @param pFSys FMOD_SYSTEM the system variable for fmod
 */
void displayAccueil(SDL_Surface *pRootWin, FMOD_SYSTEM *pFSys);


/**
 * Display the name selection menu .It allow to choose a name for the player by using an alphabet .
 * @param pRootWin SDL_Surface A pointer to the main window .
 * @param pFSys FMOD_SYSTEM A variable system for fmod
 * @param playerName char A variable where put the player name .
 */
void displayNameSelection(SDL_Surface *pRootWin, FMOD_SYSTEM *pFSys, char playerName[]);


void displayLoadingScreen(SDL_Surface *pRootWin, int level);
#endif //SHOOT_ME_WINDOW_H
