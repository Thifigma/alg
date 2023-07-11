#include "ordenacao.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void getNome(char nome[]){
	strncpy(nome, "Thiago Figueiredo Marcos", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//Retorna o GRR
unsigned int getGRR(){
	return 20205982;
}
					//Funções complementares

void Troca (int v[], int a, int b)
{
	int tmp;

	tmp = v[a];
	v[a] = v[b];
	v[b] = tmp;

}

void Insere (int v[], int a, int b, int *n)
{
	int numCompBusca = 0;
	int p = buscaSequencial (v, b, v[b], &numCompBusca, 0);
	int i = b;
	while (i > p + 1){
		Troca (v, i, - 1);
		i--;
	}	
}

int Minimo(int v[], int a, int b, int *n)
{
	int m = 0;

	if (a == b){
		*n = *n + 1;
		return a;
	}
	
	m = Minimo(v, a, b - 1, n);
	if (v[b] < v[m]){
		m = b;
		*n = *n + 1;
	}	

	return m;
}


					//Fim Funções complementares


					//Inicio Busca Sequencial
int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes, int n)
{
	int a = 0;
	*numComparacoes = n; //Recebe o numero de comparações
	
	if (a >= tam)
		return -1;
	
	if (valor == vetor[tam])
		return tam;

	n++;
	return  buscaSequencial(vetor, tam - 1, valor, numComparacoes, n);
}


					//Fim Busca Sequencial


					//Inicio Busca Binaria
	//swap
int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes)
{
	//indice 0 do vetor. 
	int a = 0;

	//Em alguns casos a busca não funciona, não deu tempo de identificar o motivo. 
	return BuscaBinaria_recursiva (valor, vetor, a, tam, numComparacoes);
}

	// (N) é contado em cada comparação
int BuscaBinaria_recursiva (int x, int v[], int a, int b, int *n)
{
	int m = 0;
	
	if (a > b){
		*n = *n + 1;
		return -1;
	}

	m = (a + b) / 2;

	if (x == v[m]){
		*n = *n + 1;
		return m;
	}

	if (x < v[m]){
		*n = *n + 1;
		return BuscaBinaria_recursiva(x, v, a, m - 1, n);
	} else {
		*n = *n + 1;
		return BuscaBinaria_recursiva(x, v, m + 1, b, n);
	}
}
				//Fim Busca Binaria

				// INICIO InsertionSort
	//swap
int insertionSort(int vetor[], int tam) 
{	
	//Variaveis Locais
	int n = 0; // Faz a contagem das comparações
	int a = 0; //Indice 0 do vetor.
	//Fim Variaveis Locais

	insertionSort_recursivo(vetor, a, tam, &n); 


	return n;
}

int insertionSort_recursivo (int v[], int a, int b, int *n)
{
	if (a == b)
		return 0;

	//N é somada a cada recursão
	*n = *n + 1; 
	insertionSort_recursivo (v, a, b - 1, n);
	
	//Comapracoes do insere são feitas na main com o retorno da busca, sendo sempre (N - 1)
	Insere(v, a, b, n); 

	return 0; 
}
					//FIM InsertionSort ^


					//INICIO seletionSort
	//swap
int selectionSort(int vetor[], int tam)
{
	//Variaveis Locais 
	int a = 0; //Indice inicial do vetor
	int n = 0; //Contador de comparações
	//Fim variaveis Locais

	seletionSort_recursivo (vetor, a, tam, &n); // Função recursiva


	return n;
}

int seletionSort_recursivo (int v[], int a, int b, int *n)
{
	
	if ( a >= b)
		return 1;

	Troca (v, a, Minimo(v, a, b, n));

	*n = *n + 1;  // (N) é contado em toda comparação de vetor
	return seletionSort_recursivo (v, a + 1, b, n);
}
					//FIM seletionSort^

					//INICIO merge

	//swap
int mergeSort(int vetor[], int tam) 
{
	//Variaveis Locais
	int a = 0; //Inicio do vetor
	int n = 0; //Contador de comparações
	//Fim variaveis Locais
	
	
	mergeSort_recursivo(vetor, a, tam, &n); //Função recursiva

	return n;
}

int mergeSort_recursivo (int v[], int a, int b, int *n)
{
	int m = 0;

	if (a >= b) //Caso base
		return 1;

	//Piso
	m = (a + b) / 2; 

	*n = *n + 1;
	mergeSort_recursivo(v, a, m, n);

	*n = *n + 1;
	mergeSort_recursivo(v, m + 1, b, n);

	return Intercala(v, a, m, b, n);
}

int Intercala (int v[], int a, int m, int b, int *n)
{
	int i = 0;
	int j = 0;
	int tamU = b;
	int *u = malloc (tamU *sizeof(int));
	
	if (a >= b){
		return 0;
	}

	i = a;
	j = m + 1;
	for (int k = 0; k <= b - a; k++){
		if (j > b || (i <= m && v[i] <= v[j])){
			u[k] = v[i];
			*n = *n + 1; //Soma comparacao
			i++;
		} else {
			u[k] = u[j];
			*n = *n + 1; //Soma comapracao
			j++;
		}
	} 

	*v = *u;

	free (u);	
	return 0; /*Precisei deixar como inteiro pois eh um retorno para a funcao merge 
	Poderia ser um void mas ai dava erro pois so posso retonar um inteiro. */
} 

					//Fim Merge


					//Inicio Quick

int quickSort(int vetor[], int tam)
{
	//Variaveis locais
	/*No particiona o meio ( M ) recebe a - 1, se o valor for zero da erro de segmentação
	então optei por deixar o valor inicial do vetor como 1*/
	int a = 1; 
	int n = 0;
	//Fim variaveis locais

	quickSort_recursivo (vetor, a, tam, &n);

	return n;
}

int quickSort_recursivo (int v[], int a, int b, int *n)
{
	int m = 0;
	
	if (a >= b)
		return 1;

	m = Particiona (v, a, b, v[b], n);
	
	*n = *n + 1;
	quickSort_recursivo (v, a, m - 1, n);
	
	*n = *n + 1;
	quickSort_recursivo (v, m + 1, b, n);
	
	return *n;
}

int Particiona (int v[], int a, int b, int x, int *n) //Tem valor N.
{
	int m = a - 1; //Pode dar falha de segmentação caso (a) seja 0;
	
	for (int i = 0; i < b; i++){
		if(v[i] <= x){
			*n = *n + 1;
			m++;
			Troca(v, m, i);
		} 
	}
	return m;	
}
					//Fim Quick


					//INICIO Heap

int heapSort(int vetor[], int tam)
{
	int n = 0; // Contador de comparações 

	build_max_heap (vetor, tam, &n);

	for (int i = tam; i > 2; i--){
		Troca(vetor, 1, i);
		max_heapify(vetor, 1, &n);
	}

	return n; //retorna o num de comparações
}

int Pai (int i) //Nó raiz
{
	return ((i / 2));
}

int Esquerda (int i) //Filho esquerda
{
	return (2*i);
}

int Direita (int i) //Filho direita
{
	return (2*i+1);
}


int max_heapify(int v[], int i, int *n)
{
	int maior = 0;
	int pai = Pai (i);
	int esq = Esquerda (i);
	int dir = Direita (i);

	if (esq <= pai && v[esq] > v[i]){
		*n = *n + 1;
		maior = esq;
	} else {
		*n = *n + 1;
		maior = i;
	}

	if (dir <= pai && v[dir] > v[maior]){
		*n = *n + 1;
		maior = dir;
	}

	if (maior != i){
		*n = *n + 1;
		Troca (v, i, maior);
		max_heapify(v, maior, n);
	}

	return 1;
}

int build_max_heap (int v[], int tam, int *n)
{
	for (int i = 0; (tam / 2) > 1;tam--){
		max_heapify(v, i, n);
	}

	return 1;
}
					//Fim Heap