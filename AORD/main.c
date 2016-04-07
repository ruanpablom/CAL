#include<stdio.h>
#include"ordenacoes.h"
#include<stdlib.h>

int main(){
    int *vet;

    vet = criaVet(TAM);
    printVet(vet,TAM);
    bucketSort(vet,TAM); 
    printVet(vet,TAM);
    free(vet);
    return 0;
}
