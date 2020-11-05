#ifndef PILHA_DINAMICA_H_INCLUDED
#define PILHA_DINAMICA_H_INCLUDED
//==================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Celula
{
    char dado;
    struct Celula *prox;
} Celula;
//==================================================
typedef struct Pilha
{
    Celula *topo;
    int tam;
} Pilha;
//==================================================
void criar_pilha(Pilha *p)
{
    p->topo = NULL;
    p->tam = 0;
}
//==================================================
bool push(Pilha *p, char dado)
{

    Celula *nova = (Celula *)malloc(sizeof(Celula));
    if (nova == NULL)
    {
        printf("\nPilha Cheia!\n");
        return false;
    }
    nova->dado = dado;

    nova->prox = p->topo;
    p->topo = nova;
    p->tam++;
    return true;
}

//==================================================
char pop(Pilha *p)
{

    if (p->tam == 0)
    {
        printf("\nPilha Vazia!\n");
        return -1;
    }

    char dado = p->topo->dado;

    Celula *tmp = p->topo;
    p->topo = p->topo->prox;
    free(tmp);

    p->tam--;
    return dado;
}
//==================================================
void printar_pilha(Pilha *p)
{

    Celula *tmp = p->topo;
    printf("\nTamanho: %d\n", p->tam);
    while (tmp != NULL)
    {
        printf("%c\n", tmp->dado);
        tmp = tmp->prox;
    }
}

void sort_pilha(Pilha *p)
{

    for (int i = 0; i < p->tam - 1; i++)
    {
        Celula *tmp = p->topo;
        for (int j = 0; j < p->tam - i - 1; j++)
        {
            if (tmp->dado > tmp->prox->dado)
            {
                char aux = tmp->dado;
                tmp->dado = tmp->prox->dado;
                tmp->prox->dado = aux;
            }
            tmp = tmp->prox;
        }
    }
}

//==================================================

//==================================================
#endif // PILHA_H_INCLUDED