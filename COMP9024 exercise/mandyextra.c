//
// Created by 56915 on 2019/7/25.
//
#include <stdio.h>
#include <stdlib.h>

#define TOOFEW 4
#define ENOUGH 6

int main(void){
    char *p;
    p = malloc(TOOFEW);
    if (p == NULL){
        fprintf(stderr, "malloc(): failed\n");
        return EXIT_FAILURE;
    }
    *p = 'S';
    *(p+1) = 'P';
    *(p+2) = 'A';
    *(p+3) = 'C';

    char *pextra;
    pextra = realloc(p, ENOUGH);
    if (pextra == NULL){
        fprintf(stderr, "realloc(): failed\n");
    }
    *(pextra+4) = 'E';
    *(pextra+5) = '\0';
    printf("%s\n", pextra);
    printf("%c\n", *pextra);
    free(pextra);
    return EXIT_SUCCESS;
}
