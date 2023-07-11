#include <stdio.h>
#include <stdlib.h>

    // exercicio feito em sala;

typedef struct Pessoa
{

    char nome [51];
    int ano_nascimento;
    float salario;



} jogador;

typedef struct Organizacao
{

    char nome[51];
    int ano_fund;
    jogador v_jog[3];


} time;

void cadastro(time v_times[], int tam)
{
    int j;
    for(j = 0; j < tam; j++)
    {
        fflush(stdin);
        printf("digite o nome do time:\n");
        fgets(v_times[j].nome, 51, stdin);
        printf("qual ano de fundacao:\n");
        scanf("%d", &v_times[j].ano_fund);
        int i;
        for(i = 0; i < 3; i++)
        {
            fflush(stdin);
            printf("digite o nome do jogador %d do time:\n", i + 1);
            fgets(v_times[j].v_jog[i].nome, 51, stdin);
            printf("digite o ano de nascimento do jogador %d:\n", i + 1);
            scanf("%d", &v_times[j].v_jog[i].ano_nascimento);
            printf("digite o salario do jogador %d\n", i + 1);
            scanf("%f", &v_times[j].v_jog[i].salario);

        }

    }

}

void imprimir(time v_times[], int tam)
{
    int j;

    for( j = 0; j < tam; j++){

    printf("------------------------------\n");
    printf("o time: ");
    puts(v_times[j].nome);
    printf("o ano de fundacao: ");
    printf("\n%d", v_times[j].ano_fund);

    int i;
    for(i = 0; i < 3; i++)

    {
        printf("o jogador %d: ", i + 1);
        puts(v_times[j].v_jog[i].nome);
        printf("o ano de nascimento: %d", v_times[j].v_jog[i].ano_nascimento);
        printf("o salario: %f\n", v_times[j].v_jog[i].salario);

    }

    }
}

void imprimir_maior_sal(time v_times[], int tam)
{

    float maior_sal;
    int i, j, ti=0, jo=0;
    maior_sal = v_times[0].v_jog[0].salario;

    for(i = 0; i < tam; i++)
    {
        for( j = 0; j < 3; j++)
        {

            if (v_times[i].v_jog[j].salario > maior_sal ){
                maior_sal = v_times[i].v_jog[j].salario;
                ti = i;
                jo = j;
            }
        }
    }

    printf("\no maior salario eh do:\n");
    puts(v_times[ti].v_jog[jo].nome);
}

void imprimir_time_novo(time v_times[], int tam)
{

    int mais_novo;
    int i, temp;

    mais_novo = v_times[0].ano_fund;

    for(i = 0; i < tam; i++)
    {

        if(mais_novo < v_times[i].ano_fund)
            mais_novo = v_times[i].ano_fund;
        temp = i;
    }

    printf("O time mais novo sera: %d", v_times[temp].ano_fund);


}



int main()
{

    time *v_times;
    v_times = (time*)malloc(3 * sizeof(time));

    cadastro(v_times, 3);
    imprimir(v_times, 3);
    imprimir_maior_sal(v_times, 3);
    imprimir_time_novo(v_times, 3);

    free(v_times);

    return 0;
}

