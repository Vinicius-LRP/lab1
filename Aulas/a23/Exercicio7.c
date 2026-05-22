#include <stdio.h>

int existeArquivo(char nome[]){
    FILE *arq = fopen(nome, "r");
    if(arq) {
        fclose(arq);
        return 1;
    }
    return 0;
}



int main(){

    if(existeArquivo("dados.txt"))
        printf("Arquivo existe!");
    else
        printf("Arquivo não existe!");

}