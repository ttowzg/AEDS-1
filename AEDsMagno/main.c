
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main()
{

    TLista Lista;
    FLVazia(&Lista);
    TProduto prod;

    int opcao;

    do
    {
        printf("\nMenu:\n");
        printf("1. Adicionar produto\n");
        printf("2. Buscar produto\n");
        printf("3. Excluir produtos com codigo impar\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {

            printf("\nAdicionar Produto\n");
            fflush(stdin);
            LerProduto(&prod);
            Inserir(prod, &Lista);
            ImprimirProdutos(&Lista);
            break;
        }
        case 2:
        {
            printf("\nBuscar Produto\n");
            printf("Insira o codigo do produto: ");
            scanf("%d", &prod.codigo);
            TCelula *achou = NULL;
            achou = Pesquisar(Lista, prod);

            if (achou)
            {
                impProd(prod);
            }
            else
            {
                printf("Produto nao encontrado\n");
            }
            break;
        }
        case 3:
        {
            TCelula *p, *ant;
            for (p = Lista.primeiro->prox, ant = Lista.primeiro; p != NULL; ant = p, p = p->prox)
            {
                if (p->item.codigo % 2 != 0)
                {
                    ant->prox = p->prox;
                    TProduto prod = p->item;
                    Excluir(&Lista, &prod);
                    p = ant;
                }
            }
            break;
        }
        case 4:
        {
            printf("Saindo do programa...\n");
            break;
        }
        default:
        {
            printf("Opcao invalida, escolha novamente\n");
            break;
        }
        }
    } while (opcao != 4);

    Liberar(&Lista);

    return 0;
}
