#include <stdio.h>

int somaInteiros(FILE *a){
    int c;
    int num = 0;
    int soma = 0;
    while(!feof(a)){
        c = fgetc(a);
        if(c != EOF && c != '\n' && c != ' '){
            num = num * 10 + (c - '0');
        } else{
            soma += num;
            num = 0;
        }
    }
    return soma;
}

int main(){
    FILE *arq = fopen("arquivo.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir arquivo!");
        return 1;
    }
    printf("%d\n", somaInteiros(arq));

    fclose(arq);
    return 0;
}