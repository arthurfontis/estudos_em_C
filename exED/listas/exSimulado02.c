#include <stdlib.h>
#include <stdio.h>


typedef struct no *p_no;

struct no
{
    int valor;
    p_no prox;
    p_no ant;
};

p_no criarNo(int valor){
    p_no novo = (p_no)malloc(sizeof(struct no));
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;

    return novo;
}

p_no inserir_inicio(p_no lista, int valor){
    p_no novo = criarNo(valor);
    if(lista != NULL){
        novo->prox = lista;
        lista->ant = novo;
    }
    return novo;
}

p_no inserir_final(p_no lista, int valor){
    p_no novo = criarNo(valor);

    if(lista == NULL) return novo;

    p_no atual = lista;
    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }

    atual->prox = novo;
    novo->ant = atual;

    return lista;
}

p_no inserir_posicao(p_no lista, int valor, int posicao){
    if(posicao <=1 || lista == NULL){
        return inserir_inicio(lista,valor);
    }

    p_no atual = lista;
    int count = 1;

    while (count < posicao - 1 && atual->prox != NULL)
    {
        atual = atual->prox;
        count++;
    }
    
    if(atual->prox == NULL){
        return inserir_final(lista, valor);
    }

    p_no novo = criarNo(valor);
    novo->prox = atual->prox;
    novo->ant = atual;
    atual->prox->ant = novo;
    atual->prox = novo;
    
    return lista;
}

p_no remover_inicio(p_no lista){
    if(lista == NULL) return NULL;

    p_no aux = lista;
    lista = lista->prox;
    if(lista != NULL){
        lista->ant = NULL;
    }
    free(aux);
    return lista;
}

p_no remover_final(p_no lista){
    if(lista == NULL) return NULL;
    if(lista->prox == NULL){
        free(lista);
        return NULL;
    }

    p_no atual = lista;
    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }

    atual->ant->prox = NULL;
    free(atual);
    return lista;    
}

p_no remover_posicao(p_no lista, int posicao){
    if(lista == NULL) return NULL;
    if(posicao <= 1) return remover_inicio(lista);

    p_no atual = lista;
    int count = 1;
    while (count < posicao && atual != NULL)
    {
        atual = atual->prox;
        count++;
    }

    if(atual == NULL) return lista;
    if(atual->prox == NULL)return remover_final(lista);

    atual->ant->prox = atual->prox;
    atual->prox->ant = atual->ant;
    free(atual);

    return lista;
}

void imprimir_lista(p_no lista){
    if(lista == NULL){
        printf("Lista vazia.\n");
        return;
    }
    p_no atual = lista;
    while (atual != NULL)
    {
        int tem_ant = (atual->ant != NULL) ? 1 : 0;
        int tem_prox = (atual->prox != NULL) ? 1 : 0;
        printf("[%d | Ant: %d | Prox: %d] -> ", atual->valor, tem_ant, tem_prox);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void imprimir_reverso(p_no lista){
    if(lista == NULL){
        printf("Lista vazia.\n");
        return;
    }
    
    p_no atual = lista;
    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }
    
    while (atual != NULL)
    {
        int tem_ant = (atual->ant != NULL) ? 1 : 0;
        int tem_prox = (atual->prox != NULL) ? 1 : 0;
        printf("[%d | Ant: %d | Prox: %d] -> ", atual->valor, tem_ant, tem_prox);
        atual = atual->ant;
    }
    printf("NULL\n");
    
}

p_no liberar_lista(p_no lista){
    p_no atual = lista;
    while (atual != NULL)
    {
        p_no aux = atual->prox;
        free(atual);
        atual = aux;
    }
    return NULL;
}

int main(){
    
    p_no lista = NULL; // Inicializa a lista vazia

    printf("--- INÍCIO DOS TESTES ---\n");
    
    printf("\n1. Imprima a lista:\n");
    imprimir_lista(lista);

    printf("\n2. Adicione 43 e 65 no final da lista:\n");
    lista = inserir_final(lista, 43);
    lista = inserir_final(lista, 65);

    printf("\n3. Imprima a lista:\n");
    imprimir_lista(lista);

    printf("\n4. Adicione 56 e 12 no início da lista:\n");
    lista = inserir_inicio(lista, 56);
    lista = inserir_inicio(lista, 12);

    printf("\n5. Imprima a lista:\n");
    imprimir_lista(lista);

    printf("\n6. Adicione 10 na 3ª posição e 15 na 1ª posição:\n");
    lista = inserir_posicao(lista, 10, 3);
    lista = inserir_posicao(lista, 15, 1);

    printf("\n7. Imprima a lista:\n");
    imprimir_lista(lista);

    printf("\n8. Remova os 3 últimos nós da lista:\n");
    lista = remover_final(lista);
    lista = remover_final(lista);
    lista = remover_final(lista);

    printf("\n9. Imprima a lista:\n");
    imprimir_lista(lista);

    printf("\n10. Remova os 3 primeiros nós da lista:\n");
    lista = remover_inicio(lista);
    lista = remover_inicio(lista);
    lista = remover_inicio(lista);

    printf("\n11. Imprima a lista:\n");
    imprimir_lista(lista);
    
    // Para testar as remoções específicas abaixo de forma consistente,
    // vamos reinserir alguns elementos para a lista não ficar vazia.
    printf("\n[Ajuste para os próximos testes: Inserindo 99, 88, 77, 66]\n");
    lista = inserir_final(lista, 99);
    lista = inserir_final(lista, 88);
    lista = inserir_final(lista, 77);
    lista = inserir_final(lista, 66);
    imprimir_lista(lista);

    printf("\n12. Remova o nó na última posição e o nó na 3ª posição:\n");
    lista = remover_final(lista);       // Remove o último
    lista = remover_posicao(lista, 3);  // Remove o 3º elemento atual

    printf("\n13. Imprima a lista:\n");
    imprimir_lista(lista);

    printf("\n14. Imprima a lista de trás para frente:\n");
    imprimir_reverso(lista);

    printf("\n15. Libere a lista.\n");
    lista = liberar_lista(lista);
    
    return 0;
    
}