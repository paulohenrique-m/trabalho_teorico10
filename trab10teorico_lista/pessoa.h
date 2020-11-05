#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED
//====================================
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//====================================
typedef struct Pessoa
{
    int id;
    char nome[100];
    int idade;
} Pessoa;
//====================================
void print_Pessoa(Pessoa p)
{
    printf("id: %d, nome: %s, idade: %d\n", p.id, p.nome, p.idade);
}

Pessoa nova_Pessoa(Pessoa p)
{
    srand(time(NULL));
    printf("digite o nome do Pessoa: ");
    scanf(" %[^\n]s\n", p.nome);
    fflush(stdin);
    printf("digite a idade da Pessoa: ");
    scanf("%i", &p.idade);
    return p;
}

//====================================
#endif // PESSOA_H_INCLUDED