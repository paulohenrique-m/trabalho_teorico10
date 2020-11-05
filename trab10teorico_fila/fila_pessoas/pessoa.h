#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//==========================================
typedef struct Pessoa
{
    int id;
    char nome[100];
    int idade;
} Pessoa;

//==========================================
void printar_pessoa(Pessoa *p)
{
    printf("nome: %s,idade: %d ,id: %d\n", p->nome, p->idade, p->id);
}
//==========================================
Pessoa nova_pessoa()
{
    srand(time(NULL));
    Pessoa p;
    p.id = rand() % 1000;
    printf("nome: ");
    scanf(" %[^\n]s\n", p.nome);
    printf("idade: ");
    scanf("%i", &p.idade);

    return p;
}
//==========================================
Pessoa invalida_pessoa()
{
    Pessoa p;

    p.id = -1;
    sprintf(p.nome, "Pessoa: %d", p.id);
    p.idade = 0;

    return p;
}
//==========================================
//==========================================
//==========================================

#endif
