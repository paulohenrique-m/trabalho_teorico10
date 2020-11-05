#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
//==================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5
//==================================================
typedef struct Carro
{
    char nome[100];
    int placa;
    int qtd_manobras;

} Carro;
typedef struct Pilha
{
    Carro dados[MAX];
    int topo;
} Pilha;
//==================================================
void criar_pilha(Pilha *p)
{
    p->topo = 0;
}
//==================================================
Carro novo_carro()
{
    Carro carro;
    printf("\nnome: ");
    scanf(" %[^\n]s\n", carro.nome);
    fflush(stdin);
    printf("\nplaca: ");
    scanf("%i", &carro.placa);
    carro.qtd_manobras = 0;
    return carro;
}
//==================================================
bool push(Pilha *p, Carro dado)
{

    if (p->topo == MAX)
    {
        printf("\ngaragem Cheia!\n");
        return false;
    }

    p->dados[p->topo] = dado;
    p->topo++;
    printf("\nentrou carro!");
    return true;
}

//==================================================
Carro pop(Pilha *p)
{

    if (p->topo == 0)
    {
        Carro carro;
        carro.placa = -1;
        printf("\ngaragem Vazia!\n");
        return carro;
    }

    p->topo--;
    printf("\nsaiu carro!\n");
    return p->dados[p->topo];
}
//==================================================
void printar_pilha(Pilha *p)
{

    printf("\nTamanho: %d\n", p->topo);
    for (int i = p->topo - 1; i >= 0; i--)
    {
        printf("%s", p->dados[i].nome);
        printf("%i\n", p->dados[i].placa);
    }
}
//==================================================
//==================================================
#endif // PILHA_H_INCLUDED