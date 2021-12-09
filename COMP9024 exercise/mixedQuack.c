//
// Created by 56915 on 2019/7/24.
//
#include <stdio.h>
#include "quack.h"

int main(void){
    Quack s = NULL;

    s = createQuack();

    printf("push 1 and 2\n");
    push(1, s);
    push(2, s);

    printf("qush 3 and 4\n");
    qush(3, s);
    qush(4, s);

    showQuack(s);
    printf("pop produces %d\n", pop(s));
    printf("pop produces %d\n", pop(s));
    printf("pop produces %d\n", pop(s));
    printf("pop produces %d\n", pop(s));
    return EXIT_SUCCESS;
}
