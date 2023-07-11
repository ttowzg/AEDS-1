#include <stdio.h>
#include <stdlib.h>

int testaVetor(int *v, int tam, int conf, int i){

    if (i >= tam){
        return -1;
    }

    if(v[i] == conf){
        return i;
    }

        return testaVetor(v,tam,conf, i + 1);



}

int main()
{
    int v[] = {1,3,5,7,9,11};
    int tam = sizeof(v) / sizeof(v[0]);
    int conf;
    int i = 0;

    printf("Digite um numero de 1 a 12: ");
    scanf("%d", &conf);

    int resul = testaVetor(v, tam, conf, i);
    printf("O resultado sera: %da posicao", resul);



    return 0;
}
