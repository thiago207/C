#include <stdio.h>

void troca_char(char *p1, char *p2) {
    char temp[100];  

    strcpy(temp, p1);  
    strcpy(p1, p2);    
    strcpy(p2, temp);  
}

int main() {
    char a[30] = "Cristiano";
    char b[30] = "Messi";


    printf("ANTES DA FUNCAO (A): %s\n", a);
    printf("ANTES DA FUNCAO (B): %s\n", b);

    troca_char(a, b);

    printf("DEPOIS DA FUNCAO (A): %s\n", a);
    printf("DEPOIS DA FUNCAO (B): %s\n", b);

    return 0;
}