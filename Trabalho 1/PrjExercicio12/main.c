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


void inssub(TLista* l1, int i1, TLista* l2, int i2, int len)
{
    TCelula* pAuxL1 = l1->pPrimeiro->pProx;
    TCelula* pAuxL2 = l2->pPrimeiro->pProx;

    int count1 = 0;
    while (count1 < i1 && pAuxL1 != NULL)
    {
        pAuxL1 = pAuxL1->pProx;
        count1++;
    }

    int count2 = 0;
    while (count2 < i2 && pAuxL2 != NULL)
    {
        pAuxL2 = pAuxL2->pProx;
        count2++;

    }

    int count = 0;
    while (count < len && pAuxL2 != NULL)
    {
        Linsere(l1, &(pAuxL2->item));
        pAuxL2 = pAuxL2->pProx;
        count++;
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


    ///////////////////////////////////////////////

    TLista l2;
    FLVazia(&l2);
    TItem newItem;

    for (i = 1; i <= 3; i++) // Exemplo de inserção na l2
    {
        newItem.codigo = 100 + i; // Geração aleatoria de codigo para evitar entrada exagerada do teclado
        sprintf(newItem.nome, "Produto %d", i);
        newItem.valor = 10.0 * i;
        Linsere(&l2, &newItem);
    }

    inssub(&lista, 2, &l2, 1, 2);

    printf("Lista apos a insercao de elementos da l2:\n");
    Limprime(&lista);
    printf("----------------------------\n");

    for(i = 1; i < contador; i++){

        Lretira(&lista, &prod);

    }


    FLVazia(&lista);
    int resul = Lvazia(&lista);
    if (resul == 1){
        printf("lista vazia");
    }


}
