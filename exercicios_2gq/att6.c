#include <stdio.h>

void incrementa_pares(int *p, int n){
    for (int i = 0; i< n; i++){
        if (p[i] % 2 == 0){
            *(p + i) += 1;
        }
    }
}

int main(){
    int v[5] = { 3, 20, 2, 40, 5};
    int n = 5;

    printf("Vetor original:\n");
    for (int i = 0; i < n; i++) {
        printf("v[%d] = %d  (endereco: %p)\n", i, v[i], &v[i]);
    }

    incrementa_pares(v, n);

    printf("\nDepois de dobrar():\n");
    for (int i = 0; i < n; i++) {
        printf("v[%d] = %d  (endereco: %p)\n", i, v[i], &v[i]);
    }

}