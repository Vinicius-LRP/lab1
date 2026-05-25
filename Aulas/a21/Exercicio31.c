#include <stdio.h>

typedef struct{
    int x;
    int y;
}Ponto;

typedef struct{
    Ponto centro;
    int raios[5];
}Alvo;

int main(){

    Alvo a = {{10,20}, {5, 10, 15, 20, 25}};

    Ponto p = {15,20};

    printf("Centro: (%d, %d)\n", a.centro.x, a.centro.y);

    for(int i = 0; i < 5; i++){
        printf("Raio %d: %d\n", i+1, a.raios[i]);
    }

    return 0;
}