

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

void phase3(Graph g, int count_of_word, char **words) {
    int all[NODES][NODES];
    for (int i=count_of_word-1; i>=0; i--){
        for (int j=0; j<count_of_word; j++){
            if (i==count_of_word-1){
                all[i][j]=1;
            }
            else{
                if (j>i){
                    all[i][j]
                }
                else{
                    all[i][j]=1;
                }
            }
        }
    }
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

