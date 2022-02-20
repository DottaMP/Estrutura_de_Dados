// Lista circular
#include <stdio.h>
#include <stdlib.h>

typedef struct item{
 int valor;
 struct item *proximo;
} Item;

typedef struct lista{
 Item *primeiro;
} Lista ;

void atualizaUltimo(Lista *lista, Item *novo){
	Item *aux = lista->primeiro;
	while(aux->proximo != lista->primeiro){
		aux = aux->proximo;
	}
	aux->proximo = novo;
}

void colocarNoFim(Lista *lista, int valor){
	printf("Colocar no Fim %i\n", valor);
	Item *novo=(Item*)malloc(sizeof(Item));
	novo->valor = valor;
	novo->proximo = lista->primeiro;  
	
	if(lista->primeiro==NULL){
		lista->primeiro = novo;
		novo->proximo = novo;	
	} else {
		Item *aux = lista->primeiro;
		while(aux->proximo != lista->primeiro){ // não se compara mais com NULL e sim com o primeiro, pois ao chegar no fim, volta para o começo.
			aux = aux->proximo;
		}
		aux->proximo = novo;
	}
}


void colocarNoInicio(Lista *lista, int valor){
	printf("Colocar no Início %i\n", valor);
	Item *novo=(Item*)malloc(sizeof(Item));
	novo->valor = valor;
	novo->proximo = NULL;  
	
	if(lista->primeiro==NULL){
		lista->primeiro = novo;	
		novo->proximo = novo;
	} else {
		atualizaUltimo(lista, novo);
		novo->proximo = lista->primeiro;
		lista->primeiro = novo;
	}
}

void removerInicio(Lista *lista){
	printf("Removendo o Início = ");
	if(lista->primeiro==NULL){
		printf("Lista vazia\n");	
	} else {
		Item *aux = lista->primeiro;
		atualizaUltimo(lista, aux->proximo);
		printf("%i\n", aux->valor);
		lista->primeiro = aux->proximo;	//transformado o segundo em primeiro
		free(aux);
	}
}

void removerFim(Lista *lista){
	printf("Removendo o Fim = ");
	if(lista->primeiro==NULL){
		printf("Lista vazia\n");	
	} else {
		Item *aux = lista->primeiro;
		Item *aux2 = aux;
		while(aux->proximo!=lista->primeiro){
			aux2 = aux;
			aux = aux->proximo;
		}
		aux2->proximo = lista->primeiro;
		printf("%i \n", aux->valor);
		free(aux);
	}
}

void removerPesquisa(Lista *lista, int valor){
	printf("\nRemovendo Pesquisa = ");
	if(lista->primeiro==NULL){
		printf("Lista vazia\n");	
	} else {
	   Item *aux = lista->primeiro;
        Item *penultimo = aux;
        while(aux->proximo != NULL){
            if(valor == aux->valor){
                if(aux == penultimo){ //quando for o primeiro elemento
                    atualizaUltimo(lista, aux->proximo);
                    lista->primeiro = aux->proximo;
                } else {
                    penultimo->proximo = aux->proximo;
                }
                printf("%i\n", aux->valor);
                free(aux); // removendo pesquisa
                break;
            } else {
                penultimo = aux;
                aux = aux->proximo;
            }
        }
	}
}

void listar(Lista *lista){
    if(lista->primeiro==NULL){
		printf("Lista vazia\n");	
	} else {
       	Item *aux = lista->primeiro;
    	do {
    		printf("Item (%x) %i \n", aux, aux->valor);
    		aux = aux->proximo;
    	} while(aux != lista->primeiro);
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
	
	removerPesquisa(&l1, 21);
	listar(&l1);
	
	removerPesquisa(&l1, 34);
	listar(&l1);
	
	removerPesquisa(&l1, 56);
	removerPesquisa(&l1, 16);
	listar(&l1);
	
	return 0;
}


