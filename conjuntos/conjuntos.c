#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conjuntos.h"

#define MAX 42
#define MIN 15
	

/*O laço garante que o usuario digitara um valor dentro dos limites.
 *A função garante que no final do vetor tem um vazio (-1).  */
void iniciaVazio(int *conjunto)
{
	conjunto[MAXTAM] = -1;

	for (int i = 0; i < MAXTAM; i++) {
		conjunto[i] = -1;
	}
}

/*Quando se encontra no conteudo do vetor o valor (-1), entende-se que
 * dali em diante o vetor encontra-se vazio.  
 *Como dito anteriormente na função acima o valor -1 
 * é posto na posição final do conjunto*/
int tamConjunto(int *conjunto)
{
	int tamanho = 0;

	for (int i = 0; i < MAXTAM; i++) {
		if (conjunto[i] == -1) {
			return tamanho;
		}

		tamanho++;
	}

	return tamanho;
}

int vazio(int conjunto[])
{
	int tam = tamConjunto(conjunto);

	if (!(tam)) {
		return 1;
	}

	return 0;
}

/*Ao mostrar o conjunto a função vai de 0 a 9 (10) posições. 
 * Exclui-se a posição 10 do conjunto, pois esta esta reservada para o -1. */
void mostraConjunto (int *conjunto)
{
	int tam = tamConjunto(conjunto);

	if (vazio(conjunto)) {
		printf ("Conjunto vazio! \n");
		return;
	}

	for(int i = 0; i < tam; i++) {
		printf ("%d ", conjunto[i]);
	}

	printf ("\n");
}

void criaConjunto(int *conjunto)
{
	int tam = 0;
    	srand(time(NULL));

	scanf ("%d", &tam);

	while (tam > MAXTAM) {
		scanf ("%d", &tam);
	}

	for (int i = 0; i < tam; i++) {
		conjunto[i] = MIN + rand() % (MAX - MIN + 1);
	}
}


void troca (int *v, int a, int b)
{
	int aux;

	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

int minimo (int *v, int n)
{
	int a = 0;
	int m = 0;

	if (n == a) { 
		return a;
	}

	m = minimo(v, n - 1);

	if (v[n] < v[m]) {
		m = n;
	}

	return m;
}

void selectionSort (int *v, int n)
{
	int a = 0; /*Inicio do vetor. */

	if (n <= a)
		return;

	troca(v, n, minimo(v, n));
	selectionSort(v, n - 1);
}

void une(int *uniao, int *c1, int *c2)
{
	int tc1 = tamConjunto(c1);
	int tc2 = tamConjunto(c2);

	selectionSort(c1, tc1);
	selectionSort(c2, tc2);

    int i = 0; /*c1*/
    int j = 0; /*c2*/
    int k = 0; /*tam*/

	while ( i < tc1 || j < tc2) {
		if (i < tc1 && (j >= tc2 || c1[i] <= c2[j])) {
			uniao[k] = c1[i];
			i++;
		} else {
			uniao[k] = c2[j];
			j++;
		}

		k++;
	}
}

int uniao(int *c1, int *c2)
{
	if ( (vazio(c1)) && (vazio(c1)) ) {
		printf ("A uniao eh vazia! \n");
		return 0;
	}
	
	int tam = tamConjunto(c1) + tamConjunto(c2);
	int uniao[tam];

	une(uniao, c1, c2);
	
	for (int i = 0; i < tam; i++) {
		printf ("%d ", uniao[i]);
	}
	printf ("\n"); 

	// mostraConjunto(uniao); Como arrumar este erro? 

	return 1;
}



