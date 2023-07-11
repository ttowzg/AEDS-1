#include <stdio.h>
#include <stdlib.h>

typedef struct TItemEst
{
    int Chave;

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

    fflush(stdin);
    printf("Chave do produto: ");
    scanf("%d", &pItem->Chave);

}


void Limprime (TFila* pFila)
{
    TCelula* pAux;
    pAux = pFila->pFrente->pProx;
    while (pAux != NULL)
    {
        printf("----------------------------\n");
        printf("%d\n", pAux->item.Chave);
        pAux = pAux->pProx; /* proxima celula */
    }
}

int main (void){

    TFila fila;
    FFVazia(&fila);
    TItem item;


    int opcao;

  do
  {
    printf("\nMenu:\n");
    printf("1. Enfileirar\n");
    printf("2. Desenfileirar\n");
    printf("3. Imprimir\n");
    printf("4. Imprimir o comprimento\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
    {

      printf("\nAdicionar Chave\n");
      fflush(stdin);
      LerItem(&item);
      Enfileira(&fila, &item);
      printf("---------------\n");
      printf("Enfileirado.\n");
      printf("---------------");
      break;
    }
    case 2:
    {
      Desenfileira(&fila, &item);
      printf("\nDesenfileirado primeiro\n");
      if(fila.tamanho == 0){
         printf("\nFila vazia.\n");
      }
      break;
    }
    case 3:
    {
      printf("\nImprimindo o conteudo:\n");
      printf(".\n");
      printf("..\n");
      printf("...\n");
      printf("....\n");
      Limprime(&fila);
      printf("----------------------------\n");
      printf("....\n");
      printf("...\n");
      printf("..\n");
      printf(".");
      break;
    }
    case 4:
    {
      printf("\nTamanho da lista sera: ");
      printf("%d\n", fila.tamanho);

      break;
    }
    case 5:
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
  } while (opcao != 5);



    return 0;
}
