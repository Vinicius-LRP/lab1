#include <stdio.h>

typedef struct{
    float raio;
    float area;
}Circulo;

void calcularArea(Circulo *c){
    c->area = 3.14 * (c->raio * c->raio);
}

void imprimeCirculo(Circulo *c){
    printf("Raio: %.2f\n", c->raio);
    printf("Area: %.2f\n", c->area);
}

int main(){
    Circulo c = {2.0};

    calcularArea(&c);
    imprimeCirculo(&c);

}