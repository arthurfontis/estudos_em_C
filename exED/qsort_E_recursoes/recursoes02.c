#include <stdio.h>
#include <stdlib.h>

int maximo(int *v, int n)
{
    if (n == 1)
        return v[0];
    int m = maximo(v, n - 1);
    return v[n - 1] > m ? v[n - 1] : m;
}

int binomio(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return binomio(n - 1, k) + binomio(n - 1, k - 1);
}

int main()
{
    int vetor[5] = {5, 2, 22, 6, 1};

    printf("%d", binomio(3, 2));

    return 0;
}