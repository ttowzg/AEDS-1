#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char indice;
    char nome[101];

} TItem;

typedef struct TCelulaEst
{
    TItem item;
    struct TCelulaEst *pProx; /* Apontador pProx; */
} TCelula;

typedef struct
{
    TCelula *pPrimeiro;
    TCelula *pUltimo;
} TLista;

void FLVazia(TLista *pLista)
{
    pLista->pPrimeiro = (TCelula *)
        malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
}
int Lvazia(TLista *pLista)
{
    return (pLista->pPrimeiro == pLista->pUltimo);
}

void Linsere(TLista *pLista, TItem *pItem)
{
    pLista->pUltimo->pProx =
        (TCelula *)malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->item = *pItem;
    pLista->pUltimo->pProx = NULL;
}

int Lretira(TLista *pLista, TItem *pItem)
{
    TCelula *pAux;
    if (Lvazia(pLista))
        return 0;
    *pItem = pLista->pPrimeiro->pProx->item;
    pAux = pLista->pPrimeiro;
    pLista->pPrimeiro = pLista->pPrimeiro->pProx;
    free(pAux);
    return 1;
}

void LerProd(TItem *prod)
{

    fflush(stdin);
    printf("indice do produto: ");
    scanf("%c", &prod->indice);
    fflush(stdin);
    printf("Nome: ");
    fgets(prod->nome, 101, stdin);
}

void ImpProd(TLista *pLista, TItem *pItem)
{

    printf("-------------//-------------\n");
    printf("O item sera:\n");
    printf("Indice: %c\n", pItem->indice);
    printf("Nome: %s", pItem->nome);
    printf("------------//--------------\n");
}

void Limprime(TLista *pLista)
{
    TCelula *pAux;
    pAux = pLista->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        printf("----------------------------\n");
        printf("%c\n", pAux->item.indice);
        printf("%s", pAux->item.nome);
        pAux = pAux->pProx;
    }
}

void Troca(TLista *pLista, TCelula *pCampo)
{

    if(pCampo == pLista->pPrimeiro)
         pLista->pPrimeiro = pCampo->pProx;
         else{

            TCelula *ant = pLista->pPrimeiro;
            while(ant->pProx != pCampo)
            ant = ant->pProx;

            ant->pProx = pCampo->pProx;
         }

    if (pCampo == pLista->pUltimo) {
        pLista->pUltimo = pCampo;
    }

    TCelula *proxima = pCampo->pProx;
    pCampo->pProx = proxima->pProx;
    proxima->pProx = pCampo;
        

}

int main(){

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
    printf("Lista original:\n");
    Limprime(&lista);
    printf("----------------------------\n");


    TCelula *p = lista.pPrimeiro->pProx; // Célula a ser trocada com a seguinte
    Troca(&lista, p);

    printf("Lista modificada:\n");
    Limprime(&lista);


    for(i = 1; i < contador; i++){

        Lretira(&lista, &prod);

    }


    FLVazia(&lista);
    int resul = Lvazia(&lista);
    if (resul == 1){
        printf("lista vazia");
    }





    return 0;
}



 