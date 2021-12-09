//
// Created by 56915 on 2019/8/7.
//

#ifndef INC_9024_EXERCISE_QUACK_H
#define INC_9024_EXERCISE_QUACK_H
// Quack.h: an interface definition for a queue/stack
#include <stdio.h>
#include <stdlib.h>

typedef struct node *Quack;

Quack createQuack(void);    // create and return Quack
Quack destroyQuack(Quack);  // remove the Quack
void  push(int, Quack);     // put int on the top of the quack
void  qush(int, Quack);     // put int at the bottom of the quack
int   pop(Quack);           // pop and return the top element on the quack
int   isEmptyQuack(Quack);  // return 1 is Quack is empty, else 0
void  makeEmptyQuack(Quack);// remove all the elements on Quack
void  showQuack(Quack);     // print the contents of Quack, from the top down


#endif //INC_9024_EXERCISE_QUACK_H
