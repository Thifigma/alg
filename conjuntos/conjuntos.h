
#define MAXTAM 9

/*Inicia um conjunto vazio inciado com -1. */
void iniciaVazio(int *conjunto);i

/*Retorna o tamanho do conjunto*/
int tamConjunto(int conjunto);

/*Mostra todos os conteudos do conjunto fornecido.
 *Pode ser usada somente após ser iniciado com o vazio. */
void mostraConjunto(int conjunto);

/*Verifica se um dado conjunto é vazio. 
 *O vazio é definido como -1.
 *Pode ser usada somente quando iniciada com o vazio.*/
int verificaVazio(int conjunto);

/*Cria um conjunto, onde os elementos serão preenchidos com inteiros aleatorios.'
 *Tam será fornecido pelo usuário e tera seu limite vinculado a macro MAXTAM.*/
int criaConjunto(int conjunto, int tam);

/*"retorna" a uniao de dois conjuntos, ou seja, verifica a possibilidade 
 * de uniao entre os dois conjuntos e caso seja possivel a realiza.
 *
 *A uniao entre dois conjuntos onde o tamanho sera maior que 10 
 * pode ser valida?*/
int uniao(int conjunto, int conjunto1);

/*Verifica a possibilidade de realizar a interseccao entre dois conjuntos 
 * fornecidos*/
int intersec(int conjunto, int conjunto1);


