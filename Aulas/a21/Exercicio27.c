#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

bool comparaDatas(Data *d1, Data *d2){

    if(d1->ano > d2->ano) return false;
    if(d1->ano < d2->ano) return true;

    if(d1->mes > d2->mes) return false;
    if(d1->mes < d2->mes) return true;

    if(d1->dia > d2->dia) return false;
    if(d1->dia < d2->dia) return true;

    printf("Dias iguais!");
    return 1;
}

int main(){
    Data data1 = {22, 05, 2026};
    Data data2 = {10, 04, 2003};

    printf("%d\n", comparaDatas(&data2, &data1));

}