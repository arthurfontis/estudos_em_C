#include <stdio.h>
#include <stdlib.h>

int potencia(int n, int r)
{
    if (n == 1 || r == 0)
    {
        return 1;
    }

    return n * potencia(n, r-1);
}

int main()
{

    int teste1 = potencia(2, 3);

    printf("%d", teste1);

    return 0;
}
