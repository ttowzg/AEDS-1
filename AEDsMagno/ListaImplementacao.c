#include <stdlib.h>
#include <stdio.h>
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
  struct celula *prox;
} TCelula;

typedef struct
{
  TCelula *primeiro;
  TCelula *ultimo;
  int tamanho;

} TLista;

void FLVazia(TLista *Lista)
{
  Lista->primeiro = (TCelula *)malloc(sizeof(TCelula));
  Lista->ultimo = Lista->primeiro;
  Lista->primeiro->prox = NULL;
  Lista->tamanho = 0;
}

int Vazia(TLista Lista)
{
  return (Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto x, TLista *Lista)
{

  Lista->ultimo->prox =
      (TCelula *)malloc(sizeof(TCelula));
  Lista->ultimo = Lista->ultimo->prox;
  Lista->ultimo->item = x;
  Lista->ultimo->prox = NULL;
  Lista->tamanho++;
}

void ImprimirProdutos(TLista *Lista)
{

  TCelula *p;
  p = Lista->primeiro->prox;

  while (p != NULL)
  {
    printf("\n------------//------------\n");
    printf("nome: %s\n", strtok(p->item.nome, "\n"));
    printf("descricao: %s\n", strtok(p->item.descricao, "\n"));
    printf("Preco: %lf\n", p->item.preco);
    printf("Peso: %lf\n", p->item.peso);
    printf("codigo: %d\n", p->item.codigo);
    printf("quantidade: %d\n", p->item.quantidade);
    p = p->prox;
  }
}

void impProd(TProduto x)
{

  printf("nome: %s\n", strtok(x.nome, "\n"));
  printf("Preco: %lf\n", x.preco);
  printf("Peso: %lf\n", x.peso);
  printf("codigo: %d\n", x.codigo);
  printf("quantidade: %d\n", x.quantidade);
}

TCelula *Pesquisar(TLista Lista, TProduto Item)
{

  TCelula *Aux;
  Aux = Lista.primeiro;
  while (Aux->prox != NULL)
  {
    if (Aux->prox->item.codigo == Item.codigo)
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

void Excluir(TLista *Lista, TProduto *Item)
{

  TCelula *Aux1, *Aux2;
  Aux1 = Pesquisar(*Lista, *Item);
  if (Aux1 != NULL)
  {
    Aux2 = Aux1->prox;
    Aux1->prox = Aux2->prox;
    *Item = Aux2->item;

    if (Aux1->prox == NULL)
      Lista->ultimo = Aux1;
    free(Aux2);
    Lista->tamanho--;
  }
}

void LerProduto(TProduto *x)
{

  printf("Digite o nome do produto: ");
  setbuf(stdin, NULL);
  fgets(x->nome, 50, stdin);

  printf("Digite uma descricao do produto: ");
  setbuf(stdin, NULL);
  fgets(x->descricao, 100, stdin);

  fflush(stdin);
  printf("Digite o codigo do produto: ");
  scanf("%d", &x->codigo);

  printf("Digite o preco do produto: ");
  scanf("%lf", &x->preco);

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
