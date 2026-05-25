#include <stdio.h>
#include <stdbool.h>

bool copiaInteiros(char n[], int v[], int t){
    FILE *arq = fopen(n, "w");
    if(arq == NULL){
        printf("Erro ao abrir!");
        return false;
    }
    int a;
    for(a = 0; a < t; a++){
        fprintf(arq, "%d", v[a]);
        fputs("\n", arq);
    }

    fclose(arq);
    if(a == t) return true;
    return false;
}

int main(){
    char nome[] = "arquivo.txt";
    int vet[5] = {2, 3, 1, 4, 5};

    printf("Copia feita? %d\n", copiaInteiros(nome, vet, 5));


    return 0;
}