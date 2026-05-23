#include <stdio.h>

void trocaPosicao(char p[], int a, int b){
    char troca = p[a];
    p[a] = p[b];
    p[b] = troca;
}

int tamanhoString(char *s){
    int a = 0;
    while(s[a] != '\0'){
        a++;
    }
    return a;
}

void invertePalavra(FILE *a1, FILE *a2){
    char palavra[50];
    int b = 0;
    int c;
    while((c = fgetc(a1)) != EOF && b < 49){
        palavra[b] = c;
        b++;
    }
    
    palavra[b] = '\0';

    int tam = tamanhoString(palavra);

    for(int a = 0; a < tam / 2 ; a++){
        trocaPosicao(palavra, a, tam - 1 - a);
    }

    for(int a = 0 ; palavra[a] != '\0'; a++){
        fputc(palavra[a],a2);
    }
}

int main(){
    FILE *arquivo = fopen("arquivo.txt", "r");
    FILE *novo = fopen("novo.txt", "w");

    if(arquivo == NULL || novo == NULL){
        printf("Erro ao abrir o(s) arquivo(s)!");

        if(arquivo != NULL) fclose(arquivo);
        if(novo != NULL) fclose(novo);
        return 1;
    }
    invertePalavra(arquivo, novo);

    fclose(arquivo);
    fclose(novo);
    return 0;
}