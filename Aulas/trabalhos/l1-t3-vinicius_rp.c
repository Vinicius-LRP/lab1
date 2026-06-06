#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static int PRINCIPAL = 0;
static int EDITAR_TEXTO = 1;
static int EDITAR_ETIQUETA = 2;
static int EDITAR_COR = 3;
static int EDITAR_TEXTO_BUSCA = 4;
static int EDITAR_ETIQUETA_BUSCA = 5;
static int TERMINAR = 6;


typedef struct{
    int r;
    int g;
    int b;
}Cor;

typedef struct{
    int x;
    int y;
}Ponto;

typedef struct{
    int largura;
    int altura;
}Tamanho;

typedef struct{
    Ponto ponto;
    Tamanho tamanho;
}Retangulo;

typedef struct{
    char texto[101];
    Cor cor;
    Retangulo retangulo;
    char etiqueta[3];
}Nota;

typedef struct{
    int x;
    int y;
} Cursor;

typedef struct{
    Nota *notas;

    int quantidade;
    int capacidade;

    int modo;
    int notaCorrente;
    Cursor cursor;

    int *validos;

    Nota ultimaRemovida;
    int existeUltimaRemovida;

    char textoBusca[101];
    char etiquetaBusca[3];
} Sistema;

Nota notaDefault(){
    Nota n;
    n.etiqueta[0] = 'A';
    n.etiqueta[1] = 'A';
    n.etiqueta[2] = 'A';

    n.cor.r = 0;
    n.cor.g = 0;
    n.cor.b = 0;

    n.retangulo.ponto.x = 0;
    n.retangulo.ponto.y = 0;
    n.retangulo.tamanho.largura = 0;
    n.retangulo.tamanho.altura = 0;

    strcpy(n.texto, "Default");

    return n;
}

int aumentaCapacidade(Sistema *s){
    Nota *novaCapacidade = realloc(s->notas, s->capacidade * 2 * sizeof(Nota));

    if(novaCapacidade == NULL) return 0;

    s->notas = novaCapacidade;
    s->capacidade *= 2;

    return 1;
}

int diminuiCapacidade(Sistema *s){
    if(s->capacidade <= 1) return 1; 

    Nota *novaCapacidade = realloc(s->notas,(s->capacidade / 2) * sizeof(Nota));
    if(novaCapacidade == NULL) return 0;

    s->notas = novaCapacidade;
    s->capacidade /= 2;

    return 1;
}

void inserirNotaComProblema(char l[], FILE *p){
    fprintf(p, "%s", l);
    fflush(p); // rever
}

int valido(char c){
    return (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int verificaQuebraDeLinha(int c, FILE *a){
    if(c == '\n'){
        ungetc(c, a);
        return 1;
    }
    return 0;
}

int leEtiqueta(FILE *a, char e[]){
    int c;
    int e0 = -1;
    int e1;
    int e2;
    while((c = fgetc(a)) != '\n' && c != EOF){
        if(c != ' '){
            if(e0 == -1){
                if(!valido(c)){
                    printf("Etiqueta invalida!\n");
                    return 1;
                }
                e0 = c;
                c = fgetc(a);
                if(verificaQuebraDeLinha(c, a) || !valido(c) || c == EOF){
                    printf("Etiqueta invalida!\n");
                    return 1;
                }
                e1 = c;
                c = fgetc(a);
                if(verificaQuebraDeLinha(c, a) || !valido(c) || c == EOF){
                    printf("Etiqueta invalida!\n");
                    return 1;
                }
                e2 = c;
                break;
            }
        }
    }
    if(verificaQuebraDeLinha(c, a)){
        printf("Etiqueta invalida!\n");
        return 1;
    }
    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
    return 0;
}

int leCor(FILE *a, Cor *c){
    int ch;
    int r = -1;
    int g = -1;
    int b = -1;
    while((ch = fgetc(a)) != '\n' && ch != EOF){
        if((ch != ' ') && (ch < '0' || ch > '9')){
            printf("Erro na formatação da cor!\n");
            return 1;
        }
        if(ch >= '0' && ch <= '9'){
            ungetc(ch, a);
            if(r == -1){
                if(fscanf(a, "%d", &r) != 1)
                    return 1;
            }else if(g == -1){
                if(fscanf(a, "%d", &g) != 1)
                    return 1;
            }else if(b == -1){
                if(fscanf(a, "%d", &b) != 1)
                    return 1;
                break;
            }
        }
    }
    if(verificaQuebraDeLinha(ch, a))
        return 1;
    if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255){
        printf("Cor invalida!\n");
        return 1;
    }
    c->r = r;
    c->g = g;
    c->b = b;
    return 0;
}

int leRetangulo(FILE *a, Retangulo *r){
    int c;
    int x = -999;
    int y = -999;
    int largura = -1;
    int altura = -1;
    while((c = fgetc(a)) != '\n' && c != EOF){
        if((c != ' ') && (c < '0' || c > '9')){
            printf("Erro na formatação do retangulo!\n");
            return 1;
        }
        if(c >= '0' && c <= '9'){ 
            ungetc(c, a);
            if(x == -999){
                if(fscanf(a, "%d", &x) != 1)
                    return 1;
            }else if(y == -999){
                if(fscanf(a, "%d", &y) != 1)
                    return 1;
            }else if(largura == -1){
                if(fscanf(a, "%d", &largura) != 1)
                    return 1;
            }else if(altura == -1){
                if(fscanf(a, "%d", &altura) != 1)
                    return 1;
                break;
            }
        }
    }
    if(verificaQuebraDeLinha(c, a))
        return 1;
    r->ponto.x = x;
    r->ponto.y = y;
    r->tamanho.largura = largura;
    r->tamanho.altura = altura;
    return 0;
}

int leTexto(FILE *a, char t[], char l[], FILE *p) {
    int c;
    while ((c = fgetc(a)) != '"') {
        if (c == EOF){
            printf("Erro na formatação do texto!\n");
            return 1;
        }
        if (c == '\n') {
            printf("Erro na formatação do texto!\n"); 
            ungetc(c, a); 
            return 1; 
        }
        if(c != ' '){
            printf("Erro na formatação do texto!\n");
            return 1;
        }
    }
    int i = 0;
    while (i < 101 && (c = fgetc(a)) != '"') {
        if (c == EOF) return 1;
        if (c == '\n') { 
            ungetc(c, a); 
            return 1; 
        } 
        t[i++] = c;
    }
    t[i] = '\0';
    if(i == 101){
        printf("Texto maior que o suportado!\n");
        inserirNotaComProblema(l,p); //refazer essa parte
    }
    return 0;
}

void consumirLinha(FILE *a){
    int c;
    while((c = fgetc(a)) != '\n' && c != EOF);
}

Nota leNota(FILE *arq, FILE *p){
    Nota n = {0};
    Nota np = {0};
    char linha[300];
    long pos = ftell(arq);

    if(fgets(linha, sizeof(linha), arq) == NULL){
        n.cor.r = -3;
        return n;
    }
    fseek(arq, pos, SEEK_SET);

    if(leEtiqueta(arq, n.etiqueta) || leCor(arq, &n.cor) || 
    leRetangulo(arq, &n.retangulo) || leTexto(arq, n.texto, linha, p)){
        inserirNotaComProblema(linha, p);
        consumirLinha(arq);  
        np.cor.r = -2; 
        return np;
    }
    consumirLinha(arq);
    return n;
}

int leNotas(FILE *arq, FILE *p, Sistema *s){
    Nota nt = {0};
    int a = 0;
    while(1){
        nt = leNota(arq, p);
        if(nt.cor.r == -3) break;
        if(nt.cor.r != -2){
            if(a == s->capacidade){
                if(!aumentaCapacidade(s)){
                    printf("Sem memoria\n");
                    return a;
                }
            }
        s->notas[a] = nt;
        a++;
        }
    }
    return a;
}

void inserirNota(Nota n, FILE *a){
    if(fprintf(a, "%c%c%c", n.etiqueta[0], n.etiqueta[1], n.etiqueta[2]) < 0)
        printf("Erro ao inserir etiqueta!\n");
    if(fprintf(a, " %d %d %d",n.cor.r, n.cor.g, n.cor.b) < 0)
        printf("Erro ao inserir cor!\n");
    if(fprintf(a, " %d %d %d %d", n.retangulo.ponto.x, n.retangulo.ponto.y, n.retangulo.tamanho.largura, n.retangulo.tamanho.altura) <0)
        printf("Erro ao inserir retangulo!");
    if(fprintf(a, " \"%s\"", n.texto) < 0)
        printf("Erro ao inserir texto!\n");
    if(fprintf(a, " \n") < 0)
        printf("Erro ao criar linha!");
}

void inserirNotas(Nota n[], int t){
    FILE *novo = fopen("novo.txt", "w");
    if(novo == NULL){
        printf("Erro ao abrir!\n");
        return;
    }
    for(int a = 0; a < t; a++){
        inserirNota(n[a], novo);
    }
    fclose(novo);
}

void trocaPosicaoNota(Sistema *s, int a, int b){
    if(a < b){
        for(int i = a; i < b ; i++){
            Nota troca = s->notas[b];
            s->notas[b] = s->notas[i];
            s->notas[i] = troca;
        }
    }
    if(a > b){
        for(int i = a; i > b; i--){
            Nota troca = s->notas[b];
            s->notas[b] = s->notas[i];
            s->notas[i] = troca;
        }
    }
}

Nota notaVazia(){
    Nota n = {0};
    n.cor.r = -1;
    return n;
}

void desenhaNota(Nota n){
    printf("NOTA %c%c%c %s\n",n.etiqueta[0], n.etiqueta[1], n.etiqueta[2], n.texto);
}

void imprimeVet(int v[]){
    for(int i = 0; v[i] != -1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void encontrarValidos(Sistema *s){
    int a = 1;
    for(int i = 0; i < s->quantidade; i++){
        if(strcmp("\0", s->textoBusca) != 0 && s->etiquetaBusca[0] != '\0'){
            if(!strcmp(s->notas[i].texto, s->textoBusca) && s->etiquetaBusca[0] == s->notas[i].etiqueta[0] &&
                s->etiquetaBusca[1] == s->notas[i].etiqueta[1] && s->etiquetaBusca[2] == s->notas[i].etiqueta[2]){
                s->validos[a] = i;
                a++;
            }
        } else if(strcmp("\0", s->textoBusca) != 0){
            if(!strcmp(s->notas[i].texto, s->textoBusca)){
                s->validos[a] = i;
                a++;
            }
        } else if(s->etiquetaBusca[0] != '\0'){
            if(s->etiquetaBusca[0] == s->notas[i].etiqueta[0] && s->etiquetaBusca[1] == s->notas[i].etiqueta[1] && 
                s->etiquetaBusca[2] == s->notas[i].etiqueta[2]){
                s->validos[a] = i;
                a++;
            }
        } else if(strcmp("\0", s->textoBusca) == 0 && s->etiquetaBusca[0] == '\0'){
            s->validos[a] = i;
            a++;
        }
    }
    s->validos[0] = a - 1; 
    for(int b = 0; b < s->capacidade; b++){
        s->validos[a + b] = -1;
    }
}

void desenhaModoPrincipal(Sistema *s){
    printf("MENU PRINCIPAL\n");
    printf("\n");
    for(int i = 1; i < s->validos[0] + 1; i++){
        desenhaNota(s->notas[s->validos[i]]);
        printf("Posição: %d\n", s->validos[i]);
        printf("\n");
    }
    printf("\n");
    printf("Notas encontradas: %d\n", s->validos[0]);
}

void modoPrincipal(Sistema *s){
    encontrarValidos(s);
    s->notaCorrente = s->validos[1];
    while(s->modo == PRINCIPAL){
        encontrarValidos(s);
        desenhaModoPrincipal(s);
        printf("Nota corrente: %d", s->notaCorrente);
        printf("\n");
        printf("\n");
        char c;
        scanf(" %c", &c);
        if(c == 'i'){
            if(s->quantidade != 0 && s->notaCorrente != -1){
                trocaPosicaoNota(s, 0, s->notaCorrente);
                s->notaCorrente = 0;
            }
        }
        if(c == 'f'){
            if(s->quantidade != 0 && s->notaCorrente != -1){
                trocaPosicaoNota(s, s->quantidade - 1, s->notaCorrente);
                s->notaCorrente = s->quantidade - 1;
            }
        }
        if(c == 'd'){
            if(s->quantidade == 0 || s->notaCorrente == -1){
                printf("Sem nota corrente para remover!\n");
            } else{
                s->ultimaRemovida = s->notas[s->notaCorrente];
                s->notas[s->notaCorrente] = notaVazia();
                trocaPosicaoNota(s, s->quantidade - 1, s->notaCorrente);
                encontrarValidos(s);
                if(s->validos[0] != 0){
                    s->notaCorrente = s->validos[1];
                } else {
                    s->notaCorrente = -1;
                }
                s->quantidade--;
                if(s->quantidade * 100 < s->capacidade * 30){
                    if(!diminuiCapacidade(s)){
                        printf("Erro ao diminuir capacidade!\n");
                        return;
                    }
                }
            }
        }
        if(c == '0'){
            if(s->ultimaRemovida.cor.r == -1){
                printf("Não existe ultima nota removida para inserir!\n");
            } else{
                if(s->quantidade == s->capacidade){
                    if(!aumentaCapacidade(s))
                        printf("Sem memoria\n");
                    }
                s->notas[s->quantidade] = s->ultimaRemovida;
                s->quantidade++;
                s->notaCorrente = s->quantidade - 1;
                s->ultimaRemovida = notaVazia();  
            }
        }
        if(c == 'n'){
            if(s->quantidade == s->capacidade){
                if(!aumentaCapacidade(s)){
                    printf("Sem memoria\n");
                    return;
                }
            }
            s->notas[s->quantidade] = notaDefault();
            s->quantidade++;
            if(strcmp("\0", s->textoBusca) == 0 && s->etiquetaBusca[0] == '\0'){
                s->notaCorrente = s->quantidade - 1;
            }
        }
        if(c == 'g'){
            inserirNotas(s->notas,  s->quantidade);
        }
        if(c == 'e'){
            s->modo = EDITAR_TEXTO;
        }
        if(c == 'b'){
            s->modo = EDITAR_TEXTO_BUSCA;
        }
        if(c == 'c'){
            s->modo = EDITAR_COR;
        }
        if(c == 'A'){
            for(int i = 1; i < s->validos[0] + 1 ; i++){
                if(s->validos[i] == s->notaCorrente){
                    if(i > 1) s->notaCorrente = s->validos[i - 1];
                    break;
                }
            }
        }
        if(c == 'D'){
            for(int i = 1; i < s->validos[0] + 1 ; i++){
                if(s->validos[i] == s->notaCorrente){
                    if(i < s->validos[0]) s->notaCorrente = s->validos[i + 1];
                    break;
                } 
            }
        }
        if(c == 'h'){
            if(s->validos[0] != 0){
                s->notaCorrente = s->validos[1];
            }
            
        }
        if(c == 'E'){
            if(s->validos[0] != 0){
                s->notaCorrente = s->validos[s->validos[0]];
            }
        }
        if(c == 't'){
            s->modo = EDITAR_ETIQUETA;
        }
        if(c == 'B'){
            s->modo = EDITAR_ETIQUETA_BUSCA;
        }
    }
}

void modoEditarTexto(Sistema *s){
    
    s->modo = PRINCIPAL;
}

void modoEditarEtiqueta(Sistema *s){
    s->modo = PRINCIPAL;
}

void modoEditarCor(Sistema *s){
    s->modo = PRINCIPAL;
}

void modoEditarTextoBusca(Sistema *s){
    s->modo = PRINCIPAL;
}

void modoEditarEtiquetaBusca(Sistema *s){
    s->modo = PRINCIPAL;
}

void incializarVetorValidos(Sistema *s){
    for(int i = 0; i < s->capacidade; i++){
        s->validos[i] = -1;
    }
}


void inicializaSistema(Sistema *s, FILE *a, FILE *p){
    s->cursor.x = 0;
    s->cursor.y = 0;
    s->capacidade = 10;
    s->notaCorrente = -1;
    s->modo = PRINCIPAL;
    strcpy(s->textoBusca, "\0");
    s->etiquetaBusca[0] = '\0';
    s->etiquetaBusca[1] = 'X';
    s->etiquetaBusca[2] = 'X';
    s->notas = malloc(s->capacidade * sizeof(Nota));
    if(s->notas == NULL){
        printf("Erro de memoria!\n");
        exit(1);
    }
    s->validos = malloc(s->capacidade * sizeof(Nota));
    if(s->validos == NULL){
        printf("Erro de memoria!\n");
        exit(1);
    }    
    incializarVetorValidos(s);

    s->quantidade = leNotas(a, p, s);
    s->ultimaRemovida = notaVazia();
}

int main(){
    Sistema s;
    FILE *arq = fopen("arquivo.txt", "r");
    FILE *p = fopen("problemas.txt", "w");

    if(arq == NULL || p == NULL){
        printf("Erro ao abrir!\n");

        if(arq != NULL) fclose(arq);
        if(p != NULL) fclose(p);
        
        return 1;
    }
    inicializaSistema(&s, arq, p);
    while(s.modo != TERMINAR){ 
        switch(s.modo){ 
            case 0: 
                modoPrincipal(&s); 
                break; 
            case 1: 
                modoEditarTexto(&s); 
                break; 
            case 2: 
                modoEditarEtiqueta(&s); 
                break; 
            case 3: 
                modoEditarCor(&s); 
                break; 
            case 4: 
                modoEditarTextoBusca(&s); 
                break; 
            case 5: 
                modoEditarEtiquetaBusca(&s); 
                break; 
            default: 
                s.modo = TERMINAR; 
        } 
    }

    free(s.notas);
    fclose(arq);
    fclose(p);
    return 0;
}

