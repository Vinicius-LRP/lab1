#include <stdio.h>

void copiaArquivo(FILE *arq1, FILE *arq2){
    int c;
    while((c = fgetc(arq1)) != EOF){
        if(c >= 'a' && c <= 'z'){
            fputc(c - 32 ,arq2);
        }else{
            fputc(c, arq2);
        }
    }
}


int main(){
    FILE *texto = fopen("texto.txt", "r");
    FILE *novo = fopen("nova.txt", "w");

    if(texto == NULL || novo == NULL){
        printf("Erro ao abrir arquivo(s)!");
        if(texto != NULL) fclose(texto);
        if(novo != NULL) fclose(novo);
        return 1;
    }
    
    copiaArquivo(texto, novo);

    fclose(texto);
    fclose(novo);
    return 0;
}