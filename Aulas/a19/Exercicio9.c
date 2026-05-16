#include <stdio.h>
#include <string.h>

typedef struct{
    char rua[50];
    int numero;
    char cidade[50];
}Endereco;

typedef struct{
    char nome[50];
    int idade;
    Endereco endereco;
}Pessoa;

Endereco inserirEndereco(char r[], int n, char c[]){
    Endereco e;
    strcpy(e.rua, r);
    e.numero = n;
    strcpy(e.cidade,c);
    return e;
}

Pessoa inserirPessoa(char n[], int i, char r[], int num, char c[]){
    Pessoa p;
    strcpy(p.nome,n);
    p.idade = i;
    p.endereco = inserirEndereco(r,num,c);
    return p;
}

void informacoesPessoais(Pessoa p){
    printf("Nome: %s\n",p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Endereço:\n");
    printf("Rua %s, N° %d, %s\n",p.endereco.rua, p.endereco.numero, p.endereco.cidade);
}

int inserirVariasPessoas(Pessoa p[]){
    int n = 0;
    printf("Quantas pessoas você quer inserir? ");
    scanf("%d", &n);
    for(int a = 0; a < n; a++){
        char nome[50];
        int idade;
        char rua[50];
        int numero;
        char cidade[50];
        printf("Inserir pessoa número %d\n", a + 1);
        printf("Nome: ");
        scanf("%s", nome);
        printf("Idade: ");
        scanf("%d", &idade);
        printf("Rua: ");
        scanf("%s", rua);
        printf("Número: ");
        scanf("%d", &numero);
        printf("Cidade: ");
        scanf("%s", cidade);
        p[a] = inserirPessoa(nome, idade, rua, numero, cidade);
    }
    return n;
}

void informacoesGrupoDePessoas(int n, Pessoa p[]){
    for(int a = 0; a < n; a++){
        informacoesPessoais(p[a]);
    }
}

int main(){
    Pessoa pessoas[50];

    int numeroDePessoasAdicionadas= inserirVariasPessoas(pessoas);
    
    informacoesGrupoDePessoas(numeroDePessoasAdicionadas, pessoas);
    
}