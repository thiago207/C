#include <stdio.h>


int main() {

    // Atividade
    // Leia um nome completo. Imprima o nome digitado e endereço de memória do primeiro caractere da string.

    char nome_completo[40];

    printf("Digite seu nome completo: ");

    fgets(nome_completo, 40, stdin);

    for (int i = 0; i < 40; i++) {
        if (nome_completo[i] == '\n') {   
            nome_completo[i] = '\0';      
            break;            
        }
    }

    printf("Seu nome completo: \"%s\"\n", nome_completo);
    
    printf("Endereco de memoria do 1 elemento do seu nome ('%c'): %p\n", nome_completo[0], &nome_completo[0]);

    
    return 0;
}
