#include <stdio.h>
#include "conjuntos.h"

int main()
{
	int conjunto1[MAXTAM + 1];
	int conjunto2[MAXTAM + 1];

	iniciaVazio(conjunto1);
	iniciaVazio(conjunto2);

	/*Confere que os conjuntos foram gerados vazios*/
	mostraConjunto(conjunto1);
	mostraConjunto(conjunto2);

	criaConjunto(conjunto1);
	criaConjunto(conjunto2);

	/*Mostra os conjuntos que foram gerados com numeros pseudoaleatorios. */
	mostraConjunto(conjunto1);
	mostraConjunto(conjunto2);

	if (uniao(conjunto1, conjunto2)) {
		printf ("A uniao foi efetiva! \n");
	}

	return 0;
}

