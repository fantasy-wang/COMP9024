//9024 19T2 assignment1
//boardADT head file

//
// written by zhuoran wang on 2019/6/21.
//

#ifndef INC_9024_DATE_STRU_BOARDADT_H
#define INC_9024_DATE_STRU_BOARDADT_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define SIZE 1024

//board struct
struct Board{
    //numbers
    int *numbers;
    //length of line
    int length_of_line;
    //the row number of board
    int row_of_board;
};
typedef struct Board *board;


board init();
board get_elements(char *);
bool check_correctness(board b);
int check_two_valid(board b1, board b2);
int count_of_disorder(board b);
bool check_solution(board b1, board b2);
void free_board(board b);

#endif //INC_9024_DATE_STRU_BOARDADT_H