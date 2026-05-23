#include <stdio.h>

int contarCaracter(FILE *a, char c){
    int quantidade = 0;
    int ca;
    while((ca = fgetc(a)) != EOF){
        if(ca == c) quantidade++;
    }
    return quantidade;
}

int main(){

    FILE *arq = fopen("arquivo.txt", "r");

    if(arq == NULL){
        printf("Erro ao abrir arquivo!");
        return 1;
    }

    printf("%d\n", contarCaracter(arq, '\n'));

    fclose(arq);
}