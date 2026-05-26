#include <stdio.h>

int copiaInteiros(char n[], int v[]){
    FILE *arq = fopen(n, "r");
    if(arq == NULL){
        printf("Erro!");
        return -1;
    }
    int tamanhoVetor;
    int num;

    if(fscanf(arq, "%d", &tamanhoVetor) != 1 || tamanhoVetor > 100 || tamanhoVetor < 1 ){
        fclose(arq);
        return -1;
    } 

    int a;

    for(a = 0; a < tamanhoVetor && fscanf(arq, "%d", &num) == 1 ; a++)
        v[a] = num;
    
    if(a != tamanhoVetor) {
        fclose(arq);
        return -1;
    }

    fclose(arq);
    return tamanhoVetor;
}

int main(){
    char nome[50] = "arquivo.txt";
    int vet[100];

    printf("%d\n", copiaInteiros(nome, vet));

    return 0;
}