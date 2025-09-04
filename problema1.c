#include <stdio.h>

int main(){

    float notas[10];
    float media = 0;
    float soma = 0;
    int quantidade_acima_media = 0;

    for (int i = 1; i < 11; i++) {
        printf("Digite a nota %d: ", i);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    media = soma / 10;

    for (int i = 1; i < 11; i++) {
        if (notas[i] > media) {
            quantidade_acima_media++;
        }
    }

    printf("Media dos 10 alunos: %f \n", media);

    printf("Quantidade alunos acima da media: %d", quantidade_acima_media);

    return 0;

}