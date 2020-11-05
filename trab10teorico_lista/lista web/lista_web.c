#include <stdio.h>
#include <string.h>
#include "web.h"
#include "lista_dinamica.h"
//====================================================
int menu()
{
    int opcao = 0;
    printf("\n--------------LISTA DE PAGINAS--------------\n");
    printf("1 - Listar Paginas\n");
    printf("2 - Inserir nova Pagina\n");
    printf("3 - Editar dados de uma Pagina\n");
    printf("4 - Apagar uma Pagina\n");
    printf("6 - Acessar uma Pagina\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    return opcao;
}
//====================================================

int main(void)
{
    // CRIA A LISTA WEB
    Lista lista, lista_clonada, lista_concatenado;
    Pagina paux;
    int op = 0, codigo;
    char nome[100];

    create_lista(&lista);

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            print_lista(&lista);
            break;

        case 2:
            paux = novo_pagina();
            add_lista(&lista, paux);
            break;

        case 3:
            printf("\nDigite o codigo da pagina: ");
            scanf("%d", &codigo);
            paux = novo_pagina();
            paux.codigo = codigo;
            update_lista(&lista, paux);
            break;

        case 4:
            printf("\nDigite o codigo da pagina: ");
            scanf("%d", &codigo);
            delete_lista(&lista, codigo);
            break;

        case 5:
            clonar(&lista, &lista_clonada);
            printf("\nLista clonada: \n");
            print_lista(&lista_clonada);
            break;

        case 6:
            printf("Digite o nome da pagina: ");
            scanf("%s", nome);
            acessa_pagina(&lista, nome);
            // print_lista(&lista);       // utilizado para teste
            break;
        }
    } while (op != 0);

    return 0;
}