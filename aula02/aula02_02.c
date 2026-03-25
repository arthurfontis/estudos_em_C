#include <stdlib.h>
#include <stdio.h>

int main()
{
    float notas[] = {1.0,2.0,3.0,4.0,5.0};

    printf("\n%.2f", notas[0]);
    printf("\n%.2f", notas[1]);
    printf("\n%.2f", notas[2]);
    printf("\n%.2f", notas[3]);
    printf("\n%.2f", notas[4]);
    printf("\n----------");
    
    notas[0] = 8.0;
    notas[1] = 8.9;
    notas[2] = 8.5;
    notas[3] = 8.3;
    notas[4] = 8.1;

    printf("\n%.2f", notas[0]);
    printf("\n%.2f", notas[1]);
    printf("\n%.2f", notas[2]);
    printf("\n%.2f", notas[3]);
    printf("\n%.2f", notas[4]);
    printf("\n----------");
    
    notas[3] = 10.0;
    

    printf("\n%.2f", notas[0]);
    printf("\n%.2f", notas[1]);
    printf("\n%.2f", notas[2]);
    printf("\n%.2f", notas[3]);
    printf("\n%.2f", notas[4]);
    return 0;
}