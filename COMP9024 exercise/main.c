#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "LL.h"


int main() {
    List p;
    p=createList();
    putHead(1, p);
    putTail(2, p);
    int i=getTail(p);
    showList(p);
   // printf("%d",i);
}

