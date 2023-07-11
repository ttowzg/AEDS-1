#include <stdio.h>
#include <stdlib.h>

int somatorio(int n){

    if (n == 0)
        return 0;

    else
        return n + somatorio(n - 1);

}

int main()
{
    int n;
    int resul;

    printf("Digite um numero aleatorio: ");
    scanf("%d", &n);

    resul = somatorio(n);
    printf("O resultado do somatorio sera: %d", resul);



    return 0;
}
