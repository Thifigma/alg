#include <time.h>

#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR_NOME 50
#define MAX_TAM 100000
#define MAX 64
#define MIN 10


/* Retorna o nome. */
void getNome(char nome[]);

/* Retorna o GRR. */
unsigned int getGRR();

/* Funcao auxiliar, troca dois inteiros em um vetor V. */
void troca (int *v, int a, int b);

/* Realiza o processo de inserção em um vetor. */
void insere (int *v, int n);

/* Retorna o conteudo de menor valor de um vetor V. */
int minimo(int *v, int n);

/* Inicia o vetor com valores aleatorios. */
void iniciaVetor (int *v, int n);

/* Buscas. */

/* Percorre o vetor recursivamente ate encontrar o valor x, caso não encontre é encerrado. */
int buscaSequencial(int x, int *v, int n);

/* Separa o vetor em duas metades, e compara o valor x com a metade a esquerda e a direita. 
 * caso o valor da direita seja maior que x, então repetira o processo no lado esquerdo 
 * e vise versa. */
void buscaBinaria(int x, int *v, int a, int n);

/* Ordenações. */

/* Faz uma troca sequencial com o valor maior subsequente. */ 
void insertionSort(int *v, int n); 

/* Seleciona o menor elemento do vetor e coloca na sua posição inicial 
 * até que o vetor fique ordenado. */
void selectionSort(int *v, int n);

/* Divide o vetor ate um tamanho trivial*/
int mergeSort(); 

/* Mescla os vetores divididos no merge*/
int Intercala ();

/* Utiliza um pivô, onde todos a esquerda serão menores e a direita maiores, 
 * Repete o processo recursivamente. */
int quickSort(); 

/* Realiza o processo de reorganização dos sub-vetores a partir do pivô. */
int Particiona ();

/* Ordena uma árvore binária completa. */
int heapSort();

/* Nó raiz ou Pai. */
int Pai (int i);

/* Filho da esquerda de i, (2*i). */
int Esquerda (int i);

/* Filho da direita de i, (2*i+1). */
int Direita (int i);

/* Compara o nó raiz com os nós filhos da arvore binaria e se necessário realiza a troca.
 * O nó com o maior valor ficara sempre na raiz.*/
int max_heapify ();

/* Aplica o max-heapfy para todos os nós da árvore*/
int build_max_heap ();

#endif // ORDENACAO_H_
