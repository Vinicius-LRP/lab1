#include <stdio.h>

int ultimaPosicaoNoVetor(int tam, int v[tam], int num){
    for(int a = tam - 1; a >= 0 ; a--){
        if(v[a] == num) return a;
    }
    return -1;
}




int main(){
    int vet[5] = {1 , 2, 3, 2, 4};

    printf("%d\n", ultimaPosicaoNoVetor(5, vet, 2));

}