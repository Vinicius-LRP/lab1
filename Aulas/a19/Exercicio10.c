#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    float primeiraNota;
    float segundaNota;
}Nota;

typedef struct{
    char curso[50];
    int semestre;
}Turma;

typedef struct{
    char nome[50];
    int idade;
    Nota notas;
    Turma turma;
}Aluno;

Nota inserirNota(float n1, float n2){
    Nota n;
    n.primeiraNota = n1;
    n.segundaNota = n2;
    return n;
}

Turma inserirTurma(char c[], int s){
    Turma t;
    strcpy(t.curso, c);
    t.semestre = s;
    return t;
}

Aluno inserirAluno(char n[], int i, char c[], int s, float n1, float n2){
    Aluno a;
    strcpy(a.nome, n);
    a.idade = i;
    a.notas = inserirNota(n1,n2);
    a.turma = inserirTurma(c,s);
    return a;
}

float calculaMedia(Aluno a){
    return (a.notas.primeiraNota + a.notas.segundaNota) / 2;
}

bool resultadoAprovadoOuReprovado(float m){
    if(m > 7) return true;
    return false;
}
void alunoDetalhes(Aluno a){
    printf("\n");
    printf("Detalhes do aluno\n");
    printf("Nome: %s\n", a.nome);
    printf("Idade: %d\n", a.idade);
    printf("Curso: %s\n", a.turma.curso);
    printf("Semestre: %d\n", a.turma.semestre);
    printf("Primeira nota: %.2f\n", a.notas.primeiraNota);
    printf("Segunda nota: %.2f\n", a.notas.segundaNota);
    if(resultadoAprovadoOuReprovado(calculaMedia(a))) 
        printf("Aluno aprovado!\n");
    else
        printf("Aluno reprovado\n");
    printf("\n");
}

void menu(Aluno p[]){
    for(int a = 0 ; ; a++){
        char nome[50];
        int idade;
        char curso[50];
        int semestre;
        float nota1;
        float nota2;
        char continuar;
        printf("Inserir aluno %d\n", a + 1);
        printf("Nome: ");
        scanf("%s", nome);
        printf("Idade: ");
        scanf("%d", &idade);
        printf("Curso: ");
        scanf("%s", curso);
        printf("Semestre: ");
        scanf("%d", &semestre);
        printf("Primeira nota: ");
        scanf("%f", &nota1);
        printf("Segunda nota: ");
        scanf("%f", &nota2); 
        p[a] = inserirAluno(nome, idade, curso, semestre, nota1, nota2);
        alunoDetalhes(p[a]);

        printf("Quer continuar? [s/n]");
        scanf(" %c", &continuar);
        if(continuar == 'n') break;
    }
}

int main(){
    Aluno alunos[50];

    menu(alunos);


    return 0;
}