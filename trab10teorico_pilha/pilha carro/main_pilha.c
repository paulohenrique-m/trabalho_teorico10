#include <stdio.h>
#include "pilha.h"

//===========================================
int menu(int opc)
{
  printf("\n--------------PILHA--------------\n");
  printf("1-mostrar os carros \n");
  printf("2-add carro\n");
  printf("3-tirar ultimo carro\n");
  printf("opc:");
  scanf("%i", &opc);
  return opc;
}
//===========================================
void retira_carro(Pilha *p, Carro *carro)
{
  Carro aux;
  Pilha aux_pilha;

  int qtd_manobras;

  criar_pilha(&aux_pilha);

  int placa;
  printf("qual a placa do carro a ser retirado?\n");
  scanf("%i", &placa);
  aux = pop(p);

  while (aux.placa != -1 && aux.placa != placa)
  {
    push(&aux_pilha, aux);
    aux = pop(p);
  }

  qtd_manobras = carro->qtd_manobras;

  if (aux.placa == -1)
  {
    printf("\nCarro nao encontrado!!");
    aux = pop(&aux_pilha);
    while (aux.placa != -1)
    {
      push(p, aux);
      aux = pop(&aux_pilha);
    }
    return;
  }

  printf("\nCarro foi manobrado %i vezes antes de sair!\n", qtd_manobras);

  aux = pop(&aux_pilha);
  while (aux.placa != -1)
  {
    aux.qtd_manobras++;
    push(p, aux);
    aux = pop(&aux_pilha);
    printf("carro manobrado na pilha padrão\n");
  }
}
//===========================================
int main(void)
{
  Pilha pilha;
  Carro carro;
  int aux, opc = -1;
  criar_pilha(&pilha);
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
      //add
      carro = novo_carro();
      push(&pilha, carro);
      break;
    case 3:
      //tirar da pilha
      pop(&pilha);
      break;
    case 4:
      //pesquisar carro pela placa e excluir
      printar_pilha(&pilha);
      retira_carro(&pilha, &carro);
      printar_pilha(&pilha);
      break;
    default:
      break;
    }
  }

  return 0;
}
