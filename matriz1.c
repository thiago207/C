#include <stdio.h>

int main(){
    int v[2][2];
    float soma;
    for (int i=0 ;  i < 2; i++){
        for (int j=0; j < 2; j++){
            soma += v[i][j];
            scanf("%d", &v[i][j]);
        }
    }

    return 0;
}

