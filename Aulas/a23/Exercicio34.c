#include <stdio.h>

int contarInteiros(char nome[]){
    FILE *arq = fopen(nome, "r");
    if(arq == NULL){
        return -2;
    }
    int quantidade = 0;
    int numero;
    int r;
    
    while((r = fscanf(arq, "%d", &numero)) != EOF){
        if(r == 0 && !feof(arq)){
            fclose(arq);
            return -1;
        }
        quantidade++;
    }
    fclose(arq);
    return quantidade;
}

int main(){
    char arquivo[50] = "arquivo.txt";
    int resultado = contarInteiros(arquivo);

    if(resultado == -2){
        printf("Erro ao abrir arquivo!\n");
    } else if(resultado == -1){
        printf("Não há somente números!");
    } else {
        printf("Quantidade: %d\n", resultado);
    }
    return 0;
}