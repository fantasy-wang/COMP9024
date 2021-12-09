//
// Created by 56915 on 2019/7/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pointADT.h"

struct point{
    float x;
    float y;
};

Point creat(float xpos, float ypos){
    Point p;
    p = malloc(sizeof(struct point));
    if (p == NULL){
        fprintf(stderr, "No memory\n");
        exit(1);
    }
    p->x = xpos;
    p->y = ypos;

    return p;
}

float distance(Point a, Point b){
    float dx = a->x-b->x;
    float dy = a->y-b->y;

    return sqrt(dx*dx + dy*dy);
}

void move(Point a, float dx, float dy){
    a->x += dx;
    a->y += dy;
}