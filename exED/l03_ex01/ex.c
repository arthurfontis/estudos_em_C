#include <stdio.h>

int main(){
    char str[200];
    int atual = 0;
    int max = 0;

    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '0'){
            atual++;
        }
        if(atual > max){
            max = atual;
        }
    }

    printf("%d", max);
}