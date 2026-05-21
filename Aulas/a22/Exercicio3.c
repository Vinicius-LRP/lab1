#include <stdio.h>

int posicaoNoVetor(int tam, int v[tam], int num){
    for(int a = 0 ; a < tam ; a++){
        if(v[a] == num) return a;
    }
    return -1;
}

int main(){
    int vet[5] = {1 , 2, 3, 2, 4};

    printf("%d\n",posicaoNoVetor(5, vet, 2));

}