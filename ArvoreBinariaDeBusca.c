#include<stdio.h>
#include <stdlib.h>
#include "arvore_PO.h"

NoArv* arv_cria_vazia() {
    return NULL;
}
NoArv* arv_cria(int x, NoArv* sae, NoArv* sad) {
    NoArv* no = malloc(sizeof(NoArv));
    no->info = x;
    no->esq = sae;
    no->dir = sad;
    
    return no;
}
void abb_imprime(NoArv* a){
	if(a != NULL){
		abb_imprime(a->esq);
		printf("%d\n", a->info);
		abb_imprime(a->dir);
	}
}
NoArv* maior_valor(NoArv* a){ //Questão 2
	NoArv* temp_esq;
	NoArv* temp_dir;
	NoArv* maior = a;
	if(a == NULL){
		return NULL;
	}
	temp_esq = maior_valor(a->esq);
	temp_dir = maior_valor(a->dir);
	if(temp_esq != NULL){
		if(temp_esq->info > maior->info){
			maior = temp_esq;
		}
	}
        if(temp_dir != NULL){
                if(temp_dir->info > maior->info){
                        maior = temp_dir;
                }
	}
	return maior;
}

int main(void){

NoArv* arv;
    
    arv = arv_cria(17,
                        arv_cria(39, 
                                    arv_cria(-80, 
                                            arv_cria_vazia(), 
                                            arv_cria_vazia()),
                                    arv_cria(-21, 
                                            arv_cria_vazia(), 
                                            arv_cria(-95, 
                                                    arv_cria_vazia(), 
                                                    arv_cria_vazia()))),
                        arv_cria(-45, 
                                    arv_cria(-87, 
                                            arv_cria(-96, 
                                                    arv_cria_vazia(), 
                                                    arv_cria_vazia()), 
                                            arv_cria(5, 
                                                    arv_cria_vazia(), 
                                                    arv_cria_vazia())), 
                                    arv_cria(66, 
                                            arv_cria(10, 
                                                    arv_cria_vazia(), 
                                                    arv_cria_vazia()), 
                                            arv_cria(-42, 
                                                    arv_cria_vazia(), 
                                                    arv_cria_vazia()))));
	abb_imprime(arv);
	printf("\n###\n");
	printf("%d", maior_valor(arv)->info);
	return 0;
}