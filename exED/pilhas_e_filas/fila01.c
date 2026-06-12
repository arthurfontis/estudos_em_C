#include <stdlib.h>
#include <stdio.h>

typedef struct no *p_no;

struct no
{
    int dado;
    p_no prox;
};

typedef struct fila *p_fila;

struct fila{
    p_no inicio, fim;
};

void destruir_lista(p_no lista)
{
    if (lista != NULL)
    {
        destruir_lista(lista->prox);
        free(lista);
    }
}

p_fila criar_fila(){
    p_fila f;
    f = malloc(sizeof(struct fila));
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

void destruir_fila(p_fila f){
    destruir_lista(f->inicio);
    free(f);
}

void enfileira(p_fila f, int dado){
    p_no novo;
    novo = malloc(sizeof(struct no));
    novo->dado = dado;
    novo->prox = NULL;
    if(f->inicio == NULL){
        f->inicio = novo;
    }else {
        f->fim->prox = novo;
    }
    f->fim = novo;
}

int desinfileirar(p_fila f){
    p_no primeiro = f->inicio;
    int dado = f->inicio->dado;
    f->inicio = f->inicio->prox;
    if(f->inicio == NULL){
        f->fim == NULL;
    }
    free(primeiro);
    return dado;
}

void imprimir_fila(p_fila f){
    if(f->inicio == NULL){
        printf("Lista vazia");
        return;
    }

    p_no atual = f->inicio;

    while (atual != NULL)
    {
        printf("%d\n", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

int main(){

    p_fila f = criar_fila();
    enfileira(f, 4);
    enfileira(f, 2);
    enfileira(f, 3);
    enfileira(f, 10);

    imprimir_fila(f);



    return 0;
}