#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circulo.h"

Circulo * circ_cria (float x, float y, float r)
{

    Circulo* c = (Circulo*)malloc(sizeof(Circulo));

    c->x = x;
    c->y = y;
    c->r = r;

    return c;
}


void circ_libera (Circulo * c)
{

    free(c);

}


float circ_area (Circulo * c)
{

    float area;
    area = 3.14 * pow((c->r),2); //considerando pi = 3.14

    return area;

}


int circ_concentricos (Circulo * c1, Circulo * c2)
{

    int ver;
    if(c1->x == c2->x && c1->y == c2->y)
        ver = 1;
    else
        ver = 0;

        return ver;

}


float circ_raio (Circulo * c)
{
    float raio;
    raio = c->r;
    return raio;

}
