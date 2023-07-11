#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

int main()
{
    int i;
    Circulo* c1;
    Circulo* c2;

    c1 = circ_cria(1.25, 2.20,4.0);
    c2 = circ_cria(1.25, 2.5,5.0);

    printf("Circulo 1:\n");
    printf("Centro: (%.2f, %.2f)\n", c1->x, c1->y);
    printf("Raio: %.2f\n", c1->r);

    printf("\nCirculo 2:\n");
    printf("Centro: (%.2f, %.2f)\n", c2->x, c2->y);
    printf("Raio: %.2f\n", c2->r);


    if(circ_concentricos(c1,c2) == 1){
        printf("\nSao concentricos\n\n");

        if(circ_raio(c1) > circ_raio(c2))
            printf("O maior Raio sera do circulo 1: %.2f\n\n",circ_raio(c1));
            else
                printf("O maior Raio sera do circulo 2: %.2f\n\n", circ_raio(c2));
    }
        else
            printf("\nNao concentricos\n\n");


    printf("A area do circulo 1 sera: ");
    printf("%.2f", circ_area(c1));
    printf("\nA area do circulo 2 sera: ");
    printf("%.2f", circ_area(c2));

    free(c1);
    free(c2);



}
