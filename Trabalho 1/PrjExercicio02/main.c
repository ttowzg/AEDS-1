#include <stdio.h>
#include <stdlib.h>

typedef struct livroEst
{

    char titulo[151];
    char autor [151];
    float preco[6];


} livro;

void dadosLivro(livro book[], int tam)
{

    int i,j;

    for(i = 0; i < tam; i++)
    {
        fflush(stdin);
        printf("Livro %d\n", i+1);
        printf("Titulo: ");
        fgets(book[i].titulo,151, stdin);
        printf("Autor: ");
        fgets(book[i].autor,151, stdin);
        printf("Precos 6 ultimos meses:\n");

        for(j = 0 ; j < 6; j++)
        {
            printf("Mes %d: ", j + 1);
            scanf("%f", &book[i].preco[j]);

        }

        printf("/////////////////////////////////////\n");

    }
}

void ImpCaroBarato (livro book[], int tam)
{

    int i, j;
    int posi_i, posi_j, posi_im, posi_jm;

    float maior_preco, menor_preco;

    maior_preco = book[0].preco[0];
    menor_preco = book[0].preco[0];

    for(i = 0; i < tam; i++)
    {
        for(j = 0 ; j < 6; j++)
        {

            if(book[i].preco[j] > maior_preco)
            {
                maior_preco = book[i].preco[j];
                posi_i = i;
                posi_j = j;
            }


            if(book[i].preco[j] < menor_preco)
            {
                menor_preco = book[i].preco[j];
                posi_im = i;
                posi_jm = j;

            }



        }


    }

    printf("\nO maior preco sera do livro com:\n");
    printf("Titulo: %s", book[posi_i].titulo);
    printf("Autor: %s", book[posi_i].autor);
    printf("Preco: %.2f\n", book[posi_i].preco[posi_j]);
    printf("-------------------------------------\n");
    printf("O menor preco sera do livro:\n");
    printf("Titulo: %s", book[posi_im].titulo);
    printf("Autor: %s", book[posi_im].autor);
    printf("Preco: %.2f\n", book[posi_im].preco[posi_jm]);


}





void ImpPrecoMed(livro book[], int tam)
{

    int i,j;
    float soma[6];
    float media[6];
    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < 6; j++)
        {

            soma[i] += book[i].preco[j];

        }
        media[i] = (soma[i])/6;
        printf("A media de precos do livro %d : %.2f\n", i+ 1, media[i]);

    }

}

int main()
{

    int tam;
    printf("Quantos livros deseja entrar: ");
    scanf("%d", &tam);

    livro *book = (livro*)malloc(tam * sizeof(livro));

    dadosLivro(book,tam);
    ImpPrecoMed(book, tam);
    printf("-------------------------------------");
    ImpCaroBarato(book, tam);


    return 0;
}
