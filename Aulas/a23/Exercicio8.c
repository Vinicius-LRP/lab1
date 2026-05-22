#include <stdio.h>

void escreverNoArquivo(char s[], FILE *arq){
    for(int a = 0; s[a] != '\0'; a++){
        fputc(s[a], arq);
    }
}

int main(){

    FILE *arq;
    arq = fopen("arquivo.txt", "w");

    if(arq == NULL){
        printf("Erro ao abrir arquivo!");
        return 1;
    }

    char string[30] = "Computador";
    
    escreverNoArquivo(string, arq);


    fclose(arq);
    return 0;
}