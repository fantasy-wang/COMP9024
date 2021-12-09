//
// Created by 56915 on 2019/7/1.
//
//week2 exercise2
#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int year,month,day;
}Date;

typedef struct{
    int hour,minute;
}Time;

typedef struct{
    int transaction_number;
    char weekday[4];
    Date date;
    Time time;
    char mode;
    char from[32], to[32];
    int journey_number;
    char fare_applied[12];
    float fare,discount,amount;
}Opal_card;

int main(){
    Opal_card opal_card;
    printf("The Opal data structure requires %d bytes.", sizeof(opal_card));
}


//week2 exercise2
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    if (argc > 1){
        int n;
        int sum=0;
        for (int i=1; i<argc; i++){
            if((sscanf(argv[i], "%d", &n) != 1)){
                fprintf(stderr, "error: argument %s is non-numeric\n", argv[i]);
                return EXIT_FAILURE;
            }
            sum += n;
        }
        printf("%d\n", sum);
        return EXIT_SUCCESS;
    }
}

//week2 exercise3
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    if (argc == 1){
        for (int i=0; i <= atoi(argv[0]); i++){
            printf("%d ", i);
        }
    } else{
        printf(" number");
    }
    return 0;
}

//week2 exercise3
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    int endcount = 0;
    if(argc != 2 || (sscanf(argv[1], "%d", &endcount) != 1)){
        fprintf("Usage: %s number", argv[0]);
        return EXIT_FAILURE;
    } else{
        for (int i=0; i<=endcount; i++){
            printf("%d", i);
            if (i<endcount){
                printf(',');
            } else{
                printf('\n');
            }
        }
        return EXIT_SUCCESS;
    }
}

//week2 exercise4 5
#include <stdio.h>
#include <stdlib.h>

void printn(int, int); //recursive

int main(int argc, char *argv[]){
    int endcount;
    if (argc != 2 || (sscanf(argv[1],"%d", &endcount)!=1)){
        fprintf("Usage: %s number", argv[0]);
        return EXIT_FAILURE;
    } else{
        printn(0, endcount);
        return EXIT_SUCCESS;
    }
}

void printn(int number, int limit){
    if (number == limit){
        printf("%d\n", number);
    } else if(number<limit){
        printf("%d,", number);
        printn(++number, limit);
    } else if{
        printn("%d,", number);
        printn(--number, limit);
    }
    else{
        return;
    }
}
