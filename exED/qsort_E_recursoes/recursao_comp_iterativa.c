#include <stdio.h>
#include <stdlib.h>

int potencia(int num,int potencia){
    int resultado = 1;
    for (int i = 0; i < potencia; i++){
        resultado = resultado * num;
    }

    return resultado;
}

int main(){

    int teste1 = potencia(2,3);

    printf("%d", teste1);


    return 0;
}