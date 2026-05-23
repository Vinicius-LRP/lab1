#include <stdio.h>

FILE* abrirArquivo(){
    FILE *dados = fopen("dados.txt", "r");
    return dados;
}

int main(){
    FILE *arq = abrirArquivo();

    if(!arq){
        printf("Arquivo não foi aberto!");
        return 1;
    }
    
    printf("Arquivo foi aberto!");
    fclose(arq);

    return 0;

}