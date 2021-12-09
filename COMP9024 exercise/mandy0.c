//
// Created by 56915 on 2019/7/25.
//

#include <stdio.h>
#include <stdlib.h>

struct somedata{
    int age;
    float weight;
    char gender;
};

int main(){
    struct somedata mandy;
    mandy.age=21;
    mandy.weight=65.5;
    mandy.gender='f';
    printf("%d %.2f %c", mandy.age, mandy.weight, mandy.gender);
    return EXIT_SUCCESS;
}