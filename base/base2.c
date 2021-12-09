#include <stdlib.h>
#include <stdio.h>
#include "quack.h"

int main(int argc, char *argv[]) {
   int n;
   Quack qs;
   if (argc != 2) {
      printf("Usage: %s number\n", argv[0]);
      return 1;
   }

   qs = createQuack();
   n = atoi(argv[1]);
   int number = 0;
   if(sscanf(argv[1],"%d", &number) == 0){
      printf("Usage: ./base2 number\n");
      return EXIT_FAILURE;
   }
   if (n == 0){
      printf("0\n");
      return 0;
   }
   while (n > 0) {
      push( n % 2, qs);
      n = n / 2;
   }
   while (!isEmptyQuack(qs)) {
      printf("%d", pop(qs));
   }
   putchar('\n');
   makeEmptyQuack(qs);
   return 0;
}