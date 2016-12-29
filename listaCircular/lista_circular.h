typedef struct lista_circ ListaCirc;

/* Cria uma lista circular vazia.*/
ListaCirc * lst_circ_cria();
/* Testa se uma lista circular é vazia.*/
int lst_circ_vazia(ListaCirc * l);
/* Insere um elemento em uma lista circular.*/
ListaCirc * lst_circ_insere(ListaCirc * l, int info);
/* Busca um elemento em uma lista circular.*/
ListaCirc * lst_circ_busca(ListaCirc * l, int info);
/* Imprime uma lista circular.*/
void lst_circ_imprime(ListaCirc * l);
/* Remove um elemento de uma lista circular.*/
ListaCirc * lst_circ_remove(ListaCirc * l, int info);
/* Libera o espaço alocado por uma lista circular .*/
void lst_circ_libera(ListaCirc * l);
