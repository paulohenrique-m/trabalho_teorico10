#ifndef WEB_H_INCLUDED
#define WEB_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pagina
{
    int codigo;
    char nome[100];
    char url[100];
} Pagina;

void print_pagina(Pagina p)
{
    printf("codigo: %d, nome: %s, url: %s\n", p.codigo, p.nome, p.url);
}

Pagina novo_pagina()
{
    Pagina p;
    sprintf(p.nome, "Pagina %d", p.codigo);
    printf("Digite o nome da pagina: ");
    scanf("%s", p.nome);
    fflush(stdin);
    printf("Digite a url da pagina: ");
    scanf("%s", p.url);
    fflush(stdin);
    return p;
}
#endif // WEB_H_INCLUDED