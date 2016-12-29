#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

struct lista_circ {
	int info;
	ListaCirc * prox;
};

/* Cria uma lista circular vazia.*/
ListaCirc * lst_circ_cria() {
	return NULL;
}
/* Testa se uma lista circular é vazia.*/
int lst_circ_vazia(ListaCirc * l) {
	return (l == NULL);
}
/* Insere um elemento em uma lista circular.*/
ListaCirc * lst_circ_insere(ListaCirc * l, int info) {
	ListaCirc * ln = (ListaCirc * )malloc(sizeof(ListaCirc));
	ln->info = info;
	if(l == NULL)
		ln->prox = ln;
	else {
		ln->prox = l->prox;
		l->prox = ln;
	}
	return ln;
}
/* Busca um elemento em uma lista circular.*/
ListaCirc * lst_circ_busca(ListaCirc * l, int info) {
	ListaCirc * lAux = l;
	do {
		if(lAux->info == info)
			return lAux;
		lAux = lAux->prox;
	} while(l != lAux);
	return NULL;
}
/* Imprime uma lista circular.*/
void lst_circ_imprime(ListaCirc * l) {
	if(l != NULL) {
		ListaCirc * lAux = l;
		printf("Lista de Elementos \n");
		do {
			printf("Info = %d\n", lAux->info);
			lAux = lAux->prox;
		} while(l != lAux);
	}
}
/* Remove um elemento de uma lista circular.*/
ListaCirc * lst_circ_remove(ListaCirc * l, int info) {
	ListaCirc * lPrim = l;
	if(l != NULL) {
		ListaCirc * lAux = l->prox;
		if(l->info == info) {
			free(l);
			return lAux;
		} else {
			ListaCirc * lAnt = l;
			do {
				if(lAux->info == info) {
					lAnt->prox = lAux->prox;
					free(lAux);
					break;
				} else {
					lAnt = lAux;
					lAux = lAux->prox;
				}
			} while(lAux != lPrim);
		}
	}
	return l;
}
/* Libera o espaço alocado por uma lista circular .*/
void lst_circ_libera(ListaCirc * l) {
	ListaCirc * lProx;
	ListaCirc * lPrim=l;
	do{
		lProx = l->prox;
		free(l);
		l = lProx;
	}while(l != lPrim); 
}
