#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef TAM
#define TAM 100
#endif
#define MAX 1000000 
void countSort(int *v)
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
	for (int i = 0; i < TAM; ++i){
		v[i] = aux[i];
	}
}
void randomize(int* v){
    srand(time(NULL));
    for(int i=0; i<TAM; i++){
        v[i]=rand()%MAX;
    }
    v[0]=2000000;
}
int main(int argc, char const *argv[])
{
	int v[TAM];	
        randomize(v);
//        for(int i=0; i<TAM;i++)
//            printf("%d ",v[i]);
//        printf("\n\n);
        countSort(v); 
        //for (int i = 0; i < TAM; ++i)
                //printf("%d ", v[i]);
	//printf("\n");
	return 0;
}
