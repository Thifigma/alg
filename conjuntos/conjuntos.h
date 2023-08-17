
#define MAXTAM 10
#define MIN 13
#define MAX 42

/*Inicia um conjunto vazio inciado com -1. */
void iniciaVazio(int *conjunto);

/*Retorna o tamanho do conjunto*/
int tamConjunto(int *conjunto);

/*Mostra todos os conteudos do conjunto fornecido.
 *Pode ser usada somente após ser iniciado com o vazio. */
void mostraConjunto(int *conjunto);

/*Verifica se um dado conjunto é vazio. 
 *Pode ser usada somente apos ter sido iniciado o vazio.
 *A função retorna 1 caso esteja vazio e 0 caso contrario.*/
int vazio(int conjunto[]);

/*Cria um conjunto, onde os elementos serão preenchidos com inteiros 
 * pseudoaleatorios.
 *Tam será fornecido pelo usuário e tera seu limite vinculado a macro MAXTAM.*/
void criaConjunto(int *conjunto);

/*Une dois conjuntos no conjunto uniao. */
void une(int *uniao, int *c1, int *c2);

/*"retorna" a uniao de dois conjuntos, ou seja, verifica a possibilidade 
 * de uniao entre os dois conjuntos e caso seja possivel a realiza.
 *
 *A uniao entre dois conjuntos onde o tamanho sera maior que 10 
 * pode ser valida? Considerando que seja valido 
 * 
 * Os tamanhos dos vetores serão somados e sera o tamanho do novo vetor. 
 * A função vai retornar 1 caso ocorra a união e 0 caso contrario. */
int uniao(int *c1, int *c2);

/*Função complementar para o selection sort. 
 * Troca os conteudos fornecidos de posição no vetor. */
void troca(int *v, int a, int b);

/*Retorna o menor valor de um determinado vetor V. */
int minimo(int *v, int n);

/*Ordena o vetor.*/
void selectionSort(int *v, int n);

/*Verifica a possibilidade de realizar a interseccao entre dois conjuntos 
 * fornecidos*/
int intersec(int conjunto, int conjunto1);


