#include <stdlib.h>
#include <stdio.h>

typedef struct no *p_no;

struct no {
    int dado;
    p_no prox;
};

typedef struct pilha *p_pilha;

struct pilha
{
    p_no topo;
};

p_pilha criar_pilha(){
    p_pilha p = malloc(sizeof(struct pilha));
    p->topo = NULL;

    return p;
}

void empilhar(p_pilha p, int dado){
    p_no novo = malloc(sizeof(struct no));
    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
}

int desempilhar(p_pilha p){
    p_no ultimo = p->topo;
    int dado = ultimo->dado;
    p->topo = p->topo->prox;
    
    free(ultimo);
    return dado;
}
