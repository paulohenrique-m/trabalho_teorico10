#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica.h"
// #include "fila_estatica.h"
#include "pessoa.h"
//====================================================
void clonar_fila(Fila *f, Fila *c)
{
    Pessoa dado;
    Fila aux;
    int tam = f->tam;
    criar_fila(&aux);
    for (int i = 0; i < tam; i++)
    {
        dado = desenfileirar(f);
        enfileirar(&aux, dado);
    }
    tam = aux.tam;
    for (int i = 0; i < tam; i++)
    {
        dado = desenfileirar(&aux);
        enfileirar(c, dado);
        enfileirar(f, dado);
    }
}
//====================================================
Fila concatenar(Fila *f, Fila *c)
{
    Fila concatenada, aux;
    Pessoa dado;
    int tam = f->tam; //pega o tamanho da fila e guarda em uma variavel
    criar_fila(&concatenada);
    criar_fila(&aux);
    //se a fila estiver vazia, clonar a f para c
    if (c->tam == 0)
    {
        clonar_fila(f, c);
    }
    //clona fila original para concatenada
    clonar_fila(f, &concatenada);
    //joga os dados da fila c para uma auxiliar
    for (int i = 0; i < tam; i++)
    {
        dado = desenfileirar(c);
        enfileirar(&aux, dado);
    }
    //pega os dados da aux e passa para concatenada e c
    for (int i = 0; i < tam; i++)
    {
        dado = desenfileirar(&aux);
        enfileirar(&concatenada, dado);
        enfileirar(c, dado);
    }
    // printar_fila(&concatenada);
    return concatenada;
}
//====================================================
// void inverter(Fila *f)
// {
//     int tam = f->tam;
//     Fila aux;
//     criar_fila(&aux);
//     Pessoa *dado = (Pessoa *)malloc(tam * sizeof(Pessoa));
//     for (int i = 0; i < tam; i++)
//     {
//         dado = desenfileirar(f);
//         enfileirar(&aux, *dado);
//     }
//     for (int i = tam; i < 0; i++)
//     {
//         dado = desenfileirar(f);
//         enfileirar(&aux, *dado);
//     }
//     free(dado);
// }
//====================================================
int menu()
{
    int opcao;
    printf("\n -------------FILA DE ATENDIMENTO------------- \n");
    printf("1 - Entrar na fila\n");
    printf("2 - printar a fila\n");
    printf("3 - Chamar o próximo da fila\n");
    printf("4 - clonar fila\n");
    printf("5 - concatenar fila\n");
    printf("6 - inverter fila(nao funcionou)\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");

    scanf("%d", &opcao);

    return opcao;
}
//====================================================
int main(void)
{
    //fila preferencial colocando as pessoas maiores de 65 anos na frente da fila
    int op;
    Fila fila, clone, concatenada;
    Pessoa p_aux;
    criar_fila(&fila);
    criar_fila(&clone);
    criar_fila(&concatenada);

    fflush(stdin);
    do
    {

        op = menu();

        switch (op)
        {
        case 1:
            // adicionar fila
            p_aux = nova_pessoa();
            fflush(stdin);
            enfileirar(&fila, p_aux);
            break;
        case 2:
            // printar a fila
            printar_fila(&fila);
            break;
        case 3:
            // tirar fila
            p_aux = desenfileirar(&fila);
            printar_pessoa(&p_aux);
            printf("-----------fila-----------\n");
            printar_fila(&fila);
            break;
        case 4:
            //clonar fila
            clonar_fila(&fila, &clone);
            printf("fila normal!\n");
            printar_fila(&fila);
            printf("fila clonada!\n");
            printar_fila(&clone);
            break;
        case 5:
            //concatena
            concatenada = concatenar(&fila, &clone);
            printar_fila(&concatenada);
            break;
        case 6:
            //inverter
            // inverter(&fila);
            printar_fila(&fila);
            break;
        }

    } while (op != 0);

    return 0;
}