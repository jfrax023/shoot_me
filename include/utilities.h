/**
 * file with utilities function
 *
 * function :
 *  myPause() => this function pause the program .
 *  void checkPointer(void *pointer, char message[]) => check if the pointer is null
 *  void initPlayerName(char playerName[]) => initialize the player name with _ .
 */

#ifndef SHOOT_ME_UTILITIES_H
#define SHOOT_ME_UTILITIES_H

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

#endif //SHOOT_ME_UTILITIES_H
