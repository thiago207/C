#include <stdio.h>
#include <string.h>
/*
Atividade
Crie uma struct chamada "Aluno" com os campos:
nome, curso e idade.
Leia os dados de um aluno e imprima.
*/

struct aluno
{
   char nome [30];
   char curso [40];
   int idade;    
};


int main(){
    struct aluno a;

    printf("Digite seu nome: ");
    fgets(a.nome, sizeof(a.nome), stdin);
    a.nome[strlen(a.nome) - 1] = "\0";

    printf("Digite seu curso: ");
    fgets(a.curso, sizeof(a.curso), stdin);
    a.curso[strlen(a.curso) - 1] = "\0";

    printf("Digite sua idade: ");
    scanf("%d", &a.idade);

    printf("Nome : %s\nCurso: %s\nIdade: %d", a.nome, a.curso, a.idade);


    return 0;
}