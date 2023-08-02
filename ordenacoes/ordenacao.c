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

	if (a >= n){
		(*numComp)++;
		return 0;
	}

	if (x == v[n]){
		(*numComp)++;
		return x;
	}

	(*numComp)++;
	buscaSequencial(x, v, n - 1, numComp);
}

void buscaBinaria(int x, int *v, int a, int n, int *numComp)
{
	int m = 0; /*Determina o meio do vetor. */

	if (a > n){
		return;
	}

	m = ((a + n) / 2);

	if (x == v[m]){
		(*numComp)++;
		return;
	}

	if(x < v[m]){
		(*numComp)++;
		return buscaBinaria(x, v, a,  m - 1, numComp);
	}

	(*numComp)++;
	return buscaBinaria(x, v, m + 1, n, numComp);
}

/*Esta função vai servir como auxiliar de várias outras. */
void Troca (int *v, int a, int b)
{
	int aux;

	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

/*Esta função vai servir como auxiliar do algoritmo insertionSort. */
int Insere (int *v, int a, int b)
{
	int numComp = 0;
	int x = buscaSequencial(v[b], v, b - 1, &numComp);
	int i = b;

	while (i > x + 1){
		Troca(v, i, i - 1);
		i++;
	}

	return numComp;
}

int insertionSort (int *v, int n, int *numComp)
{
	int a = 0; 

	if (a > b){
		(*numComp)++;
		return 0;
	}

	insertionSort(v, n - 1, numComp);
	Insere(v, a, b);

	return 1;
}
