#include <stdio.h>

void main(){
    int *p;
    int num=30;
    printf("%d\n", num);
    p = &num;
    printf("%p\n", &num);
    printf("%p\n", p);
    *p=20;
    printf("%d\n", num);

}