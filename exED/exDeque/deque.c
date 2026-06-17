#include <stdio.h>
#include <stdlib.h>

typedef struct no *p_no;

struct no
{
    int dado;
    p_no prox, ant;
};

typedef struct deque *p_deque;

struct deque
{
    p_no inicio, fim;
};

p_deque criar_deque()
{
    p_deque d = malloc(sizeof(struct deque));
    d->fim = NULL;
    d->inicio = NULL;

    return d;
}

void add_inicio(p_deque d, int dado)
{
    p_no novo = malloc(sizeof(struct no));
    novo->dado = dado;
    novo->prox = d->inicio;
    novo->ant = NULL;
    if(d->inicio != NULL){
        d->inicio->ant = novo;
    }
    else {
        d->fim = novo;
    }
    d->inicio = novo;
}

void add_final(p_deque d, int dado)
{
    p_no novo = malloc(sizeof(struct no));
    novo->dado = dado;
    novo->prox = NULL;
    novo->ant = d->fim;
    if(d->fim != NULL){
        d->fim->prox = novo;
    }
    else {
        d->inicio = novo;
    }
    d->fim = novo;
}

int remove_inicio(p_deque d){
    p_no remover = d->inicio;
    int dado = d->inicio->dado; 
    d->inicio = d->inicio->prox;

    if(d->inicio != NULL){
        d->inicio->ant = NULL;
    }
    else{
        d->fim = NULL;
    }
    free(remover);
    return dado;
    
}

int remover_final(p_deque d){
    p_no remover = d->fim;
    int dado = d->fim->dado;
    d->fim = d->fim->ant;
    if(d->fim != NULL){
        d->fim->prox = NULL;
    }
    else {
        d->inicio = NULL;
    }

    free(remover);
    return dado;
}


