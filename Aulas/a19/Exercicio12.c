#include <stdio.h>

typedef struct{
    int x;
    int y;
}Ponto;

void imprimePonto(Ponto *p){
    printf("X: %d\n", p->x);
    printf("Y: %d\n", p->y);
}

int main(){
    Ponto p = {2,4};

    imprimePonto(&p);

}