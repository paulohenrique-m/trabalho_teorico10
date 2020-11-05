#include <stdio.h>
#include <string.h>
#include "dupla.h"
#include "pessoa.h"

int menu()
{
    int opcao = 0;
    printf("\n---------------lista de pessoas---------------\n");
    printf("1 - Inserir nova Pessoa\n");
    printf("2 - Listar Pessoas\n");
    printf("3 - Editar dados de uma Pessoa\n");
    printf("4 - Apagar uma Pessoa\n");
    printf("5 - Verificar tamanho lista\n");
    printf("6 - Pesquisar na lista\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    return opcao;
}

int main(void)
{
    // CRIA A LISTA DE PESSOAS
    Lista lista, lista_clonada, lista_concatenado;
    Pessoa paux;
    int op = 0, id;
    char nome[100];

    create_lista(&lista);

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            printf("\nPrintando lista: \n");
            print_lista(&lista);
            break;

        case 2:
            paux = nova_Pessoa();
            add_lista(&lista, paux);
            break;

        case 3:
            printf("\nDigite o id da pessoa: ");
            scanf("%d", &id);
            paux = nova_Pessoa();
            paux.id = id;
            update_lista(&lista, paux);
            break;

        case 4:
            printf("\nDigite o id da pessoa: ");
            scanf("%d", &id);
            delete_lista(&lista, id);
            break;

        case 5:
            printf("\nQuantidade de elementos na lista: %i\n", tamanho_lista(&lista));
            break;

        case 6:
            printf("\nDigite um nome para ser pesquisado: ");
            scanf("%s", nome);
            if (pesquisar(&lista, nome) != -1)
            {
                printf("\nPessoa encontrada!\n");
            }
            else
            {
                printf("\nPessoa nao encontrada!\n");
            }
            break;
        }
    } while (op != 0);

    return 0;
}