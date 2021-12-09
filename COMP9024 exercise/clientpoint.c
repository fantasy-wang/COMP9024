//
// Created by 56915 on 2019/7/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main(int argc, char *argv[]){
    Point r, s;
    float d;

    r.x = 5;
    r.y = 5;
    s.x = 4;
    s.y = 6;
    d = distance(r, s);
    printf("1st distance: %0.1f\n", d);
    move(&r, -1, 2);
    printf("r.x: %f, r.y: %f\n", r.x, r.y);
    d = distance(r, s);
    printf("2nd distance: %0.1f\n", d);
    return EXIT_SUCCESS;
}
