#include <stdlib.h>
#include <stdio.h>

int potencia(int n, int r){
    if(n == 1 || r == 0){
        return 1;
    }else {
        return n * potencia(n, r-1);
    }
}

int main() {

    int teste = potencia(2,3);

    printf("%d", teste);
    return 0;
}