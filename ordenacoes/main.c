#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main(){
	char nome[MAX_CHAR_NOME];
	int x = rand() %100; 	/*Valor aleatorio a ser buscado*/
	int n = MAX_TAM; 	/*Tamanho do vetor*/	
	int a = 0; 		/*Inicio do vetor*/
	int numComp = 0; 	/*Ponteiro para o umero de comparações*/
	

	/*Numero de comparações da busca binaria e sequencial separadamente
	 * para enfatizar a diferença de quantidade de comparações.*/
	int numCompB = 0;
	int numCompBB  = 0;

	int *vetor;
	if (!(vetor = malloc(n*sizeof(int)))){
		printf ("Erro de alocacao! \n");
		return 1;
	}

	iniciaVetor(vetor, n);

	srand (time(NULL));

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
	printf ("\n");

	/* start recebe o inicio do 'ciclo' corrente
	 * end recebe o finl do 'ciclo'. 
	 * O tempo total é a diferença dividida pelos ciclos por segundos.*/
	clock_t start, end;
	double total;

	start = clock();
	buscaSequencial(x, vetor, n, &numCompB);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf ("Busca Sequencial\n");
	printf("Tempo total: %f\n", total);
	printf ("Numero de comparacoes: %d\n", numCompB);

	printf ("\n");

	start = clock();
	buscaBinaria(x, vetor, a, n, &numCompBB);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf ("Busca Binaria\n");
	printf("Tempo total: %f\n", total);
	printf ("Numero de comparacoes: %d\n", numCompBB);

	printf ("\n");

	start = clock();
	insertionSort(vetor, n, &numComp);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf ("InsertionSort\n");
	printf ("Tempo total: %f\n", total);
	printf ("Numero de comparacoes: %d\n", (numComp - 1) + numCompB);
	
	free(vetor);
	return 0;
}
