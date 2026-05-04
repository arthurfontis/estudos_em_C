#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char str1[10] = "Fontis!";
    char str2[10] = "ola";

    //printf("%d", strlen(str1));
    //printf("\n%d", strlen(str2));

    printf("\n%s", str1);
    printf("\n%s", str2);

    //strcpy(str1, str2);

    //printf("\n%s", str1);
    
    //strcat(str1, str2);
    //printf("\n\n%s", str1);


    int teste_comp = strcmp(str1, str2);

    printf("\n\n%d", teste_comp);
    

    return 0;
}