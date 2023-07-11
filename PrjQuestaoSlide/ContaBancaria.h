#ifndef LISTA_HEADER
#define LISTA_HEADER

#include <stdio.h>

typedef struct ContaBancariaEst{

    int numero;
    double saldo;

} ContaBancaria;

void inicializa(ContaBancaria*);
void deposito(ContaBancaria*);
void saque(ContaBancaria*);
void imprime(ContaBancaria);

#endif
