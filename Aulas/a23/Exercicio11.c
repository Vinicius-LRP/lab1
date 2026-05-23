#include <stdio.h>

int contarLetras(FILE *arq){
    int quantidade = 0;
    int c;

    while((c = fgetc(arq)) != EOF){
        if(c == 'A' || c == 'a') 
            quantidade++;
    }
    return quantidade;
}

int main(){
    FILE *arquivo = fopen("arquivo.txt", "r");
    if(arquivo == NULL){
        printf("Não foi possivel abrir o arquivo!");
        return 1;
    }
    printf("%d\n", contarLetras(arquivo));

    fclose(arquivo);
}