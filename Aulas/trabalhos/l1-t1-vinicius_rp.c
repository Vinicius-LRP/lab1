#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double potencia(double num, int elevado){
    if(elevado > 0){
        double result = num;
        for(int a = 1; a < elevado; a++){
            result = result * num;
        }
        return result;
    } else if(elevado < 0){
        double result = num;
        for(int a = 1; a < (elevado * -1); a++){
            result = result * num;
        }
        return (1/result);
    } else {
        return 1;
    }
}
long fatorial(long num){
    if(num > 0){
        long result = num;
        for(; num != 1; num--){
            result = result * (num - 1);
        }
        return result;
    } else if(num < 0){
        printf("O fatorial do seu número não existe:");
        return num;
    } else {
        return 1;
    }
}
double seno(double x){
    int sinal = 1;
    double result = x;
    long double num;

    for(int a = 3; ; a += 2){
        num = potencia(x, a) / fatorial(a);
        if(sinal % 2 == 0){
            result = result + num;
        } else {
            result = result - num;
        }
        if(fabs(num)  < 0.000000001){
            break;
        }
        sinal++;
    }
    return result;
}
double diferenca(double chute, double chuteanterior){
    if(chute > chuteanterior){
            return chute - chuteanterior;
        } else{
            return chuteanterior - chute;
        }
}
double raizquadrada(double num){
    double chute = num;
    double chuteanterior;
    for(int a = 0;;a++){
        chuteanterior = chute;
        chute = (chute + (num/chute)) / 2;
        if(diferenca(chute, chuteanterior) < 0.0000000001) break;
    }
    return chute;
}

double grauspararad(double num){
    long double x = num * 3.141592 / 180.0;
    return seno(x);
}
double cosseno(double coss){
    return raizquadrada(1 - potencia(grauspararad(coss), 2));
}
void linha(){
    printf("╠");
    for(int a = 0; a < 4; a++){
        printf("═");
    }
    printf("╬");
    for(int b = 1; b < 10; b++){    
        for(int a = 0; a < 10; a++){
            printf("═");
        }
        printf("╬");
    }
    for(int a = 0; a < 10; a++){
        printf("═");
    }
    printf("╣");
}
void linhacomponta(bool cimaoubaixo){
    if(cimaoubaixo){
        printf("╔");
        for(int a = 0; a < 4; a++){
            printf("═");
        }
        printf("╦");
        for(int b = 1; b < 10; b++){    
            for(int a = 0; a < 10; a++){
                printf("═");
            }
            printf("╦");
        }
        for(int a = 0; a < 10; a++){
            printf("═");
        }
        printf("╗");
    } else {
        printf("╚");
        for(int a = 0; a < 4; a++){
            printf("═");
        }
        printf("╩");
        for(int b = 1; b < 10; b++){    
            for(int a = 0; a < 10; a++){
                printf("═");
            }
            printf("╩");
        }
        for(int a = 0; a < 10; a++){
            printf("═");
        }
        printf("╝");
    }
}
void coluna(){
    printf(" ║");
}
void topo(){
    coluna();
    printf("ang");
    for(int a = 0; a < 5; a++){
        coluna();
        printf("   seno  ");
        coluna();
        printf(" cosseno ");
    }
    coluna();
};
void formatacao(int a){
    if(a == 0){
        printf("\n ");
        linhacomponta(true);
        printf("\n");
        topo();
    }
    if(a % 5 == 0){
        printf("\n ");
        linha();
        printf("\n");
        coluna();
        printf(" %2d", a);
        coluna();
    }
    printf(" %8.6lf", grauspararad(a));
    coluna();
    printf(" %8.6lf", cosseno(a));
    coluna();
}

int main(){
    for(int a = 0; a <= 89; a++){
        formatacao(a);
    }
    printf("\n ");
    linhacomponta(false);
}