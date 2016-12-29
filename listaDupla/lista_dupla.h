typedef struct lista_dupl ListaDupl;

/* Cria uma lista dupl. encadeada vazia.*/
ListaDupl* lst_dupl_cria();
/* Testa se uma lista dupl. encadeada é vazia.*/
int lst_dupl_vazia(ListaDupl *l);
/* Insere um elemento no início da lista dupl. encadeada.*/
ListaDupl* lst_dupl_insere(ListaDupl *l, int info);
/* Imprime uma lista dupl. encadeada.*/
void lst_dupl_imprime(ListaDupl *l);
/* Busca um elemento em uma lista dupl. encadeada.*/
ListaDupl* lst_dupl_busca(ListaDupl *l, int info);
/* Remove um elemento de uma lista dupl. encadeada.*/
ListaDupl* lst_dupl_remove(ListaDupl *l, int info);
/* Libera o espaço alocado por uma lista dupl. encadeada.*/
void lst_dupl_libera(ListaDupl *l);