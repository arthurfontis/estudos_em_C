#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float nota;
    int id;
}Aluno;


int main(){
    Aluno *alunos;
    int i;
    alunos = (Aluno *)malloc(5 * sizeof(Aluno));

    if(alunos == NULL){
        printf("Falha na alocacao de memoria. \n");
        return 1;
    }

    strcpy(alunos[0].nome, "Leonardo");
    alunos[0].nota = 10.0;
    alunos[0].id = 1;
    
    strcpy(alunos[1].nome, "a");
    alunos[1].nota = 5.0;
    alunos[1].id = 2;

    strcpy(alunos[2].nome, "b");
    alunos[2].nota = 5.1;
    alunos[2].id = 3;

    strcpy(alunos[3].nome, "c");
    alunos[3].nota = 7.2;
    alunos[3].id = 4;

    strcpy(alunos[4].nome, "d");
    alunos[4].nota = 8.4;
    alunos[4].id = 5;


    for (i=0; i< 5; i++){
        printf("\n\nNome: %s",alunos[i].nome);
        printf("\nNota: %.lf",alunos[i].nota);
        printf("\n\Id: %d",alunos[i].id);
    }


    return 0;
}