#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha_estatica.h"
//#include "pilha_dinamica.h"
//====================================================
void clonar_pilha(Pilha *p, Pilha *c)
{
    char palavra;
    Pilha aux;
    criar_pilha(&aux);
    //desempilhar p em uma pilha auxiliar
    //da pilha auxiliar, tenho que desempilhar em c e p juntos
    //guardando o valor desempilhado em uma variavel
    palavra = pop(p);
    while (palavra != -1)
    {
        push(&aux, palavra);
        palavra = pop(p);
    }
    palavra = pop(&aux);
    while (palavra != -1)
    {
        push(p, palavra);
        push(c, palavra);
        palavra = pop(&aux);
    }
}
//====================================================
Pilha concatenar(Pilha *p, Pilha *c)
{
    Pilha concatenada;
    Pilha aux;
    char palavra;
    criar_pilha(&aux);
    criar_pilha(&concatenada);
    clonar_pilha(p, &concatenada);
    //desempilhar p em auxiliar e voltar da auxiliar para a pilha
    //concatenada e p

    palavra = pop(c);
    while (palavra != -1)
    {
        push(&aux, palavra);
        palavra = pop(c);
    }
    palavra = pop(&aux);
    while (palavra != -1)
    {
        push(&concatenada, palavra);
        push(c, palavra);
        palavra = pop(&aux);
    }
    printf("-------------teste\n");
    printar_pilha(&concatenada);
    return concatenada;
}
//====================================================
void inverte_pilha(Pilha *p)
{
    char palavra;
    Pilha aux1;
    criar_pilha(&aux1);
    Pilha aux2;
    criar_pilha(&aux2);
    //desempilhar p em uma pilha auxiliar
    //da pilha auxiliar tem q ir para outra auxiliar
    //e dessa segunda auxiliar tem q ir para original;
    palavra = pop(p);
    while (palavra != -1)
    {
        push(&aux1, palavra);
        palavra = pop(p);
    }
    palavra = pop(&aux1);
    while (palavra != -1)
    {
        push(&aux2, palavra);
        palavra = pop(&aux1);
    }
    //inverter aux2(igual a original) mandando ela para original
    palavra = pop(&aux2);
    while (palavra != -1)
    {
        push(p, palavra);
        palavra = pop(&aux2);
    }
}
//====================================================
void retira_impares(Pilha *p)
{
    //mandar a pilha original para uma auxiliar1
    //do auxiliar 1, quando for dar pop/push para original de volta
    //faz a verificacao dos numeros
    Pilha aux;
    char palavra;
    criar_pilha(&aux);
    palavra = pop(p);
    while (palavra != -1)
    {
        push(&aux, palavra);
        palavra = pop(p);
    }
    palavra = pop(&aux);
    while (palavra != -1)
    {
        if (palavra % 2 == 0)
        {
            push(p, palavra);
        }

        palavra = pop(&aux);
    }
}
//====================================================
int menu(int opc)
{
    printf("\n--------------PILHA--------------\n");
    printf("1-printar pilha\n");
    printf("2-add pilha\n");
    printf("3-excluir da pilha\n");
    printf("4-clonar pilha\n");
    printf("5-concatenar pilha\n");
    printf("6-inverte pilha\n");
    printf("7-tirar impares pilha\n");
    printf("opc:");
    scanf("%i", &opc);
    return opc;
}

int main()
{
    Pilha pilha, pilha_aux;
    Pilha clone;
    int opc = -1;
    char letra;
    criar_pilha(&pilha);
    fflush(stdin);
    while (opc != 0)
    {
        opc = menu(opc);
        switch (opc)
        {
        case 1:
            // printar a pilha
            printar_pilha(&pilha);
            break;
        case 2:
            //add na pilha
            // for (int i = 0; i < n; i++)
            // {
            //     scanf("%i", &numero);
            //     push(&pilha, numero);
            // }
            fflush(stdin);
            scanf("%c", &letra);
            // fflush(stdin);
            push(&pilha, letra);
            break;
        case 3:
            //tirar da pilha
            // printf("elemento retirado da pilha:%i\n", pilha.dados[pilha.topo]);
            // saber qual elemento foi retirado
            pop(&pilha);
            break;
        case 4:
            //clonar
            criar_pilha(&clone);
            clonar_pilha(&pilha, &clone);
            printf("\n-------lista normal-------\n");
            printar_pilha(&pilha);
            printf("\n-------lista clonada-------\n");
            printar_pilha(&clone);
            break;
        case 5:
            //concatenar
            clonar_pilha(&pilha, &clone);
            criar_pilha(&pilha_aux);
            pilha_aux = concatenar(&pilha, &clone);
            printar_pilha(&pilha_aux);
            break;
        case 6:
            //inverter
            printf("pilha original");
            printar_pilha(&pilha);
            inverte_pilha(&pilha);
            printf("pilha inversa");
            printar_pilha(&pilha);
            break;
        case 7:
            //retira impares(tratando letra como numero da tabela ASCII)
            printf("pilha original\n");
            printar_pilha(&pilha);
            retira_impares(&pilha);
            printf("pilha sem impares\n");
            printar_pilha(&pilha);
            break;
        case 8:
            //ordenar
            /*
            printf("pilha original\n");
            printar_pilha(&pilha);
            ordena_pilha(&pilha);
            printf("pilha ordenada\n");
            printar_pilha(&pilha);
            */
            break;
        default:
            printf("invalido!");
            break;
        }
    }

    return 0;
}