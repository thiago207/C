/*
Atividade
Crie uma struct chamada "Produto" com nome, preço e quantidade usando uma funcao cria_produto
Faça uma função valor_total que receba um Produto e retorne seu valor total (preço * quantidade).
*/

#include <stdio.h>
#include <string.h>

struct produto
{
    char nome[30];
    float preco;
    int quantidade;
};

struct produto criar_produto (char nome_recebido[], float preco_recebido, int quantidade_recebida){
    struct produto p;
    strcpy(p.nome, nome_recebido);
    p.preco = preco_recebido;
    p.quantidade = quantidade_recebida;
    return p;
};


float valor_total(struct produto p) {
    return p.preco * p.quantidade; 

};

int main() {
    struct produto p1 = criar_produto("Mouse", 150.0, 3);

    printf("Produto: %s\n", p1.nome);
    printf("Preco unitario: %.2f\n", p1.preco);
    printf("Quantidade: %d\n", p1.quantidade);
    printf("Valor total: R$%.2f\n", valor_total(p1));

    return 0;
}