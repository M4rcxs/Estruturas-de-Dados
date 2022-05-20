#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* fila_cria (void){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->n = 0; /* inicializa a fila vazia */
    f->ini = 0; /* escolhe uma posição inicial */
    return f;
}
void fila_insere (Fila* f, float v){
    int fim;
    if (f->n == N) { /* fila cheia */
    printf("CAPACITADE ESOTOROU!");
    exit(1); /* aborta o programa */
    }
    /* insere elemento na próxima posição livre */
    fim = (f->ini + f->n) % N;
    f->vet[fim] = v;
    f->n++;
}
int fila_vazia (Fila* f){
    return (f->n == 0);
}
float fila_retira (Fila* f){
    float v;
    if (fila_vazia(f)) { /* fila vazia */
        printf("fila vazia");
        exit(1); /* aborta o programa */
    }
    /* retira elemento do início*/
    v = f->vet[f->ini];
    f->ini = (f->ini + 1) % N;
    f->n--;
    return v;
}
void fila_libera (Fila* f){
    free(f);
}

int fila_soma(Fila *f){ //4
    if(fila_vazia(f)){
        fila_libera(f);
        return 0; 
    }
    return fila_retira(f) + fila_soma(f);
}
int main(void){
    int f;
    f = fila_cria();
    fila_insere(f,5);
    fila_insere(f,5);
    fila_insere(f,1);
    fila_insere(f,5);
    fila_insere(f,5);
    fila_insere(f,5);
    fila_insere(f,5);
    fila_insere(f,5);
    printf("%d", fila_soma(f));
    return 0;
}