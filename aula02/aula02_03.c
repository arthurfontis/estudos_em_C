#include <stdlib.h>
#include <stdio.h>
#define MAX 2

int main()
{
    float notas[MAX][MAX] = {{1.0,2.0}, {3.0,4.0}};
    
    printf("\n%.2f %.2f", notas[0][0], notas[0][1]);
    printf("\n%.2f %.2f", notas[1][0], notas[1][1]);
    printf("\n----------");
    
    return 0;
}