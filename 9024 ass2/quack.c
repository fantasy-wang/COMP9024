#include "quack.h"

#define HEIGHT 1000

struct node{
    int array[HEIGHT];
    int top;
};

Quack createQuack(void){
    Quack qs;
    qs = malloc(sizeof(struct node));
    if (qs == NULL){
        fprintf(stderr, "createQuack: no memory, aborting\n");
        exit(1);
    }
    qs->top=-1;
    return qs;
}

void push(int data, Quack qs){
    if (qs == NULL){
        fprintf(stderr, "push: Qauck not initialised\n");
    }else {
        if (qs->top>=HEIGHT-1){
            fprintf(stderr, "push: quack overflow\n");
        }else{
            ++qs->top;
            qs->array[qs->top]=data;
        }
    }
    return ;
}

void qush(int data, Quack que){
    if (que == NULL){
        fprintf(stderr, "qush: Quack not initialised\n");
        return ;
    } else{
        if (que->top==HEIGHT-1){
            fprintf(stderr, "qush: quack overflow\n");
            return ;
        }else{
            ++que->top;
            for (int i=que->top; i>=1; i--){
                que->array[que->top]=que->array[que->top-1];
            }
            que->array[0]=data;
        }
    }
    return ;
}

int pop(Quack qs){
    int data=0;
    if (qs == NULL){
        fprintf(stderr, "pop: quack not initialised\n");
    }else{
        if(isEmptyQuack(qs)){
            fprintf(stderr, "pop: quack underflow\n");
        }else{
//            printf("top = %d   topItem = %d\n", qs->top, qs->array[qs->top]);
            data=qs->array[qs->top];
            --qs->top;
        }
    }
    return data;
}

void makeEmptyQuack(Quack qs){
    if (qs == NULL){
        fprintf(stderr, "makeEmptyQuack: quack not initialised\n");
    }else{
        while(!isEmptyQuack(qs)){
            pop(qs);
        }
    }
    return ;
}

Quack destroyQuack(Quack qs){
    if (qs == NULL){
        fprintf(stderr, "destroyQuack: quack not initialised\n");
    }
    free(qs);
    return qs;
}

int isEmptyQuack(Quack qs){
    int empty=0;
    if (qs == NULL){
        fprintf(stderr, "isEmptyQuack: quack not initialised\n");
    }else{
        empty = qs->top<0;
    }
    return empty;
}

void showQuack(Quack qs){
    if (qs == NULL){
        fprintf(stderr, "showQuack: quack not initialised\n");
    } else{
        printf("Quack: ");
        if (qs->top < 0){
            printf("<< >>\n");
        } else{
            int i;
            printf("<<");
            for (i=qs->top; i>0; i++){
                printf("%d ", qs->array[i]);
            }
            printf("%d>>\n", qs->array[0]);
        }
    }
    return ;
}