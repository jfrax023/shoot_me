/**
 * some define to help us .
 */

#ifndef SHOOT_ME_DEFINE_H
#define SHOOT_ME_DEFINE_H

#include <SDL/SDL.h>

// main window size
#define ROOT_WINDOW_WIDTH 1450
#define ROOT_WINDOW_HEIGHT 850

// array size
#define SMALL_ARRAY 50
#define MEDIUM_ARRAY 100
#define BIG_ARRAY 1000

// path for images
#define IMG_DIVERS_PATH "img/divers/"
#define IMG_LEVELS_PATH "img/levels/"
#define IMG_LEVELS_MINI_PATH "img/levels/mini/"

// path for fonts
#define FONTS_PATH "fonts/"

// sounds path
#define SOUNDS_PATH "sounds/"
#define MUSIC_PATH "sounds/music/"

// target path
#define RED_BIRD_LEFT_PATH "img/targets/red_bird/left/"
#define RED_BIRD_RIGHT_PATH "img/targets/red_bird/right/"
#define DRAGON_LEFT_PATH "img/targets/dragon/left/"
#define DRAGON_RIGHT_PATH "img/targets/dragon/right/"
#define GREY_BIRD_LEFT_PATH "img/targets/grey_bird/left/"
#define GREY_BIRD_RIGHT_PATH "img/targets/grey_bird/right/"
#define PURPLE_BIRD_LEFT_PATH "img/targets/purple_bird/left/"
#define PURPLE_BIRD_RIGHT_PATH "img/targets/purple_bird/right/"
#define SMALL_RED_BIRD_LEFT_PATH "img/targets/small_red_bird/left/"
#define SMALL_RED_BIRD_RIGHT_PATH "img/targets/small_red_bird/right/"
#define BLUE_BIRD_LEFT_PATH "img/targets/blue_bird/left/"
#define BLUE_BIRD_RIGHT_PATH "img/targets/blue_bird/right/"

// bird id
#define RED_BIRD_ID 0
#define DRAGON_ID 1
#define GREY_BIRD_ID 2
#define PURPLE_BIRD_ID 3
#define SMALL_RED_BIRD_ID 4
#define BLUE_BIRD_ID 5

// nb target
#define NB_TARGET 6

// level number
#define NB_LEVEL 4
// Structure
/**
 * structure to pass data to thread_1 .
 */
typedef struct Thread1Data Thread1Data;
struct Thread1Data{
    int level;
    SDL_Surface *pRootWin;
};

/**
 * Element of the chained list TargetList .
 */
typedef struct TargetElement TargetElement;
struct TargetElement{
    SDL_Surface *psTargetImageLeft;
    SDL_Surface *psTargetImageRight;
    TargetElement *next;
};

/**
 * First element of the chained list TargetList .
 */
typedef struct TargetList TargetList;
struct TargetList{
    int nbImages;
    TargetElement *first;
};


typedef struct Target Target;
struct Target{
    int birdId;
    TargetList *list;
};
#endif //SHOOT_ME_DEFINE_H
