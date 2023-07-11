#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Chave;
    /* --- outros componentes --- */
} TItem;

typedef struct TCelulaEst
{
    TItem item;
    struct TCelulaEst* pProx;
} TCelula;

typedef struct
{
    TCelula* pFundo;
    TCelula* pTopo;
    int tamanho;
} TPilha;

void FPVazia(TPilha* pPilha)
{
    pPilha->pTopo = (TCelula*)malloc(sizeof(TCelula));
    pPilha->pFundo = pPilha->pTopo;
    pPilha->pTopo->pProx = NULL;
    pPilha->tamanho = 0;
}

int PVazia(TPilha* pPilha)
{
    return (pPilha->pTopo == pPilha->pFundo);
}

int Empilha(TPilha* pPilha, TItem* pItem)
{
    TCelula* pNovo;
    pNovo = (TCelula*)malloc(sizeof(TCelula));
    pPilha->pTopo->item = *pItem;
    pNovo->pProx = pPilha->pTopo;
    pPilha->pTopo = pNovo;
    pPilha->tamanho++;
    return 1;
}

int Desempilha(TPilha* pPilha, TItem* pItem)
{
    TCelula* pAux; /* celula a ser removida */
    if (PVazia(pPilha))
        return 0;
    pAux = pPilha->pTopo;
    pPilha->pTopo = pAux->pProx;
    *pItem = pAux->pProx->item;
    free(pAux);
    pPilha->tamanho--;
    return 1;
}

int PTamanho(TPilha* pPilha)
{
    return (pPilha->tamanho);
}

void RemoveChave(TPilha* pPilha, TItem* pItem)
{
    int chave;
    int encontrada = 0;

    TPilha pAux;
    FPVazia(&pAux);

    printf("Digite a chave que deseja retirar: ");
    scanf("%d", &chave);

    while (!PVazia(pPilha)) {
        Desempilha(pPilha, pItem);

        if (pItem->Chave == chave) {
            encontrada = 1;
        } else {
            Empilha(&pAux, pItem);
        }
    }

    while (!PVazia(&pAux)) {
        Desempilha(&pAux, pItem);
        Empilha(pPilha, pItem);
    }

    if (!encontrada) {
        printf("A chave %d não foi encontrada na pilha.\n", chave);
    } else {
        printf("A chave %d foi removida da pilha.\n", chave);
    }
}

int main()
{
    TPilha pilha;
    FPVazia(&pilha);

    int opcao;
    TItem itemRemovido;

    do {
        printf("----- Menu -----\n");
        printf("1. Empilhar item\n");
        printf("2. Remover item por chave\n");
        printf("3. Exibir itens da pilha\n");
        printf("4. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                TItem novoItem;
                printf("Digite a chave do item: ");
                scanf("%d", &novoItem.Chave);
                Empilha(&pilha, &novoItem);
                printf("Item empilhado.\n");
                break;
            }
            case 2: {
                RemoveChave(&pilha, &itemRemovido);
                if (PTamanho(&pilha) > 0) {
                    printf("Item removido: %d\n", itemRemovido.Chave);
                }
                break;
            }
            case 3: {
                if (PTamanho(&pilha) > 0) {
                    printf("Itens na pilha:\n");
                    while (!PVazia(&pilha)) {
                        Desempilha(&pilha, &itemRemovido);
                        printf("%d\n", itemRemovido.Chave);
                    }
                } else {
                    printf("A pilha esta vazia.\n");
                }
                break;
            }
            case 4: {
                printf("Encerrando o programa.\n");
                break;
            }
            default: {
                printf("Opção invalida. Tente novamente.\n");
                break;
            }
        }

        printf("----------------\n");
    } while (opcao != 4);

    return 0;
}
