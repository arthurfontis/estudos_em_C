#include <stdio.h>

int main(){
    int num, parte1, parte2, soma, quadrado;

    num = 202;
    parte1 = num / 100;
    parte2 = num % 100;

    soma = parte1 + parte2;
    quadrado = soma * soma;

    if(quadrado == num){
        printf("Verdade");
    }
    else{
        printf("Falso");
    }
    

    return 0;
}