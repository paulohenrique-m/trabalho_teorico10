#ifndef FILA_ESTATICA_H_INCLUDED
#define FILA_ESTATICA_H_INCLUDED
//======================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pessoa.h"
#define MAX 5
//====================================
typedef struct Fila
{
    Pessoa dados[MAX];
    int inicio, fim;
    int tam;
} Fila;
//======================================
void criar_fila(Fila *f)
{
    f->inicio = 0;
    f->fim = 0;
    f->tam = 0;
}
//======================================
bool ajusta_prefencial(Fila *f, int num, Pessoa dado)
{
    Pessoa aux;
    int id, idade;
    char nome[100];

    aux = f->dados[num];
    f->dados[num] = dado;
    f->fim = (f->fim + 1) % MAX;
    f->tam++;
    for (int i = num + 1; i <= f->fim; i++)
    {
        dado = f->dados[i];
        f->dados[i] = aux;
        aux = dado;
    }

    return true;
}
//======================================
bool enfileirar_prioridade(Fila *f, Pessoa dado)
{
    int aux = (f->inicio + 1) % MAX;
    for (int i = 0; i < f->tam; i++)
    {
        //verifica se a pessoa e menor de 65
        //e manda o dado pro ajusta_preferencial
        if (f->dados[aux].idade < 65)
        {
            return ajusta_prefencial(f, aux, dado);
        }
        aux = (f->inicio + 1) % MAX;
    }

    return ajusta_prefencial(f, (f->inicio + 1) % MAX, dado);
}
//======================================
bool enfileirar(Fila *f, Pessoa dado)
{
    if ((f->fim + 1) % MAX == f->inicio)
        return false;

    if (dado.idade >= 65)
        return enfileirar_prioridade(f, dado);

    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = dado;
    f->tam++;

    return true;
}
//======================================
void printar_fila(Fila *f)
{

    int pos = (f->inicio + 1) % MAX;

    for (int i = 0; i < f->tam; i++)
    {
        printar_pessoa(&f->dados[pos]);
        pos = (pos + 1) % MAX;
    }
}
//======================================
Pessoa desenfileirar(Fila *f)
{
    if (f->tam == 0)
    {
        return invalida_pessoa();
    }

    f->inicio = (f->inicio + 1) % MAX;
    f->tam--;
    return f->dados[f->inicio];
}

//======================================
#endif // FILA_H_INCLUDED
