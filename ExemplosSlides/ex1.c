#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int inteiro = 10;
    float real = 3.1415;

    int *x = &inteiro;
    float *y = &real;

    printf("\nantes o int: %d\n", inteiro);
    printf("antes o real: %.4f\n\n", real);

    *x *= (3);
    *y *= (3);

    printf("agora o int: %d\n", inteiro);    
    printf("agora o real: %.4f\n", real );

    return 0;
}