#include <stdio.h>

int main() {
    // Atividade
    // inicialize uma string com a palavra Pernambuco, imprima apenas Perna 

    char p[] = "Pernambuco";

    for (int i = 0; p[i] != '\0'; i++) {
        if (p[i] == 'm'){
            p[i] = '\0';
            break;
        }

    }
    printf("%s", p);

}

