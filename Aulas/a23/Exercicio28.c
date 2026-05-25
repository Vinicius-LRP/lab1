#include <stdio.h>
#include <string.h>

void converteParaMaiuscula(char f[]){
    for(int a = 0; f[a] != '\0'; a++){
        if(f[a] >= 'a' && f[a] <= 'z') f[a] -= 32;
    }
}

void gravaNoArquivo(FILE *a){
    char frase[100];
    while(1){
        fgets(frase, 100, stdin);
        if(strcmp(frase, "fim\n") == 0) break; 
        converteParaMaiuscula(frase);
        fputs(frase, a);
    }
}

int main(){
    FILE *arq = fopen("arquivo.txt", "w");
    if(arq == NULL){
        printf("Erro ao abrir!");
        return 1;
    }
    
    gravaNoArquivo(arq);

    fclose(arq);
    return 0;
}