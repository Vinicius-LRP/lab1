#include <stdio.h>
#include <stdbool.h>

int encontrarPalavra(FILE *ar, char p[]){
    char linha[100];
    int igual = 0;
    while(fgets(linha, 100, ar) != NULL){
        for(int a = 0; linha[a] != '\0' && linha[a] != '\n'; a++){
            if(linha[a] == p[0]){
                bool diferente = false;
                for(int b = 0; p[b] != '\0'; b++){
                    if(linha[a + b] == '\0' || linha[a + b] != p[b]){
                        diferente = true;
                        break;
                    }
                }
                if(!diferente){
                    igual++;
                }
            }
        }
    }
    return igual;
}

int main(){
    FILE *arq = fopen("arquivo.txt", "r");
    
    if(arq == NULL){
        printf("Erro ao abrir!");
        return 1;
    }

    char palavra[] = "computador";
    printf("%d", encontrarPalavra(arq, palavra));
    

    fclose(arq);
    return 0;
}