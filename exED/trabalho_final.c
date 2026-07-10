#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000000

typedef struct Aresta {
    int destino;
    char movimento;
    struct Aresta *proxima;
} Aresta;

Aresta *listaDeAdjacencia[MAX_VERTICES];
char mapa[1000][1001];
int distancia[MAX_VERTICES];
int veioDe[MAX_VERTICES];
char movimentoParaChegar[MAX_VERTICES];
int fila[MAX_VERTICES];

int altura, largura;

int deltaLinha[4]  = {-1, 1, 0, 0};
int deltaColuna[4] = {0, 0, -1, 1};
char letraDoMovimento[4] = {'C', 'B', 'E', 'D'};

void adicionarAresta(int origem, int destino, char movimento) {
    Aresta *nova = (Aresta *) malloc(sizeof(Aresta));
    nova->destino = destino;
    nova->movimento = movimento;
    nova->proxima = listaDeAdjacencia[origem];
    listaDeAdjacencia[origem] = nova;
}

int indiceDoVertice(int linha, int coluna) {
    return linha * largura + coluna;
}

void construirGrafo(void) {
    for (int linha = 0; linha < altura; linha++) {
        for (int coluna = 0; coluna < largura; coluna++) {
            if (mapa[linha][coluna] == '@') {
                continue;
            }

            int origem = indiceDoVertice(linha, coluna);

            for (int d = 0; d < 4; d++) {
                int novaLinha = linha + deltaLinha[d];
                int novaColuna = coluna + deltaColuna[d];

                if (novaLinha < 0 || novaLinha >= altura ||
                    novaColuna < 0 || novaColuna >= largura) {
                    continue;
                }
                if (mapa[novaLinha][novaColuna] == '@') {
                    continue;
                }

                int destino = indiceDoVertice(novaLinha, novaColuna);
                adicionarAresta(origem, destino, letraDoMovimento[d]);
            }
        }
    }
}

void bfs(int verticeInicial, int verticeFinal, int totalDeVertices) {
    for (int i = 0; i < totalDeVertices; i++) {
        distancia[i] = -1;
    }

    int inicioDaFila = 0, fimDaFila = 0;

    fila[fimDaFila] = verticeInicial;
    fimDaFila++;
    distancia[verticeInicial] = 0;

    while (inicioDaFila < fimDaFila) {
        int verticeAtual = fila[inicioDaFila];
        inicioDaFila++;

        if (verticeAtual == verticeFinal) {
            break;
        }

        Aresta *aresta = listaDeAdjacencia[verticeAtual];
        while (aresta != NULL) {
            if (distancia[aresta->destino] == -1) {
                distancia[aresta->destino] = distancia[verticeAtual] + 1;
                veioDe[aresta->destino] = verticeAtual;
                movimentoParaChegar[aresta->destino] = aresta->movimento;

                fila[fimDaFila] = aresta->destino;
                fimDaFila++;
            }
            aresta = aresta->proxima;
        }
    }
}

int main(void) {
    scanf("%d %d", &altura, &largura);

    int linhaAluno, colunaAluno, linhaRU, colunaRU;

    for (int linha = 0; linha < altura; linha++) {
        for (int coluna = 0; coluna < largura; coluna++) {
            scanf(" %c", &mapa[linha][coluna]);

            if (mapa[linha][coluna] == 'A') {
                linhaAluno = linha;
                colunaAluno = coluna;
            }
            if (mapa[linha][coluna] == 'R') {
                linhaRU = linha;
                colunaRU = coluna;
            }
        }
    }

    construirGrafo();

    int verticeInicial = indiceDoVertice(linhaAluno, colunaAluno);
    int verticeFinal = indiceDoVertice(linhaRU, colunaRU);
    int totalDeVertices = altura * largura;

    bfs(verticeInicial, verticeFinal, totalDeVertices);

    if (distancia[verticeFinal] == -1) {
        printf("VOU MORRER DE FOME\n");
        return 0;
    }

    int totalDePassos = distancia[verticeFinal];
    char caminho[1000001];

    int verticeAtual = verticeFinal;
    int posicao = totalDePassos - 1;

    while (verticeAtual != verticeInicial) {
        caminho[posicao] = movimentoParaChegar[verticeAtual];
        posicao--;
        verticeAtual = veioDe[verticeAtual];
    }
    caminho[totalDePassos] = '\0';

    printf("AMEM\n%s\n%d\n", caminho, totalDePassos);
    return 0;
}