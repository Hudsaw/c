#include <stdio.h>
#include <stdlib.h>

void findMinMax(int a, int b, int *pMin, int *pMax){
    if(a>b){
        *pMin=b;
        *pMax=a;
    }
    else{
        *pMin=a;
        *pMax=b;
    }

}

void main(){

    int a=5, b=7;
    int max, min;

    findMinMax(a,b, &min, &max);
    printf("Minimo entre %d eh %d: %d\n", a, b, min);
    printf("Maximo entre %d eh %d: %d\n", a, b, max);

}