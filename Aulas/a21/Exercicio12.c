#include <stdio.h>

typedef struct{
    int x;
    int y;
}Ponto;

void imprimePonto(Ponto *p){
    printf("X: %d\n", p->x);
    printf("Y: %d\n", p->y);
}

void movePonto(Ponto *p, int dx, int dy){
    p->x += dx;
    p->y += dy;
}

int main(){
    Ponto p = {2,4};

    imprimePonto(&p);
    movePonto(&p, 3,3);
    imprimePonto(&p);

}