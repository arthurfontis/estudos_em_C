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

p_no clonar_lista(p_no lista){
    p_no novo;
    if(lista == NULL){
        return NULL;
    }
    novo = malloc(sizeof(struct no));

    novo->dado = lista->dado;
    novo->prox = clonar_lista(lista->prox);
    return novo;
}

p_no lista_invertida(p_no lista){
    p_no atual, ant, invertida = NULL;
    atual = lista;
    while (atual != NULL)
    {
        ant = atual;
        atual = ant->prox;
        ant->prox = invertida;
        invertida = ant;
    }
    return invertida;
}

p_no concatenar(p_no l1, p_no l2){
    if(l1 == NULL)
    return l2;
    l1->prox = concatenar(l1->prox, l2);
    return l1;
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

    p_no listaCopiada = clonar_lista(lista2);

    imprimir_lista(listaCopiada);
    
    printf("--------------\n");
    
    p_no inversa = lista_invertida(listaCopiada);
    imprimir_lista(inversa);
    
    p_no lista_concat;
    lista_concat = malloc(sizeof(struct no));
    
    lista_concat = concatenar(lista, lista2);
    printf("--------------\n");
    imprimir_lista(lista_concat);


    return 0;
}