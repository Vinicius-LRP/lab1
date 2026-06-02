*/
/* Faça uma função que lê de um arquivo e retorna uma nota, no formato: etiqueta, cor, retângulo, texto, como abaixo:
   Xxx 5 4 3 3 4 7 9 “texto” … \n */

void lerarquivo(){
    FILE *arquivo = fopen("a.txt", "r");

}

// ir usando o switch -> ler o arquivo com todas as notas (cada linha será uma nota separada) -> todos os números até o texto tem 
//um tamanho e posição determinados. por exemplo: os três primeiros caracteres (0-2) PRECISAM ser a etiqueta. os três caracteres após (3-6) 
//precisam ser as cores rgb. os quatro caracteres após (7-11) precisam ser as coordenadas x e y e larg/alt dos retângulos. o caractere 12 é a 
//primeira aspas dupla, e acho que faríamos uma verificação pra lermos o texto até chegar na última aspa

/* FUNÇÕES DE LEITURA DE ARQUIVO
 - fopen("filename.txt", "r") -> abre o arquivo para leitura. "w" para escrita e "a" para apendice (final do arquivo) e "rw" para leitura e escrita
    - FILE *ptr = fopen("filename.txt", "r"); // ponteiro do arquivo ira receber o endereço do arquivo aberto
    - recomendado verificar se ptr == NULL (erro ao abrir o arquivo)
- fscanf(ptr, "%d", &variavel) -> le um inteiro do arquivo e armazena na variavel passada por referencia (bom para achar numeros na string)
 - fgets(buffer, tamanho, ptr) -> le uma linha inteira do arquivo ate a quantidade definida ou encontrar um '\n'
    - fgets(buffer, 256, ptr); // le uma linha do arquivo e armazena no buffer (const char[256])
    - pode usar essa funcao como parametro do while() para cair fora quando nao tiver mais linhas

    - da para ler varios numeros antes de ler a string de texto
- fclose(ptr) -> fecha o arquivo

ptr = fopen("filename.txt", "r"); // o arquivo aberto
while (fscanf(ptr, "%d %d %d %d %d %d %d %d %d %d", &etiqueta, &r, &g, &b, &x, &y, &w, &h, &px, &py)){
    Nota entrada; //entrada é o nome de um struct que vai receber cada uma dessas informações
    entrada.etiqueta = etiqueta; 
    entrada.c.r = r;
    entrada.c.g = g;
    entrada.c.b = b;
    ...
    char buf[1024];
    fgets(buf, 1024, ptr); // le o texto depois de ler os numeros ate o \n
    // ler string de texto com fgets
    //tratar o texto dentro das aspas e descartar lixo (fazer nada com ele)

    // gravar a nota no vetor de notas
    registro.reg[lastNota] = entrada;
    lastNota++;
}


