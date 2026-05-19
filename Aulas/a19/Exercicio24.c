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

typedef struct{
    char nome[20];
    retangulo r;
    cor c;
}postit;

int acha_postit(int n, postit v[n], ponto p){
    n -= 1;
    for(; n >= 0 ; n--){
        printf("N: %d\n", n);
        printf("r inf_esq x: %d\n",v[n].r.inf_esq.x);
        printf("r inf_esq y: %d\n",v[n].r.inf_esq.y);
        printf("r sup_dir x: %d\n",v[n].r.sup_dir.x);
        printf("r sup_dir y: %d\n",v[n].r.sup_dir.y);
        printf("X: %d\n", p.x);
        printf("Y: %d\n", p.y);

        if(p.x >= v[n].r.inf_esq.x && p.x <= v[n].r.sup_dir.x && p.y >= v[n].r.inf_esq.y && p.y <= v[n].r.sup_dir.y)
            return n;
    }
    return -1;
}

void imprimepostit(postit p){
    printf("r inf_esq x: %d\n",p.r.inf_esq.x);
    printf("r inf_esq y: %d\n",p.r.inf_esq.y);
    printf("r sup_dir x: %d\n",p.r.sup_dir.x);
    printf("r sup_dir y: %d\n",p.r.sup_dir.y);
}



int main(){
    postit postits[50] = {{"postit 1", { { 3 , 3 } , { 1 , 1 } } }, {"postit 2", { { 5 , 5 } , { 2 , 2 } } } };
    
    ponto p = {2,2};

    imprimepostit(postits[acha_postit(2, postits, p)]);
    
}
