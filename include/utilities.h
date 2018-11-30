/**
 * file with utilities function
 *
 * function :
 *  myPause() => this function pause the program .
 *  void checkPointer(void *pointer, char message[]) => check if the pointer is null
 *  void initPlayerName(char playerName[]) => initialize the player name with _ .
 *  void createArrayAlphabet(char arrayAlphabet[], char alphabet[]) => create an array with the alphabet string .
 *  void cleanWindow(SDL_Surface *pRootWin) => clean the main window .
 *  int getNbFileInDir(char dirPath[], char fExt[]) => count the number of file found in one directory .
 *  void cleanString(char string[], int size) => clean the string passed in parameter .
 *  void createBirdPath(char ret[], char birdPath[], int num) => create the birdPath string .
 */

#ifndef SHOOT_ME_UTILITIES_H
#define SHOOT_ME_UTILITIES_H

#include <SDL/SDL.h>

/**
 * pause the program and wait
 */
void myPause();


/**
 * Check if the pointer passed in parameter is null and raise an error if is null .
 * @param pointer void The pointer to check .
 * @param message char The message to display .
 */
void checkPointer(void *pointer, char message[]);


/**
 * Initialize the player name with _ .
 * @param playerName char the variable where the player name is store .
 */
void initPlayerName(char playerName[]);


/**
 * Create an array based on the alphabet passed in parameter .
 * @param arrayAlphabet char An array where put the alphabet .
 * @param alphabet char The alphabet string .
 */
void createArrayAlphabet(char arrayAlphabet[], char alphabet[]);


/**
 * Clean the main window with SDL_FillRect function .
 * @param pRootWin SDL_Surface A pointer to the main window .
 */
void cleanWindow(SDL_Surface *pRootWin);


/**
 * Count the number of file found in a directory passed in parameter .
 * @param dirPath char A path where search .
 * @param fExt char An flag who tell the extention we looking for . 0 for all file
 * @return int nbFile The number of file found .
 */
int getNbFileInDir(char dirPath[], char fExt[]);


/**
 * Clean the string passed in parameter .
 * @param string char The string .
 * @param size int The size of the string .
 */
void cleanString(char string[], int size);


/**
 * Create a birdPath .
 * @param ret char The string where put the path
 * @param birdPath char The path to use at start .
 * @param num int The number corresponding to the image number .
 */
void createBirdPath(char ret[], char birdPath[], int num);


#endif //SHOOT_ME_UTILITIES_H
