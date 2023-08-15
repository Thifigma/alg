#include "ordenacao.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*adicionada terminação manual para caso de overflow*/
void getNome(char nome[]){
	strncpy(nome, "Thiago Figueiredo Marcos", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';
}

unsigned int getGRR(){
	return 20205982;
}

void iniciaVetor (int *v, int n)
{
	for(int i = 0; i < n; i++){
		v[i] = rand() %100;
	}
}

int buscaSequencial(int x, int *v, int n, int *numComp)
{
	int a = 0; /*Determina o valor inicial do vetor. */

	if (a >= n)
		return 0;

	if (x == v[n]) {
		(*numComp)++;
		return x;
	}

	(*numComp)++;
	buscaSequencial(x, v, n - 1, numComp);
}

void buscaBinaria(int x, int *v, int a, int n, int *numComp)
{
	int m = 0; /*Determina o meio do vetor. */

	if (a > n)
		return;

	m = ((a + n) / 2);

	if (x == v[m]) {
		(*numComp)++;
		return;
	}

	if(x < v[m]) {
		(*numComp)++;
		return buscaBinaria(x, v, a,  m - 1, numComp);
	}

	(*numComp)++;
	return buscaBinaria(x, v, m + 1, n, numComp);
}

/*Esta função vai servir como auxiliar de várias outras. */
void troca (int *v, int a, int b)
{
	int aux;

	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

/*Esta função vai servir como auxiliar do algoritmo insertionSort. 
 * Pode ser inserido como VOID, verificar... */
void insere (int *v, int b, int *numComp)
{
	int x = buscaSequencial(v[b], v, b - 1, numComp);
	int i = b;

	while (i > x + 1) {
		troca(v, i, i - 1);
		(*numComp)++;
		i--;
	}
	
	return;
}
int minimo (int *v, int n, int *numComp)
{
	int a = 0;
	int m = 0;
	
	if (n == a)
		return a;

	(*numComp)++;
	m = minimo(v, n - 1, numComp);
	
	if (v[n] < v[m]) {
		(*numComp)++;
		m = n;
	}

	return m;
}
void insertionSort (int *v, int n, int *numComp)
{
	int a = 0; 

	if (a >= n) {
		(*numComp)++;
		return;
	}

	(*numComp)++;	
	insertionSort(v, n - 1, numComp);
	insere(v, n, numComp);
}

void selectionSort (int *v, int n, int *numComp)
{
	int a = 0;
	if (n <= a){
		return;
	}

	troca(v, n, minimo(v, n, numComp));
	selectionSort(v, n - 1, numComp);
}
