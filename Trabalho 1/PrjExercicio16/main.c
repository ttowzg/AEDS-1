#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TItemEst
{
    int id;
    char nome[101];
    int telefone;

} TItem;

typedef struct TCelulaEst
{
    TItem item;
    struct TCelulaEst* pProx;

} TCelula;

typedef struct TfilaEst
{
    TCelula* pFrente;
    TCelula* pTras;
    int tamanho;

} TFila;

void FFVazia(TFila *pFila){

    pFila->pFrente = (TCelula*)malloc(sizeof(TCelula));
    pFila->pTras = pFila->pFrente;
    pFila->pFrente->pProx = NULL;
    pFila->tamanho = 0;

}

int FVazia (TFila *pFila){

    return (pFila->pFrente == pFila->pTras);

}

int Enfileira (TFila *pFila, TItem *pItem){

    TCelula *pNovo;
    pNovo = (TCelula*)malloc(sizeof(TCelula));

    if(pNovo == NULL)
        return 0;

    pFila->pTras->pProx = pNovo;
    pFila->pTras = pNovo;
    pNovo->item = *pItem;
    pNovo->pProx = NULL;
    pFila->tamanho++;

    return 1;
}

int Desenfileira (TFila *pFila, TItem *pItem){

    TCelula *pAux;

    if(FVazia(pFila))
        return 0;

    pAux = pFila->pFrente;
    pFila->pFrente = pFila->pFrente->pProx;
    *pItem = pAux->item;
    free(pAux);
    pFila->tamanho--;

    return 1;


}

void LerItem(TItem *pItem){

    printf("ID do cliente: ");
    scanf("%d", &pItem->id);
    printf("Nome do cliente: ");
    getchar();
    fgets(pItem->nome, 101, stdin);
    fflush(stdin);
    printf("Celular para contato: ");
    scanf("%d", &pItem->telefone);

}


void Limprime (TFila* pFila)
{
    TCelula* pAux;
    pAux = pFila->pFrente->pProx;
    while (pAux != NULL)
    {
        fflush(stdin);
        printf("----------------------------\n");
        printf("ID do cliente: %d\n", pAux->item.id);
        printf("Nome do cliente: %s\n", pAux->item.nome);
        printf("Telefone do cliente: %d\n", pAux->item.telefone);
        pAux = pAux->pProx; /* proxima celula */
    }
}

void impPrimeiro(TFila *pFila)
{
  printf("----------------------------\n");
  printf("ID do primeiro: %d\n", pFila->pFrente->pProx->item.id);
  printf("Nome: %s", pFila->pFrente->pProx->item.nome);
  printf("Numero de celular: %d", pFila->pFrente->pProx->item.telefone);
}

int main (void){

    TFila fila;
    FFVazia(&fila);
    TItem item;


    int opcao;

  do
  {
    printf("\nMenu:\n");
    printf("1. Inserir contato\n");
    printf("2. Proximo contato\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
    {
      fflush(stdin);
      printf("\nInserir Contato\n");
      LerItem(&item);
      Enfileira(&fila, &item);
      printf("---------------\n");
      printf("Inserido.\n");
      printf("---------------");

      break;
    }
    case 2:
    {
      impPrimeiro(&fila);
      Desenfileira(&fila, &item);
      printf("\nProximo:\n");
      FVazia(&fila);
      if(fila.tamanho == 0){
         printf("\nFila vazia.\n");
      }
     break;
    }
    case 3:
    {
        printf("\nSaindo\n");

      break;
    }
    default:
    {
      printf("\nOpcao invalida, escolha novamente\n");
      break;
    }
    }
  } while (opcao != 3);



    return 0;
}
