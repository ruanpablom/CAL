#include <stdio.h>
#ifndef TAM
#define TAM 10
#endif
void countSort(int *v)
{
	int maior=0,i;
	for (i = 0; i < TAM; ++i){
		if (v[i]>maior)
		{
			maior=v[i];
		}
	}
	int c[maior] = {0};
	for (i = 0; i < TAM; ++i)
	{
		c[v[i]]++;
	}
	int j, *aux = v;
	for (int i = 0; i < maior; ++i)
	{
		for (int j = 0; j < c[i]; ++j)
		{
			*aux = i;
			c[i]--;
		}
	}
}

int main(int argc, char const *argv[])
{
	int v[TAM] = [5, 1, 4, 1, 2, 4, 5, 3, 3, 2];
	countSort(v);
	for (int i = 0; i < TAM; ++i)
	{
		printf("%d ", v[i]);
	}
	printf("\n");
	return 0;
}