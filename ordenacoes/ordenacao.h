/*
 *A ideia geral do programa de ordenação é fazer uma análise através da biblioteca TIME 
 *para determinar o tempo que cada algoritmo de ordenação leva. 
  *O objetivo é compreender e verificar qual algoritmo possui a melhor 
 *eficiência em relação aos clocks por segundo (clocks per sec).
*/

#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR_NOME 50
#define MAX_TAM 100

/*Retorna o nome */
void getNome(char nome[]);

/*Retorna o GRR */
unsigned int getGRR();

/*Funcao auxiliar, troca dois inteiros em um vetor V*/
void Troca (int *v, int a, int b);

/*Insere um valor I em um vetor V*/
void Insere (int *v, int a, int b);

/*Retorna o minimo de um vetor V*/
int Minimo(int *v, int a, int b);

/*Recebe um vetor como entrada e retorna um vetor iniciado com valores aleatorios*/
void inicia_vetor (int *v, int n);

/* Realiza uma busca sequencial recursiva de um determinado valor X
 * O ponteiro numComp, realiza a contagem do numero de comparações */
void buscaSequencial(int x, int *v, int n, int *numComp);

/* Realiza uma busca bianria recursiva de um determinado valor X
 * O ponteiro numComp, realiza a contagem do numero de comparações*/
void buscaBinaria(int x, int *v, int n, int *numComp);

/* Algoritmo que organiza os dados contidos no vetor de forma que
 * faz uma troca sequencial com o valor maior subsequente 
 * e insere na sua posicao correta*/
int insertionSort(); 

/* Algoritmo que seleciona o menor elemento e coloca na sua posição inicial 
 * Até que o vetor fique ordenado. */
int selectionSort();

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