#include <stdio.h>
#include <stdlib.h>
#include "ContaBancaria.h"

int main()
{

    int opcao;

    printf("Escolha quais acoes deseja:\n");

    ContaBancaria conta1; //nao foi vetor, pois queremos apenas mostrar como funcionaria uma interface de comando;
    
    do{

    printf("Aperte:\n");
    printf("1 - Inicializar\n2 - Depositar\n3 - Sacar\n4 - Imprimir\n5 - Sair\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:

        inicializa(&conta1);
        break;

        case 2: 

        deposito(&conta1);
        break;

        case 3: 

        saque(&conta1);
        break;

        case 4:

        imprime(conta1);
        break;

        case 5: 

        printf("Done.");
        break;
    
    default:
        printf("erro.");
        break;
    }


    }while(opcao != 5);
    





}
