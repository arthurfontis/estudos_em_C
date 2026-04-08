#include <stdio.h>
#define MAX 100

int main()
{
    int x;
    int menor, maior;

    printf("Digite uma Lista: ");

    if(scanf("%d", &x) != 1){
        return 0;
    }

    menor = maior = x;

    while(scanf("%d", &x) == 1) {
        if(x < menor) {
            menor = x;
        }
        if(x > maior) {
            maior = x;
        }
    }

    int diferenca = maior - menor;

    if(diferenca < 0) {
        diferenca = -diferenca;
    }

    printf("Diferença absoluta é %d\n", diferenca);

    return 0;
}