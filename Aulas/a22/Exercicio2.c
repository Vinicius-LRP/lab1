#include <stdio.h>

int qntsVezesNoVetor(int tam, int v[tam], int num){
    int vezes = 0;
    for(int a = 0; a < tam ; a++){
        if(v[a] == num) vezes++;
    }
    return vezes;
}


int main(){
    int vet[5] = {1 , 2, 3, 2, 2};

    printf("%d", qntsVezesNoVetor(5, vet, 2));

}