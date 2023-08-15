#include <stdio.h>
#include "ordenacao.h"

int main()
{
	int conjunto[MAXTAM];
	int tamanhoConjunto = 0;

	iniciaVazio(&conjunto);
	tamanhoConjunto = tamConjunto(conjunto);

	printf ("Tamanho do conjunto: [%d]", tamanhoConjunto);

	return 0;
}

