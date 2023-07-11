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

void ProcuraTrocaIndices(TLista *pLista, TItem *pItem)
{

    char temp_1;
    char temp_2;

    TCelula *pAux1 = pLista->pPrimeiro->pProx;
    TCelula *pAux2 = pLista->pPrimeiro->pProx;

    TCelula* pCelula1 = NULL;
    TCelula* pCelula2 = NULL;

    printf("Digite o indice do primeiro elemento: ");
    scanf(" %c", &temp_1);
    printf("Digite o indice do segundo elemento: ");
    scanf(" %c", &temp_2);

    while (pAux1 != NULL && pAux2 != NULL)
    {
        if (pAux1->item.indice == temp_1)
            pCelula1 = pAux1;

        if (pAux2->item.indice == temp_2)
            pCelula2 = pAux2;
            
        if(pCelula1 != NULL && pCelula2 != NULL){
            char temp;

            temp = pCelula1->item.indice;
            pCelula1->item.indice = pCelula2->item.indice;
            pCelula2->item.indice = temp;
            printf("Indices trocados.\n");
            break;
        }
        
        pAux1 = pAux1->pProx;
        pAux2 = pAux2->pProx;

        
        
    }

       if(pCelula1 == NULL || pCelula2 == NULL){
        printf("Indice nao encontrado na lista.\n");
    }
    
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
    Limprime(&lista);
    printf("----------------------------\n");

    ProcuraTrocaIndices(&lista, &prod);
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

