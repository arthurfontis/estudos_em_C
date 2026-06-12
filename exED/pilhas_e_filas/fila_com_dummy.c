#include <stdlib.h>
#include <stdio.h>

typedef struct no *p_no;
struct no {
    int dado;
    p_no prox;
};

typedef struct fila *p_fila;
struct fila {
    p_no fim;
};

p_fila criar_fila(){
    p_fila f = malloc(sizeof(struct fila));
    p_no dummy = malloc(sizeof(struct no));
    dummy->prox = dummy;
    f->fim = dummy;

    return f;
}

void enfileira_fila(p_fila f, int dado){
    p_no novo = malloc(sizeof(struct no));
    novo->dado = dado;
    novo->prox = f->fim->prox;
    f->fim->prox = novo;
    f->fim = novo;
}

int desinfileira(p_fila f){
    if(f->fim->prox == f->fim){
        return -1;
    }
    p_no primeiro = f->fim->prox->prox;
    int dado = primeiro->dado;
    f->fim->prox->prox = primeiro->prox;

    if (primeiro == f->fim) {
        f->fim = f->fim->prox; // f->fim aponta de volta para o dummy
    }

    free(primeiro);
    return dado;
}