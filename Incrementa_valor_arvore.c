#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

//1, 5, 6, 10, 17, 19, 21

int main(void) { // Arv* arv_cria (int c, Arv* sae, Arv* sad)
    Arv* a = arv_cria(1,
        arv_cria(2,
            arv_criavazia(),
            arv_cria(3, arv_criavazia(), arv_criavazia())
        ),
        arv_cria(4,
            arv_cria(5, arv_criavazia(), arv_criavazia()),
            arv_cria(6, arv_criavazia(), arv_criavazia())
        )
    );
    arv_imprime(a);
    printf("\n \n \n");
    //incrementar(a, 2);
    //arv_imprime(a);
    return 0;
}

Arv* arv_criavazia (void) {
    return NULL;
}

Arv* arv_cria (int c, Arv* sae, Arv* sad) {
    Arv* p = (Arv*) malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

Arv* arv_libera (Arv* a) {
    if (!arv_vazia(a)) {
        arv_libera(a->esq); /* libera sae */
        arv_libera(a->dir); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}

int arv_vazia (Arv* a) {
    return a==NULL;
}

void arv_imprime (Arv* a) {
    //printf("<");
    if (!arv_vazia(a)){
        printf("%d ", a->info); /* mostra raiz */
        arv_imprime(a->esq); /* mostra sae */
        arv_imprime(a->dir); /* mostra sad */
    }
    //printf(">");
}

void incrementar(Arv *a, int x) {
    if (a != NULL){
      a->info += x;
      incrementar(a->esq, x);
      incrementar(a->dir, x);      
   }
}

