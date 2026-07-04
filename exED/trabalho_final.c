#include <stdio.h>
#include <stdlib.h>

struct Vizinho {
    int casaDestino;
    char movimento;
    struct Vizinho *proximo;
};

struct Vizinho *listaDeVizinhos[1000000];
int distancia[1000000];
int veioDe[1000000];
char movimentoParaChegar[1000000];
int filaBFS[1000000];

void adicionarVizinho(int casaOrigem, int casaDestino, char movimento) {
    struct Vizinho *novo = malloc(sizeof(struct Vizinho));
    novo->casaDestino = casaDestino;
    novo->movimento = movimento;
    novo->proximo = listaDeVizinhos[casaOrigem];
    listaDeVizinhos[casaOrigem] = novo;
}

int main(void) {
    int altura, largura;
    scanf("%d %d", &altura, &largura);

    char mapa[1000][1001];
    int linhaAluno, colunaAluno, linhaRU, colunaRU;

    for (int linha = 0; linha < altura; linha++) {
        for (int coluna = 0; coluna < largura; coluna++) {
            scanf(" %c", &mapa[linha][coluna]);
            if (mapa[linha][coluna] == 'A') { linhaAluno = linha; colunaAluno = coluna; }
            if (mapa[linha][coluna] == 'R') { linhaRU = linha; colunaRU = coluna; }
        }
    }

    int deltaLinha[4]  = {-1, 1, 0, 0};
    int deltaColuna[4] = {0, 0, -1, 1};
    char letraDoMovimento[4] = {'C', 'B', 'E', 'D'};

    for (int linha = 0; linha < altura; linha++) {
        for (int coluna = 0; coluna < largura; coluna++) {
            if (mapa[linha][coluna] == '@') continue;
            int casaAtual = linha * largura + coluna;
            for (int d = 0; d < 4; d++) {
                int linhaVizinha  = linha + deltaLinha[d];
                int colunaVizinha = coluna + deltaColuna[d];
                if (linhaVizinha < 0 || linhaVizinha >= altura || colunaVizinha < 0 || colunaVizinha >= largura) continue;
                if (mapa[linhaVizinha][colunaVizinha] == '@') continue;
                adicionarVizinho(casaAtual, linhaVizinha * largura + colunaVizinha, letraDoMovimento[d]);
            }
        }
    }

    int casaInicial = linhaAluno * largura + colunaAluno;
    int casaFinal    = linhaRU * largura + colunaRU;

    int totalDeCasas = altura * largura;
    for (int i = 0; i < totalDeCasas; i++) distancia[i] = -1;

    int inicioDaFila = 0, fimDaFila = 0;
    filaBFS[fimDaFila] = casaInicial;
    fimDaFila++;
    distancia[casaInicial] = 0;

    while (inicioDaFila < fimDaFila) {
        int casaAtual = filaBFS[inicioDaFila];
        inicioDaFila++;
        if (casaAtual == casaFinal) break;

        struct Vizinho *vizinho = listaDeVizinhos[casaAtual];
        while (vizinho != NULL) {
            if (distancia[vizinho->casaDestino] == -1) {
                distancia[vizinho->casaDestino] = distancia[casaAtual] + 1;
                veioDe[vizinho->casaDestino] = casaAtual;
                movimentoParaChegar[vizinho->casaDestino] = vizinho->movimento;
                filaBFS[fimDaFila] = vizinho->casaDestino;
                fimDaFila++;
            }
            vizinho = vizinho->proximo;
        }
    }

    if (distancia[casaFinal] == -1) {
        printf("VOU MORRER DE FOME\n");
        return 0;
    }

    int totalDePassos = distancia[casaFinal];
    char caminho[1000001];
    int casaAtual = casaFinal;
    int posicao = totalDePassos - 1;

    while (casaAtual != casaInicial) {
        caminho[posicao] = movimentoParaChegar[casaAtual];
        posicao--;
        casaAtual = veioDe[casaAtual];
    }
    caminho[totalDePassos] = '\0';

    printf("AMEM\n%s\n%d\n", caminho, totalDePassos);
    return 0;
}