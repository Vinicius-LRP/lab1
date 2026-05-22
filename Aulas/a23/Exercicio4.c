#include <stdio.h>

int main(){
    FILE *a;
    FILE *b;
    FILE *c;

    a = fopen("a.txt", "r");
    b = fopen("b.txt", "r");
    c = fopen("c.txt", "r");

    int arqAbertos = 0;

    if(a != NULL) arqAbertos++;
    if(b != NULL) arqAbertos++;
    if(c != NULL) arqAbertos++;

    if(arqAbertos)
        printf("%d arquivo(s) aberto(s)!\n", arqAbertos);
    else
        printf("Nenhum arquivo aberto!");

    if(a != NULL) fclose(a);
    if(b != NULL) fclose(b);
    if(c != NULL) fclose(c);

    return 0;

}