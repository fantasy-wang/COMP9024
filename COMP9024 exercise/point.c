#include "point.h"


float distance(Point a, Point b){
    float dx = a.x-b.x;
    float dy = a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

void move(Point *a, float dx, float dy){
    a->x += dx;
    a->y += dy;
}
