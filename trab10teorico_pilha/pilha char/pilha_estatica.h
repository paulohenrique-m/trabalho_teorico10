#ifndef PILHA_ESTATICA_H_INCLUDED
#define PILHA_ESTATICA_H_INCLUDED
//====================================================
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 100
//====================================================
typedef struct Pilha
{
    char dados[MAX];
    int topo;

} Pilha;
//====================================================
void criar_pilha(Pilha *p)
{
    p->topo = 0;
}
//====================================================
//passa pilha e o dado a ser inserido
bool push(Pilha *p, char dado)
{
    if (p->topo == MAX)
    {
        printf("pilha cheia!!");
        return false;
    }
    p->dados[p->topo] = dado;
    p->topo++;
}
//====================================================
//retira da pilha um dado
char pop(Pilha *p)
{
    if (p->topo == 0)
    {
        //printf("pilha vazia!!");
        return -1;
    }
    p->topo--;
    return p->dados[p->topo];
}
//====================================================
void printar_pilha(Pilha *p)
{
    printf("tamanho da pilha: %d\n", p->topo);
    for (int i = 0; i < p->topo; i++)
    {
        printf("%c\n", p->dados[i]);
    }
}

//====================================================
/*
void ordena_pilha(Pilha *p)
{
    int palavra, i = 0;
    int vetor[1000];
    Pilha aux1;
    criar_pilha(&aux1);
    palavra = pop(p);
    while (palavra != -1)
    {
        push(&aux1, palavra);
        vetor[i] = palavra;
        i++;
        palavra = pop(p);
    }
    int k, j, aux;

    for (k = 1; k < i; k++)
    {
        for (j = 0; j < i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    palavra = vetor[i];
    palavra = pop(&aux1);
    while (palavra != -1)
    {
        push(p, palavra);
        i--;
        palavra = pop(&aux1);
    }
}
*/
//====================================================
#endif