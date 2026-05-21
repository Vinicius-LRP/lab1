#include <stdio.h>





int main(){

    FILE *arq = fopen("arquivo.txt", "r");

    if(arq == NULL){
        printf("Não foi possivel abrir!\n");
        return 1;
    }

    fclose(arq);
    return 0;
}