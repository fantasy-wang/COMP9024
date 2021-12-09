//
// Created by 56915 on 2019/7/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "quack.h"

int main(int argc, char *argv[]){
    Quack q = NULL;

    int n,m;
    if (argc != 3 || sscanf(argv[1], "%d", &n)!=1 || sscanf(argv[2], "%d", &m)!=1){
        fprintf(stderr, "Usage: %s total eliminate\n", argv[0]);
        return EXIT_FAILURE;
    }
    q = createQuack();
    for (int i=1; i<=n; i++){
        qush(i, q);
    }
    showQuack(q);
    int person = 0;
    while (!isEmptyQuack(q)){
        for (int i=0; i<m-1; i++){
            qush(pop(q), q);
        }
        person = pop(q);
        if (!isEmptyQuack(q)){
            printf("byebye %d\n", person);
        }
    }
    printf("%d is only person left\n", person);
    return EXIT_SUCCESS;
}