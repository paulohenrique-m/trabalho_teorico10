#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include "pilha_dinamica.h"
#include "pilha_estatica.h"
void verificaParenteses(Pilha *p, char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == 40)
        {
            push(p, string[i]);
        }
        else if (string[i] == 41)
        {
            if (pop(p) == -1)
            {
                printf("\nExpressão Matemática Incorreta\n");
                return;
            }
        }
    }
    if (pilha_vazia(p))
    {
        printf("\nExpressão Matemática Correta\n");
    }
    else
    {
        printf("\nExpressão Matemática Incorreta\n");
    }
}
int main()
{
    char string[100];
    Pilha pilha;
    criar_pilha(&pilha);
    printf("\nvalida parenteses\n");
    printf("Digite uma expressao: ");
    scanf("%s", string);
    verificaParenteses(&pilha, string);
    return 0;
}