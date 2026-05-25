#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct{
    int x;
    int y;
}Ponto;

typedef struct{
    Ponto centro;
    int raios[5];
}Alvo;

float dist_pt(Ponto a, Ponto b)
{
  // dá para calcular a distância usando o que nos ensinou Pitágoras
  float cateto1 = a.x - b.x;
  float cateto2 = a.y - b.y;
  float hipotenusa = sqrt(cateto1*cateto1 + cateto2*cateto2);
  return hipotenusa;
}

bool pontoEstaNoCirculo(Alvo c, Ponto p, int r){
    if(dist_pt(c.centro, p) < c.raios[r]) return true;
    return false;
}

int calculaPontos(Alvo a, Ponto p){
    if(!pontoEstaNoCirculo(a, p, 4)) return 0;
    for(int i = 0; i < 5; i++){
        if(pontoEstaNoCirculo(a, p, i)) return 100 - (15 * i);
    }
    return 0;
}

int main(){

    Alvo a = {{10,20}, {5, 10, 15, 20, 25}};

    Ponto p = {15,20};

    printf("Pontuação: %d", calculaPontos(a, p));

    return 0;
}