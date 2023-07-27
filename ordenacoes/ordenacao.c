#include "ordenacao.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void getNome(char nome[]){
	strncpy(nome, "Thiago Figueiredo Marcos", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0'; /*adicionada terminação manual para caso de overflow*/
}

unsigned int getGRR(){
	return 20205982;
}

void inicia_vetor (int *v, int n)
{
	for(int i = 0; i < n; i++){
		v[i] = rand() %100;
	}
}

void buscaSequencial(int x, int *v, int n, int *numComp)
{
	int a = 1;

	if (a > n){
		(*numComp)++;
		return;
	}

	if (x == v[n]){
		(*numComp)++;
		return;
	}

	(*numComp)++;
	buscaSequencial(x, v, n - 1, numComp);
}

void Troca (int *v, int a, int b)
{
	int aux;

	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}