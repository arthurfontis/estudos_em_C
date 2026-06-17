#include <stdio.h>
#include <stdlib.h>

typedef struct no *p_no;
struct no{
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

int avaliar_rpn(char *tokens[], int n){
    p_pilha p = criar_pilha();

    for (int i = 0; i < n; i++)
    {
        if(tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/'){
            int b = remover_pilha(p);
            int a = remover_pilha(p);

            if(tokens[i][0] == '+') add_pilha(p, a + b);
            if(tokens[i][0] == '-') add_pilha(p, a - b);
            if(tokens[i][0] == '*') add_pilha(p, a * b);
            if(tokens[i][0] == '/') add_pilha(p, a / b);
        }
        else {
            add_pilha(p, atoi(tokens[i]));
        }
    }
    return remover_pilha(p);
}