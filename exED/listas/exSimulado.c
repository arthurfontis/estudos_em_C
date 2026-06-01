#include <stdio.h>
#include <stdlib.h>
// Q1
struct no;

typedef struct no *p_no;

struct no {
    int chave;
    int tempo;
    p_no prox;
    p_no ant;
};

p_no criarNo(int chave, int tempo){
    p_no novo = (p_no)malloc(sizeof(struct no));
    novo->chave = chave;
    novo->tempo = tempo;
    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}

p_no encontrarNo(p_no cabeca, int posicao){
    p_no atual = cabeca;
    int i = 0;
    while (atual != NULL && i <posicao)
    {
        atual = atual->prox;
        i++;
    }
    return atual;
}

p_no inserirNo(p_no cabeca, int chave, int j, int tempoAtual){
    p_no novo = criarNo(chave, tempoAtual);
    if(cabeca == NULL) return novo;

    p_no atual = cabeca;
    int totalNos = 1;
    while (atual->prox != NULL)
    {
        atual = atual->prox;
        totalNos++;
    }

    atual->prox = novo;

    if(j > 0){
        int posicaoAlvo = totalNos - j;
        if(posicaoAlvo >= 0){
            novo->ant = encontrarNo(cabeca, posicaoAlvo);
        }
    }

    return cabeca;
}

p_no removerNo(p_no cabeca, int chave){
    if(cabeca == NULL) return NULL;

    p_no atual = cabeca;
    p_no anterior = NULL;
    p_no noParaRemover = NULL;

    //encontrar no com a chave passada
    while (atual != NULL)
    {
        if(atual->chave == chave){
            noParaRemover = atual;
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }

    if(noParaRemover == NULL){
        return cabeca;
    }

    //atualização de ponteiros back
    atual = cabeca;
    while (atual != NULL)
    {
        if(atual->ant == noParaRemover){
            atual->ant = NULL;
        }
        atual = atual->prox;
    }

    //remoção do NO na lista
    if(anterior == NULL){
        //o no para remover é a cabeca
        cabeca = noParaRemover->prox;
    } else {
        anterior->prox = noParaRemover->prox;
    }

    free(noParaRemover);

    return cabeca;
}

int obterPosNo(p_no cabeca, p_no alvo){
    if(alvo == NULL) return -1;
    p_no atual = cabeca;
    int posicao = 0;

    while (atual != NULL)
    {
        if(atual == alvo) return posicao;
        atual = atual->prox;
        posicao++;    
    }
    return -1;
}

void imprimirLista(p_no cabeca){
    if(cabeca == NULL){
        printf("-1\n");
        return;
    }

    p_no atual = cabeca;
    int primeiro = 1;
    while (atual != NULL)
    {
        if(!primeiro){
            printf(" ");
        }
        primeiro = 0;
        if(atual->ant != NULL) {
            int posBack = obterPosNo(cabeca,atual->ant);
            printf("[%d,%d,%d]", atual->chave, atual->tempo, posBack);
        } else {
            printf("[%d,%d]", atual->chave, atual->tempo);
        }
        atual = atual->prox;
    }
    printf("\n");
}

int main(){

    p_no lista = NULL;
    char operacao;
    int tempoGlobal = 0;

    while(scanf(" %c", &operacao) && operacao != 'f'){
        if(operacao == 'i'){
            int n, j;
            scanf("%d %d", &n, &j);
            lista = inserirNo(lista,n,j,tempoGlobal);
            tempoGlobal++;
        }
        else if(operacao == 'r'){
            int n;
            scanf("%d", &n);
            lista = removerNo(lista, n);
            tempoGlobal++;
        }
    }

    imprimirLista(lista);
    while (lista != NULL)
    {
        p_no aux = lista;
        lista = lista->prox;
        free(aux);
    }
    

    return 0;
}