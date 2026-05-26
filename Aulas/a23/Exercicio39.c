#include <stdio.h>

void gravaVetor(char nome[], int v[], int n){
    FILE *arq = fopen(nome, "w");

    if(arq == NULL){
        printf("Erro!");
        return;
    }
    fprintf(arq, "%d ", n);

    for(int i = 0; i < n; i++){
        fprintf(arq, "%d ", v[i]);
    }

    fclose(arq);
}

int main(){
    int vet[5] = {1 ,2 , 3, 4, 5};
    char nome[] = "arquivo.txt";
    gravaVetor(nome,vet, 5);

    return 0;
}