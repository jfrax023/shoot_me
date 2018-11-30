/**
 * this file is an helper to help us for create or manage the target for the game .
 */

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "define.h"
#include "utilities.h"


/**
 * Initialize the TargetList with the first elment of the chained list .
 * @param imgPathLeft char The path where found the image for the element variable .
 * @param imgPathRight char The path where found the image for the element variable .
 * @return TargetList The chained list .
 */
TargetList *targetInitialize(char leftImgPath[MEDIUM_ARRAY], char rightImgPath[MEDIUM_ARRAY]){
    // create element
    TargetList *targetList = malloc(sizeof(*targetList));
    TargetElement *targetElement = malloc(sizeof(*targetElement));

    if(targetList == NULL || targetElement == NULL){
        fprintf(stderr, "Can't initialize TargetList");
        exit(EXIT_FAILURE);
    }

    // set the variable psTargetImage with the path passed in parameter .
    targetElement->psTargetImageLeft = IMG_Load(leftImgPath);
    if(targetElement->psTargetImageLeft == NULL){
        fprintf(stderr, "Can't load image in psTargetImageLeft (initialize)");
    }
    targetElement->psTargetImageRight = IMG_Load(rightImgPath);
    if(targetElement->psTargetImageRight == NULL){
        fprintf(stderr, "Can't load image in psTargetImageRight (initialize)");
    }
    // set next, first and nbImages .
    targetElement->next = NULL;
    targetList->first = targetElement;
    targetList->nbImages = 1;

    return targetList;
}


/**
 * Add a new element to the TargetList .
 * @param list TargetList The chained list .
 * @param imgPathLeft char The path where found the image for a element variable .
 * @param imgPathRight char The path where found the image for a element variable .
 */
void targetInsert(TargetList *list, char leftImgPath[MEDIUM_ARRAY], char rightImgPath[MEDIUM_ARRAY]){

    TargetElement *tmpElement = list->first;

    // create element
    TargetElement *targetElement = malloc(sizeof(*targetElement));
    if(list == NULL || targetElement == NULL){
        fprintf(stderr, "Can't create new element in targetInsert");
        exit(EXIT_FAILURE);
    }

    targetElement->psTargetImageLeft = IMG_Load(leftImgPath);
    if(targetElement->psTargetImageLeft == NULL){
        fprintf(stderr, "Can't load image in psTargetImage (insert)");
        exit(EXIT_FAILURE);
    }

    targetElement->psTargetImageRight = IMG_Load(rightImgPath);
    if(targetElement->psTargetImageRight == NULL){
        fprintf(stderr, "Can't load image in psTargetImageRight (initialize)");
    }



    do {
        if(tmpElement->next == NULL){
            // last element
            tmpElement->next = targetElement;
            targetElement->next = NULL;
        }
        tmpElement = tmpElement->next;


    }while (tmpElement != NULL);

    list->nbImages++;
}

/**
 * Remove all element of TargetList .
 * @param list TargetList The chained list .
 */
void targetDestroy(TargetList *list){
    // delete the first element
    while(list->first != NULL){
        TargetElement *toDeleteElement = list->first;
        list->first = toDeleteElement->next;
        SDL_FreeSurface(toDeleteElement->psTargetImageRight);
        SDL_FreeSurface(toDeleteElement->psTargetImageLeft);
        free(toDeleteElement);
    }
    free(list);

}


/**
 * Initialize the target structure with data for one target .
 * @param target Target The target structure where add the data .
 * @param nbTarget int The number of image the target have .
 * @param leftPath char The left path where found the image .
 * @param rightPath char The right path where found the image .
 */
void initTarget(Target *target, int nbTarget, char leftPath[MEDIUM_ARRAY], char rightPath[MEDIUM_ARRAY]){
    char birdPathLeft[MEDIUM_ARRAY] = "", birdPathRight[MEDIUM_ARRAY] = "";

    for(int i = 0; i < nbTarget; i++){
        // we create the bird path corresponding to where we can found the image
        createBirdPath(birdPathLeft, leftPath, i);
        createBirdPath(birdPathRight, rightPath, i);
        if(i == 0){
            // we need to initialize the chained list
            target->list = targetInitialize(birdPathLeft, birdPathRight);
            cleanString(birdPathLeft, MEDIUM_ARRAY);
            cleanString(birdPathRight, MEDIUM_ARRAY);
        } else{
            targetInsert(target->list, birdPathLeft, birdPathRight);
            cleanString(birdPathLeft, MEDIUM_ARRAY);
            cleanString(birdPathRight, MEDIUM_ARRAY);
        }

    }
}


/**
 * Create the chained list TargetList with the correct data based on the parameter birdId .
 * @param list TargetList A pointer to the chained list .
 * @param birdId int A flag to tell what bird we need to load .
 */
void createTargetList(Target *target, int birdId){

    int nbTargetImg = 0;

    switch (birdId){
        case RED_BIRD_ID:
            //load red bird
            nbTargetImg = getNbFileInDir(RED_BIRD_LEFT_PATH, 0);
            target->birdId = RED_BIRD_ID;
            initTarget(target, nbTargetImg, RED_BIRD_LEFT_PATH, RED_BIRD_RIGHT_PATH);
            break;
        case DRAGON_ID:
            nbTargetImg = getNbFileInDir(DRAGON_LEFT_PATH, 0);
            target->birdId = DRAGON_ID;
            initTarget(target, nbTargetImg, DRAGON_LEFT_PATH, DRAGON_RIGHT_PATH);
            break;
        case GREY_BIRD_ID:
            nbTargetImg = getNbFileInDir(GREY_BIRD_LEFT_PATH, 0);
            target->birdId = GREY_BIRD_ID;
            initTarget(target, nbTargetImg, GREY_BIRD_LEFT_PATH, GREY_BIRD_RIGHT_PATH);
            break;
        case PURPLE_BIRD_ID:
            nbTargetImg = getNbFileInDir(PURPLE_BIRD_LEFT_PATH, 0);
            target->birdId = PURPLE_BIRD_ID;
            initTarget(target, nbTargetImg, PURPLE_BIRD_LEFT_PATH, PURPLE_BIRD_RIGHT_PATH);
            break;
        case SMALL_RED_BIRD_ID:
            nbTargetImg = getNbFileInDir(SMALL_RED_BIRD_LEFT_PATH, 0);
            target->birdId = SMALL_RED_BIRD_ID;
            initTarget(target, nbTargetImg, SMALL_RED_BIRD_LEFT_PATH, SMALL_RED_BIRD_RIGHT_PATH);
            break;
        case BLUE_BIRD_ID:
            nbTargetImg = getNbFileInDir(BLUE_BIRD_LEFT_PATH, 0);
            target->birdId = BLUE_BIRD_ID;
            initTarget(target, nbTargetImg, BLUE_BIRD_LEFT_PATH, BLUE_BIRD_RIGHT_PATH);
            break;
    }
}





























