typedef struct lista Lista;

/* Cria uma lista vazia.*/
Lista * lst_cria();
/* Testa se uma lista é vazia.*/
int lst_vazia(Lista * l);
/* Insere um elemento no início da lista.*/
Lista * lst_insere(Lista * l, int info);
/* Busca um elemento em uma lista.*/
Lista * lst_busca(Lista * l, int info);
/* Imprime uma lista.*/
void lst_imprime(Lista * l);
/* Remove um elemento de uma lista.*/
Lista * lst_remove(Lista * l, int info);
/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista * l);
/* Insere um elemento ordenado na lista. */
Lista * lst_insere_ordenado(Lista * l, int info);
/* Imprime uma lista recursivamente.*/
void lst_imprime_rec(Lista * l);
/* Imprime uma lista invertida recursivamente.*/
void lst_imprime_invertida_rec(Lista * l);
/* Remove um elemento de uma lista recursivamente.*/
Lista * lst_remove_rec(Lista * l, int info);
/* Libera o espaço alocado por uma lista.*/
void lst_libera_rec(Lista * l);
/* Verifica se duas listas são iguais recursivamente. */
int lst_igual_rec(Lista * l1, Lista * l2);
/* Comprimento da lista. */
int comprimento(Lista * l);
/* Comprimento da lista recursivamente. */
int comprimento_rec(Lista * l);
/* Numero de elementos da lista maiores que n. */
int maiores(Lista * l, int n);
/* Numero de elementos da lista maiores que n recursivamente. */
int maiores_rec(Lista * l, int n);
/* Soma os valores de uma lista. */
int soma(Lista * l);
/* Soma os valores de uma lista recursivamente. */
int soma_rec(Lista * l);
/* Verifica se um numero qualquer é primo. */
int primo(int n);
/* Numero de nós primos de uma lista. */
int primos(Lista * l);
/* Numero de nós primos de uma lista recursivamente. */
int primos_rec(Lista * l);
