#include <stdio.h>
#include "ContaBancaria.h"

void inicializa(ContaBancaria *conta)
{
    fflush(stdin);
    printf("Digite o numero da conta: ");
    scanf("%d", &conta->numero);
    printf("Digite o saldo: ");
    scanf("%lf", &conta->saldo);
}

void deposito(ContaBancaria *conta)
{
    double valor;
    printf("Deposito no valor de: ");
    scanf("%lf", &valor);
    conta->saldo += valor;
}

void saque(ContaBancaria *conta)
{

    double saque;
    printf("Digite quanto deseja sacar: ");
    scanf("%lf", &saque);
    conta->saldo -= saque;
}

void imprime(ContaBancaria conta)
{

    printf("\nNumero: %d\n", conta.numero);
    printf("Saldo: %lf\n", conta.saldo);
}
