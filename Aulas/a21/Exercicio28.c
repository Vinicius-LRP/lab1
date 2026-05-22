#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct{
    float x;
    float y;
}Ponto;

typedef struct{
    Ponto centro;
    float raio;
}Circulo;

float dist_pt(Ponto a, Ponto b)
{
  // dá para calcular a distância usando o que nos ensinou Pitágoras
  float cateto1 = a.x - b.x;
  float cateto2 = a.y - b.y;
  float hipotenusa = sqrt(cateto1*cateto1 + cateto2*cateto2);
  return hipotenusa;
}

bool pontoEstaNoCirculo(Circulo *c, Ponto *p){
    if(dist_pt(c->centro, *p) <= c->raio) return true;
    return false;
}

int main(){

    Circulo c = {{2.0, 3.0},3.5};
    Ponto p = {2.5, 2.5};

    printf("%d\n", pontoEstaNoCirculo(&c, &p));

}