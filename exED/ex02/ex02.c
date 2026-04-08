#include <stdio.h>

int main(){
    int num, original, reverso = 0, digito;
    num = 1991;

    original = num;

    while(num > 0) {
        digito = num % 10;
        reverso = (reverso * 10) + digito;
        num = num / 10; 

    }

    if(original == reverso){
        printf("Verdadeiro");
    }
    else{
        printf("Falso");
    }
    

    return 0;
}