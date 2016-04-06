#include<stdio.h>
#include<stdlib.h>
#include"ordenacoes.h"

int *insertionSort(int *vetor, int tamVet){
    int i,j,atual;

    for(i=1;i<tamVet;i++){
        atual = vetor[i];
        j=i-1;

        while((j>=0) && (atual < vetor[j])){
            vetor[j+1]=vetor[j];
            j=j-1;
        }
        vetor[j+1] = atual;
    }
    return (int*)vetor;
}

void printVet(int *vet, int tam){
    int i;
    for(i=0;i<tam;i++){
        printf("%i ",vet[i]);
    }
    printf("\n");
}

int *criaVet(int tam){
    int *vet,i;

    srand(time(NULL));
    vet = (int*)malloc(sizeof(int)*tam);
    for(i=0;i<tam;i++){
        vet[i] = rand() % MAX_VALUE;
    }

    return vet;
}
