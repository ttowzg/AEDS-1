#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{

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

    ProcuraCodigo(&lista, &prod);

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
