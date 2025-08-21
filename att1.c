#include <stdio.h>

int main() {
    printf("Ola, mundo!\n");    

    float peso;
    float altura;
    float imc;
    printf("Digite seu peso: ");
    scanf("%f", &peso);

    printf("Digite sua altura: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("Seu IMC: %.2f", imc);
    
    return 0;
}