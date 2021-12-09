//
// Created by 56915 on 2019/7/25.
//

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int number;
    if (scanf("%d", &number)==1){
        int *dynamica;
        dynamica = malloc(number * sizeof(int));
        if (dynamica == NULL){
            fprintf(stderr, "Run out of memory .. must die\n");
            return EXIT_FAILURE;
        }
        printf("I am now going to read %d numbers\n", number);
        int *d;
        for (d = dynamica; d < dynamica+number; d++){
            if (scanf("%d", d)==1){
                printf("yeh, I've read %d\n", *d);
            }
        }
        free(dynamica);
    }
    return EXIT_SUCCESS;
}