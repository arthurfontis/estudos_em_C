#include <stdio.h>
#include <stdlib.h>

int maximo(int *v,int n){
    if(n == 1){
        return v[0];
    }
    int m = maximo(v,n-1);

    if(v[n-1] > m){
        m = v[n-1];
    }else {
        return m;
    }

}


int main(){
    int v[5] = {2,42,8,50,30};
    int teste = maximo(v,5);

    printf("%d", teste);

    return 0;
}