/**
 * file with utilities function
 *
 * function :
 *  myPause() => this function pause the program .
 *  void checkPointer(void *pointer, char message[]) => check if the pointer is null
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

#endif //SHOOT_ME_UTILITIES_H
