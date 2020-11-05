#include <stdio.h>
#include <stdlib.h>
#include "pista_dinamica.h"
//==============================================
int menu()
{
    int opcao;
    printf("\n =====> PISTA DE AVIAO <===== \n");
    printf("1 - Adicionar Aviao na fila\n");
    printf("2 - Listar todos Avioes na fila\n");
    printf("3 - Autorizar decolagem do primeiro Aviao\n");
    printf("4 - Listar quantidade de Avioes na fila\n");
    printf("5 - Listar caracteristicas do primeiro Aviao\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");

    scanf("%d", &opcao);

    return opcao;
}
//==============================================
int main(void)
{
    int op;
    Fila fila;
    Aviao paux;
    criar_fila(&fila);

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            paux = novo_aviao();
            if (enfileirar(&fila, paux))
            {
                printf("\nNovo Aviao na fila!\n");
            }
            else
            {
                printf("\nErro. nao tem aviao na fila.\n");
            }
            break;
        case 2:
            printf("------------FILA------------\n");
            printar_fila(&fila);
            break;
        case 3:
            paux = desenfileira(&fila);
            printar_aviao(paux);
            break;
        case 4:
            printf("\nQuantidade de avioes na fila: %i\n", fila.tam);
            break;
        case 5:
            printf("\nPrimeiro aviao na fila: \n");
            printar_aviao(fila.inicio->prox->dado);
            break;
        }

    } while (op != 0);

    return 0;
}