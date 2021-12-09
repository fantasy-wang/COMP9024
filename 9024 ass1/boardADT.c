//9024 19T2 assignment1

//boardADT.c
//define function
//
// written by zhuoran wang on 2019/6/21.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "boardADT.h"
#include <ctype.h>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define SIZE 1024



board init() {
    board b =  malloc(sizeof(struct Board));
    b->numbers=NULL;
    b->length_of_line=0;
    b->row_of_board=0;
    return b;
}

board get_elements(char *input){
    board b = init();
    if (input != NULL){
        //split input
        char *split_input;
        split_input = strtok(input, " ");
        b->numbers = malloc(SIZE * sizeof(int));

        //if split input is not null
        while(split_input != NULL){
            if (strcmp(split_input, "b")!=0) {
                *(b->numbers + b->length_of_line) = atoi(split_input);
            } else{
                *(b->numbers + b->length_of_line) = 0;
            }
            split_input = strtok(NULL, " ");
            b->length_of_line++;

        }
        b->row_of_board = (int)sqrt(b->length_of_line);
        }
    return b;
    }

//check correctness of every line
bool check_correctness(board b){
    //check the board null
    if (b->numbers == NULL){
        return EXIT_FAILURE;
    }
    if (b->length_of_line == 0){
        return EXIT_FAILURE;
    }

    if (b->row_of_board == 0){
        return EXIT_FAILURE;
    }

    //check row of board * row of board equal to length of line
    if (b->row_of_board*b->row_of_board != b->length_of_line){
        return EXIT_FAILURE;
    }


    //check whether there is a b which is 0
    int flag=0;
    for (int i=0; i<b->length_of_line; i++){
        if (*(b->numbers+i)==0){
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        return EXIT_FAILURE;
    }

    //check other numbers
    for (int i=1; i<b->length_of_line; i++){
        int flag1 = 0;
        for (int j=0; j<b->length_of_line; j++){
            if (i == *(b->numbers+j)){
                flag1 = 1;
                break;
            }
        }
        if (flag1 == 0){
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

//check correctness of two lines
int check_two_valid(board b1, board b2){
    if (b1->length_of_line==b2->length_of_line){
        if (check_correctness(b1)==0) {
            if(check_correctness(b2)==0){
                return EXIT_SUCCESS;
            }
        }
    }
    return EXIT_FAILURE;
}


//calculate the disorder count of start and goal
int count_of_disorder(board b){
    int count =0;
    if (b != NULL){
        for (int i=0; i<b->length_of_line; i++){
            if (*(b->numbers+i) !=0){
                for (int j=i+1; j<b->length_of_line; j++){
                    if(*(b->numbers+j)!=0){
                        if (*(b->numbers+i)>*(b->numbers+j)){
                            count ++;
                        }
                    }
                }
            } else{
                if (b->row_of_board % 2==0){
                    if ((i+1) % b->row_of_board == 0){
                        count += (i+1) / b->row_of_board;
                    } else{
                        count += i/b->row_of_board + 1;
                    }
                }
            }
        }
    }
    return count;
}


//check the odd and even of disorder count of start and goal
bool check_solution(board b1, board b2){
    if (count_of_disorder(b1)%2 == count_of_disorder(b2)%2){
        return true;
    } else{
        return false;
    }
}

//free memory
void free_board(board b){
    if (b != NULL){
        if (b->numbers != NULL){
            free(b->numbers);
        }
        free(b);
    }
}

