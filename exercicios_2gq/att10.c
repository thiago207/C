#include <stdio.h>
#include <string.h>

int main() {
    FILE *arquivo;
    char nome[100], curso[100];
    char linha[200];

 
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite o nome do curso: ");
    fgets(curso, sizeof(curso), stdin);

    nome[strlen(nome) - 1] = '\0';
    curso[strlen(curso) - 1] = '\0';


    arquivo = fopen("saida.txt", "w");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return 1;
    }

    fputs(nome, arquivo);
    fputs("\n", arquivo);
    fputs(curso, arquivo);
    fputs("\n", arquivo);

    fclose(arquivo);

    arquivo = fopen("saida.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return 1;
    }

    printf("\nConteudo do arquivo 'saida.txt':\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);
    return 0;
}
