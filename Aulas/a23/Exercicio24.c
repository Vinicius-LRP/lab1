#include <stdio.h>



int main(){

    bool maior = false;

    FILE *arq = fopen("arquivo.txt", "r");
    
    if(arq == NULL){
        printf("Não foi possivel abrir!");
        return 1;
    }
    char linha[21];

    while(fgets(linha, 21, arq) != NULL){
        for(int a = 0 ; a < 20; a++){
            if(linha[a] == '\0') maior = false;
        }
    }


    fclose(arq);
    return 0;
}