#include <stdio.h>

int main(){
    FILE *arq = fopen("arquivo.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir arquivo!");
        return 1;
    }
    char string[5];

    while(fgets(string, 5, arq) != NULL){
        printf("%s", string);
    }
    printf("\n");

    fclose(arq);
    return 0;
}