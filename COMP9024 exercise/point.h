//
// Created by 56915 on 2019/7/21.
//

#ifndef INC_9024_EXERCISE_POINT_H
#define INC_9024_EXERCISE_POINT_H

#include <math.h>

typedef struct point Point;

struct point{
    float x; float y;
};

float distance(Point, Point);

void move(Point *, float, float);

#endif //INC_9024_EXERCISE_POINT_H
