#include <stdio.h>

void main(){
    int *p;
    int grades[3]={80,90,100};
    printf("Grades comeca em: %p\n", grades);
    printf("Grades comeca em: %p\n", grades+1);
    printf("Grades: %d\n", *grades);
    printf("Address: %p\n", &grades[0]);
    printf("Address: %p\n", &grades[1]);
    printf("Address: %p\n", &grades[2]);

}