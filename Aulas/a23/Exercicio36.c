#include <stdio.h>
#include <stdbool.h>

bool copiaInteiros(char n[], int v[], int t){
    FILE *arq = fopen(n, "w");
    if(arq == NULL){
        printf("Erro ao abrir!");
        return false;
    }
    int a;
    int result;
    for(a = 0; a < t; a++){
        result = fprintf(arq, "%d\n", v[a]);
        if(result < 0) return false;
    }

    fclose(arq);
    return true;
}

int main(){
    char nome[] = "arquivo.txt";
    int vet[5] = {2, 3, 1, 4, 5};

    printf("Copia feita? %d\n", copiaInteiros(nome, vet, 5));

    return 0;
}