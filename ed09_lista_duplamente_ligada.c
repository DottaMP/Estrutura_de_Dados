//Lista duplamente ligada, existe um ponteiro para o anterior e outro para o próximo.

#include <stdio.h>
#include <stdlib.h>

typedef struct item{
 int valor;
 struct item *anterior;
 struct item *proximo;
} Item;

typedef struct lista{
 Item *primeiro;
} Lista ;

void colocarNoFim(Lista *lista, int valor)
{
	printf("colocarNoFim %i\n", valor);
	Item *novo=(Item*)malloc(sizeof(Item));
	novo->valor = valor;
	novo->anterior = NULL;
	novo->proximo = NULL;  
	
	if(lista->primeiro==NULL){
		lista->primeiro = novo;	
	} else {
		Item *aux = lista->primeiro;
		while(aux->proximo != NULL){
			aux = aux->proximo;
		}
		novo->anterior = aux;
		aux->proximo = novo;
	}
}


void colocarNoInicio(Lista *lista, int valor)
{
	printf("colocarNoInicio %i\n", valor);
	Item *novo=(Item*)malloc(sizeof(Item));
	novo->valor = valor;
	novo->proximo = NULL;  
	novo->anterior = NULL;
	
	if(lista->primeiro==NULL){
		lista->primeiro = novo;	
	} else {
		Item *antigo = lista->primeiro;
		
		novo->proximo = antigo;		
		antigo->anterior = novo;
		
		lista->primeiro = novo;
	}
}

void removerInicio(Lista *lista){
	printf("removerInicio=");
	if(lista->primeiro==NULL){
		printf("Lista vazia\n");	
	} else {
		Item *aux = lista->primeiro;
		printf("%i\n", aux->valor);
		aux->proximo->anterior = NULL;	
		lista->primeiro = aux->proximo;	//transformado o segundo em primeiro
		free(aux);
	}
}

void removerFim(Lista *lista){
	printf("removerFim=");
	if(lista->primeiro==NULL){
		printf("Lista vazia\n");	
	} else {
		Item *aux = lista->primeiro;
		while(aux->proximo!=NULL){
			aux = aux->proximo;
		}
		Item *penultimo = aux->anterior;
		penultimo->proximo = NULL;
		printf("%i \n", aux->valor);
		free(aux);
	}
}




void removerPesquisa(Lista *lista, int valor){
	printf("\nremoverPesquisa=");
	if(lista->primeiro==NULL){
		printf("Lista vazia\n");	
	} else {
		Item *aux = lista->primeiro;
		while(aux->proximo!=NULL){
			if(valor==aux->valor){
				if(aux->anterior==NULL){ //quando for o primeiro elemento
					lista->primeiro = aux->proximo;
					lista->primeiro->anterior = NULL;	
				} else {
					aux->anterior->proximo = aux->proximo;
				}
				printf("%i \n", aux->valor);
				free(aux);	
				break;
			} else {
				aux = aux->proximo;
			}
		}
		
	}
}

void listar(Lista *lista)
{
   	Item *aux = lista->primeiro;
	while(aux != NULL){
		printf("Item %x %i \n", aux, aux->valor);
		aux = aux->proximo;
	}
}


int main(int argc, char *argv[]) {
	Lista l1 = {NULL};
	
	
	colocarNoFim(&l1, 56);
	colocarNoFim(&l1, 21);
	colocarNoFim(&l1, 16);
	colocarNoFim(&l1, 72);
	listar(&l1);
	
	colocarNoInicio(&l1, 34);
	colocarNoInicio(&l1, 12);
	listar(&l1);

	removerInicio(&l1);
	listar(&l1);
	
	removerFim(&l1);
	listar(&l1);
	
	removerPesquisa(&l1, 3412);
	
	removerPesquisa(&l1, 21);
	listar(&l1);	
	removerPesquisa(&l1, 34);
	listar(&l1);	
	return 0;
}

