
#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR_NOME 50
#define MAX_TAM 100
#define MIN 15
#define MAX 97



/*Retorna o nome */
void getNome(char nome[]);

/*Retorna o GRR */
unsigned int getGRR();

/*Funcao auxiliar, troca dois inteiros em um vetor V*/
void troca (int *v, int a, int b);

/*Insere um valor (x) em um vetor (v)
 *Retorna o numero de comparações que foi realizada para inserir determinador. */
void insere (int *v, int n, int *numComp);

/*Retorna o minimo de um vetor V e 
 *calcula o numero de comparacoes no ponteiro fornecido */
int minimo(int *v, int n, int *numComp);

/*Recebe um vetor como entrada e retorna um vetor iniciado com valores aleatorios*/
void iniciaVetor (int *v, int n);

/* Realiza uma busca sequencial recursiva de um determinado valor X
 * O ponteiro numComp, realiza a contagem do numero de comparações 
 * Retorna o valor x caso encontre, caso contrario retorna 0 */
int buscaSequencial(int x, int *v, int n, int *numComp);

/* Realiza uma busca bianria recursiva de um determinado valor X
 * O ponteiro numComp, realiza a contagem do numero de comparações. */
void buscaBinaria(int x, int *v, int a, int n, int *numComp);

/* Algoritmo que organiza os dados contidos no vetor de forma que
 * faz uma troca sequencial com o valor maior subsequente 
 * e insere na sua posicao correta*/ 
int insertionSort(int *v, int n); 

/* Algoritmo que seleciona o menor elemento e coloca na sua posição inicial 
 * Até que o vetor fique ordenado. */
int selectionSort(int *v, int n);

/* Divide o vetor ate um tamanho trivial*/
int mergeSort(); 

/* Mescla os vetores divididos no merge*/
int Intercala ();

/* Algoritmo utiliza um pivô, onde todos a esquerda serão menores e a direita maiores, 
 * Repete o processo recursivamente e depois */
int quickSort(); 
/* Realiza o processo de reorganização do vetor a partir do pivô*/
int Particiona ();

/* Ordena uma árvore binária completa*/
int heapSort();

/* Nodo raiz ou Pai*/
int Pai (int i);

/* Filho da esquerda de i, (2*i) */
int Esquerda (int i);

/* Filho da direita de i, (2*i+1) */
int Direita (int i);

/* Compara o nó raiz com os nós filhos da arvore binaria e se necessário realiza a troca.
*  O nó com o maior valor ficara sempre na raiz.*/
int max_heapify ();

/* Aplica o max-heapfy para todos os nós da árvore*/
int build_max_heap ();

#endif // ORDENACAO_H_
