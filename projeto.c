#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 20
#define TAM_CODIGO 20
#define TAM_NOME 50
#define ARQUIVO "produtos.txt"

typedef struct {
    char codigo[TAM_CODIGO];
    char nome[TAM_NOME];
    float preco;
    int quantidade;
} Produto;

Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

// Função para ler produtos do arquivo
void lerArquivo() {
    FILE *arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) {
        printf("Arquivo não encontrado. Será criado ao adicionar produtos.\n");
        return;
    }
    
    totalProdutos = 0;
    while (fscanf(arquivo, "%s %[^\n] %f %d\n", 
                  produtos[totalProdutos].codigo,
                  produtos[totalProdutos].nome,
                  &produtos[totalProdutos].preco,
                  &produtos[totalProdutos].quantidade) == 4) {
        totalProdutos++;
        if (totalProdutos >= MAX_PRODUTOS) break;
    }
    
    fclose(arquivo);
    printf("Arquivo carregado com sucesso! Total de produtos: %d\n", totalProdutos);
}

// Função para salvar produtos no arquivo
void salvarArquivo() {
    FILE *arquivo = fopen(ARQUIVO, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para escrita!\n");
        return;
    }
    
    for (int i = 0; i < totalProdutos; i++) {
        fprintf(arquivo, "%s %s\n%.2f %d\n",
                produtos[i].codigo,
                produtos[i].nome,
                produtos[i].preco,
                produtos[i].quantidade);
    }
    
    fclose(arquivo);
}

// Função para adicionar produto
void adicionarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("\nLimite de produtos atingido!\n");
        return;
    }
    
    Produto novo;
    
    printf("\n=== ADICIONAR PRODUTO ===\n");
    printf("Código: ");
    scanf("%s", novo.codigo);
    getchar(); // Limpa o buffer
    
    // Verifica se o código já existe
    for (int i = 0; i < totalProdutos; i++) {
        if (strcmp(produtos[i].codigo, novo.codigo) == 0) {
            printf("Erro: Código já existe!\n");
            return;
        }
    }
    
    printf("Nome: ");
    fgets(novo.nome, TAM_NOME, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0; // Remove newline
    
    printf("Preço: ");
    scanf("%f", &novo.preco);
    
    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    
    produtos[totalProdutos] = novo;
    totalProdutos++;
    
    salvarArquivo();
    printf("\nProduto adicionado com sucesso!\n");
}

// Função para buscar produto por código
void buscarProduto() {
    char codigo[TAM_CODIGO];
    
    printf("\n=== BUSCAR PRODUTO ===\n");
    printf("Digite o código: ");
    scanf("%s", codigo);
    
    for (int i = 0; i < totalProdutos; i++) {
        if (strcmp(produtos[i].codigo, codigo) == 0) {
            printf("\n--- Produto Encontrado ---\n");
            printf("Código: %s\n", produtos[i].codigo);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Preço: R$ %.2f\n", produtos[i].preco);
            printf("Quantidade: %d\n", produtos[i].quantidade);
            return;
        }
    }
    
    printf("\nProduto não encontrado!\n");
}

// Função para comparar produtos por preço (para qsort)
int compararPreco(const void *a, const void *b) {
    Produto *p1 = (Produto *)a;
    Produto *p2 = (Produto *)b;
    
    if (p1->preco < p2->preco) return -1;
    if (p1->preco > p2->preco) return 1;
    return 0;
}

// Função para ordenar por preço e imprimir
void ordenarImprimir() {
    if (totalProdutos == 0) {
        printf("\nNenhum produto cadastrado!\n");
        return;
    }
    
    // Cria uma cópia para ordenar
    Produto temp[MAX_PRODUTOS];
    memcpy(temp, produtos, sizeof(Produto) * totalProdutos);
    
    // Ordena por preço
    qsort(temp, totalProdutos, sizeof(Produto), compararPreco);
    
    printf("\n=== PRODUTOS ORDENADOS POR PREÇO ===\n");
    printf("%-15s %-30s %10s %10s\n", "Código", "Nome", "Preço", "Qtd");
    printf("----------------------------------------------------------------\n");
    
    for (int i = 0; i < totalProdutos; i++) {
        printf("%-15s %-30s R$ %7.2f %10d\n",
               temp[i].codigo,
               temp[i].nome,
               temp[i].preco,
               temp[i].quantidade);
    }
}

// Função para imprimir todos os produtos
void imprimirProdutos() {
    if (totalProdutos == 0) {
        printf("\nNenhum produto cadastrado!\n");
        return;
    }
    
    printf("\n=== LISTA DE PRODUTOS ===\n");
    printf("%-15s %-30s %10s %10s\n", "Código", "Nome", "Preço", "Qtd");
    printf("----------------------------------------------------------------\n");
    
    for (int i = 0; i < totalProdutos; i++) {
        printf("%-15s %-30s R$ %7.2f %10d\n",
               produtos[i].codigo,
               produtos[i].nome,
               produtos[i].preco,
               produtos[i].quantidade);
    }
}

// Função para exibir menu
void exibirMenu() {
    printf("\n========================================\n");
    printf("   SISTEMA DE CONTROLE DE PRODUTOS\n");
    printf("========================================\n");
    printf("1. Adicionar produto\n");
    printf("2. Buscar produto por código\n");
    printf("3. Imprimir produtos\n");
    printf("4. Ordenar por preço e imprimir\n");
    printf("5. Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

int main() {
    int opcao;
    
    printf("Carregando dados...\n");
    lerArquivo();
    
    do {
        exibirMenu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                buscarProduto();
                break;
            case 3:
                imprimirProdutos();
                break;
            case 4:
                ordenarImprimir();
                break;
            case 5:
                printf("\nEncerrando sistema...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while(opcao != 5);
    
    return 0;
}