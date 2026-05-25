#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eh_palindromo(char *palavra, int ini, int fim)
{
    if (ini >= fim)
        return 1;
    return palavra[ini] == palavra[fim] &&
           eh_palindromo(palavra, ini + 1, fim - 1);
}
int main()
{

    char palavra[30] = "arara";

    printf("%d", eh_palindromo(palavra, 0, strlen(palavra) - 1));

    return 0;
}
