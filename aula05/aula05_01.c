#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 10;
    int * pont;

    pont = &num;

    printf("Valor: %d\n", *pont);
    printf("Endereco: %x\n", pont);
    printf("Endereco pont: %x\n", &pont);
    
    *pont = 11;
    printf("Valor: %d\n", *pont);
    printf("Valor variavel: %d\n", num);
    printf("Endereco: %x\n", pont);
    printf("Endereco pont: %x\n", &pont);

    return 0;
}