#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"

struct lista {
	int info;
	Lista * prox;
};

struct fila {
	Lista * ini;
	Lista * fim;
};

/*Função que cria uma Fila.*/
Fila * fila_cria(void) {
	Fila * f = (Fila * )malloc(sizeof(Fila));
	if(f == NULL) {
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->ini = NULL;
	f->fim = NULL;
	return f;
}
/*Função que adiciona um elemento em uma Fila.*/
void fila_insere(Fila * f, int info) {
	Lista * l = (Lista * )malloc(sizeof(Lista));
	if(l == NULL) {
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = NULL;
	if(!fila_vazia(f))
		f->fim->prox = l;
	else
		f->ini = l;
	f->fim = l;
}
/*Testa se uma Fila é vazia.*/
int fila_vazia(Fila * f) {
	return f->ini == NULL;
}
/*Função que remove um elemento de uma Fila.*/
int fila_remove(Fila * f) {
	Lista * l;
	int a;
	if(fila_vazia(f)) {
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->ini->info;
	l = f->ini;
	f->ini = f->ini->prox;
	free(l);
	if(fila_vazia(f))
		f->fim = NULL;
	return a;
}
/*Função que imprime os elementos de uma fila.*/
void fila_imprime(Fila * f) {
	Lista * lAux = f->ini;
	while(lAux != NULL) {
		printf("%d\n", lAux->info);
		lAux = lAux->prox;
	}
}
/*Libera o espaço alocado para uma fila.*/
void fila_libera(Fila * f) {
	Lista * l = f->ini;
	Lista * lAux;
	while(l != NULL) {
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(f);
}
/*Numero de elementos maiores que n*/
int qtd_maior(Fila * f, int n) {
	Lista * lAux = f->ini;
	int cont;
	cont = 0;
	while(lAux != NULL) {
		if(lAux->info > n) {
			cont++;
		}
		lAux = lAux->prox;
	}
	return cont;
}
/*Função que inverte a ordem dos elementos de uma fila.*/ 
void inverte(Fila* f){
	Lista * lAux = f->ini;
	Lista * temp;
	Lista * rev=NULL;
	while(lAux!=NULL){
		temp=lAux->prox;
		lAux->prox=rev;
		rev=lAux;
		lAux=temp;
	}
	f->ini=rev;
}
/*Retorna elementos pares de uma fila*/
int pares(Fila* f){
	Lista * lAux = f->ini;
	int cont;
	cont = 0;
	while(lAux != NULL) {
		if(lAux->info%2==0) {
			cont++;
		}
		lAux = lAux->prox;
	}
	return cont;
}