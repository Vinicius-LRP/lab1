#include <stdio.h>

int contaCaracter(char nome[]){
    FILE *arq = fopen(nome, "r");
    if(arq == NULL){
        return -1;
    }
    int quantidade = 0;
    int c;
    while(!feof(arq)){
        c = fgetc(arq);
        if(c != EOF) 
            quantidade++;
    }
    fclose(arq);
    return quantidade;
}

int main(){
    char arq[] = "arquivo.txt";
    
    printf("%d\n", contaCaracter(arq));
    return 0;
}