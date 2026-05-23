#include <stdio.h>

int main() {
    FILE *d1 = fopen("dados1.txt", "w");
    FILE *d2 = fopen("dados2.txt", "w");
    FILE *d3 = fopen("dados3.txt", "w");

    if (d1 == NULL || d2 == NULL || d3 == NULL) {
        printf("Nem todos os arquivos foram abertos!");

        if (d1 != NULL) fclose(d1);
        if (d2 != NULL) fclose(d2);
        if (d3 != NULL) fclose(d3);

        return 1;
    }

    printf("Todos os arquivos foram abertos!");

    fclose(d1);
    fclose(d2);
    fclose(d3);

    return 0;
}