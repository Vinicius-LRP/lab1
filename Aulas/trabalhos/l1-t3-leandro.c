#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tela.h"

typedef enum {
  acoes, edita, fim
} modo_t;

typedef struct{
  int r, g, b; // 0 A 255
} cor;

typedef struct {
  int xcur;
  int ycur;
} cursor;


typedef struct{
  int x, y; // coluna e linha respectivamente
  int altura, largura;
  cor Color;
  char text[101];
} nota;

typedef struct{
  modo_t modo;
  cursor Cursor;
  nota *notas;
  nota deletada;
  nota auxiliar;
  nota *busca;
  int totalBusca;
  int indice;
  int total;
  int *correspondentes;
  int tamCorrespondentes;
  nota *validas;
  bool temDeletada;
} estado; 

bool temRet(estado *e){
  for (int j = e->total - 1; j >= 0; j--) {
      int alt, lar;
      t_tamanho(&alt, &lar);
      if (e->Cursor.ycur >= e->notas[j].y && e->Cursor.ycur <= e->notas[j].y + e->notas[j].altura &&
          e->Cursor.xcur >= e->notas[j].x && e->Cursor.xcur <= e->notas[j].x + e->notas[j].largura) {
        e->indice = j;
        return true;
        break;
      }
  }
  return false;
}

void inicioVet(estado *e){
  for (int i = e->indice; i > 0; i--)
  {
    e->notas[i] = e->notas[i - 1];
  }
}

void fimVet(estado *e){
  for (int i = e->indice; i < e->total - 1; i++){
    e->notas[i] = e->notas[i + 1];
  }
}

void copiaNotaVet(estado *e){
  strcpy(e->auxiliar.text, e->notas[e->indice].text);

  e->auxiliar.largura = e->notas[e->indice].largura;
  e->auxiliar.altura = e->notas[e->indice].altura;

  e->auxiliar.x = e->notas[e->indice].x;
  e->auxiliar.y = e->notas[e->indice].y;
 
  e->auxiliar.Color.r = e->notas[e->indice].Color.r;
  e->auxiliar.Color.g = e->notas[e->indice].Color.g;
  e->auxiliar.Color.b = e->notas[e->indice].Color.b;
}

void copiaNota(estado *e){
  strcpy(e->deletada.text, e->notas[e->indice].text);

  e->deletada.largura = e->notas[e->indice].largura;
  e->deletada.altura = e->notas[e->indice].altura;

  e->deletada.x = e->notas[e->indice].x;
  e->deletada.y = e->notas[e->indice].y;
 
  e->deletada.Color.r = e->notas[e->indice].Color.r;
  e->deletada.Color.g = e->notas[e->indice].Color.g;
  e->deletada.Color.b = e->notas[e->indice].Color.b;
}

void desenha_texto_nota(int l, int c, int altura, int largura, char texto[101])
{
  int posicao = 0;
  int tam = strlen(texto);
  for (int linha = 0; linha < altura && posicao < tam; linha++)
  {
    t_lincol(l + linha, c);
    for (int coluna = 0; coluna < largura; coluna++)
    {
      if (posicao < tam)
      {
        putchar(texto[posicao]);
        posicao++;
      }else{
        putchar(' ');
      }
    }
  }
}

void desenha_ret_fundo(int l, int c, int altura, int largura, int r, int g, int b, char s[])
{
  t_corfundo(r, g, b);
  for (int i = 0; i < altura; i++) {
    t_lincol(l + i, c);
    printf("%*s", largura, "");
  }

  int alt, larg;
  t_tamanho(&alt, &larg);
  t_lincol(l, c);
  printf("%dx%d", altura, largura);

  t_lincol(l + altura/2, c + largura/2 - strlen(s)/2);
  t_cortexto(0, 0, 0);
  printf("%s", s);
}

void desenha_ret(int l, int c, int altura, int largura, int r, int g, int b, char s[])
{
  t_corfundo(r, g, b);
  for (int i = 0; i < altura; i++) {
    t_lincol(l + i, c);
    printf("%*s", largura, "");
  }

  if ((r + g + b) / 3 < 120)
  {
    t_cortexto(255, 255, 255);
  } else {
    t_cortexto(0, 0, 0);
  }
  desenha_texto_nota(l, c, altura, largura, s);
}

void desenha_ret_cor(int l, int c, int altura, int largura, int r, int g, int b, char s[])
{
  t_corfundo(r, g, b);
  for (int i = 0; i < altura; i++) {
    t_lincol(l + i, c);
    printf("%*s", largura, "");
  }

  int alt, larg;
  t_tamanho(&alt, &larg);
  t_lincol(l, c);
  printf("%dx%d", altura, largura);


  t_lincol(0, 0);

  if ((r + g + b) / 3 < 120)
  {
  t_cortexto(255, 255, 255);
  } else {
    t_cortexto(0, 0, 0);
  }
  printf("%s", s);
}

void muda_modo(estado *e, modo_t novo_modo)
{
  e->modo = novo_modo;
}

void tela_move(estado *e, char texto[])
{
  t_limpa();
  desenha_ret_fundo(1, 1, 30, 70, 10, 20, 30, "fundo");
  for (int i = 0; i < e->total; i++) {
    desenha_ret(e->notas[i].y, e->notas[i].x, e->notas[i].altura, e->notas[i].largura,
       e->notas[i].Color.r, e->notas[i].Color.g, e->notas[i].Color.b, e->notas[i].text);
  }

  if(e->modo == acoes){
    t_lincol(e->Cursor.ycur, e->Cursor.xcur);
  }
}

void addNota(estado *e, char texto[], int indice){
  strcpy(e->notas[indice].text, texto);

  e->notas[indice].largura = 10;
  e->notas[indice].altura = 5;

  e->notas[indice].x = 5;
  e->notas[indice].y = 5;

  e->notas[indice].Color.r = 255;
  e->notas[indice].Color.g = 255;
  e->notas[indice].Color.b = 255;

}

void tela_edita(estado *e,  char texto[])
{
  t_limpa();
  desenha_ret_fundo(1, 1, 30, 70, 10, 20, 30, "fundo");
  desenha_ret(e->notas[e->indice].y, e->notas[e->indice].x, e->notas[e->indice].altura,e->notas[e->indice].largura, 
              e->notas[e->indice].Color.r, e->notas[e->indice].Color.g, e->notas[e->indice].Color.b, texto);
}

void tela_Busca_desenho(estado *e)
{
  t_limpa();
  desenha_ret_fundo(1, 1, 30, 70, 10, 20, 30, "fundo");
  for(int i = 0; i < e->totalBusca; i++){
    desenha_ret(e->notas[e->correspondentes[i]].y, e->notas[e->correspondentes[i]].x, e->notas[e->correspondentes[i]].altura,e->notas[e->correspondentes[i]].largura, 
              e->notas[e->correspondentes[i]].Color.r, e->notas[e->correspondentes[i]].Color.g, e->notas[e->correspondentes[i]].Color.b, e->notas[e->correspondentes[i]].text);
    }
}

void remove_ultimo_caractere(char s[])
{
  int l = strlen(s);
  if (l > 0){
    s[l - 1] = '\0';
  }
}

void insere_ultimo_caractere(char s[], char c, int tamanho)
{
  int l = strlen(s);
  if (l < tamanho - 1)
  {
    s[l] = c;
    s[l + 1] = '\0';
  }
}

void tela_Busca_texto(estado *e, char texto[])
{
  tecla_t tec;
  char textoBusca[101] = "";
  int c = 17;
  int x = 0;
  e->totalBusca = 0;
 
  e->tamCorrespondentes = 0;
  t_limpa();
  printf("TEXTO DE BUSCA: ");
  tec = t_tecla();
  while (tec != T_ESC){
    tec = t_tecla();
    if(tec == T_BS) {
      remove_ultimo_caractere(textoBusca);
      if (x > 0){
        x--;
        t_lincol(1, c + x);
        putchar(' ');
      }
    }else if (tec >= 'a' && tec <= 'z') {
      t_lincol(1, c + x);
      insere_ultimo_caractere(textoBusca, tec, 100);
      putchar(tec);
      x++;
    }else if(tec == T_ESQUERDA){
      if(c + x > 17){
        x--;
        t_lincol(1, c + x);
      }
    }else if(tec == T_DIREITA){
        x++;
        t_lincol(1, c + x);
    }else if(tec == T_ENTER){
      e->correspondentes = realloc(e->correspondentes, e->total * sizeof(int));

      e->totalBusca = 0;

      int p = 0;
      for(int i = 0; i < e->total; i++){
          if(strcmp(textoBusca, e->notas[i].text) == 0){
            e->correspondentes[p++] = i;
            e->totalBusca++;
          }
      }
      break;  
    }
      
  }
}

void textoBusca(estado *e, char texto[]){
  tela_Busca_texto(e, texto);
  tela_Busca_desenho(e);
}

void alteraCores(estado *e){
  tecla_t tec = T_NADA;
  char seletor = 'r';
  while (tec != T_ENTER)
  {
    t_limpa();
    desenha_ret_cor(5, 5, e->notas[e->indice].altura, e->notas[e->indice].largura, 
                e->notas[e->indice].Color.r, e->notas[e->indice].Color.g, e->notas[e->indice].Color.b, "");
    
    printf("vermelho: %d  ",e->notas[e->indice].Color.r);
    printf("verde: %d  ", e->notas[e->indice].Color.g); 
    printf("azul: %d", e->notas[e->indice].Color.b);

    tec = t_tecla();
    
    if(tec == T_CTRL_T){
      for (int i = 0; i < e->total - 1; i++)
      {
        e->notas[i].Color.r = e->notas[e->indice].Color.r;
        e->notas[i].Color.g = e->notas[e->indice].Color.g;
        e->notas[i].Color.b = e->notas[e->indice].Color.b;
      }
      break;
    }

    if (tec == 'r'){
    seletor = 'r';
    }
    if (tec == 'g'){
    seletor = 'g';
    }
    if (tec == 'b'){
    seletor = 'b';
    }

    if(tec == T_DIREITA && seletor == 'r'){
      seletor = 'g';
    }else if(tec == T_DIREITA && seletor == 'g'){
      seletor = 'b';
    }else if(tec == T_DIREITA && seletor == 'b'){
      seletor = 'r';
    }else if(tec == T_ESQUERDA && seletor == 'r'){
      seletor = 'b';
    }else if(tec == T_ESQUERDA && seletor == 'b'){
      seletor = 'g';
    }else if(tec == T_ESQUERDA && seletor == 'g'){
      seletor = 'r';
    }

    if (seletor == 'r')
    {
      if(tec == T_CIMA){
        if(e->notas[e->indice].Color.r < 255){
          e->notas[e->indice].Color.r++;
        }
      }else if(tec == T_BAIXO){
        if(e->notas[e->indice].Color.r > 0){
          e->notas[e->indice].Color.r--;
        }
      }else if(tec == T_S_CIMA){
        if(e->notas[e->indice].Color.r < 245){
          e->notas[e->indice].Color.r = e->notas[e->indice].Color.r + 10;
        }
      }else if(tec == T_S_BAIXO){
        if(e->notas[e->indice].Color.r > 10){
          e->notas[e->indice].Color.r = e->notas[e->indice].Color.r - 10;
        }
      }else if(tec >= 'a' && tec <= 'Z'){
        int digitoValor = tec;
        if(digitoValor + e->notas[e->indice].Color.r > 255){
          e->notas[e->indice].Color.r = digitoValor;
        } else{
          e->notas[e->indice].Color.r = e->notas[e->indice].Color.r + digitoValor;
        }
      }
    }

    if (seletor == 'g')
    {
      if(tec == T_CIMA){
        if(e->notas[e->indice].Color.g < 255){
          e->notas[e->indice].Color.g++;
        }
      }else if(tec == T_BAIXO){
        if(e->notas[e->indice].Color.g > 0){
          e->notas[e->indice].Color.g--;
        }
      }else if(tec == T_S_CIMA){
        if(e->notas[e->indice].Color.g < 245){
          e->notas[e->indice].Color.g = e->notas[e->indice].Color.g + 10;
        }
      }else if(tec == T_S_BAIXO){
        if(e->notas[e->indice].Color.g > 10){
          e->notas[e->indice].Color.g = e->notas[e->indice].Color.g - 10;
        }
      }
    }

    if (seletor == 'b')
    {
      if(tec == T_CIMA){
        if(e->notas[e->indice].Color.b < 255){
          e->notas[e->indice].Color.b++;
        }
      }else if(tec == T_BAIXO){
        if(e->notas[e->indice].Color.b > 0){
          e->notas[e->indice].Color.b--;
        }
      }else if(tec == T_S_CIMA){
        if(e->notas[e->indice].Color.b < 245){
          e->notas[e->indice].Color.b = e->notas[e->indice].Color.b + 10;
        }
      }else if(tec == T_S_BAIXO){
        if(e->notas[e->indice].Color.b > 10){
          e->notas[e->indice].Color.b = e->notas[e->indice].Color.b - 10;
        }
      }
    }
  }
  muda_modo(e, acoes);
}

bool linhaValida(estado *e,char linha[])
{
  char text[101] = "";

  int lidos = sscanf(linha, "%d %d %d %d %d %d %d \"%s\"", &e->notas[e->indice].y, &e->notas[e->indice].x, &e->notas[e->indice].altura,
     &e->notas[e->indice].largura, &e->notas[e->indice].Color.r, &e->notas[e->indice].Color.g, &e->notas[e->indice].Color.b, e->notas[e->indice].text);

  if (e->notas[e->indice].Color.r < 0 || e->notas[e->indice].Color.r > 255)
  {
    return false;
  }

  if (e->notas[e->indice].Color.g < 0 || e->notas[e->indice].Color.g > 255)
  {
    return false;
  }

  if (e->notas[e->indice].Color.b < 0 || e->notas[e->indice].Color.b > 255)
  {
    return false;
  }

  if (strlen(text) == 0)
  {
    return false;
  }

  return true;
}

void dados(estado *e){
  FILE *arq;
  arq = fopen("dados.txt", "w");
  if (arq == NULL)
  {
    fprintf(stderr, "Erro: Não foi possível abrir ou criar seu arquivo\n");
    
  }
  for (int i = 0; i < e->total; i++)
  {
    fprintf(arq, "%d %d %d %d %d %d %d \"%s\"\n", e->notas[i].y, e->notas[i].x, e->notas[i].altura, e->notas[i].largura, 
             e->notas[i].Color.r, e->notas[i].Color.g, e->notas[i].Color.b, e->notas[i].text);
  }
  fclose(arq);
}

void exec_acoes(estado *e, char texto[]){
  FILE *arq;

  tela_move(e, e->notas[e->indice].text);

  tecla_t tec = t_tecla();
  
  switch (tec)
  {
  case T_ESC:
    muda_modo(e, fim);
    break;
  case 'j': case T_CIMA:
    e->Cursor.ycur--;
    break;
  case 'k': case T_BAIXO:
    e->Cursor.ycur++;
    break;
  case 'h': case T_ESQUERDA:
    e->Cursor.xcur--;
    break;
 case 'l':  case T_DIREITA:
    e->Cursor.xcur++;
    break;
  case 'H': case T_S_ESQUERDA:
    if (temRet(e) == true){
      if (e->notas[e->indice].x > 0)
      {
        e->notas[e->indice].x--;
        e->Cursor.xcur--;
      }
    }
    break;
  case 'L':case T_S_DIREITA:
    if (temRet(e) == true){
      if (e->notas[e->indice].largura + e->notas[e->indice].x != 71)
      {
        e->notas[e->indice].x++;
        e->Cursor.xcur++;
      }
    }
    break;
  case 'J': case T_S_CIMA:
    if (temRet(e) == true){
      if (e->notas[e->indice].y != 1)
      {
        e->notas[e->indice].y--;
        e->Cursor.ycur--;
      }
    }
    break;
  case 'K': case T_S_BAIXO:
    if (temRet(e) == true){
      if (e->notas[e->indice].altura + e->notas[e->indice].y != 31)
      {
        e->notas[e->indice].y++;
        e->Cursor.ycur++;
      }
    }
    break;
  case T_CTRL_H: case T_C_ESQUERDA:
    if (temRet(e) == true){
      if (e->notas[e->indice].x + e->notas[e->indice].largura < 71 && e->notas[e->indice].x > 1)
      {
        e->notas[e->indice].x--;
        e->notas[e->indice].largura++;
      }
    }
    break;
    case T_CTRL_L: case T_C_DIREITA:
    if (temRet(e) == true){
      if(e->notas[e->indice].x + e->notas[e->indice].largura < 71){
        e->notas[e->indice].largura++;
      }
    } 
      break;
    case T_CTRL_J: case T_C_CIMA:
    if (temRet(e) == true){
      if (e->notas[e->indice].altura < 30 && e->notas[e->indice].y > 0){
        e->notas[e->indice].y--;
        e->notas[e->indice].altura++;
      }
    }
      break;
    case T_CTRL_K: case T_C_BAIXO:
    if (temRet(e) == true){
      if(e->notas[e->indice].altura < 30){
        e->notas[e->indice].altura++;
      }
    }
      break;
     case T_CTRL_O: case T_A_DIREITA:
    if (temRet(e) == true){
      if (e->notas[e->indice].largura > 1)
      {
        e->notas[e->indice].largura--;
      }
    }
      break;
     T_CTRL_Y: case T_A_ESQUERDA:
    if (temRet(e) == true){
      if(e->notas[e->indice].largura > 1){
        e->notas[e->indice].x++;
        e->notas[e->indice].largura--;
      }
    }
      break;
    case T_CTRL_I: case T_A_BAIXO:
    if (temRet(e) == true){
      if(e->notas[e->indice].altura > 1){
        e->notas[e->indice].altura--;
      }
    }
      break;
    case T_CTRL_U: case T_A_CIMA: 
    if (temRet(e) == true){
      if(e->notas[e->indice].altura > 1){
        e->notas[e->indice].y++;
        e->notas[e->indice].altura--;
      }
    }
      break;
  case 'e':
    if (temRet(e) == true)
    {
      muda_modo(e, edita);
    }
    break;
  case 'i':
    if (temRet(e) == true)
    {
      copiaNotaVet(e);
      inicioVet(e);
      e->notas[0] = e->auxiliar;
      muda_modo(e,acoes);
    }
    break;
  case 'f':
    if (temRet(e) == true)
    {
      copiaNotaVet(e);
      fimVet(e);
      e->notas[e->total - 1] = e->auxiliar;
      muda_modo(e,acoes);
    }
    break;
  case 'c':
    if (temRet(e) == true)
    {
      alteraCores(e);
    }
    break;
  case 'n':
    e->total++;
    e->notas = realloc(e->notas, e->total * sizeof(nota));
    if(e->notas == NULL){
      break;
    }
    addNota(e, texto,e->total - 1);
    break;
  case 'p':
    e->Cursor.ycur = e->notas[e->total - 1].y + e->notas[e->total - 1].altura/2;
    e->Cursor.xcur = e->notas[e->total - 1].x + e->notas[e->total - 1].largura/2;
    break;
  case 'g':
    arq = fopen("dados.txt", "w");
    if (arq == NULL)
    {
      fprintf(stderr, "Erro: Não foi possível abrir ou criar seu arquivo\n");
      break;
    }
    for (int i = 0; i < e->total; i++)
    {
      fprintf(arq, "%d %d %d %d %d %d %d \"%s\"\n", e->notas[i].y, e->notas[i].x, e->notas[i].altura, e->notas[i].largura, 
                  e->notas[i].Color.r, e->notas[i].Color.g, e->notas[i].Color.b, e->notas[i].text);
    }
    fclose(arq);
    break;
  case 'b':

    textoBusca(e, texto);
    break;
  case 'I': case T_INS:
    if(e->temDeletada == true){
      e->total++;
      e->notas = realloc(e->notas, e->total * sizeof(nota));
      if (e->notas == NULL)
      {
        break;
      }
      e->notas[e->total - 1].altura = e->deletada.altura;
      e->notas[e->total - 1].largura = e->deletada.largura;
      e->notas[e->total - 1].x = e->deletada.x;
      e->notas[e->total - 1].y = e->deletada.y;
      e->notas[e->total - 1].Color.r = e->deletada.Color.r;
      e->notas[e->total - 1].Color.g = e->deletada.Color.g;
      e->notas[e->total - 1].Color.b = e->deletada.Color.b;
      strcpy(e->notas[e->total - 1].text, e->deletada.text);
    }
    e->temDeletada = false;
    e->modo = acoes;
    break;
  case T_DEL:
    if (temRet(e) == true)
    {
        copiaNota(e);
        fimVet(e);
        e->total--;
        e->notas = realloc(e->notas, e->total * sizeof(nota));
        if (e->notas == NULL)
        {
          break;
        }    
        if (e->indice >= e->total){
          e->indice = e->total - 1;
        }
        e->temDeletada = true;
        muda_modo(e, acoes);
      }
      break;
  default:
    break;
  }
}


void exec_edita(estado *e)
{
  char txt[101] = "";
  strcpy(txt, e->notas[e->indice].text);
  int x;
  while (e->modo == edita) {
    tela_edita(e, txt);

    tecla_t tec = t_tecla();

    if(tec == T_ESC || tec == T_CTRL_C) {
      muda_modo(e, acoes);
    }else if (tec == T_BS || tec == T_CTRL_B) {
      remove_ultimo_caractere(txt);
      strcpy(e->notas[e->indice].text, txt);
    }else if (tec >= 'a' && tec <= 'z') {
      insere_ultimo_caractere(txt, tec, 100);
    }else if(tec == T_ENTER){
      strcpy(e->notas[e->indice].text, txt);
      muda_modo(e, acoes);
    }else if (tec == T_DEL || tec == T_CTRL_D){
      remove_ultimo_caractere(txt);
      strcpy(e->notas[e->indice].text, txt);
    }else if(tec == T_CTRL_H || tec == T_ESQUERDA){
      x--;
      t_lincol(e->notas[e->indice].y, e->notas[e->indice].x + x);
    }else if(tec == T_CTRL_L || tec == T_DIREITA){
      x--;
      t_lincol(e->notas[e->indice].y, e->notas[e->indice].x + x);
    }
    
  }
}

int main(){
  char texto[101] = "";
  estado *sistema = malloc(sizeof(estado));
  if (sistema == NULL)
  return 1;

sistema->correspondentes = NULL;
sistema->tamCorrespondentes = 0;

  printf("digite a quantidade de notas iniciais: ");
  scanf("%d", &sistema->total);

  if (sistema->total <= 0) {
    sistema->total = 1;
  }

  t_inicia();

  sistema->notas = malloc(sistema->total * sizeof(nota));

  for (int i = 0; i < sistema->total; i++)
  {
    addNota(sistema, texto, i);
  }
    sistema->modo = acoes;
    sistema->indice = 0;
    sistema->temDeletada = false;
    sistema->Cursor.xcur = 1;
    sistema->Cursor.ycur = 1;

  while (sistema->modo != fim){
    switch (sistema->modo) {
    case acoes:
      exec_acoes(sistema, texto);
      break;
    case edita:
      exec_edita(sistema);
      break;
    default:
      break;
    }  
  } 

  free(sistema->correspondentes);
  free(sistema->notas);
  free(sistema);
  t_fim();
  return 0;
}