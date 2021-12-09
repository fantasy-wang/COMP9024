//
// Created by 56915 on 2019/7/24.
//
#include <stdio.h>
#include "quack.h"

int main(void){
    Quack s = NULL;
    Quack q = NULL;

    s = createQuack();
    q = createQuack();

    push(1, s);
    push(2, s);
    printf("pop from s produces %d\n", pop(s));
    printf("pop from s produces %d\n", pop(s));

    qush(1, q);
    qush(2, q);
    printf("pop from q produces %d\n", pop(q));
    printf("pop from q produces %d\n", pop(q));

    return EXIT_SUCCESS;
}
