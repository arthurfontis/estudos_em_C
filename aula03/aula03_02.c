#include <stdio.h>

int main()
{
    int num = 0;
    printf("%d\n", num);
    printf("Escreva um número: ");
    scanf("%d", &num);
    printf("\nO número selecionado foi: %d", num);

    return 0;
}