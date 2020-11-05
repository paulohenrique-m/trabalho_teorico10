#ifndef LISTA_DINAMICA_H_INCLUDED
#define LISTA_DINAMICA_H_INCLUDED
//=================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pessoa.h"
//=================================================
typedef struct Celula
{
    Pessoa dado;
    struct Celula *prox;

} Celula;

//=================================================
typedef struct Lista
{
    Celula *inicio;
    Celula *fim;
    int qtd;
} Lista;
//=================================================
void criar_lista(Lista *l)
{
    Celula *tmp = (Celula *)malloc(sizeof(Celula));
    tmp->prox = NULL;
    l->inicio = tmp;
    l->fim = tmp;
    l->qtd = 0;
}
//=================================================
void printa_lista(Lista *l)
{
    Celula *tmp = l->inicio->prox; //primeiro valor!!
    while (tmp != NULL)
    {
        print_Pessoa(tmp->dado);
        tmp = tmp->prox;
    }
}
//=================================================
bool add_lista(Lista *l, Pessoa p)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));

    if (nova == NULL)
    {
        printf("lista cheia!!");
        return false;
    }

    nova->dado = p;
    nova->prox = NULL;

    l->fim->prox = nova;
    l->fim = nova;
    l->qtd++;
    return true;
}
//=================================================
bool editar_lista(Lista *l, Pessoa p)
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
    {
        return true;
    }
    else
    {
        printf("produto não encontrado!!");
        return false;
    }
}
//=================================================
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
        printf("\nProduto nao encontrado na lista!\n");
        return false;
    }
}
//=================================================
void clonar_lista(Lista *l, Lista *clonada)
{
    criar_lista(clonada);
    Celula *tmp = l->inicio->prox;
    Pessoa pessoa;

    while (tmp != NULL)
    {
        pessoa = tmp->dado;
        add_lista(clonada, pessoa);
        tmp = tmp->prox;
    }
}
//=================================================
void inverter_lista(Lista *l)
{
    Pessoa *dados = (Pessoa *)malloc(l->qtd * sizeof(Pessoa));
    Celula *tmp = l->inicio->prox;

    // copia dados da lista para vetor de Pessoas
    for (int i = 0; tmp != NULL; i++)
    {
        dados[i] = tmp->dado;
        tmp = tmp->prox;
    }

    tmp = l->inicio->prox;
    // copia dados de vetor de Pessoas para lista
    for (int i = l->qtd - 1; i >= 0; i--)
    {
        dados[i].id = l->qtd - i;
        tmp->dado = dados[i];
        tmp = tmp->prox;
    }

    free(dados);
}
//=================================================
// Lista concatenar_lista(Lista *l, Lista *c)
// {
//     Lista concatenada;
//     criar_lista(&concatenada);
//     Celula *tmp = c->inicio->prox;
//     Pessoa dado;

//     // junta clone ao final da lista concatenada
//     while (tmp != NULL)
//     {
//         dado = tmp->dado;
//         add_lista(&concatenada, dado);
//         tmp = tmp->prox;
//     }
//     return concatenada;
// }
//=================================================
Pessoa maior(Lista *l)
{
    Celula *tmp = l->inicio->prox;
    Celula *maior = tmp;
    int maiorIdade = maior->dado.idade;
    for (tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {
        if (tmp->dado.idade > maiorIdade)
        {
            maiorIdade = tmp->dado.idade;
            maior = tmp;
        }
    }

    return maior->dado;
}
//=================================================
int pesquisa(Lista *l, char *nome)
{
    Celula *tmp;
    for (tmp = l->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {
        if (strcmp(tmp->dado.nome, nome) == 0)
        {
            return tmp->dado.id;
        }
    }

    return -1;
}
//=================================================

#endif //