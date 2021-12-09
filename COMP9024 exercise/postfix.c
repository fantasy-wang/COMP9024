//
// Created by 56915 on 2019/7/24.
//
#include <stdio.h>
#include <stdlib.h>
#include "Quack.h"

#define PLUSCHAR '+'
#define MULTCHAR '*'

int main(int argc, char *argv[]){
    Quack s = NULL;
    int error;
    int operandFound = 0;

    if (argc >= 2){
        char *input = argv[1];
        s = createQuack();
        while (*input != '\0'){
            int sum;
            switch (*input){
                case PLUSCHAR: push(pop(s)+pop(s), s);
                    break;
                case MULTCHAR: push(pop(s)*pop(s), s);
                    break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':   operandFound = 1;
                            sum = 0;
                            while((*input >= '0')&&(*input<'9')){
                                sum = 10*sum + (*input - '0');
                                input++;
                            }
                            push(sum, s);
                            *input--;
                            break;
                case ' ':
                case '\t':
                            break;
                default:    fprintf(stderr, "Invalid character %c\n", *input);
            }
            input++;
        }
        if (operandFound){
            if (!isEmptyQuack(s)){
                printf("%d\n", pop(s));
            } else{
                fprintf(stderr, "Error: stack empty, no result\n");
                error = 1;
            }
        }
        if (!isEmptyQuack(s)){
            fprintf(stderr, "Error: extra operand(s)\n");
        }
        if (error){
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }
}