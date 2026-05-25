#include <stdio.h>
#include <stdlib.h>

int ira_alunos(const void *a, const void *b){
    float x = *(float *)a;
    float y = *(float *)b;
   
    if (x > y) return -1;
    if (x < y) return 1;
    return 0;
}

int main() {
   
    float alunos[200];
    int N;
    float IRA;
   
    scanf("%d", &N);
   
   
   
    for (int i = 0; i < N; i++){
        scanf("%f", &IRA);
        alunos[i] = IRA;
    }
   
   
    qsort(alunos, N, sizeof(int), ira_alunos);
   
    for(int i= 0; i < N; i++){
        printf("\n%.2f", alunos[i]);
    }
   
   
    return 0;
}