#include <stdio.h>


int main(){

    FILE *arq;
    arq = fopen("arquivo.txt", "r");
    
    if(arq == NULL){
        printf("Erro ao abrir arquivo!");
        return 1;
    }

    int c = fgetc(arq);
    while(c != EOF){
        printf("%c", c);
        c =fgetc(arq);
    }
    printf("\n");
    
    fclose(arq);
    return 0;
}