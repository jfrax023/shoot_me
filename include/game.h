/**
 * define fonction to manage the game .
 *
 * function :
 *
*/

#ifndef SHOOT_ME_GAME_H
#define SHOOT_ME_GAME_H

#include <SDL/SDL.h>
#include <fmod/fmod.h>


void loadingGame(SDL_Surface *pRootWin, Target target[], int level, int loadTarget);

#endif //SHOOT_ME_GAME_H
