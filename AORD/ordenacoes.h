#ifndef ORDENACOES_H
#define ORDENACAOES_H

#define MAX_VALUE 10
#define TAM 10
#define MAX_BUCKET 100
#define NUM_BUCKET 10

typedef struct{
    int tamanhoBalde;
    int balde[MAX_BUCKET];
}bucket;

int *insertionSort(int *vetor, int tVet);
void printVet(int *vet, int tam);
int *criaVet(int tam);
void bucketSort(int *vet, int tam);
void bucketSort(int *vet, int tam);

#endif
