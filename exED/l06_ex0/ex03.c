#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int **dados, n;
} Matriz;

void permutacao(Matriz m, int j, int i)
{
    int temp;

    i--;
    j--;

    for (int col = 0; col < m.n; col++)
    {
        temp = m.dados[i][col];
        m.dados[i][col] = m.dados[j][col];
        m.dados[j][col] = temp;
    }
    for (int x = 0; x < m.n; x++)
    {
        for (int y = 0; y < m.n; y++)
        {
            printf("%d", m.dados[x][y]);
        }
        printf("\n");
    }
}

int main()
{
    Matriz m;

    printf("Digite o tamanho da Matriz: ");
    scanf("%d",&m.n);

    m.dados = (int **) malloc(m.n * sizeof(int *));

    for(int i = 0; i < m.n; i++){
        m.dados[i] = (int *) malloc(m.n * sizeof(int));
    }

    printf("Digite os valores da Matriz:\n");
    for (int x = 0; x < m.n; x++){
        for(int y = 0; y < m.n; y++){
            scanf("%d", &m.dados[x][y]);
        }
    }

    int i1, j1;

    printf("Digite as linhas para trocar: ");
    scanf("%d %d", &i1, &j1);


    permutacao(m,i1,j1);

    for (int f = 0; f < m.n; f++)
    {
        free(m.dados[i1]);
    }
    free(m.dados);

    return 0;
}