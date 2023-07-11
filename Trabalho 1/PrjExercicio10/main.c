#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 1000

typedef struct itemEst
{
    int chave;

} TItem;


typedef struct
{

    int primeiro;
    int ultimo;
    TItem item[MAXTAM];

} TLista;

void FLvazia(TLista *lista)
{

    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;

}
int Lvazia(TLista *lista)
{

    return(lista->primeiro == lista->ultimo);

}

int Linsere(TLista *lista, TItem n)
{

    if(lista->ultimo == MAXTAM)
        return 0;

    lista->item[lista->ultimo++] = n;
    return 1;

}

void Limprime (TLista* lista)
{
    for(int i = lista->primeiro; i < lista->ultimo; i++)
        printf("%d\n", lista->item[i].chave);
}

void trocaVet(TLista *lista, int m, int n)
{
    TItem temp;

    temp = lista->item[m];
    lista->item[m] = lista->item[n];
    lista->item[n] = temp;

}


void LerChaves(TLista *lista, TItem *n)
{

    printf("Digite a chave do item: ");
    scanf("%d", &(n->chave));


}
int main() // como a questão não delimita, fiz o mais simples possivel.
{
    TLista lista;
    TItem x,y;
    FLvazia(&lista);
    Lvazia(&lista);

    int m = 0;
    int n = 1;

    LerChaves(&lista, &x);
    Linsere(&lista, x);
    LerChaves(&lista, &y);
    Linsere(&lista, y);

    printf("Antes:\n");
    Limprime(&lista);

    trocaVet(&lista, m, n);

    printf("Depois:\n");
    Limprime(&lista);





    return 0;
}
