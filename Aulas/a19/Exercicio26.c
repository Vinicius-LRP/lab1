#include <stdio.h>

typedef struct{
    int potencia;
}Motor;

typedef struct{
    int aro;

}Pneu;

typedef struct{
    Motor *motor;
    Pneu *pneu;
}Veiculo;

void inspecionarVeiculo(Veiculo *v){
    printf("Potencia: %d\n", v->motor->potencia);
    printf("Aro: %d\n", v->pneu->aro);
}



int main(){
    Motor m = {200};
    Pneu p = {31};
    
    Veiculo v = {&m,&p};

    inspecionarVeiculo(&v);



}