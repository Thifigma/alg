#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR_NOME 50

//a função getNome deve colocar o seu nome dentro da chamada
//seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();

//Assuma que os vetores estão ordenados ao chamar as funções de busca
//As funções de busca não devem alterar o vetor
//O retorno das funções de busca é o índice do elemento no vetor,
//ou -1 caso o elemeno não exista no vetor
//Você deve armazenar no ponteiro int* numComparacoes o número de comparações
//envolvendo elementos do vetor feito pelo seu algoritmo na chamada

                    //Inicio Busca sequencial
    //A busca sequencial foi a unica função que não utilizei o swap
int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes, int n);

                    //Fim Busca Sequencial

                    //Inicio Busca Binaria
    //função swap
int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes);

int BuscaBinaria_recursiva (int x, int v[], int a, int b, int *n);

                    //Fim Busca Binaria


/*Funções complementares estão servindo como auxilio 
para o funionamento de alguns algoritmos*/

                    //Funções complementares
void Troca (int v[], int a, int b);

void Insere (int v[], int a, int b, int *n);

int Minimo(int v[], int a, int b, int *n);

                    //Fim Funções complementares

/*Todos os algoritmos estão organizados em funções swap (funções que chamam funções recursivas),
Todas as comparações "ifs" são calculados em forma de um ponteiro contador (N), todo retorno da função
swap, é o numero de comparações*/

                    //INICIO insertionSOrt 

int insertionSort(int vetor[], int tam); //swap

int insertionSort_recursivo (int v[], int a, int b, int *n);

                    //FIM insertionSort

                    //INICIO SeletionSort
    //swap
int selectionSort(int vetor[], int tam);

int seletionSort_recursivo (int v[], int a, int b, int *n);

                //FIM SeletionSort. ^

                //INICIO Merge
    //swap
int mergeSort(int vetor[], int tam); 

int mergeSort_recursivo (int v[], int a, int b, int *n);

int Intercala (int v[], int a, int m, int b, int *n);
                //FIM Merge

                //INICIO Quick
    //swap
int quickSort(int vetor[], int tam); 

int quickSort_recursivo (int v[], int a, int b, int *n);

int Particiona (int v[], int a, int b, int x, int *n);

                //FIM Quick

                //Inicio Heaap
int heapSort(int vetor[], int tam);

int Pai (int i);

int Esquerda (int i);

int Direita (int i);

int max_heapify(int v[], int i, int *n);

int build_max_heap (int v[], int tam, int *n);
                //FIM Heap

#endif // ORDENACAO_H_