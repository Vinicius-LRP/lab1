#include <stdio.h>

int main(){
    FILE *arq = fopen("arquivo.txt", "r");
    
    if(arq == NULL){
        printf("Erro ao abrir arquivo!");
        return 1;
    }
    char string[100];

    while(fgets(string, 100, arq) != NULL){
        printf("%s", string);
    }

    fclose(arq);
    return 0;
}