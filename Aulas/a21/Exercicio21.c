#include <stdio.h>

typedef struct{
    int potencia;
}Motor;

void modificaPontecia(Motor **m, int aumento){
    (*m)->potencia += aumento;
}

void imprimeMotor(Motor **m){
    printf("Potencia: %d\n", (*m)->potencia);
}

int main(){
    Motor m = {200};
    Motor *p = &m;
    Motor **pp = &p;

    imprimeMotor(pp);
    modificaPontecia(pp, 20);
    imprimeMotor(pp);

}