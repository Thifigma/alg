#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conjuntos.h"


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
 * dali em diante o vetor encontra-se vazio.  */
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

int uniao(int *c1, int *c2)
{
	if ( (vazio(c1)) && (vazio(c1)) ) {
		printf ("A uniao eh vazia! \n");
		return 0;
	}
	
	int tc1 = tamConjunto(c1);
	int tc2 = tamConjunto(c2);
	int tam = tc1 + tc2;
	int uniao[tam];

	for (int i = 0; i < tc1; i++) {
		uniao[i] = c1[i];
	}

	for (int i = 0; i < tc2; i++) {
		int indice = tc1;
		uniao[indice + i] = c2[i];
	}

	/*
	for (int i = 0; i < tam; i++) {
		printf ("%d ", uniao[i]);
	}
	printf ("\n"); 
	*/

	mostraConjunto(uniao);

	return 1;
}






