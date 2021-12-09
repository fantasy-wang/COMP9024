////
//// Created by 56915 on 2019/7/26.
////
////#include "quack.h"
//#include "limits.h"
//
//#define MARKERDATA INT_MAX
//
//struct node{
//    int data;
//    struct node *next;
//};
//
//Quack createQuack(void){
//    Quack marker;
//    marker = malloc(sizeof(struct node));
//    if (marker == NULL){
//        fprintf(stderr, "createQuack: no memory, aborting\n");
//        exit(1);
//    }
//    marker->data = MARKERDATA;
//    marker->next = NULL;
//    return marker;
//}
//
//void push(int data, Quack qs){
//    Quack newnode;
//    if (newnode == NULL){
//        fprintf(stderr, "push: quack not initialised\n");
//    }
//    else {
//        newnode = malloc(sizeof(struct node));
//        if (newnode == NULL){
//            fprintf(stderr, "push: no memory, aborting\n");
//            exit(1);
//        }
//        newnode->data = data;
//        newnode->next = qs->next;
//        qs->next = newnode;
//    }
//    return;
//}
//
//void qush(int data, Quack qs){
//
//
//}
//
//int pop(Quack qs){
//    int retval = 0;
//    if (qs == NULL){
//        fprintf(stderr, "pop not initialised\n");
//    }
//    else {
//        if (isEmptyQuack(qs)){
//            fprintf(stderr, "pop: quack underflow\n");
//        }
//        else{
//            Quack topnode = qs->next;
//            retval = topnode->data;
//            qs->next = topnode->next;
//            free(topnode);
//        }
//    }
//    return retval;
//}
//
//Quack destroyQuack(Quack qs){
//    if (qs == NULL){
//        fprintf(stderr, "destroyQuack: quack not initialised\n");
//    }
//    else{
//        Quack ptr = qs->next;
//        while (ptr != NULL){
//            Quack tmp = ptr->next;
//            free(ptr);
//            ptr = tmp;
//        }
//        free(qs);
//    }
//    return NULL;
//}
//
//void makeEmptyQuack(Quack qs){
//    if (qs == NULL){
//        fprintf(stderr, "makeEmptyQuack: quack not initialised\n");
//    } else{
//        while (!isEmptyQuack(qs)){
//            pop(qs);
//        }
//        return;
//    }
//}
//
//int isEmptyQuack(Quack qs){
//    int empty = 0;
//    if (qs == NULL){
//        fprintf(stderr, "isEmptyQuack: quack not initialised\n");
//    }
//    else{
//        empty = qs->next==NULL;
//    }
//    return empty;
//}
//
//void showQuack(Quack qs){
//    if (qs == NULL){
//        fprintf(stderr, "showQuack: quack not initialised\n");
//    }
//    else {
//        printf("Quack: ");
//        if (qs->next == NULL){
//            printf("<< >>\n");
//        }
//        else {
//            printf("<<");
//            qs = qs->next;
//            while (qs->next != NULL){
//                printf("%d, ", qs->data);
//                qs = qs->next;
//            }
//            printf("%d>>", qs->data);
//        }
//    }
//    return;
//}