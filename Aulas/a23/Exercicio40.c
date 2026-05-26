#include <stdio.h>

int intersecaoVetores(int v1[], int n1, int v2[], int n2, int v3[]){
    int i = 0;
    for(int a = 0; a < n1; a++){
        for(int b = 0; b < n2; b++){
            if(v1[a] == v2[b]){
                int existe = 0;
                for(int c = 0; c < i; c++){
                    if(v3[c] == v1[a]){
                        existe = 1;
                        break;
                    }
                }
                if(!existe){
                    v3[i] = v1[a];
                    i++;
                }
                break;
            }
        }
    }
    return i;
}

void imprimeVetor(int v[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int v1[] = {1, 2, 3, 4, 5};
    int v2[] = {3, 4, 5, 6, 7};
    int v3[10];

    int n1 = 5;
    int n2 = 5;

    int n3 = intersecaoVetores(v1, n1, v2, n2, v3);

    printf("Elementos em comum: %d\n", n3);
    imprimeVetor(v3, n3);

    return 0;
}