#ifndef LISTA_ESTATICA_H_INCLUDED
#define LISTA_ESTATICA_H_INCLUDED
//=================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pessoa.h"
//=================================================
typedef struct Lista
{
    Pessoa *dados;
    int MAX;
    int qtd;

} Lista;
//=================================================
void criar_lista(Lista *l, int n)
{
    l->MAX = n;
    l->dados = (Pessoa *)malloc(n * sizeof(Pessoa));
    l->qtd = 0;
}
//=================================================
bool add_lista(Lista *l, Pessoa p)
{
    if (l->qtd == l->MAX)
    {
        printf("lista cheia!!");
        //nao é possivel inserir pois esta cheio!!
        return false;
    }
    else
    {
        l->dados[l->qtd] = p;
        l->qtd++;
        return true;
    }
}
//=================================================
void printa_lista(Lista *l)
{
    for (int i = 0; i < l->qtd; i++)
    {
        print_Pessoa(l->dados[i]);
    }
}
//=================================================
bool editar_lista(Lista *l, Pessoa p)
{
    if (p.id <= 0 || p.id > l->qtd)
    {
        printf("Pessoa nao encontrado na lista");
        return false;
    }

    l->dados[p.id - 1] = p;
    return true;
}
//=================================================
bool delete_lista(Lista *l, int id)
{

    if (id <= 0 || id > l->qtd)
    {
        printf("Pessoa nao encontrado na lista");
        return false;
    }

    for (int i = id; i < l->qtd; i++)
    {
        l->dados[i - 1] = l->dados[i];
        l->dados[i - 1].id--;
    }

    l->qtd--;
    return true;
}
//=================================================
void clonar_lista(Lista *l, Lista *c)
{
    c->qtd = l->qtd;
    c->MAX = l->MAX;
    for (int i = 0; i < l->qtd; i++)
    {
        c->dados[i].id = l->dados[i].id;
        strcpy(c->dados[i].nome, l->dados[i].nome);
        c->dados[i].idade = l->dados[i].idade;
    }
}
//=================================================
int maior(Lista *l)
{
    int maior = 0;
    for (int i = 0; i < l->qtd; i++)
    {
        if (l->dados[i].idade > maior)
        {
            maior = l->dados[i].idade;
        }
    }
    return maior;
}
//=================================================
/*void ordena_lista(Lista *l)
{
}
perguntar para o prof se é para fazer id aleatorio e nessa func organizar ou
ja pode deixar do jeito q ta e boa
*/
//=================================================
int pesquisa(Lista *l)
{
    char aux_nome[100];
    printf("nome para id->");
    scanf(" %[^\n]s\n", aux_nome);
    for (int i = 0; i < l->qtd; i++)
    {
        //printf("\naux_nome: %s\n", aux_nome); teste
        //printf("\ndados[%i]: %s\n", i, l->dados[i].nome);teste
        if (strcmp(aux_nome, l->dados[i].nome) == 0)
        {
            return l->dados[i].id;
        }
    }
    return -1;
}
//=================================================
void organiza_numerica(Lista *c)
{
    int i, j, min, aux;
    for (i = 0; i < (c->qtd - 1); i++)
    {
        min = i;
        for (j = (i + 1); j < c->qtd; j++)
        {
            if (c->dados[j].idade < c->dados[min].idade)
                min = j;
        }
        if (c->dados[j].idade != c->dados[min].idade)
        {
            aux = c->dados[i].idade;
            c->dados[i].idade = c->dados[min].idade;
            c->dados[min].idade = aux;
        }
    }
}
//=================================================
/*
void organiza_alfabetica(Lista *l)
{
}
*/
//=================================================

void inverter_lista(Lista *l)
{
    Lista clone;
    criar_lista(&clone, 10);
    Pessoa *pessoa = (Pessoa *)malloc(l->qtd * sizeof(Pessoa));

    for (int i = 0; i < l->qtd; i++)
    {
        pessoa[i] = l->dados[i];
    }
    for (int i = 0; i < l->qtd; i++)
    {
        l->dados[i] = pessoa[l->qtd - i - 1];
        l->dados[i].id = i + 1;
    }
    free(pessoa);
}

//=================================================

Lista concatenar_lista(Lista *l, Lista *c)
{
    Lista concatenada;
    int aux = l->qtd + c->qtd;
    criar_lista(&concatenada, aux);
    Pessoa pessoa;

    // clona lista 1 para concatenada
    clonar_lista(l, &concatenada);

    // coloca lista clone no final da lista concatenada
    for (int i = 0; i < l->qtd; i++)
    {
        pessoa = c->dados[i];
        add_lista(&concatenada, pessoa);
    }
    return concatenada;
}
//=================================================
#endif // FILA_H_INCLUDED