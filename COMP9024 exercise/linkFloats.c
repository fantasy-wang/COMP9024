//
// Created by 56915 on 2019/7/25.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 10.0

typedef struct node {
    float ship;
    struct node *next;
} List;

void print(*start){
    if (start != NULL){
        List *p;
        p = start;
        while(p != NULL){
            printf("%.1f", p->ship);
            p = p->next;
        }
        putchar('\n');
    }
    return ;
}

int main(void){
    List *first = NULL;
    List *previous = NULL;
    List *n;

    for (float f=0.0; f<=MAX; f++){
        n = malloc(sizeof(struct node));
        if (n == NULL){
            fprintf(stderr, "Out of memory\n");
        }
        n->ship = f;
        n->next = NULL;

        if (first == NULL){
            first = n;
        } else {
            previous->next = n;
        }
        previous = n;
    }
    print(first);

    n = first;
    while (n != NULL){
        List *tmp = n->next;
        free(n);
        n = tmp;
    }
    first = NULL;
    previous = NULL;
    n = NULL;
    return EXIT_SUCCESS;
}