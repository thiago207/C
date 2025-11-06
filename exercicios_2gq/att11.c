// Atividade
// Crie um programa que leia de um arquivo numeros.txt uma lista de inteiros, 
// calcule a média e grave em um novo arquivo media.txt a média e a quantidade de valores lidos.

/*
fprintf()
Escreve dados formatados em um arquivo (semelhante ao printf).
int fprintf(FILE *arquivo, char *formato, ...);
retorna o número de caracteres gravados, ou valor negativo em caso de erro.

fscanf()
Lê dados formatados de um arquivo (semelhante ao scanf).
int fscanf(FILE *arquivo, char *formato, ...);
retorna a quantidade de itens lidos com sucesso, ou EOF se alcançar o fim do arquivo.
fscanf() lê até encontrar um espaço, quebra de linha ou fim do arquivo. Para ler linhas inteiras, use fgets().
*/
#include <stdio.h>

int main() {

    FILE *entrada, *saida;
    int numero, quantidade = 0;
    float soma = 0, media;
    char linha[100];

    // Abre o arquivo de entrada
    entrada = fopen("numeros.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo numeros.txt\n");
        return 1;
    }

    // Lê os números e calcula a soma e a quantidade
    while (fscanf(entrada, "%d", &numero) == 1) { // ← usa == 1 em vez de != EOF
        soma += numero;
        quantidade++;
    }

    fclose(entrada);

    if (quantidade == 0) {
        printf("Nenhum número encontrado no arquivo.\n");
        return 1;
    }

    media = soma / quantidade;

    saida = fopen("media.txt", "w");
    if (saida == NULL) {
        printf("Erro ao criar o arquivo media.txt\n");
        return 1;
    }

    // Grava a média e a quantidade no arquivo
    fprintf(saida, "Média: %.2f\nQuantidade de valores: %d\n", media, quantidade);
    fclose(saida);

    printf("Arquivo media.txt criado com sucesso!\n\n");

    // Reabre o arquivo para leitura
    saida = fopen("media.txt", "r");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo media.txt\n");
        return 1;
    }

    printf("Conteúdo do arquivo media.txt:\n");
    while (fgets(linha, sizeof(linha), saida)) {
        printf("%s", linha);
    }

    fclose(saida); 
    return 0;
}
