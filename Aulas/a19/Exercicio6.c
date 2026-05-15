#include <stdio.h>
#include <string.h>

typedef struct{
    char titulo[50];
    char autor[50];
    int ano;
}Livro;

void le_titulo(int indice,Livro l[]){
    int a;
    for(a = 0; ; a++){
        scanf("%c", &l[indice].titulo[a]);
        if(l[indice].titulo[a] == '\n') break;
    }
    l[indice].titulo[a] = '\0';
}

void le_autor(int indice, Livro l[]){
    int a;
    for(a = 0; ; a++){
        scanf("%c", &l[indice].autor[a]);
        if(l[indice].autor[a] == '\n') break;
    }
    l[indice].autor[a] = '\0';
}

void adicionar_livros(int num_livros, Livro l[num_livros]){
    for(int a = 0 ; a < num_livros ; a++){
        printf("Digite o título do livro: ");
        le_titulo(a, l);
        printf("Digite o nome do autor: ");
        le_autor(a, l);
        printf("Digite o ano de publicação: ");
        scanf("%d", &l[a].ano);
        getchar();
    }
}

Livro livro_mais_antigo(int num_livros,Livro l[num_livros]){
    int mais_antigo = l[0].ano;
    int indice = 0;
    for(int a = 0; a < num_livros; a++){
        if(l[a].ano < mais_antigo) {
            indice = a;
            mais_antigo = l[a].ano;
        }
    }
    return l[indice];
}

void imprime_livro(Livro l){
    printf("Título: %s\n", l.titulo);
    printf("Autor: %s\n", l.autor);
    printf("Ano: %d\n", l.ano);
}

int main(){
    Livro livros[5];

    adicionar_livros(3, livros);

    Livro livro_antigo = livro_mais_antigo(3, livros);

    printf("Livro mais antigo");
    imprime_livro(livro_antigo);


}