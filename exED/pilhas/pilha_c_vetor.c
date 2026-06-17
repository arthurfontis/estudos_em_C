#include <stdlib.h>
#include <stdio.h>

typedef struct pilha *p_pilha;

struct pilha
{
    int *v;
    int topo;
};

p_pilha criar_pilha(int N){
    p_pilha p = malloc(sizeof(struct pilha));
    p->v = malloc(N * sizeof(int));
    p->topo = 0;

    return p;
}

void empilhar(p_pilha p, int dado){
    p->v[p->topo] = dado;
    p->topo++;
}

int desinfileirar(p_pilha p){
    p->topo--;
    return p->v[p->topo];
}

void imprimir(p_pilha p){
    for(int i = 0; i < p->topo; i++){
        printf("%d\n", p->v[i]);
    }
}
