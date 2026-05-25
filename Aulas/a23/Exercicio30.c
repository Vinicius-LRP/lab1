#include <stdio.h>

typedef struct{
    char nome[50];
    char idade[50];
    char curso[50];
}Aluno;

void cadastrarAluno(FILE *a){
    Aluno al;
    printf("Digite o nome: ");
    fgets(al.nome, 50, stdin);
    fputs("Nome: ", a);
    fputs(al.nome, a);
    printf("Digite a idade: ");
    fgets(al.idade, 50, stdin);
    fputs("Idade: ", a);
    fputs(al.idade, a);
    printf("Digite o curso: ");
    fgets(al.curso, 50, stdin);
    fputs("Curso: ", a);
    fputs(al.curso,a);
}

int main(){
    FILE *arq = fopen("arquivo.txt", "w");
    if(arq == NULL){
        printf("Erro ao abrir!");
        return 1;
    }

    cadastrarAluno(arq);


    fclose(arq);
    return 0;
}