#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

struct lista_dupl {
	int info;
	ListaDupl * ant;
	ListaDupl * prox;
};

/* Cria uma lista dupl. encadeada vazia.*/
ListaDupl * lst_dupl_cria(){
	return NULL;
}
/* Testa se uma lista dupl. encadeada é vazia.*/
int lst_dupl_vazia(ListaDupl * l){
	return (l==NULL);
}
/* Insere um elemento no início da lista dupl. encadeada.*/
ListaDupl * lst_dupl_insere(ListaDupl * l, int info) {
	ListaDupl * ln = (ListaDupl * )malloc(sizeof(ListaDupl));
	ln->info = info;
	ln->prox = l;
	ln->ant = NULL;
	if(l != NULL)
		l->ant = ln;
	return ln;
}
/* Imprime uma lista dupl. encadeada.*/
void lst_dupl_imprime(ListaDupl * l){
	ListaDupl * lAux = l;
	while(lAux != NULL) {
		printf("Info = %d\n", lAux->info);
		lAux = lAux->prox;
	}
}
/* Busca um elemento em uma lista dupl. encadeada.*/
ListaDupl * lst_dupl_busca(ListaDupl * l, int info) {
	ListaDupl * lAux = l;
	while(lAux != NULL) {
		if(lAux->info == info)
			return lAux;
		lAux = lAux->prox;
	}
	return NULL;
}
ListaDupl * lst_dupl_busca2(ListaDupl * l, int info) {
	ListaDupl * lAux = l;
	if(l == NULL)
		return l;
	while(lAux != NULL) {
		if(lAux->info == info)
			return lAux;
		lAux = lAux->prox;
	}
	lAux = l->ant;
	while(lAux != NULL) {
		if(lAux->info == info)
			return lAux;
		lAux = lAux->ant;
	}
	return NULL;
}
/* Remove um elemento de uma lista dupl. encadeada.*/
ListaDupl * lst_dupl_remove(ListaDupl * l, int info) {
	ListaDupl * lAux = lst_dupl_busca(l, info);
// Não achou o elemento
	if(lAux == NULL)
		return l;
//Se é o primeiro
	if(lAux == l)
		l = lAux->prox;
	else
		lAux->ant->prox = lAux->prox;
//Se o próximo não é vazio
	if(lAux->prox != NULL)
		lAux->prox->ant = lAux->ant;
	free(lAux);
	return l;
}
/* Libera o espaço alocado por uma lista dupl. encadeada.*/
void lst_dupl_libera(ListaDupl * l){
	ListaDupl * lProx;
	while(l != NULL) {
		lProx = l->prox;
		free(l);
		l = lProx;
	}
}
