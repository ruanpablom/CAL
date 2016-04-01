#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

//#define TAM 1200000
#define Q_A 4
#define ERRO -1

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
double cTime(struct timeval t1, struct timeval t2);
long stringToNumber(char **str);


int main(int argc, char **argv){
    int i;
    Intervalo *intervalo;
    struct timeval t1, t2;
    double time[Q_A];
    FILE *arq;
    
    if(argv[1]==NULL){
        printf("./ordenacoes \"tamanho do vetor\" \"execucao\" ");
        return ERRO;
    }

    arq = fopen("res.dat","a");
    if(arq==NULL){
        printf("Erro ao abrir o arquivo!");
        return ERRO;
    }
    fprintf(arq,"%li ",stringToNumber(argv,2));

    intervalo=(Intervalo*)malloc(sizeof(Intervalo)*stringToNumber(argv, 1));
    vetorPreenche(intervalo,0);
    gettimeofday(&t1, NULL); 
    quickSort(intervalo,0,TAM-1);
    gettimeofday(&t2, NULL); 
    time[0]=cTime(t1,t2); 
    fprintf(arq,"%.3lf ",time[0]);

    vetorPreenche(intervalo,0);
    bubbleSort(intervalo);
    gettimeofday(&t2, NULL); 
    time[1]=cTime(t1,t2); 
    fprintf(arq,"%.3lf ",time[1]);

    vetorPreenche(intervalo,0);
    insertion(intervalo);
    gettimeofday(&t2, NULL); 
    time[2] = cTime(t1,t2);
    fprintf(arq,"%.3lf ",time[2]);

    vetorPreenche(intervalo,0);
    mergeSort(intervalo,0,TAM-1);
    gettimeofday(&t2, NULL); 
    time[3] = cTime(t1,t2);
    fprintf(arq,"%.3lf\n",time[3]);

    return 0;
}

long stringToNumber(char **stri, int pos){
    int i=0;
    long result=0;
    int p = 0;
    for(i=0;str[pos][i]!='\0';i++);
    i--;
    while(i!=-1){
        result += pow(10,p)*(str[pos][i]-48);
        i--;
        p++;
    }

    return result;
}

double cTime(struct timeval t1, struct timeval t2){
    double elapsedTime;

    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    elapsedTime /=1000.0;

    return elapsedTime;
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

void quickSortRand(Intervalo *a, int n){
    int i, j, t;
    Intervalo p;
    if (n < 2)
        return;
    p = a[rand(time(NULL))%n];//escolha do pivo
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i].inicio < p.inicio || (a[i].inicio == p.inicio && a[i].fim < p.fim))//por enquanto q o pivo for o maior
            i++;
        while (a[j].inicio > p.inicio || (a[j].inicio == p.inicio && a[j].fim > p.fim))
            j--;
        if (i >= j)
            break;
        swap(&a[i], &a[j]);//troca
    }
    quickSortRand(a, i);//sublista dos elementos menores
    quickSortRand(a + i, n - i);//sublista dos elementos maiores
    }
}
