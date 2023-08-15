#include <stdio.h>
#include "ordenacao.h"


/*O laço garante que o usuario digitara um valor dentro dos limites.
 *A função também garante que ao percorrer todo o vetor sempre  */
void iniciaVazio(int *conjunto)
{
	int tam = 0;
	int[MAXTAM + 1] = -1; 

	scanf ("%d", &tam);
	
	while (tam > MAXTAM) {
		scanf ("%d", &tam);
	}

	for (int i = 0; i < tam; i++) {
		conjunto[i] = -1;
	}
}

/*Quando se encontra no conteudo do vetor o valor (-1), entende-se que
 * dali em diante o vetor encontra-se vazio.  */
int tamConjunto(int conjunto)
{
	int tamanho = 0;

	for (int i = 0; i < MAXTAM + 1; i++) {
		if (conjunto[i] == -1) {
			return tamanho;
		}
		
		tamanho++;
	}
}


/*Comentario?*/
void mostraConjunto (int conjunto)
{
	int tam = tamConjunto(conjunto);
	
	if (!(tam)){
		printf ("O conjunto fornecido eh vazio. \n");
		return;
	}

	for (int i = 0; i < tam; i++) {
		printf ("%d ", conjunto[i]);
	}
}








