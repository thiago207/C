/*
Atividade
    Escreva um programa que:
    1. Peça ao usuário um número n.
    2. Aloque dinamicamente um vetor de n floats.
    3. Leia os valores, calcule e exiba a média.
    4. Libere a memória ao final.
*/

#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    float soma, media;  
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);

    float *v = malloc(n * sizeof(float));

    for (int i = 0; i < n; i++){
        printf("Digite o valor v[%d]: \n", i);
        scanf("%f", &v[i]);
        soma += v[i];
    }
     for (int i = 0; i < n; i++){
        printf("v[%d] = %.2f \n", i, v[i]);
    }
    media = soma / n;

    printf("A media foi: %.2f", media);

    free(v);
    return 0;
}