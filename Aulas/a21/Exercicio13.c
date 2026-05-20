#include <stdio.h>

typedef struct{
    float largura;
    float altura;
}Retangulo;

void dobrar(Retangulo *r){
    r->largura *= 2;
    r->altura *= 2;
}

void imprimeRetangulo(Retangulo *r){
    printf("Largura: %.2f\n", r->largura);
    printf("Altura: %.2f\n", r->altura);
}


int main(){
    Retangulo retangulo ={3.5, 4.2};

    imprimeRetangulo(&retangulo);
    dobrar(&retangulo);
    imprimeRetangulo(&retangulo);
    dobrar(&retangulo);
    imprimeRetangulo(&retangulo);

}