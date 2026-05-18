#include <stdio.h>

typedef struct{
    char nome[50];
    float nota;
}Aluno;

void imprimeAluno(Aluno *a){
    printf("Nome: %s\n", a->nome);
    printf("Nota: %.2f\n", a->nota);

}

Aluno* piorAluno(Aluno *lista, int n){
    float menorNota = lista[0].nota;
    int indicePiorAluno = 0;
    for(int a = 0; a < n ; a++){
        if(lista[a].nota < menorNota) 
        menorNota = lista[a].nota;
        indicePiorAluno = a;
    }
    return &lista[indicePiorAluno];
}

int main(){
    Aluno alunos[3] = {{"Vinicius", 10},{"Eduardo", 9.1},{"Carlos", 8}}; 

    imprimeAluno(piorAluno(alunos, 3));

}