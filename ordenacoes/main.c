#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main(){
	char nome[MAX_CHAR_NOME];
	int idxBusca; /*Indice do valor procurado pela busca*/
	int numComp = 0; /*Numero de comparações de cada função*/

	/*Variaveis de comparações de cada busca*/
	int numCompB = 0; /*Sequencial*/
	int numCompBB = 0; /*Binária*/
	

	srand (time(NULL));

	int tamVetor = rand ()%400;
	int* vetor;

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

	/*variáveis do tipo clock_t*/
	clock_t start, end;
    double total;
	
	
	start = clock(); /*start recebe o "ciclo" corrente*/
	insertionSort(vetor, tamVetor); 
	end = clock();/*end recebe o "ciclo" corrente*/
	/*o tempo total é a diferença dividia pelos ciclos por segundo*/
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	printf ("Numero de comparações do InsertionSort: %d\n", numComp); 	

	printf ("\n");

	free(vetor);
	return 0;
}