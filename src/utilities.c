/**
 * file with utilities function
 *
 * function :
 *  myPause() => this function pause the program .
 */

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <dirent.h>


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


/**
 * Clean the main window with SDL_FillRect function .
 * @param pRootWin SDL_Surface A pointer to the main window .
 */
void cleanWindow(SDL_Surface *pRootWin){
    SDL_FillRect(pRootWin, NULL, SDL_MapRGB(pRootWin->format, 255, 255, 255));
}


/**
 * Count the number of file found in a directory passed in parameter .
 * @param dirPath char A path where search .
 * @param fExt char An flag who tell the extention we looking for . 0 for all file
 * @return int nbFile The number of file found .
 */
int getNbFileInDir(char dirPath[], char fExt[]){
    int nbFile = 0;
    DIR *rep = NULL;
    struct dirent *fileRead = NULL;
    rep = opendir(dirPath);
    if(rep == NULL){
        fprintf(stderr, "Can't open directory in getNbFileIndir");
        exit(EXIT_FAILURE);
    }
    // dir open
    if(fExt == 0){
        while((fileRead = readdir(rep)) != NULL){
            // exculde the hide file
            if(strcmp(fileRead->d_name, ".") != 0 && strcmp(fileRead->d_name, "..") != 0){
                nbFile++;
            }
        }
    } else{
        while((fileRead = readdir(rep)) != NULL){
            if(strstr(fileRead->d_name, fExt) != NULL){
                nbFile++;
            }
        }
    }
    // close dir
    closedir(rep);
    // return the number of file found .
    return nbFile;

}

/**
 * Clean the string passed in parameter .
 * @param string char The string .
 * @param size int The size of the string .
 */
void cleanString(char string[], int size){
    for(int i = 0; i < size; i++){
        string[i] = '\0';
    }
}


/**
 * Create a birdPath .
 * @param ret char The string where put the path
 * @param birdPath char The path to use at start .
 * @param num int The number corresponding to the image number .
 */
void createBirdPath(char ret[], char birdPath[], int num){

    char birdName[] = "angry_bird0", nb[2] = "", ext[] = ".png";
    sprintf(nb, "%d", num);
    strcpy(ret, birdPath);
    strcat(ret, birdName);
    strcat(ret, nb);
    strcat(ret, ext);
}