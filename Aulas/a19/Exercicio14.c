#include <stdio.h>

typedef struct{
    int timeA;
    int timeB;
}Placar;

void resetarPlacar(Placar *p){
    p->timeA = 0;
    p->timeB = 0;
}

void imprimePlacar(Placar *p){
    printf("Time A %d x %d Time B\n", p->timeA, p->timeB);
}

int main(){
    Placar p = {2, 0};

    imprimePlacar(&p);
    resetarPlacar(&p);
    imprimePlacar(&p);


}