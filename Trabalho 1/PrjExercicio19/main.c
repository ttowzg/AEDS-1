#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int Chave;
    /* --- outros componentes --- */
} TItem;

typedef struct TCelulaEst {
    TItem item;
    struct TCelulaEst* pProx;
} TCelula;

typedef struct {
    TCelula* pFundo;
    TCelula* pTopo;
    int tamanho;
} TPilha;

void FPVazia(TPilha* pPilha) {
    pPilha->pTopo = (TCelula*)malloc(sizeof(TCelula));
    pPilha->pFundo = pPilha->pTopo;
    pPilha->pTopo->pProx = NULL;
    pPilha->tamanho = 0;
}

int PVazia(TPilha* pPilha) {
    return (pPilha->pTopo == pPilha->pFundo);
}

int Empilha(TPilha* pPilha, TItem* pItem) {
    TCelula* pNovo;
    pNovo = (TCelula*)malloc(sizeof(TCelula));
    pNovo->item = *pItem;
    pNovo->pProx = pPilha->pTopo;
    pPilha->pTopo = pNovo;
    pPilha->tamanho++;
    return 1;
}

int Desempilha(TPilha* pPilha, TItem* pItem) {
    TCelula* pAux; /* celula a ser removida */
    if (PVazia(pPilha))
        return 0;
    pAux = pPilha->pTopo;
    pPilha->pTopo = pAux->pProx;
    *pItem = pAux->item;
    free(pAux);
    pPilha->tamanho--;
    return 1;
}

int PTamanho(TPilha* pPilha) {
    return (pPilha->tamanho);
}

void InverterPilha(TPilha* pPilha) {
    TPilha auxPilha;
    TItem item;

    FPVazia(&auxPilha);

    while (!PVazia(pPilha)) {
        Desempilha(pPilha, &item);
        Empilha(&auxPilha, &item);
    }

    *pPilha = auxPilha;
}

int main (void)
{
    TPilha pilha;
    FPVazia(&pilha);
    TItem item;


    int opcao;

    do{
        printf("1. Inserir elementos\n");
        printf("2. Inverter pilha\n");
        printf("3. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:{

            scanf("%d",&item.Chave);
            Empilha(&pilha,&item);
            break;
        }
        case 2:{

            printf("Pilha Invertida:\n");
            InverterPilha(&pilha);
            while(!PVazia(&pilha)){
                Desempilha(&pilha,&item);
                printf("%d\n",item.Chave);

            }

            break;
        }
        case 3:{
            printf("Saindo");
        break;
        }
        default:{
        printf("\ninvalido\n");
            break;
        }
        }

    }while(opcao != 3);





return 0;
}
