#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y){
    int X = *(int *)x;
    int Y = *(int *)y;

    return X - Y;
}

int main(){

    int numbers[] = {0,2,6,7,8,3,6,8,4,12};
    int lenght = 10;

    qsort(numbers, lenght, sizeof(int), compare);

    for(int i = 0; i < lenght; i++){
        printf("%d\n", numbers[i]);
    }
    return 0;
}