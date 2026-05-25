#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51];
    char sobrenome[51];
    int altura;
    int peso;
} Pretendente;

// Função de comparação usada pelo qsort
int comparar(const void *a, const void *b) {

    Pretendente *p1 = (Pretendente *)a;
    Pretendente *p2 = (Pretendente *)b;

    // 1º critério:
    // menor distância da altura ideal (180 cm)

    int distAltura1 = abs(p1->altura - 180);
    int distAltura2 = abs(p2->altura - 180);

    if (distAltura1 != distAltura2) {
        return distAltura1 - distAltura2;
    }

    // 2º critério:
    // menor distância do peso ideal (75 kg)

    int distPeso1 = abs(p1->peso - 75);
    int distPeso2 = abs(p2->peso - 75);

    if (distPeso1 != distPeso2) {
        return distPeso1 - distPeso2;
    }

    // 3º critério:
    // se altura igual, prefere o mais leve

    if (p1->peso != p2->peso) {
        return p1->peso - p2->peso;
    }

    // 4º critério:
    // ordenar por sobrenome

    int sobrenomeCmp = strcmp(p1->sobrenome, p2->sobrenome);

    if (sobrenomeCmp != 0) {
        return sobrenomeCmp;
    }

    // 5º critério:
    // ordenar por nome

    return strcmp(p1->nome, p2->nome);
}

int main() {

    int N;

    scanf("%d", &N);

    Pretendente lista[100];

    for (int i = 0; i < N; i++) {

        scanf("%s %s %d %d",
              lista[i].nome,
              lista[i].sobrenome,
              &lista[i].altura,
              &lista[i].peso);
    }

    // Ordena usando qsort
    qsort(lista, N, sizeof(Pretendente), comparar);

    // Saída
    for (int i = 0; i < N; i++) {
        printf("%s, %s\n",
               lista[i].sobrenome,
               lista[i].nome);
    }

    return 0;
}