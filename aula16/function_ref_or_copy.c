#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastro(char *nome, int *idade, float *nota, int *frequencia){
    strcpy(nome, "Fontis");
    *idade = 19;
    *nota = 7.1;
    *frequencia = 200;
}


int main() {
    char nome[50] = "Rafael";
    int idade = 30;
    float nota = 10.0;
    int frequencia = 100;

    printf("Nome: %s\nIdade: %d\nNota: %.2f\nFrequencia: %d", nome, idade, nota, frequencia);
    
    cadastro(nome, &idade, &nota, &frequencia);
    
    printf("\n\nNome: %s\nIdade: %d\nNota: %.2f\nFrequencia: %d", nome, idade, nota, frequencia);

    return 0;
}