#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void FLVazia(TLista *Lista)
{
    Lista -> primeiro = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> primeiro;
    Lista -> primeiro -> prox = NULL;
    Lista ->tamanho = 0;
}

int Vazia(TLista Lista)
{
    return (Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto x, TLista *Lista)
{

    Lista -> ultimo -> prox =
        (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> ultimo -> prox;
    Lista -> ultimo -> item = x;
    Lista -> ultimo -> prox = NULL;
    Lista -> tamanho++;

}

void ImprimirProdutos(TLista *Lista)
{

    TCelula *p;
    p = Lista->primeiro->prox;

    while (p != NULL)
    {
        printf("\n------------//------------\n");
        printf("nome: %s\n", strtok(p -> item.nome, "\n"));
        printf("descricao: %s\n", strtok(p -> item.descricao, "\n"));
        printf("Preco: %lf\n", p->item.preco);
        printf("Peso: %lf\n", p->item.peso);
        printf("codigo: %d\n", p -> item.codigo);
        printf("quantidade: %d\n", p -> item.quantidade);
        p = p->prox;
    }
}

void impProd(TProduto x){

        printf("nome: %s\n", strtok(x.nome, "\n"));
        printf("Preco: %lf\n",x.preco);
        printf("Peso: %lf\n",x.peso);
        printf("codigo: %d\n",x.codigo);
        printf("quantidade: %d\n",x.quantidade);

}


TCelula* Pesquisar (TLista Lista, TProduto Item)
{

    TCelula* Aux;
    Aux = Lista.primeiro;
    while(Aux -> prox != NULL)
    {
        if(Aux -> prox-> item.codigo == Item.codigo)
        {
            return Aux;
        }
        else
        {
            Aux = Aux->prox;
        }
    }



    return NULL;

}

void Excluir (TLista *Lista, TProduto *Item)
{

    TCelula *Aux1, *Aux2;
    Aux1 = Pesquisar(*Lista, *Item);
    if (Aux1 != NULL )
    {
        Aux2 = Aux1 -> prox;
        Aux1 -> prox = Aux2 -> prox;
        *Item = Aux2 -> item;

        if( Aux1 -> prox == NULL )
            Lista -> ultimo = Aux1;
        free(Aux2);
        Lista -> tamanho--;

    }

}


void LerProduto(TProduto *x)
{


    printf("Digite o nome do produto: ");
    fflush(stdin);
    fgets(x->nome, 50, stdin);

    printf("Digite uma descricao do produto: ");
    fflush(stdin);
    fgets(x -> descricao, 100, stdin);

    fflush(stdin);
    printf("Digite o codigo do produto: ");
    scanf("%d", &x->codigo);

    printf("Digite o preco do produto: ");
    scanf("%lf",&x->preco);

    printf("Digite o peso do produto: ");
    scanf("%lf", &x->peso);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &x->quantidade);


}



void Liberar(TLista *Lista)
{
    TCelula *Aux = Lista->primeiro;
    while (Aux != NULL)
    {
        TCelula *prox = Aux->prox;
        free(Aux);
        Aux = prox;
    }
    Lista->primeiro = NULL;
    Lista->ultimo = NULL;
    Lista->tamanho = 0;
}
