#ifndef ORDENACOES_H
#define ORDENACAOES_H

#define MAX_VALUE 1000
#define TAM 15
#define MAX_BUCKET 1500
#define NUM_BUCKET 10

int maiorValorVet;

typedef struct{
    int tamanhoBalde;
    int balde[MAX_BUCKET];
}bucket;

int *insertionSort(int *vetor, int tVet);
void printVet(int *vet, int tam);
int *criaVet(int tam);
void bucketSort(int *vet, int tam);

#endif
