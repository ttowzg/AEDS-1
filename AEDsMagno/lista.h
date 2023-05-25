#ifndef LISTA_HEADER
#define LISTA_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto
{

    char nome[50];
    char descricao[100];
    int codigo;
    double preco;
    double peso;
    int quantidade;

} TProduto;

typedef struct celula
{
    TProduto item;
    struct celula* prox;
} TCelula;

typedef struct
{
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;

} TLista;


//-----------ESTRUTURAS-------------//

void FLVazia(TLista *Lista);
int Vazia(TLista Lista);
void Inserir(TProduto x, TLista *Lista);
void ImprimirProdutos(TLista *Lista);
void impProd(TProduto x);
TCelula* Pesquisar (TLista Lista, TProduto Item);
void Excluir (TLista *Lista, TProduto *Item);
void LerProduto(TProduto *x);
void Liberar(TLista *Lista);


#endif