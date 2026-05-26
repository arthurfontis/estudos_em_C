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

p_no adicionando_elementos_listaCircular(p_no lista, int x)
{
    p_no novo;
    novo = malloc(sizeof(struct no));
    novo->dado = x;

    if (lista == NULL)
    {
        novo->prox = novo;
        lista = novo;
    }
    else
    {
        novo->prox = lista->prox;
        lista->prox = novo;
    }
    return lista;
}

void imprimir_listaCircular(p_no lista)
{
    p_no atual = lista->prox;
    do
    {
        printf("%d\n", atual->dado);
        atual = atual->prox;
    } while (atual != lista->prox);
}

p_no buscar_no(p_no lista, int valor)
{
    if (lista == NULL)
        return NULL;
    p_no atual = lista->prox;
    do
    {
        if (atual->dado == valor)
        {
            return atual;
        }
        atual = atual->prox;
    } while (atual != lista->prox);
    return NULL;
}

p_no remover_no(p_no lista, p_no no)
{
    p_no ant;
    if (no->prox == no)
    {
        free(no);
        return NULL;
    }
    for (ant = no->prox; ant->prox != no; ant = ant->prox)
        ;
    ant->prox = no->prox;
    if (lista == no)
    {
        lista = ant;
    }
    free(no);
    return lista;
}

p_no unir_listas(p_no l1, p_no l2)
{
    p_no p = l1;
    while (p->prox != l1)
    {
        p = p->prox;
    }
    p->prox = l2;
    p = l2;
    while (p->prox != l2)
    {
        p = p->prox;
    }
    p->prox = l1;

    return l1;
}
p_no unir_listas_corrigida(p_no l1, p_no l2)
{
    // Tratamento caso alguma das listas esteja vazia
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    // Guarda quem são os "primeiros" elementos de cada lista
    p_no primeiro_l1 = l1->prox;
    p_no primeiro_l2 = l2->prox;

    // O fim da lista 1 aponta para o começo da lista 2
    l1->prox = primeiro_l2;

    // O fim da lista 2 aponta para o começo da lista 1
    l2->prox = primeiro_l1;

    // Retorna l1 (ou l2, tanto faz, o círculo agora é um só)
    return l1;
}

int main()
{
    p_no lista = criar_lista();
    p_no lista2 = criar_lista();
    lista = adicionando_elementos_listaCircular(lista, 1);
    lista = adicionando_elementos_listaCircular(lista, 2);
    lista = adicionando_elementos_listaCircular(lista, 3);
    lista = adicionando_elementos_listaCircular(lista, 4);
    lista = adicionando_elementos_listaCircular(lista, 5);
    
    lista2 = adicionando_elementos_listaCircular(lista2, 11);
    lista2 = adicionando_elementos_listaCircular(lista2, 61);
    lista2 = adicionando_elementos_listaCircular(lista2, 1);
    lista2 = adicionando_elementos_listaCircular(lista2, 0);

    printf("---------\n");
    imprimir_listaCircular(lista);
    
    p_no remover = buscar_no(lista, 4);
    lista = remover_no(lista, remover);
    printf("---------\n");
    imprimir_listaCircular(lista);
    
    printf("---------\n");
    p_no concat = unir_listas_corrigida(lista, lista2);
    imprimir_listaCircular(concat);

    return 0;
}