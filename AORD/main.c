#include<stdio.h>
#include"ordenacoes.h"

int main(){
    int *vet;

    vet = criaVet(TAM);
    printVet(vet,TAM);
    bucketSort(vet,TAM);
    printVet(vet,TAM);
    return 0;
}
