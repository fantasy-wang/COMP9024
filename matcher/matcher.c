#include <stdio.h>
#include "quack.h"

#define OPENA '('
#define CLOSA ')'
#define OPENB '{'
#define CLOSB '}'
#define OPENC '['
#define CLOSC ']'

int main() {
   char ch, opening;
   int  mismatch = 0;

   Quack q;
   q = createQuack();

   while ((ch = getchar()) != EOF && !mismatch) {
      if (ch == '\n'){
         break;
      }
      if (ch == OPENA || ch == OPENB || ch == OPENC) {
         push(ch,q);
      } else if (ch == CLOSA || ch == CLOSB || ch == CLOSC) {
         if (isEmptyQuack(q) == 1) {
            mismatch = 1;              // an opening bracket is missing
         } else {
            opening = pop(q);
            printf("opening bracket : %c\n", opening);
            if (!((opening == OPENA && ch == CLOSA) ||
                  (opening == OPENB && ch == CLOSB) ||
                  (opening == OPENC && ch == CLOSC))) {
               mismatch = 1;           // wrong closing bracket
            }
         }
      }
   }
   if (mismatch || !(isEmptyQuack(q) == 1)) {  // mismatch or some brackets unmatched
      printf("unbalanced\n");
   } else {
      printf("balanced\n");
   }
   return 0;
}