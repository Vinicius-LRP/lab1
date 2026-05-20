#include <stdio.h>

typedef struct{
    float valor;
}Temperatura;

Temperatura* maiorTemperatura(Temperatura *a, Temperatura *b){
    if(a->valor > b->valor) return a;
    return b;
}

void imprimeTemperatura(Temperatura *a){
    printf("Temperatura: %.2f\n",a->valor );
}

int main(){
    Temperatura temp1 = {7.1};
    Temperatura temp2 = {8.1};


    imprimeTemperatura(maiorTemperatura(&temp1,&temp2));

}