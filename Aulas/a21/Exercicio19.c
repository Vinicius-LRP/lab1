#include <stdio.h>
typedef struct{
    int potencia;
}Motor;

typedef struct{
    char modelo[50];
    Motor *motor;
}Carro;

void imprimeCarro(Carro *c){
    printf("Modelo: %s\n", c->modelo);
    printf("Potencia: %d\n", c->motor->potencia);
}

void turbinarCarro(Carro *c, int extra){
    c->motor->potencia += extra;
}


int main(){
    Carro c = {"Jetta"};
    Motor m = {230};

    c.motor = &m;

    imprimeCarro(&c);
    turbinarCarro(&c, 200);
    imprimeCarro(&c);
}