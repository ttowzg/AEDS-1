#include <stdio.h>
#include <stdlib.h>
void ImpInvertido(int n)
{

    if(n < 10)
    {

        printf("%d", n);
        return;
    }

    printf("%d", n % 10);

    ImpInvertido(n/10);

}

int main()
{

    int n;
    printf("Digite um numero aleatorio: ");
    scanf("%d", &n);

    printf("Seu numero: %d\n", n);
    printf("Seu numero Invertido: ");
    ImpInvertido(n);


    return 0;
}
