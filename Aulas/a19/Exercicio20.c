#include <stdio.h>

typedef struct{
    int valor;
}Ponto;

void trocaPonto(Ponto *a, Ponto *b){
    Ponto troca = *a;
    *a = *b;
    *b = troca;
}

void imprimePonto(Ponto *p){
    printf("Ponto: %d\n", p->valor);
}

int main(){
    Ponto p1 = {20};
    Ponto p2 = {30};

    imprimePonto(&p1);
    imprimePonto(&p2);

    trocaPonto(&p1, &p2);

    imprimePonto(&p1);
    imprimePonto(&p2);


}