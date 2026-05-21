#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int inferior;
    int superior;
} intervalo;

typedef struct {
    intervalo i1;
    intervalo i2;
} intervalo_duplo;

typedef struct {
    int a;
    int b;
} dupla;

bool verificaIntervalo(intervalo_duplo v, dupla d){
    if(d.a >= v.i1.inferior && d.a <= v.i1.superior && 
       d.b >= v.i2.inferior && d.b <= v.i2.superior) return true;
    return false;
}

bool contem_dupla(int n, intervalo_duplo v[n], dupla d){
    for(int a = 0; a < n ; a++){
        if(verificaIntervalo(v[a], d))
            return true;
    }
    return false;
}

int num_duplas(int n, intervalo_duplo v[n], dupla d){
    int vezes = 0;
    for(int a = 0; a < n ; a++){
        if(verificaIntervalo(v[a], d)) vezes++;
    }
    return vezes;
}

int prim_dupla(int n, intervalo_duplo v[n], dupla d){
    for(int a = 0; a < n; a++){
        if(verificaIntervalo(v[a], d)) return a;
    }
    return -1;
}

int ult_dupla(int n, intervalo_duplo v[n], dupla d){
    for(int a = n - 1; a >= 0; a--){
        if(verificaIntervalo(v[a], d)) return a;
    }
    return -1;
}

int main(){
    intervalo_duplo intervalos[2] = {{{1,5},{4,10}},{{1,5},{4,6}}};
    
    dupla i = {3,7};

    printf("%d\n", contem_dupla(2, intervalos, i));
    printf("%d\n", num_duplas(2, intervalos, i));
    printf("%d\n", prim_dupla(2, intervalos, i));
    printf("%d\n", ult_dupla(2, intervalos, i));

}