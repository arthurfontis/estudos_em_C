#include <stdlib.h>
#include <stdio.h>

typedef struct no *p_no;

struct no
{
    int dado;
    p_no prox;
    p_no ant;
};

p_no criar_lista()
{
    return NULL;
}

p_no adicionando_elementos(p_no lista, int dado)
{
    p_no novo;
    novo = malloc(sizeof(struct no));
    novo->dado = dado;
    novo->ant = NULL;
    novo->prox = lista;

    if (lista != NULL)
        lista->ant = novo;

    return novo;
}

void imprimir_listaDupla(p_no lista)
{
    p_no atual = lista;
    while (atual != NULL)
    {
        printf("%d\n", atual->dado);
        atual = atual->prox;
    }
}


int main()
{

    p_no lista = criar_lista();
    p_no lista2 = criar_lista();
    lista = adicionando_elementos(lista, 2);
    lista = adicionando_elementos(lista, 1);
    lista = adicionando_elementos(lista, 5);

    lista2 = adicionando_elementos(lista2, 5);
    lista2 = adicionando_elementos(lista2, 8);
    lista2 = adicionando_elementos(lista2, 11);

    imprimir_listaDupla(lista);
    printf("--------------\n");
    imprimir_listaDupla(lista2);

    return 0;
}