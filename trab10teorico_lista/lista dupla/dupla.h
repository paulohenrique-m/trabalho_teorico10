#ifndef LISTA_DUPLA_H_INCLUDED
#define LISTA_DUPLA_H_INCLUDED
//=============================================
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
//=============================================
typedef struct Celula
{
    Pessoa dado;
    struct Celula *prox;
    struct Celula *ant;
} Celula;
typedef struct Lista
{
    Celula *inicio;
    Celula *fim;
    int qtd;
} Lista;
//=============================================
// Criar uma lista
void create_lista(Lista *l)
{
    Celula *tmp = (Celula *)malloc(sizeof(Celula));
    tmp->prox = NULL;
    tmp->ant = NULL;

    l->inicio = tmp;
    l->fim = tmp;
    l->qtd = 0;
}
//=============================================

// Inserir um novo elemento
bool add_lista(Lista *l, Pessoa p)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));

    if (nova == NULL)
    {
        printf("\nLista Cheia!\n");
        return false;
    }

    p.id = l->qtd + 1;

    nova->dado = p;
    nova->prox = NULL;

    l->fim->prox = nova;
    nova->ant = l->fim;
    l->fim = nova;
    l->qtd++;

    return true;
}
//=============================================
// Remover um elemento
bool delete_lista(Lista *l, int id)
{
    bool achou = false;
    Celula *ant, *tmp;

    for (ant = l->inicio, tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox, ant = ant->prox)
    {
        if (tmp->dado.id == id)
        {
            ant->prox = tmp->prox;

            if (tmp->prox == NULL)
                l->fim = ant;
            else
                tmp->prox->ant = ant;

            free(tmp);
            l->qtd--;
            achou = true;
            break;
        }
    }

    if (achou)
        return true;
    else
    {
        printf("\nPessoa nao encontrado na lista!\n");
        return false;
    }
}

// Verificar o tamanho da lista
int tamanho_lista(Lista *l)
{
    return l->qtd;
}

// Pesquisar um elemento na lista e retorna o id ou -1
int pesquisar(Lista *l, char *nome)
{
    Celula *tmp = l->inicio->prox;

    while (tmp != NULL)
    {
        if (strcmp(tmp->dado.nome, nome) == 0)
        {
            // printf("\nEncontrou pessoa!\n");
            return tmp->dado.id;
        }
        tmp = tmp->prox;
    }
    // printf("\nNao encontrou pessoa!\n");
    return -1;
}

// Imprimir o conteúdo da lista
void print_lista(Lista *l)
{
    Celula *tmp = l->inicio->prox;

    while (tmp != NULL)
    {
        print_pessoa(tmp->dado);
        tmp = tmp->prox;
    }
}

// Imprimir o conteúdo da lista invertida
void print_lista_invertida(Lista *l)
{
    Celula *tmp = l->fim;

    while (tmp->ant != NULL)
    {
        print_pessoa(tmp->dado);
        tmp = tmp->ant;
    }
}

// atualizar valor de registro na lista
bool update_lista(Lista *l, Pessoa p)
{
    bool achou = false;

    for (Celula *tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {
        if (tmp->dado.id == p.id)
        {
            tmp->dado = p;
            achou = true;
            break;
        }
    }

    if (achou)
        return true;
    else
    {
        printf("\nPessoa nao encontrado na lista!\n");
        return false;
    }
}

#endif // FILA_H_INCLUDED