#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main(){
	char nome[MAX_CHAR_NOME];
	int x = rand() %100; /*Valor aleatorio a ser buscado*/
	int n = MAX_TAM; 	 /*Tamanho do vetor*/	
	int numComp = 0; 	 /*Ponteiro para o umero de comparações*/
	

	/*Ponteiros para numero de comparações da busca Binaria e Sequencial*/
	int numCompB = 0; 		/*Sequencial*/
	int numCompBB  = 0; 	/*Binária*/

	int *vetor;
	if (!(vetor = malloc(n*sizeof(int)))){
		printf ("Erro de alocacao! \n");
		return 1;
	}

	inicia_vetor(vetor, n);

	srand (time(NULL));

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
	printf ("\n");

	/*variáveis do tipo clock_t*/
	clock_t start, end;
    double total;

	start = clock(); /*start recebe o "ciclo" corrente*/
	buscaSequencial(x, vetor, n, &numCompB);
	end = clock();/*end recebe o "ciclo" corrente*/
	/*o tempo total é a diferença dividia pelos ciclos por segundo*/
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf ("Busca Sequencial\n");
	printf("Tempo total: %f\n", total);
	printf ("Numero de comparações: %d\n", numCompB - 1);

	printf ("\n");

	free(vetor);
	return 0;
}