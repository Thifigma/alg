#include <stdio.h>
#include <stdlib.h>

#include "ordenacao.h"

int main(){
	char nome[MAX_CHAR_NOME];
	int n = MAX_TAM; 	/* Tamanho do vetor. */	
	int a = 0; 			/* Inicio do vetor. */
	
	srand (time(NULL)); 	
	int x = MIN - rand() % (MAX - MIN + 1); /* Valor a ser buscado. */ 

	int *vetor;
	if (!(vetor = malloc(n*sizeof(int)))) {
		printf ("Erro de alocacao! \n");
		exit(1);
	}

	iniciaVetor(vetor, n);

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
	printf ("\n");

	/* start recebe o inicio do 'ciclo' corrente
	 * end recebe o finl do 'ciclo'. 
	 * O tempo total é a diferença dividida pelos ciclos por segundos. */
	clock_t start, end;
	double total;

	start = clock();
	buscaSequencial(x, vetor, n);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf ("Busca Sequencial\n");
	printf("Tempo total: %f\n", total);
	printf ("\n");

	start = clock();
	buscaBinaria(x, vetor, a, n);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf ("Busca Binaria\n");
	printf("Tempo total: %f\n", total);
	printf ("\n");

	start = clock();
	insertionSort(vetor, n);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf ("insertionSort\n");
	printf ("Tempo total: %f\n", total);
	printf ("\n");

	start = clock();
	selectionSort(vetor, n);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf ("selectionSort\n");
	printf ("Tempo total: %f\n", total);
	printf("\n");

	start = clock();
	mergeSort(vetor, a, n);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf ("mergeSort\n");
	printf ("Tempo total: %f\n", total);
	printf("\n");

	free(vetor);
	
	return 0;
}
