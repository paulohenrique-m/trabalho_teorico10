#ifndef FILA_DINAMICA_H_INCLUDED
#define FILA_DINAMICA_H_INCLUDED
//==============================================
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "aviao.h"
//==============================================
typedef struct Fila
{
    Celula *inicio;
    Celula *fim;
    int tam;
} Fila;

//==============================================
void criar_fila(Fila *f)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->prox = NULL;

    f->inicio = nova;
    f->fim = nova;
    f->tam = 0;
}
//==============================================
bool enfileirar_prioridade(Fila *f, Aviao dado)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    if (nova == NULL)
        return false;
    nova->prox = NULL;
    nova->dado = dado;

    Celula *ant = f->inicio;

    while (ant->prox != NULL && ant->prox->dado.carga <= 50)
        ant = ant->prox;

    nova->prox = ant->prox;
    ant->prox = nova;

    if (nova->prox == NULL)
        f->fim = nova;

    f->tam++;

    return true;
}

//==============================================
bool enfileirar(Fila *f, Aviao dado)
{
    if (dado.carga <= 50)
        return enfileirar_prioridade(f, dado);

    Celula *nova = (Celula *)malloc(sizeof(Celula));
    if (nova == NULL)
        return false;
    nova->prox = NULL;
    nova->dado = dado;
    f->fim->prox = nova;
    f->fim = nova;
    f->tam++;

    return true;
}

//==============================================
void printar_fila(Fila *f)
{
    Celula *tmp = f->inicio->prox;

    printf("\nQuantidade de avioes: %d\n", f->tam);
    while (tmp != NULL)
    {
        printar_aviao(tmp->dado);
        tmp = tmp->prox;
    }
}
//==============================================
Aviao desenfileira(Fila *f)
{
    if (f->tam == 0)
    {
        return invalida_aviao();
    }

    Celula *tmp = f->inicio;
    f->inicio = f->inicio->prox;
    free(tmp);

    f->tam--;
    return f->inicio->dado;
}

#endif // FILA_H_INCLUDED