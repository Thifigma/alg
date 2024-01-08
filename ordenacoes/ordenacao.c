#include "ordenacao.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Adicionada terminação manual para caso de overflow. */
void getNome(char nome[]){
	strncpy(nome, "Thiago Figueiredo Marcos", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';
}

unsigned int getGRR(){
	return 20205982;
}

void iniciaVetor (int *v, int n)
{
	srand (time(NULL)); 	
	int x = MIN - rand() % (MAX - MIN + 1); 	

	for(int i = 0; i < n; i++){
		x = MIN - rand() % (MAX - MIN + 1); 
		v[i] = x;
	}
}

int buscaSequencial(int x, int *v, int n)
{
	int a = 0; 

	if (a > n)
		return a;

	if (x == v[n]) {
		return n;
	}

	buscaSequencial(x, v, n - 1);
}

void buscaBinaria(int x, int *v, int a, int n)
{
	if(a > n)
		return;

	int m = ((a+n) / 2);

	if(x == v[m]){
		return;
	}

	if(x < v[m])
		return buscaBinaria(x, v, a, m - 1);
	return buscaBinaria(x, v, m + 1, n);
}

/* Função axiliar. */
void troca (int *v, int a, int b)
{
	int aux;

	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

/* Auxiliar do insertionSort. */
void insere (int *v, int b)
{
	int x = buscaSequencial(v[b], v, b - 1);
	int i = b;

	while (i > x + 1) {
		troca(v, i, i - 1);
		i--;
	}
	
	return;
}

int minimo (int *v, int n)
{
	int a = 0;
	int m = 0;
	
	if (n == a)
		return a;

	m = minimo(v, n - 1);
	
	if (v[n] < v[m]) {
		m = n;
	}

	return m;
}

void insertionSort (int *v, int n)
{
	int a = 0;

	if(a > n)
		return;

	insertionSort(v, n - 1);	
	insere(v, n);

	return;
}

void selectionSort (int *v, int n)
{
	int a = 0;

	if (n <= a){
		return;
	}

	troca(v, n, minimo(v, n) );
	selectionSort(v, n - 1);

	return;
}

// a = p
// n == r

void intercala(int *v, int a, int m, int b) 
{
    if (a >= b)
        return;
    
    int *u;
    if (!(u = malloc((b - a + 1) * sizeof(int)))) {
        printf("Erro de alocacao!\n");
        exit(1);
    }

    int i = a;
    int j = m + 1;

    for (int k = a; k <= b - a; k++) {
        if ((j > b) || (i <= m && v[i] <= v[j])) {
            u[k] = v[i];
            i++;
        } else {
            u[k] = v[j];
            j++;
        }
    }

    for (int i = a; i < b - a; i++) {
        v[i] = u[i - a];
    }

    free(u);
}

void mergeSort(int *v, int a, int b)
{
	int m;

	if(a >= b)
		return;

	m = ((a + b) / 2);

	mergeSort(v, a, m);
	mergeSort(v, m + 1, b);
	
	intercala(v, a, m, b);
}

