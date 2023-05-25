#include <stdio.h>

void swap2x (int *a, int *b){

    int temp;
    
    *a *= (2);
    temp = *a;      //armazena o valor de a duplicado em uma variavel temporaria
    *b *= (2);      
    *a = *b;        // troca
    *b = temp;


}


int main(void){

    int x = 10;
    int y = 20;

    printf("O x era: %d\nO y era: %d\n", x, y);

    swap2x(&x,&y);

    printf("O x sera: %d\nO y sera: %d", x, y);


    return 0;
}