#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int inferior;
    int superior;
}Intervalo;

bool estaNoVetor(int tam, Intervalo i[tam], int num){
    for(int a = 0; a < tam ; a++){
        if(num >= i[a].inferior && num <= i[a].superior) return true;
    }
    return false;
}

int qntsVezesNoVetor(int tam, Intervalo i[tam], int num){
    int vezes = 0;
    for(int a = 0; a < tam ; a++){
        if(num >= i[a].inferior && num <= i[a].superior) vezes++;
    }
    return vezes;
}

int posicaoNoVetor(int tam, Intervalo i[tam], int num){
    for(int a = 0; a < tam; a++){
        if(num >= i[a].inferior && num <= i[a].superior) return a;
    }
    return -1;
}

int ultimaPosicaoNoVetor(int tam, Intervalo i[tam], int num){
    for(int a = tam - 1; a >= 0 ; a--){
        if(num >= i[a].inferior && num <= i[a].superior) return a;
    }
    return -1;
}


int main(){
    Intervalo intervalos[3] = {{2, 3},{3, 5},{4, 6}};

    printf("%d\n", estaNoVetor(3, intervalos, 1));
    printf("%d\n", qntsVezesNoVetor(3, intervalos, 4));
    printf("%d\n", posicaoNoVetor(3, intervalos, 5));
    printf("%d\n", ultimaPosicaoNoVetor(3, intervalos, 2));
}