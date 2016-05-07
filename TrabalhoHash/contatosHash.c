#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define TAM_TAB 100
#define MODO 0
#define STR_FIXA 7
#define QTD_INSERT 100000

typedef struct{
	char *nome;
	char *endereco;
	char *telefone;
}Contato;

typedef struct NoTab{
	Contato *data; 
	struct NoTab *next;
}NoTab;

Contato contatoNulo;

Contato *tabSearch(char *v, NoTab **tab);
Contato *novoContato();
void printContato(Contato *contato);
NoTab **tabInit();
void tabInsert(Contato *obj, NoTab **tab);
int hash(char *v, int M);

int ultimoHash;

int main(){
	int x;
	contatoNulo.nome = NULL;
	NoTab **tab = tabInit();
	char chave[200];
	srand(time(NULL));

	if(MODO){
	while(1){
		printf("1-Novo contato.\n");
		printf("0-Sair.\n");
		scanf("%i",&x);
		__fpurge(stdin);
		if(x==0)break;
		tabInsert(novoContato(),tab);
	}
	while(1){
		printf("Digite o nome do contato que deseja procurar ou 0 para sair: ");
		scanf("%200[^\n]",chave);
		__fpurge(stdin);
		if(chave[0]-48 == x) return 1;
		printContato(tabSearch(chave,tab));
	}
	}else{
		for(x=0;x<QTD_INSERT;x++)tabInsert(novoContato(),tab);
		printContato(tabSearch(tab[ultimoHash]->data->nome,tab));	
	}
	return 0;
}

Contato *novoContato(){
	Contato *contato;
	char str[200];
	int tamString;
	int i = 0,j;	

	contato = (Contato*)malloc(sizeof(Contato));
	while(i<3){
		if(MODO){
			switch(i){
				case 0:
					printf("Digite o nome do novo Contato: ");
					break;
				case 1:
					printf("Digite o endereço de %s: ",contato->nome);
					break;
				case 2:
					printf("Digite o número do telefone de %s: ",contato->nome);
					break;
			}
			scanf("%200[^\n]",str);
			__fpurge(stdin);
			tamString = strlen(str);
		}else{
		     for(j=0;j<STR_FIXA;j++) str[j] = 65 + rand()%26;
			str[j]='\0';
			tamString = STR_FIXA;
		}	
		//printf("%s\n",str);
		switch(i){
			case 0:
				contato->nome = (char*)malloc(sizeof(char)*tamString);
				memcpy(contato->nome, str, sizeof(char)*tamString); 
				break;
			case 1:
				contato->endereco = (char*)malloc(sizeof(char)*tamString);
				memcpy(contato->endereco, str, sizeof(char)*tamString);
				break;
			case 2:
				contato->telefone = (char*)malloc(sizeof(char)*tamString);
				memcpy(contato->telefone, str, sizeof(char)*tamString);           
				break; 
		}
		i++;
	}
	return contato;
}

void printContato(Contato *contato){
	printf("Nome: %s\n",contato->nome);
	printf("Endere�o: %s\n",contato->endereco);
	printf("Telefone: %s\n",contato->telefone);
}

NoTab **tabInit(){
	int i;
	NoTab **tab;

	tab = (NoTab**)malloc(sizeof(NoTab*)*TAM_TAB);
	for(i=0;i<TAM_TAB;i++){
		tab[i]=NULL;
	}

	return tab;
}

void tabInsert(Contato *obj, NoTab **tab) { 
	int h;
	char *chave;
	NoTab *novo;
	NoTab *aux;	
	chave = obj->nome;
	h = hash(chave, TAM_TAB);
	ultimoHash = h;
	//printf("%i\n",h);
	novo = (NoTab*)malloc(sizeof(NoTab));
	novo->data = obj;	
	novo->next = tab[h];	
	tab[h] = novo;	
}

int hash(char *v, int M) {
	int i; 
	long h = v[0];
	for (i = 1; v[i] != '\0'; i++){
		//printf("%c\n",v[i]); 
		h = h * 251 + v[i];
	}
	return h % M;
}

Contato *tabSearch(char *v, NoTab **tab){ 
	NoTab *t;
	int h;
	h = hash(v, TAM_TAB);
	for (t = tab[h]; t != NULL; t = t->next){
		if (strcmp(t->data->nome,v) == 0){ 
			break;
		}
	}
	if (t != NULL) return t->data;
	return &contatoNulo;
}
