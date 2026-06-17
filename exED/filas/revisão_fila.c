#include <stdlib.h>
#include <stdio.h>

typedef struct no *p_no;

struct no {
    int dado;
    p_no prox;
};

typedef struct fila *p_fila;

struct fila
{
    p_no inicio, fim;
};

p_fila criar_fila(){
    p_fila f;
    f = malloc(sizeof(struct fila));
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

void enfileirar(p_fila f, int dado){
    p_no novo;
    novo = malloc(sizeof(struct no));
    novo->dado = dado;
    novo->prox = NULL;

    if(f->inicio == NULL) f->inicio = novo;
    else f->fim->prox = novo;
    f->fim = novo;
}

int desinfileirar(p_fila f){
    p_no primeiro;
    primeiro = f->inicio;
    int dado = primeiro->dado;

    f->inicio = f->inicio->prox;
    if(f->inicio == NULL) f->fim = NULL;

    free(primeiro);
    return dado;
}

void imprimir(p_fila f){
    p_no atual = f->inicio;
    while (atual != NULL)
    {
        printf("%d\n", atual->dado);
        atual = atual->prox;
    }
}
