//
// Created by 56915 on 2019/7/1.
//
//week1 exercise 1
#include <stdio.h>
#include <stdlib.h>

#define MIN 10000
#define MAX 25000

int main() {
    int a,b,c,d,e,n;
    for (n=MIN; n<MAX; n++){
        a = (n/10000) % 10;
        b = (n/1000) % 10;
        c = (n/100) % 10;
        d = (n/10) % 10;
        e = n % 10;
        if (4 * n == e*10000+d*1000+c*100+b*10+a){
            printf("%d\n", n);
        }
    }
    return EXIT_SUCCESS;
}

//week1 exercise 2
float innerProduct(float a[], float b[], int n){
    float sum = 0.0;
    for (int i=1; i<n; i++){
        sum += a[i]*b[i];
    }
    return sum;
}

//week1 exercise 3
#define M 3
#define N 4
#define P 4

void matrixProduct(float a[M][N], float b[N][P], float c[M][P]){
    for (int i=1; i<M; i++){
        for (int j=1; j<P; j++){
            c[i][j] = 0.0;
            for (int k=1; k<N; k++){
                c[i][j] = a[i][k] * b[k][j];
            }
        }
    }
}

//week1 exercise 4
#include <stdio.h>
#include <stdlib.h>

#define LEN 4

int main(){
    char able[]={'a', 'b', 'e', 'l'};

    int count = 0;
    for (int i=0; i<LEN; i++){
        for (int j=0; j<LEN; j++){
            for (int k=0; k<LEN; k++){
                for (int n=0; n<LEN; n++){
                    if (i!=j && i!=k && i!=n && j!=k && j!=n && k!=n){
                        printf("%c%c%c%c\n", able[i], able[j], able[k], able[n]);
                        count++;
                    }
                }
            }
        }
    }
    printf("%d\n", count);
    return EXIT_SUCCESS;
}

//week1 exercise 5
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
// a
void collat(int n){
    while (n!=1){
        if (n%2==0){
            n = n/2;
        } else{
            n = 3*n+1;
        }
        printf("%d ", n);
    }
    putchar('\n');
}

//b
int main(void){
    int fib[MAX];
    for (int i=0; i<MAX; i++){
        if (i<2){
            fib[i] = 1;
        } else{
            fib[i] = fib[i-1]+fib[i-2];
        }
        printf("Fib[%d] = %d: ", i+1, fib[i]);
        collat(fib[i]);
    }
    return 0;
}

//week1 exercise 6
//week1 exercise 6
#include <stdio.h>
#include <stdbool.h>

#define num1 10
#define num2 20
#define num3 13

int fastMax(int a, int b, int c){
    int d;
    d = a*(a>b)+b*(a<b);
    d = d*(d>c)+c*(d<c);
    return d;
}

int main(){
    int largest;
    largest = fastMax(num1,num2,num3);
    printf("the largest of %d %d %d is %d\n", num1,num2,num3,largest);
}

