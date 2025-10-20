#include <stdio.h>

int busca_binaria(int vetor[], int tamanho_vetor, int valor_buscado) {
    int ini = 0;
    int fim = tamanho_vetor - 1;
    int pos = -1;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;

        if (vetor[meio] == valor_buscado) {
            pos = meio;
            return pos; 
        } else if (vetor[meio] < valor_buscado) {
            ini = meio + 1; 
        } else {
            fim = meio - 1; 
        }
    }

    return -1; 
}


int busca_sequencial(int vetor[], int tamanho_vetor, int valor_buscado) {
    for (int i = 0; i < tamanho_vetor; i++){
        if (vetor[i] == valor_buscado){
            return i;
        }
    }
}

void selection_sort(int v[], int n) {
    int temp, menor, i, j;
    
    for (i = 0; i < n; i++ ){
        for (j = i + 1; j < n; j++){
            if (v[j] < v[menor]){
                menor = j;
            }
        }

        temp = v[i];
        v[i] = v[menor];
        v[menor] = temp;
    }

}

void bubble_sort(int v[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                // Troca os elementos
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        } 
    }
}

int main() {
    int vetor[] = {8, 3, 10, 1, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor_buscado;

    printf("Vetor original: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    // Ordenando com Selection Sort
    selection_sort(vetor, tamanho);

    printf("\nVetor ordenado (Selection Sort): ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    // Busca Sequencial
    printf("\n\nDigite um valor para busca sequencial: ");
    scanf("%d", &valor_buscado);

    int pos_seq = busca_sequencial(vetor, tamanho, valor_buscado);
    if (pos_seq != -1)
        printf("Valor %d encontrado na posicao %d (sequencial).\n", valor_buscado, pos_seq);
    else
        printf("Valor %d nao encontrado (sequencial).\n", valor_buscado);

    // Busca Binária (funciona com vetor já ordenado)
    printf("\nDigite um valor para busca binaria: ");
    scanf("%d", &valor_buscado);

    int pos_bin = busca_binaria(vetor, tamanho, valor_buscado);
    if (pos_bin != -1)
        printf("Valor %d encontrado na posicao %d (binaria).\n", valor_buscado, pos_bin);
    else
        printf("Valor %d nao encontrado (binaria).\n", valor_buscado);

    return 0;
    
}
 