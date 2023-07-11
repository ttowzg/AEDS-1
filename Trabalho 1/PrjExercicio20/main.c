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

int TestarIgualdadePilhas(TPilha* pPilha1, TPilha* pPilha2) {
    if (PTamanho(pPilha1) != PTamanho(pPilha2))
        return 0;

    TPilha auxPilha1;
     TPilha auxPilha2;
    FPVazia(&auxPilha1);
    FPVazia(&auxPilha2);

    TItem item1, item2;
    int iguais = 1;

    while (!PVazia(pPilha1)) {
        Desempilha(pPilha1, &item1);
        Desempilha(pPilha2, &item2);

        if (item1.Chave != item2.Chave) {
            iguais = 0;
            break;
        }

        Empilha(&auxPilha1, &item1);
        Empilha(&auxPilha2, &item2);
    }

    while (!PVazia(&auxPilha1)) { // restaura pilhas
        Desempilha(&auxPilha1, &item1);
        Empilha(pPilha1, &item1);
    }

    while (!PVazia(&auxPilha2)) {
        Desempilha(&auxPilha2, &item2);
        Empilha(pPilha2, &item2);
    }

    return iguais;
}

int main(void) {
    
    TPilha pilha1, pilha2;
    FPVazia(&pilha1);
    FPVazia(&pilha2);

    TItem item;
    int opcao;

    do {
        printf("1. Inserir elementos na pilha 1\n");
        printf("2. Inserir elementos na pilha 2\n");
        printf("3. Testar igualdade das pilhas\n");
        printf("4. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                printf("Digite um elemento para a pilha 1: ");
                scanf("%d", &item.Chave);
                Empilha(&pilha1, &item);
                break;
            }
            case 2: {
                printf("Digite um elemento para a pilha 2: ");
                scanf("%d", &item.Chave);
                Empilha(&pilha2, &item);
                break;
            }
            case 3: {
                int saoIguais = TestarIgualdadePilhas(&pilha1, &pilha2);
                if (saoIguais)
                    printf("As pilhas sao iguais.\n");
                else
                    printf("As pilhas sao diferentes.\n");
                break;
            }
            case 4: {
                printf("Saindo\n");
                break;
            }
            default: {
                printf("\nOpcao invalida\n");
                break;
            }
        }
    } while (opcao != 4);

    return 0;
}
