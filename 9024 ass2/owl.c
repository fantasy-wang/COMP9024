
//
// Created by zhuoran wang on 2019/7/30.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Quack.h"
#include "Graph.h"
#include <ctype.h>

#define NODES 1000
#define LENGTH_OF_WORD 21
#define MAX_PATH_OF_OWL 99

int number_of_path = 1;
int adjacency_list[NODES][NODES];
int adjacency_list_number[NODES];

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

int find_longest_length(int word_num, int* length){
    //find the length of all vertex
    for(int i = word_num - 1; i >= 0; i--){
        int newLen = length[i] + 1;
        for(int j = 0; j < adjacency_list_number[i]; j++){
            int neighbor = adjacency_list[i][j];
            if(i > neighbor && newLen > length[neighbor]){
                length[neighbor] = newLen;
            }
        }
    }

    //find longest_length
    int longest_length = length[0];
    for(int i = 1; i < word_num; i++) {
        if(length[i] > longest_length) {
            longest_length = length[i];
        }
    }
    return longest_length;
}

/*display longest path*/
void show_path(int* path, int* node_num, char **word){
    // display path
    if (number_of_path>=1 && number_of_path<=9){
        printf(" ");
    }
    printf("%d: ", number_of_path);
    for (int i=0; i<*node_num-1; i++){
        printf("%s -> ", word[path[i]]);
    }
    printf("%s\n", word[path[*node_num-1]]);
    return;
}

void find_path_dfs(Graph g, int word_num, int vertex, char **word, int* length, int longest_len, int* path, int* node_num){
    //find 99 path
    if(number_of_path > MAX_PATH_OF_OWL){
        return;
    }

    //find the end point, path found
    if(length[vertex] == 1){
        show_path(path, node_num, word);
        number_of_path += 1;
        return;
    }

    for(int i = 0; i < adjacency_list_number[vertex]; i++){
        int neighbor = adjacency_list[vertex][i];
        if(length[neighbor] == length[vertex] - 1){
            path[*node_num] = neighbor;
            *node_num += 1;
            find_path_dfs(g, word_num, neighbor, word, length, longest_len, path, node_num);
            *node_num -= 1;
        }
    }
    return;
}

//find  longest path from front to back
void find_longest_path(Graph g, int word_num, int longest_len, char **word, int* length) {
    //create path to store path temporary
    int *path = malloc(word_num * sizeof(int));
    int *node_num = malloc(sizeof(int));
    *node_num = 0;

    for(int i = 0; i < word_num; i++){
        //find item in longest path
        if(length[i] == longest_len){
            //recursively to find latter item
            path[*node_num] = i;
            *node_num += 1;
            find_path_dfs(g, word_num, i, word, length, longest_len, path, node_num);
            *node_num -= 1;
        }
    }
    free(path);
    free(node_num);
    return;
}

void phase3(Graph g, int count_of_word, char **word) {
    int *length = malloc(count_of_word * sizeof(int));
    //initialize length
    for (int i=0; i<count_of_word; i++){
        length[i]=1;
    }
    int longest_ladder_length = find_longest_length(count_of_word, length);
    printf("Longest ladder length: %d\n", longest_ladder_length);
    printf("Longest ladders:\n");

    find_longest_path(g, count_of_word, longest_ladder_length, word, length);
    free(length);
}

int main() {
    char *line = malloc(NODES * LENGTH_OF_WORD * sizeof(char));
    int num=0;
    char input;
    do {
        input = getchar();
        if (input == EOF){
            break;
        }
        *(line+num)=input;
        num++;
    } while (input != EOF);
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

    //if it is null
    if (!count_of_word){
        return 0;
    }

    //second question
    printf("Dictionary\n");
    for (int i = 0; i < count_of_word; i++) {
        printf("%d: %s\n", i, words[i]);
        adjacency_list_number[i]=0;
    }
    printf("Ordered Word Ladder Graph\n");
    Graph g = newGraph(count_of_word);
    for (int i = 0; i < count_of_word; i++) {
        for (int j = i+1; j < count_of_word; j++) {
            if (differByOne(words[i], words[j])) {
                insertEdge(newEdge(i, j), g);
                adjacency_list[i][adjacency_list_number[i]++] = j;
                adjacency_list[j][adjacency_list_number[j]++] = i;
            }
        }
    }
    //show graph
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

