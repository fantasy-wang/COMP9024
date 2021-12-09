//9024 19T2 assignment1

//written by zhuoran wang 2019/6/21

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include "boardADT.h"

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define SIZE 1024

int main(){
    //allocate memory to pointers
    //get string
    //print out
    char *first_line;
    first_line = malloc(SIZE * sizeof(char));
    char *second_line;
    second_line = malloc(SIZE * sizeof(char));
    //second_line = malloc(SIZE * sizeof(char));
    char *start_line;
    char *goal_line;
    start_line = fgets(first_line, SIZE, stdin);
    goal_line = fgets(second_line, SIZE, stdin);
    printf("start: %s", first_line);
    printf("goal: %s", second_line);

    //get board elements from start and goal line
    int length_of_start_line = strlen(start_line);
    for (int i=0; i<length_of_start_line; i++){
        if (*(start_line+i)=='b'){
            continue;
        }
        else if (!isdigit(*(start_line+i))){
            *(start_line+i) = ' ';
        }
    }
    board start = get_elements(start_line);
    int length_of_goal_line = strlen(goal_line);
    for (int i=0; i<length_of_goal_line; i++){
        if (*(goal_line+i)=='b'){
            continue;
        }
        else if (!isdigit(*(goal_line+i))){
            *(goal_line+i) = ' ';
        }
    }
    board goal = get_elements(goal_line);

    //check start and goal board
    if (check_two_valid(start, goal)==1){
        printf("input error\n");
        return EXIT_FAILURE;
    } else{
        if (check_solution(start, goal)){
            printf("solvable\n");
        } else{
            printf("unsolvable\n");
        }
    }

    // free memory
    free_board(start);
    free_board(goal);
    return EXIT_SUCCESS;
}



