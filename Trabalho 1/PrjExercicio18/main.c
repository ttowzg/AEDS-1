#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char carac;
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

void ImprimirPilha(TPilha* pPilha) {
    while (!PVazia(pPilha)) {
        TItem item;
        Desempilha(pPilha, &item);
        printf("%c", item.carac);
    }
}

int main() {
    TPilha pilha;
    TPilha pilhaAux;
    TItem item;
    char letra;
    FPVazia(&pilha);
    FPVazia(&pilhaAux);

    printf("Digite um caractere de cada vez (termine com '.'):\n"); /* por algum motivo, da primeira para segunda palavra precisa-se 
                                                                        de dois espaços para que apareça bem estruturado. */
    letra = getchar();
    while (letra != '.') {
        if (letra != ' ') {
            item.carac = letra;
            Empilha(&pilha, &item);
        } else {
            while (!PVazia(&pilha)) { 
                Desempilha(&pilha, &item);
                Empilha(&pilhaAux, &item);
            }
        }
        letra = getchar();
    }

    while (!PVazia(&pilha)) {
        Desempilha(&pilha, &item);
        Empilha(&pilhaAux, &item);
    }
    while (!PVazia(&pilhaAux)) {
        Desempilha(&pilhaAux, &item);
        Empilha(&pilha, &item);
    }

    printf("\n\nTexto invertido: ");
    ImprimirPilha(&pilha);
    printf(".\n");

    return 0;
}
