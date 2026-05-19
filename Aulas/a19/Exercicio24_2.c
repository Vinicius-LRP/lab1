#include <stdio.h>

typedef struct {
  int r;
  int g;
  int b;
} cor;

typedef struct{
    int x;
    int y;
}ponto;

typedef struct{
    ponto inf_esq;
    ponto sup_dir;
}retangulo;

typedef struct {
  retangulo r;
  cor c;
  char nome[20];
} postit;


int acha_postit(int n, postit v[n], ponto p){
    n -= 1;
    for(; n >= 0 ; n--){
        if(p.x >= v[n].r.inf_esq.x && p.x <= v[n].r.sup_dir.x && p.y >= v[n].r.inf_esq.y && p.y <= v[n].r.sup_dir.y)
            return n;
    }
    return -1;
}

void cor_letra(cor c)
{
  printf("%c[38;2;%d;%d;%dm", 27,
         c.r*256/100, c.g*256/100, c.b*256/100);
}

void cor_fundo(cor c)
{
  printf("%c[48;2;%d;%d;%dm", 27,
         c.r*256/100, c.g*256/100, c.b*256/100);
}

void cor_normal()
{
  printf("%c[0m", 27);
}

void desenha_postits(int n, postit v[n])
{
  char letra;
  for (int lin = 23; lin >= 0; lin-=1) {
    for (int col = 0; col < 80; col++) {
      ponto pos = { col, lin };
      int i = acha_postit(n, v, pos);
      if (i != -1) {
        cor_fundo(v[i].c);
        cor_letra(v[i].c);
        letra = v[i].nome[0];
      } else {
        cor_fundo((cor){0,0,0});
        letra = ' ';
      }
      putchar(letra);
    }
    cor_normal();
    putchar('\n');
  }
}

int main()
{
    postit v[] = {
        {{{ 0, 0}, {79,23}}, { 0, 0, 0}, " tela"   },
        {{{10,10}, {20,20}}, {99, 0, 0}, "vermelho"},
        {{{15, 9}, {40,30}}, {10,10,80}, "azul"    },
        {{{40,15}, {75,22}}, {99,70, 0}, "laranja" },
    };
    desenha_postits(4, v);
    
}


