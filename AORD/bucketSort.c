#include<stdio.h>
#include"ordenacoes.h"

int maiorValor(int *vet,int tamanho);

void bucketSort(int *vet, int tam){
    bucket buckets[NUM_BUCKET];
    int i,j,k;
    
    maiorValorVet = maiorValor(vet,tam);

    int qtdElementosBalde = maiorValorVet/NUM_BUCKET;
    
    for(i=0;i<NUM_BUCKET;i++) buckets[i].tamanhoBalde=0; //inicializa os topos

    for(i=0;i<tam;i++){
        j=NUM_BUCKET-1;
        while(1){
            if(j<0) break;
            if(vet[i]>=j*qtdElementosBalde){
                buckets[j].balde[buckets[j].tamanhoBalde]=vet[i];
                (buckets[j].tamanhoBalde)++;
                break;
            }
            j--;
        }
    }

    for(i=0;i<NUM_BUCKET;i++){ //ordenacao dos baldes
        if(buckets[i].tamanhoBalde) insertionSort(buckets[i].balde,buckets[i].tamanhoBalde);
    }

    i=0;
    for(j=0;j<NUM_BUCKET;j++){
        for(k=0;k<buckets[j].tamanhoBalde;k++){
            vet[i]=buckets[j].balde[k];
            i++;
        }
    }
}

int maiorValor(int *vet,int tamanho){
    int maior=0;
    int i;
    for(i=0;i<tamanho;i++){
        if(vet[i]>maior)maior=vet[i];
    }
    return maior;
}
