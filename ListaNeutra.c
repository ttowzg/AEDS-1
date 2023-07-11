#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char nome[101];
    float valor;

} TItem;

typedef struct TCelulaEst
{
    TItem item;
    struct TCelulaEst* pProx; /* Apontador pProx; */
} TCelula;

typedef struct
{
    TCelula* pPrimeiro;
    TCelula* pUltimo;
} TLista;

//---------------------------------------------------//

void FLVazia (TLista* pLista)
{
    pLista->pPrimeiro = (TCelula*)
                        malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
}
int Lvazia (TLista* pLista)
{
    return (pLista->pPrimeiro == pLista->pUltimo);
}

void Linsere (TLista* pLista, TItem* pItem)
{
    pLista->pUltimo->pProx =
        (TCelula*) malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->item = *pItem;
    pLista->pUltimo->pProx = NULL;
}

int Lretira (TLista* pLista, TItem* pItem)
{
    TCelula* pAux;
    if (Lvazia(pLista))
        return 0;
    *pItem = pLista->pPrimeiro->pProx->item;
    pAux = pLista->pPrimeiro;
    pLista->pPrimeiro = pLista->pPrimeiro->pProx;
    free(pAux);
    return 1;
}

void LerProd(TItem *prod){

    fflush(stdin);
    printf("Codigo do produto: ");
    scanf("%d", &prod->codigo);
    fflush(stdin);
    printf("Nome: ");
    fgets(prod->nome, 101, stdin);
    printf("Valor do Produto: ");
    scanf("%f", &prod->valor);

}

void ImpProd(TLista* pLista, TItem* pItem){


    printf("-------------//-------------\n");
    printf("O codigo sera deste item:\n");
    printf("%d\n", pItem->codigo);
    printf("%s", pItem->nome);
    printf("%.2f\n", pItem->valor);
    printf("------------//--------------\n");

}

void Limprime (TLista* pLista)
{
    TCelula* pAux;
    pAux = pLista->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        printf("----------------------------\n");
        printf("%d\n", pAux->item.codigo);
        printf("%s", pAux->item.nome);
        printf("%.2f\n", pAux->item.valor);
        pAux = pAux->pProx; /* proxima celula */
    }
}

void ProcuraCodigo (TLista* pLista, TItem* pItem){

    int temp;
    TCelula* pAux;
    pAux = pLista->pPrimeiro->pProx;


    printf("Digite o codigo para imprimir o item: ");
    scanf("%d", &temp);

    while (pAux != NULL){
        if (pAux->item.codigo == temp){
            ImpProd(pLista, pItem);
            break;
        }
        pAux = pAux->pProx;
    }

    if (pAux == NULL) {
        printf("Codigo nao encontrado na lista.\n");
    }

}





int main (void){

    TLista lista;
    FLVazia(&lista);
    TItem prod;
    char verif;
    int i;
    int contador = 0;

    fflush(stdin);
    printf("\nDigite S para incluir e N para parar.");
    printf("\nDeseja incluir produtos: ");
    fflush(stdin);
    scanf("%c", &verif);

    while(verif != 'n'){


    LerProd(&prod);
    Linsere(&lista, &prod);

    fflush(stdin);
    printf("\nDigite S para incluir e N para parar.");
    printf("\nDeseja incluir produtos: ");
    fflush(stdin);
    scanf("%c", &verif);
    contador++;

    }
    ///////////////////////////////////////////////
    
    Limprime(&lista);
    printf("----------------------------\n");

    ProcuraCodigo(&lista, &prod);

    ///////////////////////////////////////////////

    for(i = 1; i < contador; i++){

        Lretira(&lista, &prod);

    }


    FLVazia(&lista);
    int resul = Lvazia(&lista);
    if (resul == 1){
        printf("lista vazia");
    }


}