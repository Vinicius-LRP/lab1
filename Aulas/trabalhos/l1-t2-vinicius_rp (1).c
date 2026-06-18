#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void ordem(int v[]){
    for (int a = 0; a < 16; a++){
        v[a] = a;
    }
}
int indice(int n, int v[]){
    for(int a = 0; a < 16; a++){
        if(v[a] == n) return a;
    }
    return -1;
}
bool crescente(int v[]){
    int ordem = 0;
    for(int a = 0; a < 16 ; a++){
        if(v[a] == a){
            ordem++;
        }
    }
    if(ordem == 16) return true;
    return false;
}
void troca_esq(int v[]){
    for(int a = 0; a < 16; a++){
        if(v[a] == 15){
            if(a % 4 != 0){
                int troca = v[a - 1];
                v[a - 1] = v[a];
                v[a] = troca;
                break;
            }
        }
    }
}
void troca_dir(int v[]){
    for(int a = 0; a < 16; a++){
        if(v[a] == 15){
            if((a + 1) % 4 != 0){
                int troca = v[a + 1];
                v[a + 1] = v[a];
                v[a] = troca;
                break;
            }
        }
    }
}
void troca_cima(int v[]){
    for(int a = 0; a < 16; a++){
        if(v[a] == 15){
            if(a > 3){
                int troca = v[a - 4];
                v[a - 4] = v[a];
                v[a] = troca;
                break;
            }
        }
    }
}
void troca_baixo(int v[]){
    for(int a = 0; a < 16; a++){
        if(v[a] == 15){
            if(a < 12){
                int troca = v[a + 4];
                v[a + 4] = v[a];
                v[a] = troca;
                break;
            }
        }
    }
}
void troca_ale(int v[]){
    int a = (rand() % 4) + 1;
    switch (a)
    {
    case 1:
        troca_esq(v);
        break;
    case 2:
        troca_dir(v);
        break;
    case 3:
        troca_cima(v);
        break;
    case 4:
        troca_baixo(v);
        break;
    }
}
void embaralha(int v[]){
    for(int a = 0; a < 100; a++){
        troca_ale(v);
    }
}
void movimenta(char c,int v[]){
    if(c == 'w' || c == 'c' || c == 'A'){
        troca_baixo(v);
    }
    if(c == 'a' || c == 'e' || c == 'D'){
        troca_dir(v);
    }
    if(c == 's' || c == 'b' || c == 'B'){
        troca_cima(v);
    }
    if(c == 'd' || c == 'C'){
        troca_esq(v);
    }
}
void troca(int pos , int v[]){
    if(pos % 4 != 0 && v[pos - 1] == 15){
        troca_dir(v);
    }
    else if(pos >= 4 && v[pos - 4] == 15){
        troca_baixo(v);
    }
    else if(pos % 4 != 3 && v[pos + 1] == 15){
        troca_esq(v);
    }
    else if(pos < 12 && v[pos + 4] == 15){
        troca_cima(v);
    }
}
void imprime_vet(int v[]){
    printf("\n\r");
    for(int a = 0; a < 16; a++){
        if(a % 4 == 0 && a != 0){
            printf("\n\r");
        }
        printf("%3d", v[a]);
    }
    printf("\n\r");
}

void cor_letra(int r, int g, int b)
{
  printf("%c[38;2;%d;%d;%dm", 27, r, g, b);
}

void cor_fundo(int r, int g, int b)
{
  printf("%c[48;2;%d;%d;%dm", 27, r, g, b);
}

void cor_normal()
{
  printf("%c[0m", 27);
}

void cor_tabuleiro()
{
  cor_fundo(140, 70, 20); // marrom
}
void cor_peca()
{
  cor_fundo(200, 200, 170); // branco sujo
  cor_letra(70, 50, 40); // escuro
}
void cor_vazio()
{
  cor_fundo(0, 0, 0); // preto
}
void imprime_pedaco_linha_v7(int t[], int l, bool com_peca)
{
  char desenho[] = "ABCDEFGHIJKLMNO ";

  cor_normal();
  printf("%3s", "");
  cor_tabuleiro();
  printf("  ");
  for (int i = 0; i < 4; i++) {
    int v = t[l*4 + i];
    v == 15 ? cor_vazio() : cor_peca();
    printf("   %c   ", com_peca ? desenho[v] : ' ');
  }
  cor_tabuleiro();
  printf("  ");
  cor_normal();
  printf("\n\r");
}

void imprime_linha_v7(int t[], int l)
{
  imprime_pedaco_linha_v7(t, l, false);
  imprime_pedaco_linha_v7(t, l, true);
  imprime_pedaco_linha_v7(t, l, false);
}

void limpa_tela()
{
  cor_normal();
  printf("%c[2J", 27); // limpa a tela
  printf("%c[H", 27);  // põe o cursor no início
}

void desenha_borda()
{
  cor_normal();
  printf("%3s", "");
  cor_tabuleiro();
  printf("%32s","");
  cor_normal();
  printf("\n\r");
}

void imprime_tabuleiro_v8(int t[])
{
  limpa_tela();
  printf("\n\n\n\n\r");
  desenha_borda();
  for (int linha = 0; linha < 4; linha++) {
    imprime_linha_v7(t, linha);
  }
  desenha_borda();
}
 
int main(){
    system("stty raw -echo");
    srand(time(0));
    int vet[16];
    ordem(vet);
    embaralha(vet);
    char digitado;
    for(;;){
        imprime_tabuleiro_v8(vet);
        printf("Digite um caracter: ");
        scanf(" %c", &digitado);
        if(digitado == 'Q') break ;
        movimenta(digitado, vet);
        if(crescente(vet) == true){
            printf("Você Ganhou!");
            break;
        }
    }
    system("stty sane");
    printf("Adeus!");
}