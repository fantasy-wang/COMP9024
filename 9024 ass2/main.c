

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
#define UNVISITED -1


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
    if (length_of_one==length_of_two){
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
    return false;
}

//int defArray(int visited[], int num){
//    for (int i=0; i<num; i++){
//        visited[i]=-1;
//    }
//}

int dfs(Graph g, int start, int numV, int *depth, int *max_length, Quack stack, Quack temp, Quack result_que){
    push(start, stack);
//    visited[start]=*order++;
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

        }
    }
//    visited[start]=UNVISITED;
    *depth=*depth-1;
    pop(stack);
    return *depth;
}

void phase3(Graph g, int count_of_word, char **words) {
    int *depth, *max_length;
    depth = malloc(sizeof(int));
    max_length = malloc(sizeof(int));
    *depth = 0;
    *max_length = 0;
    Quack qs = createQuack();
    Quack temp = createQuack();
    Quack result_que = createQuack();
//    int visit[count_of_word];
//    defArray(visit, count_of_word);
//    int *order;
//    order=malloc(sizeof(int));
//    *order=0;
    for (int i=0; i<count_of_word; i++){
        dfs(g, i, count_of_word, depth, max_length, qs, temp, result_que);
        *depth=0;
        makeEmptyQuack(qs);
        makeEmptyQuack(temp);
    }
    *max_length = *max_length + 1;
    printf("Longest ladder length: %d\n", *max_length);
    printf("Longest ladders:\n");
    Quack pre;
    pre = createQuack();
    Quack result;
    result = createQuack();
    while (!isEmptyQuack(result_que)) {
        push(pop(result_que), pre);
    }
    int n = 1;
    while (!isEmptyQuack(pre)) {
        if (n>=1 && n<=9){
            printf(" ");
        }
        printf("%d: ", n);
        for (int i = 0; i < *max_length; i++) {
            push(pop(pre), result);
        }
        for (int j = 0; j < *max_length - 1; j++) {
            printf("%s -> ", words[pop(result)]);
        }
        printf("%s\n", words[pop(result)]);
        n++;
        if (n>99){
            break;
        }
    }
    free(depth);
    free(max_length);
    destroyQuack(qs);
    destroyQuack(temp);
    destroyQuack(result_que);
    destroyQuack(pre);
    destroyQuack(result);
//    free(order);
}

int main() {
    char *line = malloc(NODES * LENGTH_OF_WORD * sizeof(char));
//    fgets(line, NODES * LENGTH_OF_WORD, stdin);
    int num=0;
    char input;
    do {
        input = getchar();
        if (input == EOF){
            break;
        }
        *(line+num)=input;
        num++;
    }while (input != EOF);
    *(line+num)='\0';
    const char *deli = " \n\t\r";
    char **words = malloc(NODES * sizeof(char *));
    char *p;
    p = strtok(line, deli);
    int count_of_word = 0;
    while ((p != NULL)) {
        words[count_of_word] = malloc(LENGTH_OF_WORD * sizeof(char));
        int n = 0;
        while (*(p + n) != '\0') {
            words[count_of_word][n] = *(p + n);
            n++;
        }
        words[count_of_word][n] = '\0';
        p = strtok(NULL, deli);
        count_of_word++;
    }
    int ii=1;
    while (ii<count_of_word){
        if (strcmp(words[ii], words[ii-1])==0){
            for (int j=ii; j<count_of_word-1; j++){
                words[j]=words[j+1];
            }
            count_of_word--;
            ii--;
        }
        ii++;
    }
    //second question
    printf("Dictionary\n");
    for (int i = 0; i < count_of_word; i++) {
        printf("%d: %s\n", i, words[i]);
    }
    printf("Ordered Word Ladder Graph\n");
    Graph g = newGraph(count_of_word);
    for (int i = 0; i < count_of_word; i++) {
        for (int j = 0; j < count_of_word && i != j; j++) {
            if (differByOne(words[i], words[j])) {
                insertEdge(newEdge(i, j), g);
            }
        }
    }
    showGraph(g);
    //third question
    phase3(g, count_of_word, words);
    free(line);
    for (int f=0; f<count_of_word; f++){
        free(words[f]);
    }
    free(words);
    free(g);
}

