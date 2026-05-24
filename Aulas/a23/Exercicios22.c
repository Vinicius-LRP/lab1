#include <stdio.h>

int maiorValor(FILE *a){
    int c;
    int num = 0;
    int maior = 0;
    while(!feof(a)){
        c = fgetc(a);
        if(c != EOF && c != '\n' && c != ' '){
            num = num * 10 + (c - '0');
        } else{
            if(num > maior) maior = num;
            num = 0;
        }
    }
    return maior;
}

int main(){
    FILE *arq = fopen("arquivo.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir arquivo!");
        return 1;
    }

    printf("Maior valor: %d\n", maiorValor(arq));

    fclose(arq);
    return 0;
}