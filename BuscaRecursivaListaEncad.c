#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elemento {
	int info; 
	struct elemento* prox; 
}; typedef struct elemento Elem;

Elem* lista_cria (void){
	return NULL;
}
Elem* lista_insere (Elem* lista, int x){
	Elem* novo = (Elem*) malloc(sizeof(Elem));
	novo->info = x;
	novo->prox = lista;
	return novo;
}
void lista_imprime (Elem* lista){
	Elem* p;
	for(p = lista; p != NULL; p = p->prox)
	printf("info = %d\n", p->info);
}
int lista_vazia (Elem* lista){
	return (lista == NULL);
}
/*Elem* busca (Elem* lista, int v){ 
	Elem* p;
	for(p=lista; p!=NULL; p = p->prox){
		if(p->info == v){
			return p;
		}
	}
	return NULL; 
}*/

Elem* busca_rec(Elem* lst, int x){ //Questão 1
	if(lst == NULL){
		return NULL;
	}
	if(lst->info == x){
		return lst;
	}
	return busca_rec(lst->prox, x);
}

int main(void){
	Elem* lst; 
	lst = lista_cria(); 
	lst = lista_insere(lst,17); 
	lst = lista_insere(lst,28); 
	lst = lista_insere(lst,39); 
	lst = lista_insere(lst,40); 
	lst = lista_insere(lst,50);
	lista_imprime(lst); 
	printf("##########\n");
	lista_imprime(busca_rec(lst,39));
	return 0;
}