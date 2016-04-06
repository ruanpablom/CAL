#include<stdio.h>
#include"ordenacoes.h"
#include<stdlib.h>

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
