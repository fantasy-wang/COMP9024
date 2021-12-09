

//
// Created by zhuoran wang on 2019/7/30.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "quack.h"
#include "graph.h"
#include <ctype.h>

#define NODES 1000
#define LENGTH_OF_WORD 21
#define START 0


bool differByOne(char *one, char *two){
    int length_of_one = 0;
    int length_of_two = 0;
    while (*(one+length_of_one) != '\0'){
        length_of_one++;
    }
    while (*(two+length_of_two) != '\0'){
        length_of_two++;
    }
    // if the gap more than 2, return false
    if (abs(length_of_one-length_of_two)>1){
        return false;
    }
    // if gap is 0 , compare every element
    if (abs(length_of_one==length_of_two)){
        int difference=0;
        int i=0;
        while (i < length_of_one){
            if (*(one+i)!=*(two+i)){
                difference++;
            }
            i++;
        }
        if (difference>1){
            return false;
        }
        return true;
    }
    // if gap is 1, if the first is not same , compare the next
    if (abs(length_of_one-length_of_two)==1){
        char *longer;
        char *shorter;
        int j=0;
        int difference=0;
        if (length_of_one-length_of_two==1){
            longer = one;
            shorter = two;
            j=length_of_one;
        } else{
            longer = two;
            shorter = one;
            j=length_of_two;
        }
        if (*longer==*shorter){
            for (int i=0; i<j; i++){
                if (*(longer+i)!=*(shorter+i)){
                    shorter--;
                    difference++;
                    if (difference>1){
                        return false;
                    }
                }
            }
        } else{
            difference++;
            for (int m=0; m<j-1; m++){
                if (*(longer+m+1)!=*(shorter+m)){
                    difference++;
                }
            }
        }
        if (difference>1){
            return false;
        }
        return true;
    }
}

//void phase2(char **words, int count_of_word){
//
//}

//void def_array(int array[], int length){
//    for (int i=0; i<length; i++){
//        array[i]=-1;
//    }
//}

Quack dfs(Graph g, int start, int numV, int *depth, int *max_length, Quack stack, Quack temp, Quack result_que){
    push(start, stack);
    for (int i=0; i<numV; i++){
        if (isEdge(newEdge(start, i), g) && i>start){
            *depth=*depth+1;
            dfs(g, i, numV, depth, max_length, stack, temp, result_que);
        } else{
            if (i<numV-1){
                continue;
            } else{
                if (*depth>*max_length){
                    *max_length=*depth;
                    makeEmptyQuack(result_que);
                    while (!isEmptyQuack(stack)){
                        int temp1 = pop(stack);
                        push(temp1, temp);
                        push(temp1, result_que);
                    }
                    while (!isEmptyQuack(temp)){
                        push(pop(temp), stack);
                    }
                } else{
                    if (*depth==*max_length){
                        while (!isEmptyQuack(stack)){
                            int temp1 = pop(stack);
                            push(temp1, temp);
                            push(temp1, result_que);
                        }
                        while (!isEmptyQuack(temp)){
                            push(pop(temp), stack);
                        }
                    }
                }
            }
            pop(stack);
        }
    }
    *depth=*depth-1;
    return result_que;
}

//void dfs(Graph g, int start, int numV, int *depth, int *max_length, int *n, int **stack){
//    stack[*n][*depth] = start;
//    for (int i=0; i<numV; i++){
//        if (isEdge(newEdge(start, i), g) && i>start){
//            *depth = *depth+1;
//            dfs(g, i, numV, depth, max_length, n, stack);
//        } else{
//            if (i<numV-1){
//                continue;
//            } else{
//                if (*max_length<=*depth){
//                    *max_length=*depth;
//                }
//                //stack[*n][*depth+1]='\0';
//                *n = *n + 1;
//                for (int nn=0; nn<*n; nn++) {
//                    //int mm = 0;
//                    printf("%d\n",stack[nn][1]);
//                    while (stack[nn][mm] != '\0') {
//                        printf("stack = %d  ", stack[nn][mm]);
//                        mm++;
//                    }
//                }
//                stack[*n] = malloc(NODES * sizeof(int));
//                for (int j=0; j<*depth; j++){
//                    stack[*n][j]=stack[*n-1][j];
//                }
//                for (int nn=0; nn<*n; nn++) {
//                   //int mm = 0;
//                    printf("%d\n",stack[nn][1]);
//                    while (stack[nn][mm] != '\0') {
//                        printf("stack = %d  ", stack[nn][mm]);
//                        mm++;
//                    }
//                }
//
//            }
//        }
//    }
//    *depth=*depth-1;
//    return ;
//}

void phase3(Graph g, int count_of_word, char **words){
//    int visited[count_of_word];
//    def_array(visited, count_of_word);
    int *depth, *max_length;
    depth = malloc(sizeof(int));
    max_length = malloc(sizeof(int));
    *depth = 0;
    *max_length = 0;
//    int **stack;
//    stack = malloc(NODES * sizeof(int *));
//    int *n = malloc(sizeof(int));
//    *n = 0;
//    stack[*n] = malloc(NODES * sizeof(int));
    Quack qs=createQuack();
    Quack temp=createQuack();
    Quack result_que=createQuack();
    result_que = dfs(g, START, count_of_word, depth, max_length, qs, temp, result_que);
    *max_length=*max_length+1;
    printf("Longest ladder length: %d\n", *max_length);
    Quack pre;
    pre = createQuack();
    Quack result;
    result = createQuack();
    while (!isEmptyQuack(result_que)){
        push(pop(result_que), pre);
    }
    int n=1;
    while (!isEmptyQuack(pre)){
        printf("%d: ", n);
        for (int i=0; i<*max_length; i++){
            push(pop(pre), result);
        }
        for (int j=0; j<*max_length-1; j++){
            printf("%s -> ", words[pop(result)]);
        }
        printf("%s\n", words[pop(result)]);
        n++;
    }
//    showQuack(result_que);
//    if (**stack=='\0'){
//        printf("NULL");
//    }
//    int **out;
//    out = malloc(NODES * sizeof(int *));
//    for (int i=0; i<*n; i++){
//        int j=0;
//        while (stack[i][j]!='\0'){
//            printf("%d\n", *(*(stack+i)+j));
//            j++;
//        }
//    }
//    int number_of_out=0;
//    for (int i=0; i<*n; i++){
//        int j=0;
//        printf("%d\n", stack[i][j]);
//        while(stack[i][j]!='\0'){
//            printf("st%d", stack[i][j]);
//            j++;
//        }
//        if (j==*max_length-1){
//            out[number_of_out]=malloc(NODES * sizeof(int));
//            for (int k=0; k<*max_length; k++){
//                printf("stack = %d\n", stack[i][k]);
//                out[number_of_out][k]=stack[i][k];
//            }
//            number_of_out++;
//        }
//    }
//    for (int i=0; i<=number_of_out; i++){
//        for (int j=0; j<*max_length; j++){
//            printf("out = %d", out[i][j]);
//        }
//        putchar('\n');
//    }
}


int main(){
    char *line = malloc(NODES * LENGTH_OF_WORD * sizeof(char));
    fgets(line, NODES * LENGTH_OF_WORD, stdin);

    const char *deli = " \n\t\r";
    char **words = malloc(NODES * sizeof(char *));
    char *p;
    p = strtok(line, deli);
    int count_of_word=0;
    while ((p != NULL)){
        words[count_of_word] = malloc(LENGTH_OF_WORD * sizeof(char));
        int n=0;
        while (*(p+n) != '\0'){
            words[count_of_word][n] = *(p+n);
            n++;
        }
        words[count_of_word][n] = '\0';
        p = strtok(NULL, deli);
        count_of_word++;
    }
    //second question
    printf("Dictionary\n");
    for (int i=0; i<count_of_word; i++){
        printf("%d: %s\n", i, words[i]);
    }
    printf("Ordered Word Ladder Graph\n");
    Graph g = newGraph(count_of_word);
    for (int i=0; i<count_of_word; i++){
        for (int j=0; j<count_of_word && i!=j; j++){
            if (differByOne(words[i], words[j])){
                insertEdge(newEdge(i,j), g);
            }
        }
    }
    showGraph(g);
    //phase2(words, count_of_word);
    //third question
    phase3(g, count_of_word, words);
}

