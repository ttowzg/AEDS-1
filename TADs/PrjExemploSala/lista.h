#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

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

void FLVazia (TLista* pLista);
int Lvazia (TLista* pLista);
void LerProd(TItem *prod);
void Linsere (TLista* pLista, TItem* pItem);
int Lretira (TLista* pLista, TItem* pItem);
void Limprime (TLista* pLista);
void ImpProd(TLista* pLista, TItem* pItem);
void ProcuraCodigo(TLista *pLista, TItem *pItem);




#endif // LISTA_H_INCLUDED
