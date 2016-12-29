typedef struct arv ArvB;

/*Fun��o que cria uma �rvore Bin�ria Vazia.*/
ArvB * arvb_cria_vazia(void);
/*Fun��o que cria um n� em uma �rvore Bin�ria.*/
ArvB * arvb_cria_no(int c, ArvB * sae, ArvB * sad);
/*Testa se uma �rvore Bin�ria � vazia.*/
int arvb_vazia(ArvB * a);
/*Fun��o que imprime os elementos de uma �rvore Bin�ria.*/
void arvb_imprime(ArvB * a);
/*Fun��o que determina se um caractere pertence � �rvore.*/
int arvb_pertence(ArvB * a, int c);
/*Libera o espa�o alocado para uma �rvore Bin�ria.*/
void arvb_libera(ArvB * a);
/*Fun��o que retorna a altura da �rvore*/
int arvb_altura(ArvB * a);
/*Fun��o que busca a sub-�rvore que cont�m um inteiro.*/
ArvB * arvb_busca(ArvB * a, int c);
/*Fun��o que insere um inteiro em uma �rvore.*/
ArvB * arvb_insere(ArvB * a, int c);
/*Fun��o que remove um inteiro em uma �rvore.*/
ArvB * arvb_remove(ArvB * a, int c);
/*Fu��o que retorna o numero de folhas*/
int folhas(ArvB * a);
/*Fun��o que retorna o numero de n�s que possuem apenas um filho*/
int um_filho(ArvB * a);
int primos3(ArvB * a);
void transfere(ArvB * a, ArvB * b);
ArvB * transfere2(ArvB * a, ArvB * b);
int iguais(ArvB * a, ArvB * b);
