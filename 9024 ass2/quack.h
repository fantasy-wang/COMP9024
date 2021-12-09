//
// Created by 56915 on 2019/7/3.
//

#ifndef INC_9024_EXERCISE_QUACK_H
#define INC_9024_EXERCISE_QUACK_H

#include <stdio.h>
#include <stdlib.h>


typedef struct node *Quack;

Quack createQuack(void);
Quack destroyQuack(Quack);
void push(int, Quack);
void qush(int, Quack);
int pop(Quack);
int isEmptyQuack(Quack);
void makeEmptyQuack(Quack);
void showQuack(Quack);

#endif //INC_9024_EXERCISE_QUACK_H
