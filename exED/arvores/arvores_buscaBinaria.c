#include <stdlib.h>
#include <stdio.h>

typedef struct abb_int {
    int dado;
    struct abb_int *esq;
    struct abb_int *dir;
}abb_int;

void insere(abb_int **raiz, int dado){
    if(*raiz == NULL){
        abb_int *novo = (abb_int *) malloc(sizeof(abb_int));
        novo->dado = dado;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return;
    }

    if(dado > (*raiz)->dado){
        insere(&((*raiz)->dir), dado);
    }
    else {
        insere(&((*raiz)->esq), dado);
    }
}

void mostra_arvore(abb_int *raiz){
    if(raiz == NULL){
        printf("()");
    }
    else{
        printf("(%d ", raiz->dado);
        mostra_arvore(raiz->esq);
        printf(" ");
        mostra_arvore(raiz->dir);
        printf(")");
    }

}

int altura(abb_int *raiz){
    if(raiz == NULL){
        return 0;
    }

    int h_dir = altura(raiz->dir);
    int h_esq = altura(raiz->esq);

    return (h_dir > h_esq ? h_dir : h_esq) + 1;
}

void em_lista(abb_int **raiz){
    if(raiz == NULL){
        return;
    }

    abb_int **atual = raiz;
    while (*atual != NULL)
    {   
        if((*atual)->dir != NULL){
            rotaciona_esquerda(atual);
        }
        else {
            atual = &((*atual)->esq);
        }
    }
    
}