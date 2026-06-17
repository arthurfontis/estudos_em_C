#include <stdlib.h>
#include <stdio.h>

typedef struct no *p_no;
struct no {
    int dado;
    p_no prox;
};

typedef struct pilha *p_pilha;
struct pilha {
    p_no topo;
};

p_pilha criar_pilha(){
    p_pilha p = malloc(sizeof(struct pilha));
    p->topo = NULL;
    return p;
}

void add_pilha(p_pilha p, int dado){
    p_no novo = malloc(sizeof(struct no));
    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
}

int remover_pilha(p_pilha p){
    p_no ultimo = p->topo;
    int dado = ultimo->dado;
    p->topo = p->topo->prox;

    free(ultimo);
    return dado;
}

void decimal_para_binario(int n){
    p_pilha p = criar_pilha();
    while(n != 0){
        int resto = n % 2;
        add_pilha(p, resto);
        n = n / 2;
    }

    p_no atual = p->topo;
    for (atual; atual != NULL ; atual = atual->prox)
    {
        printf("%d", atual->dado);
    }
    
}

