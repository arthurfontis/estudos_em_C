#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[101];
    char mencao[3];
    int nota;
} Aluno;

int valorMencoes(char *m)
{
    if (strcmp(m, "SS") == 0)
        return 6;
    if (strcmp(m, "MS") == 0)
        return 5;
    if (strcmp(m, "MM") == 0)
        return 4;
    if (strcmp(m, "MI") == 0)
        return 3;
    if (strcmp(m, "II") == 0)
        return 2;
    return 1;
}

int mencoes(const void *a, const void *b)
{
    Aluno *x = (Aluno *)a;
    Aluno *y = (Aluno *)b;
    if(x->nota != y->nota){
        return y->nota - x->nota;
    }

    return strcmp(x->nome, y->nome);

    return x - y;
}

int main()
{
    int n;
    char mencao[3];
    char nome[100];
    Aluno alunos[500];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%2s %[^\n]", alunos[i].mencao, alunos[i].nome);
        alunos[i].nota = valorMencoes(alunos[i].mencao);
    }

    qsort(alunos, n, sizeof(Aluno), mencoes);

    for (int i = 0; i < n; i++)
    {
        printf("\n%s %s\n",
               alunos[i].mencao,
               alunos[i].nome);
    }

    return 0;
}