#include <stdio.h>

int contarCaracter(FILE *a, char caracter){
    int c;
    int quantidade = 0;
    while(!feof(a)){
        c = fgetc(a);
        if(c != EOF && c == caracter)
            quantidade++;
    }
    return quantidade;
}

int main(){
    FILE *arq = fopen("arquivo.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir arquivo!");
        return 1;
    }

    printf("Caracter: %d\n", contarCaracter(arq, 'a'));

    fclose(arq);
    return 0;
}