#include <stdio.h>

int copiaInteiros(char n[], int v[]) {
    FILE *arq = fopen(n, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", n);
        return -1;
    }

    int tamanhoVetor, num;

    if (fscanf(arq, "%d", &tamanhoVetor) != 1 || tamanhoVetor > 100 || tamanhoVetor < 1) {
        fclose(arq);
        return -1;
    }

    int a;
    for (a = 0; a < tamanhoVetor && fscanf(arq, "%d", &num) == 1; a++)
        v[a] = num;

    if (a != tamanhoVetor) {
        fclose(arq);
        return -1;
    }

    fclose(arq);
    return tamanhoVetor;
}

void imprimeVet(int v[], int n) {
    for (int a = 0; a < n; a++)
        printf("%d ", v[a]);
    printf("\n");
}

void gravaVetor(char nome[], int v[], int n) {
    FILE *arq = fopen(nome, "w");
    if (arq == NULL) {
        printf("Erro ao gravar o arquivo: %s\n", nome);
        return;
    }

    fprintf(arq, "%d ", n);
    for (int i = 0; i < n; i++)
        fprintf(arq, "%d ", v[i]);

    fclose(arq);
}

int intersecaoVetores(int v1[], int n1, int v2[], int n2, int v3[]) {
    int i = 0;
    for (int a = 0; a < n1; a++) {
        for (int b = 0; b < n2; b++) {
            if (v1[a] == v2[b]) {
                int existe = 0;
                for (int c = 0; c < i; c++) {
                    if (v3[c] == v1[a]) {
                        existe = 1;
                        break;
                    }
                }
                if (!existe) {
                    v3[i] = v1[a];
                    i++;
                }
                break;
            }
        }
    }
    return i;
}

int main() {
    int v1[100];
    int v2[100];
    int v3[100];
    int n1; 
    int n2;
    int n3;

    n1 = copiaInteiros("vetor1.txt", v1);
    if (n1 == -1) {
        printf("Erro ao ler v1\n");
        return 1;
    }
    n2 = copiaInteiros("vetor2.txt", v2);
    if (n2 == -1) {
        printf("Erro ao ler v2\n");
        return 1;
    }

    n3 = intersecaoVetores(v1, n1, v2, n2, v3);

    printf("Vetor 1: ");
    imprimeVet(v1, n1);

    printf("Vetor 2: ");
    imprimeVet(v2, n2);

    printf("Vetor 3 ,valores comuns: ");
    if (n3 == 0)
        printf("nenhum valor em comum\n");
    else
        imprimeVet(v3, n3);

    gravaVetor("vetor3.txt", v3, n3);
    printf("\nVetor 3 gravado em vetor3.txt\n");

    return 0;
}