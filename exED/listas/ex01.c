#include <stdio.h>
#include <stdlib.h>

typedef struct no *p_no;

struct no
{
    int dado;
    p_no prox;
};

p_no criar_lista()
{
    return NULL;
}

void destruir_lista(p_no lista)
{
    if (lista != NULL)
    {
        destruir_lista(lista->prox);
        free(lista);
    }
}

void imprimir_lista(p_no lista)
{
    if (lista != NULL)
    {
        printf("%d\n", lista->dado);
        imprimir_lista(lista->prox);
    }
}

p_no adicionar_elemento(p_no lista, int valor)
{
    p_no novo;
    novo = malloc(sizeof(struct no));

    novo->dado = valor;
    novo->prox = lista;

    return novo;
}

p_no unir_listas(p_no l1, p_no l2)
{
    p_no l3;
    l3 = criar_lista();

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->dado <= l2->dado)
        {
            l3 = adicionar_elemento(l3, l2->dado);
            l2 = l2->prox;
        }
        else
        {
            l3 = adicionar_elemento(l3, l1->dado);
            l1 = l1->prox;
        }
    }

    while (l1 != NULL)
    {
        l3 = adicionar_elemento(l3, l1->dado);
        l1 = l1->prox;
    }
    while (l2 != NULL)
    {
        l3 = adicionar_elemento(l3, l2->dado);
        l2 = l2->prox;
    }

    return l3;
}

int main()
{

    p_no lista;
    p_no lista2;

    lista = criar_lista();
    lista2 = criar_lista();

    lista = adicionar_elemento(lista, 2);
    lista = adicionar_elemento(lista, 6);
    lista = adicionar_elemento(lista, 7);
    lista = adicionar_elemento(lista, 9);
    lista = adicionar_elemento(lista, 11);

    lista2 = adicionar_elemento(lista2, 1);
    lista2 = adicionar_elemento(lista2, 2);
    lista2 = adicionar_elemento(lista2, 3);
    lista2 = adicionar_elemento(lista2, 4);
    lista2 = adicionar_elemento(lista2, 5);
    lista2 = adicionar_elemento(lista2, 6);
    lista2 = adicionar_elemento(lista2, 7);


    p_no lista3 = unir_listas(lista, lista2);

    imprimir_lista(lista3);

    return 0;
}