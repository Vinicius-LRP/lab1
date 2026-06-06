bool cursorDentroDaNota(Cursor *c, Nota *n){
    return c->x >= n->retangulo.ponto.x && c->x <  n->retangulo.ponto.x + n->retangulo.tamanho.largura &&
           c->y >= n->retangulo.ponto.y && c->y <  n->retangulo.ponto.y + n->retangulo.tamanho.altura;
}

int encontraNotaCorrente(Sistema *s){
    for(int i = s->quantidade - 1; i >= 0; i--){
        Nota *n = &s->notas[i];
        if(cursorDentroDaNota(&s->cursor, n)) return i;
    }
    return -1;
}