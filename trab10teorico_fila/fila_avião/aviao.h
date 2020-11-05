#ifndef AVIAO_H_INCLUDED
#define AVIAO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Aviao
{
    int id;
    char nome[100];
    float carga;
} Aviao;
typedef struct Celula
{
    Aviao dado;
    struct Celula *prox;
} Celula;
//==============================================
void printar_aviao(Aviao p)
{
    printf("id: %d,nome: %s,carga: %0.2f\n", p.id, p.nome, p.carga);
}
//==============================================
Aviao novo_aviao()
{
    Aviao p;
    srand(time(NULL));
    p.id = rand() % 1000;
    printf("Digite o nome do Aviao: ");
    scanf(" %[^\n]s\n", p.nome);
    fflush(stdin);
    printf("Digite a quantidade de carga do aviao: ");
    scanf("%f", &p.carga);

    return p;
}

//==============================================
Aviao invalida_aviao()
{
    Aviao p;
    p.id = -1;
    sprintf(p.nome, "Aviao: %d", p.id);
    p.carga = 0;

    return p;
}
#endif //