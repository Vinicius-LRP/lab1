#include <stdio.h>



int main(){
    FILE *arq; 
    arq = fopen("numero.txt", "wb");
    if(arq == NULL){
        printf("Erro ao abrir!");
        return 1;
    }

    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);

    fwrite(&numero, sizeof(int), 1, arq);
    fclose(arq);

    arq = fopen("numero.txt", "rb");
    if(arq == NULL){
        printf("Erro ao abrir!");
        return 1;
    }
    int numerobin;

    fread(&numerobin, sizeof(int), 1, arq);

    printf("%d", numerobin);

    fclose(arq);
    return 0;
}