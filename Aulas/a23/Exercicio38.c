#include <stdio.h>

void imprimeVet(int v[], int n){
    for(int a = 0; a < n; a++){
        printf("%d ", v[a]);
    }
    printf("\n");
}


int main(){
    int vet[5] = {1 ,2 , 3, 4, 5};
    imprimeVet(vet, 5);

    return 0;
}