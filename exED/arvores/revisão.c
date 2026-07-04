#include <stdlib.h>
#include <stdio.h>

typedef struct no *p_no;

struct no{
    int dado;
    p_no esq, dir;
};

p_no criar_arvore(int dado, p_no esq, p_no dir){
    p_no r = malloc(sizeof(struct no));
    r->dado = dado;
    r->dir = dir;
    r->esq = esq;

    return r;
}

p_no procurar_no(p_no raiz, int dado){
    if(raiz == NULL || raiz->dado == dado){
        return raiz;
    }

    p_no esq = procurar_no(raiz->esq, dado);
    if(esq != NULL) return esq;
    return procurar_no(raiz->dir, dado);
}

int numero_nos(p_no raiz){
    if(raiz == NULL) return 0;
    return numero_nos(raiz->esq) + numero_nos(raiz->dir) + 1;
}

int altura(p_no raiz){
    if(raiz == NULL) return 0;

    int h_esq = altura(raiz->esq);
    int h_dir = altura(raiz->dir);

    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

p_no busca_bst(p_no raiz, int dado){
    if(raiz == NULL) return NULL;
    if(raiz->dado == dado) return raiz;
    if(raiz->dado > dado) busca_bst(raiz->esq, dado);
    else busca_bst(raiz->dir, dado);
}

p_no insere(p_no raiz, int dado){
    if(raiz == NULL){
        p_no novo = malloc(sizeof(struct no));
        novo->dado = dado;
        novo->dir = NULL;
        novo->esq = NULL;

        return novo;
    }
    if(raiz->dado > dado){
        insere(raiz->esq, dado);
    }
    else insere(raiz->dir, dado);

    return raiz;
}