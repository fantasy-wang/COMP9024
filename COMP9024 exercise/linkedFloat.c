//
// Created by 56915 on 2019/7/25.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} List;


void printList(List *head){
    List *cur;
    for (cur = head; cur != NULL; cur=cur->next){
        printf("%d\n", cur->data);
    }
    return ;
}

void freeList(List *head){
    List *cur;
    cur = head;
    while (tmp != NULL){
        List *tmp;
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    return ;
}

void makeList(int v){
    List *new;
    new = malloc(sizeof(List));
    if (new == NULL){
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    new->data=v;
    new->next=NULL;
    return new;
}

List deleteNode(List *head, List *remn){
    List *pre;

    if (head == NULL){
        return head;
    }

    List *cur;
    cur = head;

    while (cur != remn && cur != NULL){
        pre = cur;
        cur = cur->next;
    }

    if (cur != NULL){
        if (pre == NULL){
            head = cur->next;
        }else{
            pre->next = cur->next;
        }
    }
    free(cur);
    cur = NULL;
    return head;
}