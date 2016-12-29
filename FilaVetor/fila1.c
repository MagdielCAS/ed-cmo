#include <stdio.h>
#include <stdlib.h>
#include "fila1.h"
#define N 3

struct fila {
	int n;
	int ini;
	int v[N];
};

/*Função que cria uma Fila.*/
Fila * fila_cria(void) {
	Fila * f = (Fila * )malloc(sizeof(Fila));
	if(f == NULL) {
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->n = 0;
	f->ini = 0;
	return f;
}
/*Função que adiciona um elemento em uma Fila.*/
void fila_insere(Fila * f, int info) {
	int fim;
	if(f->n == N) {
		printf("Capacidade da Fila Estorou!!!\n");
		exit(1);
	}
	fim = (f->ini + f->n) % N;
	f->v[fim] = info;
	f->n++;
}
/*Testa se uma fila é vazia.*/
int fila_vazia(Fila * f) {
	return f->n == 0;
}
/*Função que remove um elemento de uma fila.*/
int fila_remove(Fila * f) {
	int a;
	if(fila_vazia(f)) {
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->v[f->ini];
	f->ini = (f->ini + 1) % N;
	f->n--;
	return a;
}
/*Função que imprime os elementos de uma Fila.*/
void fila_imprime(Fila * f) {
	int i;
	int k;
	for(i = 0; i < f->n; i++) {
		k = (f->ini + i) % N;
		printf("%d\n", f->v[k]);
	}
}
/*Libera o espaço alocado para uma Fila.*/
void fila_libera(Fila * f) {
	free(f);
}
/*Numero de elementos maiores que n*/
int qtd_maior(Fila * f, int n) {
	int i;
	int k;
	int cont;
	cont=0;
	for(i = 0; i < f->n; i++) {
		k = (f->ini + i) % N;
		if(f->v[k]>n){
			cont=cont+1;
		}
	}
	return cont;
}
/*Função que inverte a ordem dos elementos de uma fila.*/ 
void inverte(Fila* f){
	int i;
	int k;
	int v[N];
	for(i = 0; i < f->n; i++) {
		k = (f->ini + i) % N;
		v[i]=f->v[k];
	}
	for(i = 0; i < f->n; i++) {
		k = (f->ini + i) % N;
		f->v[k]=v[f->n-i-1];
	}
}
/*Retorna elementos pares de uma fila*/
int pares(Fila* f){
	int i;
	int k;
	int cont;
	cont=0;
	for(i = 0; i < f->n; i++) {
		k = (f->ini + i) % N;
		if(f->v[k]%2==0){
			cont=cont+1;
		}
	}
	return cont;
}