#include <stdio.h>


int busca_sequencial(int vetor[], int tamanho_vetor, int valor_buscado) {
    
    for (int i = 0; i < tamanho_vetor; i++){
        if (vetor[i] == valor_buscado){
            return i;
        }
    }
}
int main(){

    
}