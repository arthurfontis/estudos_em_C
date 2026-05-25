#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[101];
    char mencao[3];
    int valor;
} Aluno;

int valorAluno(char *mencao)
{
    if (strcmp(mencao, "SS") == 0)
        return 6;
    if (strcmp(mencao, "MS") == 0)
        return 5;
    if (strcmp(mencao, "MM") == 0)
        return 4;
    if (strcmp(mencao, "MI") == 0)
        return 3;
    if (strcmp(mencao, "II") == 0)
        return 2;

    return 1;
}

int comparar(const void *a, const void *b)
{
    Aluno *a1 = (Aluno *)a;
    Aluno *a2 = (Aluno *)b;

    if (a1->valor != a2->valor)
    {
        return a2->valor - a1->valor;
    }

    return strcmp(a1->name, a2->name);
}

int main()
{

    int n;
    scanf("%d", &n);

    Aluno alunos[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %[^\n]", alunos[i].mencao, alunos[i].name);

        alunos[i].valor = valorAluno(alunos[i].mencao);
    }

    qsort(alunos, n, sizeof(Aluno), comparar);

    for (int i = 0; i < n; i++)
    {
        printf("%s %s\n", alunos[i].mencao, alunos[i].name);
    }

    return 0;
}
