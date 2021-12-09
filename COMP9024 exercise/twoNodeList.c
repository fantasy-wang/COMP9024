//
// Created by 56915 on 2019/7/25.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} List;

int main(void){
    List *l;
    List *m;

    l = malloc(sizeof(List));
    m = malloc(sizeof(List));

    if (l == NULL | m == NULL){
        fprintf(stderr, "Out of memory\n");
        return EXIT_FAILURE;
    }
    printf("enter first integer: ");
    if (scanf("%d", &l->data)==1){
        l->next = m;
    }
    printf("enter second integer: ");
    if (scanf("%d", &m->data)==1){
        m->next=NULL;
        printf("element 1 is %d\n", l->data);
        printf("element 2 is %d\n", l->next->data);
    }
    free(l);
    free(m);
    l = NULL;
    m = NULL;
    return EXIT_SUCCESS;
}