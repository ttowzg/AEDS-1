#include <stdio.h>

int main(void) {

    int *v = NULL;
    int tam;

    printf("Digite um valor de tamanho para o vetor: ");
    scanf("%d", &tam);

    v = (int*) malloc(tam * sizeof(int));

    printf("\nDigite os valores inteiros que preferir:\n");

    int i;

    for(i = 0; i < tam; i++){
        
        scanf("%d", &v[i]);

    }

    printf("\nOs valores serao:\n");
    printf("{");

    for(i = 0; i < tam; i++){

       if(i == tam - 1){
        printf("%d", v[i]);
       }else{
        printf("%d-", v[i]);
       }

    }

    printf("}");

    free(v);


    return 0;
}