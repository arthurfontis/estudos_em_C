#include <stdlib.h>
#include <stdio.h>

typedef struct no *p_no;
struct no
{
    int dado;
    p_no prox;
};

typedef struct fila *p_fila;
struct fila
{
    p_no inicio, fim;
};

p_fila criar_fila()
{
    p_fila f = malloc(sizeof(struct fila));
    f->fim = NULL;
    f->inicio = NULL;

    return f;
}

void enfileira(p_fila f, int dado)
{
    p_no novo = malloc(sizeof(struct no));
    novo->dado = dado;
    novo->prox = NULL;

    if (f->inicio == NULL)
    {
        f->inicio = novo;
    }
    else
        f->fim->prox = novo;
    f->fim = novo;
}

int desenfileirar(p_fila f)
{
    p_no primeiro = f->inicio;
    int dado = primeiro->dado;

    f->inicio = f->inicio->prox;
    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }

    free(primeiro);
    return dado;
}
float media_janela(int nums[], int total, int n)
{
    p_fila f = criar_fila();
    int contador = 0;
    for (int i = 0; i < total; i++)
    {
        if (contador == n)
        {
            desenfileirar(f);
        }
        else
        {
            contador++;
        }
        enfileira(f, nums[i]);
    }

    p_no atual = f->inicio;
    int soma = 0;
    for (; atual != NULL; atual = atual->prox)
    {
        soma += atual->dado;
    }

    return (float)soma / n;
}