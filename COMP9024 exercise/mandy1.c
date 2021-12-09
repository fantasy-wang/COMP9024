//
// Created by 56915 on 2019/7/25.
//
#include <stdio.h>
#include <stdlib.h>

struct somedata{
    int age;
    float weight;
    char gender;
};

int main(void){
    struct somedata *p;

    //p = &mandy;
    p = malloc(sizeof(struct somedata));
    if (p == NULL){
        fprintf(stderr, "p is not initialised\n");
        return EXIT_FAILURE;
    }
    p->age = 21;
    p->weight = 65.5;
    p->gender = 'f';
    printf("%d %.2f %c", p->age, p->weight, p->gender);
    return EXIT_SUCCESS;
}
