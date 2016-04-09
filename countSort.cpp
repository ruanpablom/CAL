#include <stdio.h>
#ifndef TAM
#define TAM 10
#endif
//TODO debugar e fazer elementos aleatórios 
int* countSort(int *v)
{
	int maior=0;
	for (int i = 0; i < TAM; ++i)
		if (v[i]>maior)
			maior=v[i];
	int c[maior+1];
	for (int i = 0; i <= maior; i++)
		c[i] = 0;
	for (int i = 0; i < TAM; ++i)
		c[v[i]]++;
	for (int i = 1; i <= maior+1; ++i)
		c[i] += c[i-1];
	int aux[TAM];
	for (int i = 0; i < TAM; ++i)
	{
		aux[c[v[i]]-1] = v[i];
		c[v[i]]--;
	}
	return aux;
}

int main(int argc, char const *argv[])
{
	int v[TAM] = {5, 1, 4, 1, 2, 4, 5, 3, 3, 2};	
	v = countSort(v);
	for (int i = 0; i < TAM; ++i)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}
