#include <stdio.h>

typedef struct{
    char nome[50];
    char c;
}Aluno;

float percentualAprovados(int a, int t){
    return (a * 100.0) / t;
}

void detalhesTurma(int t, Aluno al[]){
    int aprovados = 0;
    printf("Resultados\n");
    for(int a = 0; a < t; a++){
        printf("%c %s \n", al[a].c, al[a].nome);
        if(al[a].c == 'A') aprovados++;
    }
    printf("Percentual aprovados: %.2f\n", percentualAprovados(aprovados, t));
}

int main(){
    Aluno a1 = {"Lucas", 'A'};
    Aluno a2 = {"Arthur", 'R'};
    Aluno a3 = {"Carlos", 'R'};
    Aluno a4 = {"Lavinia", 'A'};
    Aluno a5 = {"Vinicius", 'R'};
    Aluno alunos[5] = {a1,a2,a3,a4,a5};

    detalhesTurma(5, alunos);

}