#include<stdio.h>
#include"ordenacoes.h"

int maiorValor(int *vet,int tamanho);

void bucketSort(int *vet, int tam){
    bucket buckets[NUM_BUCKET];
    int i,j,k;
    int baldeEscolhido;
    int qtdElementosBalde; 
    
    maiorValorVet = maiorValor(vet,tam);
    /*if(NUM_BUCKET<1)qtdElementosBalde=maiorValorVet;
    else*/ qtdElementosBalde = maiorValorVet/(NUM_BUCKET);
    if(qtdElementosBalde<1)qtdElementosBalde=1;

    for(i=0;i<NUM_BUCKET;i++) buckets[i].tamanhoBalde=0; //inicializa os topos 
    for(i=0;i<tam;i++){
        /*j=NUM_BUCKET-1;
        while(1){
            if(j<0) break;
            if(vet[i]>=j*qtdElementosBalde){
                buckets[j].balde[buckets[j].tamanhoBalde]=vet[i];
                (buckets[j].tamanhoBalde)++;
                break;
            }
            j--;
        }*///primeira abordagem
        
        baldeEscolhido = (int)(vet[i]/qtdElementosBalde)-1;
        if(baldeEscolhido<0)baldeEscolhido=0;
        if(baldeEscolhido==NUM_BUCKET)baldeEscolhido--;
        //printf("baldeEscolhido %i\n",baldeEscolhido);
        //printf("%i %i\n",qtdElementosBalde,vet[i]);
        buckets[baldeEscolhido].balde[buckets[baldeEscolhido].tamanhoBalde]=(int)vet[i];
        (buckets[baldeEscolhido].tamanhoBalde)++;
    } 

    for(i=0;i<NUM_BUCKET;i++){ //ordenacao dos baldes
        if(buckets[i].tamanhoBalde) insertionSort(buckets[i].balde,buckets[i].tamanhoBalde);
        //printVet(buckets[i].balde,buckets[i].tamanhoBalde);
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
