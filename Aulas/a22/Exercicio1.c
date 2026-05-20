#include <stdio.h>
#include <stdbool.h>

bool estaNoVetor(int tam, int v[tam], int num){
    for(int a = 0; a < tam ; a++){
        if(v[a] == num) return true;
    }
    return false;
}

int main(){
    int vet[3] = {2, 3, 5};

    printf("%d", estaNoVetor(3, vet, 2));

}