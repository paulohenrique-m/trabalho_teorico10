#ifndef LISTA1_H_INCLUDED
#define LISTA1_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "web.h"
//====================================================
typedef struct Celula
{
    Pagina dado;
    struct Celula *prox;
} Celula;

typedef struct Lista
{
    Celula *inicio;
    Celula *fim;
    int qtd;
} Lista;

//====================================================
void create_lista(Lista *l)
{
    Celula *tmp = (Celula *)malloc(sizeof(Celula));
    tmp->prox = NULL;

    l->inicio = tmp;
    l->fim = tmp;
    l->qtd = 0;
}
//====================================================
//novo elemento na lista
bool add_lista(Lista *l, Pagina p)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));

    if (nova == NULL)
    {
        printf("\nLista Cheia!\n");
        return false;
    }

    p.codigo = l->qtd + 1;

    nova->dado = p;
    nova->prox = NULL;

    l->fim->prox = nova;
    l->fim = nova;
    l->qtd++;

    return true;
}
//====================================================
//printar conteudo da lista
void print_lista(Lista *l)
{
    Celula *tmp = l->inicio->prox;

    while (tmp != NULL)
    {
        print_pagina(tmp->dado);
        tmp = tmp->prox;
    }
}
//====================================================
//editar lista
bool update_lista(Lista *l, Pagina p)
{
    bool achou = false;

    for (Celula *tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {
        if (tmp->dado.codigo == p.codigo)
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
        printf("\nPagina nao encontrada na lista!\n");
        return false;
    }
}
//====================================================
//deletar da lista
bool delete_lista(Lista *l, int codigo)
{
    bool achou = false;
    Celula *ant, *tmp;

    for (ant = l->inicio, tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox, ant = ant->prox)
    {
        if (tmp->dado.codigo == codigo)
        {
            ant->prox = tmp->prox;

            if (tmp->prox == NULL)
                l->fim = ant;

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
        printf("\nProduto nao!\n");
        return false;
    }
}
//====================================================
// procedimento para clonar uma lista em outra clonada
void clonar(Lista *l, Lista *clonada)
{
    create_lista(clonada);
    Celula *tmp = l->inicio->prox;
    Pagina pagina;

    while (tmp != NULL)
    {
        pagina = tmp->dado;
        add_lista(clonada, pagina);
        tmp = tmp->prox;
    }
}
//====================================================
// procedimento para concatenar duas listas em uma terceira
void concatenar(Lista *l, Lista *c, Lista *concatenada)
{
    create_lista(concatenada);
    Celula *tmp = c->inicio->prox;
    Pagina pagina;

    // clona lista 1 para concatenada
    clonar(l, concatenada);

    // junta lista 2 ao final da lista concatenada
    while (tmp != NULL)
    {
        pagina = tmp->dado;
        add_lista(concatenada, pagina);
        tmp = tmp->prox;
    }
}
//====================================================
//inverter elementos da lista
void inverter(Lista *l)
{
    Pagina *dados = (Pagina *)malloc(l->qtd * sizeof(Pagina));
    Celula *tmp = l->inicio->prox;

    // copia dados da lista para vetor de Paginas
    for (int i = 0; tmp != NULL; i++)
    {
        dados[i] = tmp->dado;
        tmp = tmp->prox;
    }

    tmp = l->inicio->prox;
    // copia dados de vetor de Paginas para lista
    for (int i = l->qtd - 1; i >= 0; i--)
    {
        dados[i].codigo = l->qtd - i;
        tmp->dado = dados[i];
        tmp = tmp->prox;
    }

    free(dados);
}
//====================================================
// adiciona novo elemento na lista em sua posição já ordenada
void add_lista_ordenado(Lista *l, Pagina p)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    if (nova == NULL)
    {
        printf("\nLista Cheia!\n");
        return;
    }

    Celula *tmp = l->inicio->prox;
    Celula aux;

    for (tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {
        if (p.url < tmp->dado.url)
        {
            aux = *tmp;
            p.codigo = l->qtd + 1;

            tmp->dado = p;
            tmp->prox = nova;

            *nova = aux;
            l->qtd++;
            return;
        }
        tmp = tmp->prox;
    }

    p.codigo = l->qtd + 1;

    nova->dado = p;
    nova->prox = NULL;

    l->fim->prox = nova;
    l->fim = nova;
    l->qtd++;

    return;
}
//====================================================
// procedimento para acessar pagina, fazendo com que a pagina acessada passe a ficar na primeira posicação da lista
void acessa_pagina(Lista *l, char *nome)
{
    Celula *tmp = l->inicio->prox; // temporaria
    Celula *ant = l->inicio;       // anterior
    int acessos = 0;
    for (; tmp != NULL; tmp = tmp->prox)
    {
        acessos++;
        if (strcmp(tmp->dado.nome, nome) == 0)
        {
            printf("\nurl acessada: %s\nacessos na lista ate encontrar url: %i\n", tmp->dado.url, acessos);
            if (l->fim == tmp)
            {
                l->fim = ant;
                //   ant->prox = NULL;  // seta prox de celula anterior para NULL
                // } else {
            }
            ant->prox = tmp->prox;       // seta prox de celula anterior para proxima celula apos tmp
            tmp->prox = l->inicio->prox; // seta prox de tmp como atual primeira celula
            l->inicio->prox = tmp;       // seta prox do inicio para tmp
            return;
        }
        ant = tmp; // atualiza anterior
    }

    printf("\nPagina nao encontrada!\n");
}
//====================================================
// função para pesquisar e retornar codigo caso exista ou -1
int pesquisar(Lista *l, char *nome)
{
    Celula *tmp;
    for (tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {
        if (strcmp(tmp->dado.nome, nome) == 0)
        {
            return tmp->dado.codigo;
        }
    }

    return -1;
}
#endif // FILA_H_INCLUDED