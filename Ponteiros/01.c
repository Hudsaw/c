#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b){
    int temp;
    temp = a;
    a=b;
    b=temp;
}

int main(){

    int a=5, b=7;

    printf("valor de a: %d\n", a);
    printf("valor de b: %d\n", b);

    swap(a,b);

    printf("valor depois a: %d\n", a);
    printf("valor depois b: %d\n", b);

return 0;
}