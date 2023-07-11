#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int queue;
    /* outros componentes */
} TItem;

typedef struct {
    TItem vItem[MAX_SIZE];
    int iFrente, iTras;
} TFila;

void FFVazia(TFila* pFila) {
    pFila->iFrente = 0;
    pFila->iTras = pFila->iFrente;
}

int Fvazia(TFila* pFila) {
    return (pFila->iFrente == pFila->iTras);
}

int Enfileira(TFila* pFila, TItem* pItem) {
    if (((pFila->iTras + 1) % MAX_SIZE) == pFila->iFrente)
        return 0; /* fila cheia */
    pFila->vItem[pFila->iTras] = *pItem;
    pFila->iTras = (pFila->iTras + 1) % MAX_SIZE;
    return 1;
}

int Desenfileira(TFila* pFila, TItem* pItem) {
    if (Fvazia(pFila))
        return 0;
    *pItem = pFila->vItem[pFila->iFrente];
    pFila->iFrente = (pFila->iFrente + 1) % MAX_SIZE;
    return 1;
}

int main() {
    TFila fila;
    FFVazia(&fila);
    TItem item;

    int opcao;
    do {
        printf("Escolha uma opcao:\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Verificar se a fila esta vazia\n");
        printf("4. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor para enfileirar: ");
                scanf("%d", &item.queue);
                if (Enfileira(&fila, &item))
                    printf("Valor enfileirado com sucesso.\n");
                else
                    printf("Erro: a fila esta cheia.\n");
                break;
            case 2:
                if (Desenfileira(&fila, &item))
                    printf("Valor desenfileirado: %d\n", item.queue);
                else
                    printf("Erro: a fila esta vazia.\n");
                break;
            case 3:
                if (Fvazia(&fila))
                    printf("A fila esta vazia.\n");
                else
                    printf("A fila nao esta vazia.\n");
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
