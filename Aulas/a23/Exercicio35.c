#include <stdio.h>

int copiaInteiros(char n[], int v[], int t){
    FILE *arq = fopen(n, "r");
    if(arq == NULL){
        printf("Erro ao abrir!");
        return -1;
    }
    int num;
    int a;
    for(a = 0; a < t && fscanf(arq, "%d" , &num) != EOF  ; a++){
        v[a] = num;
    }

    fclose(arq);
    return a;
}

int main(){
    char nome[] = "arquivo.txt";
    int vet[5];

    printf("Numeros colocados: %d\n", copiaInteiros(nome, vet, 5));
    return 0;
}