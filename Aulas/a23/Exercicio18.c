#include <stdio.h>

int contarInteiros(char nome[]){
    FILE *arq = fopen(nome, "r");
    if(arq == NULL){
        return -1;
    }
    int quantidade = 0;
    int numero;
    while(fscanf(arq, "%d", &numero) == 1){
        quantidade++;
    }

    fclose(arq);
    return quantidade;

}


int main(){
    char arquivo[50] = "arquivo.txt";
    int resultado = contarInteiros(arquivo);

    if(resultado == -1){
        printf("Erro ao abrir arquivo!\n");
    } else {
        printf("Quantidade: %d\n", resultado);
    }
    return 0;
}