/**
 * this file contain the thread function .
 *
 * function :
 *
 * void *thread_1(void *arg) => thread to display the loading image .
 */

#ifndef SHOOT_ME_THREADING_H
#define SHOOT_ME_THREADING_H


/**
 * This thread display the loading image and wait 10 sec .
 * @param arg void A structure with the data level and pRootWin .
 * @return NULL
 */
void *thread_1(void *arg);

#endif //SHOOT_ME_THREADING_H
