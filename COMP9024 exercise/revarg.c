//
// Created by 56915 on 2019/7/27.
//

#include <stdio.h>
#include <stdlib.h>
#include "quack.h"

int main(int argc, char *argv[]){
    Quack s = NULL;

    if (argv >= 2){
        char *input = argv[1];
        s = createQuack();
        while (input != NULL){
            push(input, s);
            input++;
        }
        while (!isEmptyQuack(s)){
            printf("%c", pop(s));
        }
        putchar('\n');
    }
    return EXIT_SUCCESS;
}