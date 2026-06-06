
void desenhaModoPrincipal(Sistema *s){
    int lin = 1;

    t_lincol(lin++, 1);
    printf("=== MENU PRINCIPAL ===");
    t_lincol(lin++, 1);
    printf("Notas encontradas: %d", s->validos[0]);
    t_lincol(lin++, 1);
    printf("Nota corrente %d", s->notaCorrente);
    t_lincol(lin++, 1);
    imprimeVet(s->validos);

    lin++;
    for(int i = 1; i < s->validos[0] + 1; i++){
        Nota *n = &s->notas[s->validos[i]];
        bool corrente = false;
        if(s->validos[i] == s->notaCorrente) corrente = true;
        if(corrente){
            t_corfundo(80, 80, 180); 
            t_cortexto(255, 255, 255);
        }
        t_lincol(lin++, 1);
        if(corrente){
            printf(" > NOTA %c%c%c  |  %s", n->etiqueta[0], n->etiqueta[1], n->etiqueta[2], n->texto);
        } else {
            printf("   NOTA %c%c%c  |  %s", n->etiqueta[0], n->etiqueta[1], n->etiqueta[2], n->texto);
        }
        t_lincol(lin++, 1);
        printf("   Cor: (%d,%d,%d)  Posicao: %d", n->cor.r, n->cor.g, n->cor.b, s->validos[i]);
        if(corrente) t_cornormal();
        lin++;
    }

    fflush(stdout);
}