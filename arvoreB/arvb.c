#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

struct arv {
	int info;
	ArvB * esq;
	ArvB * dir;
};

/*Fun��o que cria uma �rvore Bin�ria Vazia.*/
ArvB * arvb_cria_vazia(void) {
	return NULL;
}

/*Fun��o que cria um n� em uma �rvore Bin�ria.*/
ArvB * arvb_cria_no(int c, ArvB * sae, ArvB * sad) {
	ArvB * a = (ArvB * )malloc(sizeof(ArvB));
	a->info = c;
	a->esq = sae;
	a->dir = sad;
	return a;
}

/*Testa se uma �rvore Bin�ria � vazia.*/
int arvb_vazia(ArvB * a) {
	return a == NULL;
}

/*Fun��o que imprime os elementos de uma �rvore Bin�ria.*/
void arvb_imprime(ArvB * a) {
	if(!arvb_vazia(a)) {
		arvb_imprime(a->esq);
		printf("%d ", a->info);
		arvb_imprime(a->dir);
	}
}

/*Fun��o que determina se um inteiro pertence � �rvore.*/
int arvb_pertence(ArvB * a, int c) {
	if(arvb_vazia(a))
		return 0;
	else
		return a->info == c || arvb_pertence(a->esq, c)
			   || arvb_pertence(a->dir, c);
}

/*Libera o espa�o alocado para uma �rvore Bin�ria.*/
void arvb_libera(ArvB * a) {
	if(!arvb_vazia(a)) {
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
	}
}

/*Fun��o que retorna a altura da �rvore*/
int arvb_altura(ArvB * a) {
	if(arvb_vazia(a))
		return -1;
	else {
		int hSAE = arvb_altura(a->esq);
		int hSAD = arvb_altura(a->dir);
		if(hSAE > hSAD)
			return 1 + hSAE;
		else
			return 1 + hSAD;
	}
}

ArvB * arvb_busca(ArvB * a, int c) {
	if(arvb_vazia(a))
		return NULL;
	else if(a->info < c)
		return arvb_busca(a->dir, c);
	else if(a->info > c)
		return arvb_busca(a->esq, c);
	else //(a->info == c)
		return a;
}

ArvB * arvb_insere(ArvB * a, int c) {
	if(arvb_vazia(a)) {
		a = (ArvB * )malloc(sizeof(ArvB));
		a->info = c;
		a->esq = NULL;
		a->dir = NULL;
	} else if(a->info > c)
		a->esq = arvb_insere(a->esq, c);
	else if (a->info < c)
		a->dir = arvb_insere(a->dir, c);
	else
		printf("\nElemento Ja Pertence a Arvore");
	return a;
}

ArvB * arvb_remove(ArvB * a, int c) {
	if(!arvb_vazia(a)) {
		if(a->info > c)
			a->esq = arvb_remove(a->esq, c);
		else if (a->info < c)
			a->dir = arvb_remove(a->dir, c);
		else {
			ArvB * t;
			if (a->esq == NULL) {
				t = a;
				a = a->dir;
				free(t);
			} else if (a->dir == NULL) {
				t = a;
				a = a->esq;
				free(t);
			} else {
				t = a->esq;
				while(t->dir != NULL)
					t = t->dir;
				a->info = t->info;
				t->info = c;
				a->esq = arvb_remove(a->esq, c);
			}
		}
	}
	return a;
}

int folhas(ArvB * a) {
	if(arvb_vazia(a)) {
		return 0;
	} else {
		if(arvb_vazia(a->esq) && arvb_vazia(a->dir)) {
			return 1;
		} else {
			return folhas(a->esq) + folhas(a->dir);
		}
	}
}

int um_filho(ArvB * a) {
	if(arvb_vazia(a)) {
		return 0;
	}
	if((a->esq != NULL && a->dir == NULL) || (a->esq == NULL && a->dir != NULL)) {
		return 1 + um_filho(a->esq) + um_filho(a->dir);
	}
	return um_filho(a->esq) + um_filho(a->dir);
}

int VerifPrimo(int val) { //Verifica se � primo maior q 3
	int i;
	if(val % 2 != 0 && val > 3) {
		for(i = 3; i < val; i += 2) {
			if(val % i == 0) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

int primos3(ArvB * a) {
	if(arvb_vazia(a)) {
		return 0;
	} else {
		if(VerifPrimo(a->info)) {
			return 1 + primos3(a->esq) + primos3(a->dir);
		}
		return primos3(a->esq) + primos3(a->dir);
	}
}

ArvB * removeRaiz(ArvB * r) {
	ArvB * p, * q;
	if (r->esq == NULL) {
		q = r->dir;
		free( r);
		return q;
	}
	p = r;
	q = r->esq;
	while (q->dir != NULL) {
		p = q;
		q = q->dir;
	}
	if (p != r) {
		p->dir = q->esq;
		q->esq = r->esq;
	}
	q->dir = r->dir;
	free( r);
	return q;
}

void transfere(ArvB * a, ArvB * b) { //N�o zera o vetor a, mas transfere todos os n�s
	if(arvb_vazia(a)) {
		return;
	} else {
		b = arvb_insere(b, a->info);
		a = removeRaiz(a);
		transfere(a, b);
	}
}

ArvB * transfere2(ArvB * a, ArvB * b) { //Transfere todos os n�s e deixa o a vazio
	if(arvb_vazia(a)) {
		return;
	} else {
		b = arvb_insere(b, a->info);
		a = removeRaiz(a);
		transfere(a, b);
	}
	return NULL;
}

int iguais(ArvB * a, ArvB * b) {
	if(arvb_vazia(a) && arvb_vazia(b)) {
		return 1;
	} else {
		if(a->info==b->info) {
			return 1 && iguais(a->esq,b->esq)&&iguais(a->dir,b->dir);
		} else {
			return 0;
		}
	}
}
