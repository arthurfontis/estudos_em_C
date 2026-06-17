#include <stdlib.h>
#include <stdio.h>

typedef struct no *p_no;
struct no {
    char *dado;
    p_no prox;
};

typedef struct fila *p_fila;
struct fila{
    p_no inicio, fim;
};

p_fila criar_fila(){
    p_fila f = malloc(sizeof(struct fila));
    f->fim = NULL;
    f->inicio = NULL;

    return f;
}

void chegou(p_fila f, char *nome){
    p_no novo = malloc(sizeof(struct no));
    novo->dado = nome;
    novo->prox = NULL;

    if(f->inicio == NULL){
        f->inicio = novo;
    }
    else {
        f->fim->prox = novo;

    }
    f->fim = novo;
}

void chamar_proximo(p_fila f){
    p_no primeiro = f->inicio;
    char *nome = primeiro->dado;

    f->inicio = f->inicio->prox;
    if(f->inicio == NULL){
        f->fim = NULL;
    }

    free(primeiro);
    printf("Chamando: %s", nome);
}