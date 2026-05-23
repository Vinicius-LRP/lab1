#include <stdio.h>

int main(){

    FILE *arq = fopen("arquivo.txt", "r");

    if(arq){
        fclose(arq);
        return 1;
    }

    return 0;

}