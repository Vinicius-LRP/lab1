#include <stdio.h>
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

void ajustarPonto(Circulo c, Ponto *p){
    float d = dist_pt(c.centro, *p);
    if(d > c.raio){
        float dx = p->x - c.centro.x;
        float dy = p->y - c.centro.y;
        p->x = c.centro.x + (dx / d) * c.raio;
        p->y = c.centro.y + (dy / d) * c.raio;
    }
}

int main(){

    Circulo c = {{2.0, 3.0},3.5};
    Ponto p = {2.5, 2.5};

    ajustarPonto(c, &p);
    printf("Ponto ajustado: (%.2f, %.2f)\n", p.x, p.y);

    return 0;
}