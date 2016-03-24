#include<stdio.h>
#include<stdlib.h>

#define TAM 4

typedef struct Intervalo{
    int inicio;
    int fim;
} Intervalo;

void bubbleSort(Intervalo *vetor);
void vetorPreenche( Intervalo *v, int tipo);
void vetorMostra( Intervalo *v);
void insertion(Intervalo *v);
void mergeSort(Intervalo *vetor, int posicaoInicio, int posicaoFim);
void quickSort(Intervalo *vet, int esq, int dir);
void quickSortRand(Intervalo *vet, int esq, int dir);

int main(){
    int i;
    Intervalo intervalo[TAM];

    /*intervalo[0].inicio = 13;
      intervalo[0].fim=15;
      intervalo[1].inicio = 12;
      intervalo[1].fim=20;
      intervalo[2].inicio = 12;
      intervalo[2].fim=17;*/

    vetorPreenche(intervalo,0);
    vetorMostra(intervalo);
    quickSortRand(intervalo,0,TAM-1);
    vetorMostra(intervalo);

    return 0;
}

void bubbleSort(Intervalo *vetor){
    int i,j;
    Intervalo aux;
    for( i=0; i<TAM; i++ ){
        for( j=i+1; j<TAM; j++ ){
            if( vetor[j].inicio < vetor[i].inicio || (vetor[j].inicio == vetor[i].inicio && vetor[j].fim < vetor[i].fim)){
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
        }
    }
}

void vetorPreenche(Intervalo *v, int tipo ){
    int i;
    switch( tipo ){
        case 1: // preenchimento ordenado - não aleatório
            for(i=0; i<TAM; i++){
                v[i].inicio = i;
                v[i].fim = i+10;
            }
            break;
        case 2: // preenchimento ordenado ao inverso - não aleatório
            for(i=0; i<TAM; i++){
                v[i].inicio = TAM-i;
                v[i].fim = TAM-i+10;
            }
            break;
        default: // preenchimento aleatório
            for(i=0; i<TAM; i++){
                v[i].inicio = rand() % 10000;
                v[i].fim = v[i].inicio + (rand() % 10000);
            }
    }

}

void vetorMostra( Intervalo *v ){
    int i;
    for(i=0; i<TAM; i++)  printf("{%i - %i}, ", v[i].inicio, v[i].fim);
    printf("\n\n");
}

void insertion(Intervalo *v){
    int i, j;
    Intervalo x;
    for (i = 1; i < TAM; i++){
        x = v[i];
        j = i - 1;
        while(j >= 0 && (v[j].inicio > x.inicio || (v[j].inicio == x.inicio && v[j].fim > x.fim))){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
}

void mergeSort(Intervalo *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho;
    Intervalo *vetorTemp;

    if(posicaoInicio == posicaoFim) return;

    //ordenacao recursiva das duas metades
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    // intercalacao no vetor temporario t
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (Intervalo*) malloc(sizeof(Intervalo) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { // i passou do final da primeira metade, pegar v[j]
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        } 
        else {
            if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            } 
            else {
                if (vetor[i].inicio < vetor[j].inicio ||(vetor[i].inicio == vetor[j].inicio && vetor[i].fim < vetor[j].fim)) { 
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                } 
                else { 
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    // copia vetor intercalado para o vetor original
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}

void quickSort(Intervalo *vet, int esq, int dir){
    int pivo = esq,i,j;
    Intervalo ch;
    for(i=esq+1;i<=dir;i++){
        j = i;
        if(vet[j].inicio < vet[pivo].inicio || (vet[j].inicio == vet[pivo].inicio && vet[j].fim < vet[pivo].fim)){
            ch = vet[j];
            while(j > pivo){    
                vet[j] = vet[j-1];
                j--;
            }
            vet[j] = ch;
            pivo++;        
        }  
    }
    if(pivo-1 > esq){
        quickSort(vet,esq,pivo-1);
    }
    if(pivo+1 < dir){
        quickSort(vet,pivo+1,dir);
    }
}

void quickSortRand(Intervalo *vet, int esq, int dir){
    int i,j;
    int pivo;
    Intervalo ch;

    srand(time(NULL));
    pivo = (rand()%(dir-esq)) + esq;
    printf("%d - %d == %d\n",dir,esq,pivo); 
    for(i=esq;i<=dir;i++){
        j = i;
        if(vet[j].inicio < vet[pivo].inicio || (vet[j].inicio == vet[pivo].inicio && vet[j].fim < vet[pivo].fim)){
            ch = vet[j];
            while(j > pivo){    
                vet[j] = vet[j-1];
                j--;
            }
            vet[j] = ch;
            pivo++;        
        }  
    }
    if(pivo-1 > esq){
        quickSortRand(vet,esq,pivo-1);
    }
    if(pivo+1 < dir){
        quickSortRand(vet,pivo+1,dir);
    }
}
