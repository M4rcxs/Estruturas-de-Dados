#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

//1,5,6,10,17,19,21

int main(void){
    Arv* a = arv_criavazia();
    a = abb_insere(a, 10);
    a = abb_insere(a, 5);
    a = abb_insere(a, 6);
    a = abb_insere(a, 1);
    a = abb_insere(a, 19);
    a = abb_insere(a, 17);
    a = abb_insere(a, 21);
    abb_imprime(a);
    printf(" ");
    return 0;
}

void abb_imprime (Arv* a) {
    if (a != NULL) {
        abb_imprime(a->esq);
        printf("%d ",a->info);
        abb_imprime(a->dir);
    }
}
Arv* abb_busca (Arv* r, int v) {
    if (r == NULL)
        return NULL;
        else if (r->info > v)
        return abb_busca (r->esq, v);
        else if (r->info < v)
        return abb_busca (r->dir, v);
        else return r;
}

Arv* arv_criavazia (void) {
    return NULL;
}
Arv* abb_insere (Arv* a, int v) {
    if (a==NULL) {
        a = (Arv*)malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if (v < a->info){
        a->esq = abb_insere(a->esq,v);
    }else{ /* v >= a->info */
        a->dir = abb_insere(a->dir,v);
        return a;
    }
}

