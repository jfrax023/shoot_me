/**
 * file with utilities function
 *
 * function :
 *  myPause() => this function pause the program .
 */

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>


/**
 * pause the program and wait
 */
void myPause(){
    int stayIn = 1;
    SDL_Event event;

    while (stayIn){
        SDL_WaitEvent(&event);
        switch (event.type){
            case SDL_QUIT:
                stayIn = 0;
                break;
        }
    }
}

/**
 * Check if the pointer passed in parameter is null and raise an error if is null .
 * @param pointer void The pointer to check .
 * @param message char The message to display .
 */
void checkPointer(void *pointer, char message[]){
    if (pointer == NULL){
        fprintf(stderr, "%s\n", message);
        exit(EXIT_FAILURE);
    }
}

/**
 * Initialize the player name with _ .
 * @param playerName char the variable where the player name is store .
 */
void initPlayerName(char playerName[]){
    for(int i = 0; i < 10; i++){
        if(i == 9){
            playerName[i] = '\0';
        } else{
            playerName[i] = '_';
        }
    }
}


/**
 * Create an array based on the alphabet passed in parameter .
 * @param arrayAlphabet char An array where put the alphabet .
 * @param alphabet char The alphabet string .
 */
void createArrayAlphabet(char arrayAlphabet[], char alphabet[]){
    int i = 0;
    while (alphabet[i] != '\0'){
        sprintf(&arrayAlphabet[i], "%c", alphabet[i]);
        //arrayAlphabet[i] = alphabet[i];
        i++;
    }
}