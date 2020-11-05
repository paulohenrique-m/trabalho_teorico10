#include <stdio.h>
#include <string.h>
#include "pessoa.h"
// #include "lista_estatica.h"
#include "lista_dinamica.h"
// #include "lista_dupla.h"
//pessoas->Código, Nome e Idade.

int menu()
{

    int opc = 0;
    printf("\n------------------LISTA DE PESSOAS------------------\n");
    printf("1 - mostrar os clientes\n");
    printf("2 - listar uma pessoa\n");
    printf("3 - Editar dados de alguem\n");
    printf("4 - Apagar uma pessoa\n");
    printf("5 - clonar a lista\n");
    printf("6 - maior idade\n");
    printf("7 - pesquisa\n");
    printf("8 - ordenar idade(nao realizado)\n");
    printf("9 - ordenar alfabetico(nao realizado)\n");
    printf("10 - inverter lista\n");
    printf("11 - concatenar lista\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opc);

    return opc;
}

int main(void)
{

    // CRIA A LISTA DE PessoaS
    Lista lista, lista_aux;
    Lista clone;
    Pessoa p_aux; // usar variavel dentro da main
    int op = 0, id;
    char aux_nome[100];
    int aux;
    // criar_lista(&lista, 5); //LISTA ESTATICA o segundo parametro é o maximo da lista!!
    criar_lista(&lista); //LISTA DINAMICA nao pode ter o segundo parametro pq pode colocar quantos quiser

    do
    {

        op = menu();

        switch (op)
        {

        case 1:
            //printar lista
            printa_lista(&lista);
            break;

        case 2:
            //adicionar pessoa
            //ok estatico
            //ok dinamico
            p_aux.id = lista.qtd + 1;
            p_aux = nova_Pessoa(p_aux);
            add_lista(&lista, p_aux);
            break;

        case 3:
            //editar
            //ok estatico
            //ok dinamico
            printf("\nDigite o codigo da pessoa: ");
            scanf("%d", &id);
            p_aux = nova_Pessoa(p_aux); //colocar o item no lugar do antigo
            p_aux.id = id;
            editar_lista(&lista, p_aux);

            break;
        case 4:
            //deletar
            //ok estatico
            //ok dinamico
            printf("\nDigite o codigo da pessoa: ");
            scanf("%d", &id);
            delete_lista(&lista, id);
            break;

        case 5:
            //clona lista
            //criar_lista(&clone, 5); //estatica
            //ok estatico
            criar_lista(&clone);
            printf("lista clone criada!\n");
            clonar_lista(&lista, &clone);
            printf("lista clonada!\n");
            printa_lista(&clone);
            break;
        case 6:

            //mais velho
            //ok estatico
            printf("o mais velho da lista tem %i anos", maior(&lista));
            break;
        case 7:
            //pesquisa id por nome
            //ok estatico

            printf("nome para id->");
            scanf(" %[^\n]s\n", aux_nome);

            printf("id = %i", pesquisa(&lista, &aux_nome));
            break;

        case 8:
            /*
            //ordenar a lista de forma crescente
            criar_lista(&clone, 5);
            // criar_lista(&clone);
            printf("lista clone criada!\n");
            clonar_lista(&lista, &clone);
            printf("lista clonada!\n");
            //organiza_numerica(&clone);
            printf("lista organizada!\n");
            printa_lista(&clone);
            */
            printf("\nnao realizada!");
            break;
        case 9: /*
            //ordenar a lista de forma alfabetica
            criar_lista(&clone, 5);
            // criar_lista(&clone);
            printf("lista clone criada!\n");
            clonar_lista(&lista, &clone);
            printf("lista clonada!\n");
            //organiza_alfabetica(&clone);
            printf("lista organizada!\n");
            printa_lista(&clone);
            */
            printf("\nnao realizada!");
            break;

        case 10:
            //inverter a lista
            printa_lista(&lista);
            printf("------------lista invertida------------\n");
            inverter_lista(&lista);
            printa_lista(&lista);
            break;

        case 11:
            //concatenar
            //criar_lista(&clone, 5); //estatico
            //criar_lista(&clone); //dinamico nao esta funcionando
            printf("lista clone criada!\n");
            clonar_lista(&lista, &clone);
            // criar_lista(&lista_aux, 100);
            criar_lista(&lista_aux);
            //criar_lista(&lista_aux);
            //lista_aux = concatenar_lista(&lista, &clone);
            printa_lista(&lista_aux);
        }

    } while (op != 0);

    return 0;
}