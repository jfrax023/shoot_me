/**
 * this file is an helper to help us for create or manage the target for the game .
 *
 * function :
 *
 * TargetList *targetInitialize(char leftImgPath[100], char rightImgPath[100]) => initialize the TargetList .
 * void targetInsert(TargetList *list, char leftImgPath[100], char rightImgPath[100]) => add a new element to TargetList .
 * void targetDestroy(TargetList *list); => delete all element of TargetList .
 * void createTargetList(TargetList *list, int birdId) => create a chained list with the correct data .
 * void initTarget(Target *target, int nbTarget, char leftPath[MEDIUM_ARRAY], char rightPath[MEDIUM_ARRAY]) => initialize
 *    the target structure .
 */

#ifndef SHOOT_ME_TARGET_HELPER_H
#define SHOOT_ME_TARGET_HELPER_H

#include "define.h"

/**
 * Initialize the TargetList with the first elment of the chained list .
 * @param leftImgPath char The path where found the image for the element variable .
 * @param rightImgPath char The path where found the image for the element variable .
 * @return TargetList The chained list .
 */
TargetList *targetInitialize(char leftImgPath[MEDIUM_ARRAY], char rightImgPath[MEDIUM_ARRAY]);


/**
 * Add a new element to the TargetList .
 * @param list TargetList The chained list .
 * @param imgPathLeft char The path where found the image for a element variable .
 * @param imgPathRight char The path where found the image for a element variable .
 */
void targetInsert(TargetList *list, char leftImgPath[MEDIUM_ARRAY], char rightImgPath[MEDIUM_ARRAY]);


/**
 * Remove all element of TargetList .
 * @param list TargetList The chained list .
 */
void targetDestroy(TargetList *list);


/**
 * Create the chained list TargetList with the correct data based on the parameter birdId .
 * @param list TargetList A pointer to the chained list .
 * @param birdId int A flag to tell what bird we need to load .
 */
void createTargetList(Target *target, int birdId);


/**
 * Initialize the target structure with data for one target .
 * @param target Target The target structure where add the data .
 * @param nbTarget int The number of image the target have .
 * @param leftPath char The left path where found the image .
 * @param rightPath char The right path where found the image .
 */
void initTarget(Target *target, int nbTarget, char leftPath[MEDIUM_ARRAY], char rightPath[MEDIUM_ARRAY]);

#endif //SHOOT_ME_TARGET_HELPER_H
