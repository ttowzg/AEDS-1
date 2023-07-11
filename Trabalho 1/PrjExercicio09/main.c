#include <stdio.h>
#include <stdlib.h>

int somaItensVet(int v[], int tam, int aux){

    if(aux == tam)
        return 0;
    else
        return v[aux] + somaItensVet(v, tam, aux + 1);

}

int main()
{
    int i;
    int tam;
    int aux = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    int v[tam];

    printf("Digite os numeros que deseja:\n");

    for (i = 0; i < tam; i++){
        scanf("%d", &v[i]);
    }

    int resul = somaItensVet(v, tam, aux);

    printf("\nO resultado da soma do vetor sera: %d", resul);


    return 0;
}
