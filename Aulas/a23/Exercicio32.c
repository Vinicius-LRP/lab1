#include <stdio.h>



int main(){
    FILE *arq; 
    arq = fopen("numero.bin", "wb");
    if(arq == NULL){
        printf("Erro ao abrir!");
        return 1;
    }

    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);

    if(fwrite(&numero, sizeof(int), 1, arq) != 1){
        printf("Erro ao gravar! \n");
        fclose(arq);
    }
    fclose(arq);

    arq = fopen("numero.bin", "rb");
    if(arq == NULL){
        printf("Erro ao abrir!");
        return 1;
    }
    
    int numerobin;
    
    if(fread(&numerobin, sizeof(int), 1, arq) != 1){
        printf("Erro ao ler!");
        fclose(arq);
    }

    printf("%d", numerobin);

    fclose(arq);
    return 0;
}