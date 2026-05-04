#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    system("cls");

    for (int i = 0; i < 3; i++)
    {
        int chute = 0;
        scanf("%d", &chute);
        if(chute == n){
            printf("Acertou");
        }
        else if (i == 2 && chute != n)
        {
            printf("Errou");
        }
        
    }
    


    return 0;
}