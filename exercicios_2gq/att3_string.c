// Atividade
// Leia duas palavras armazenando em strings diferentes, 
// copie para uma terceira string aquela que for menor e imprima.
#include <stdio.h>
#include <string.h>

int main() {
    char a[20];
    char b[20];
    char c_copia[20];

    printf("Digite a primeira palavra: ");
    fgets(a, 20, stdin);

    printf("Digite a segunda palavra: ");
    fgets(b, 20, stdin);

    if (strlen(a) < strlen(b)) {
        strcpy(c_copia, a);  // copia a menor
    } else if (strlen(b) < strlen(a)) {
        strcpy(c_copia, b);  // copia a menor
    } else {
        strcpy(c_copia, "Iguais"); // se tiverem o mesmo tamanho
    }

    printf("Copia menor: %s", c_copia);
    
    return 0;
}