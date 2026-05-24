#include <stdio.h>

int main(){

    int maior = 0;

    FILE *arq = fopen("arquivo.txt", "r");
    
    if(arq == NULL){
        printf("Não foi possivel abrir!");
        return 1;
    }
    char linha[100];

    while(fgets(linha, 100, arq) != NULL){
        for(int a = 0 ; linha[a] != '\0' && linha [a] != '\n'; a++){
            if(a == 20) {
                maior++;
                break;
            }
        }
    }
    printf("Linhas maiores que 20 caracteres: %d\n", maior);

    fclose(arq);
    return 0;
}