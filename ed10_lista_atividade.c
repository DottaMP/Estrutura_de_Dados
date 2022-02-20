/*2-Implemente uma lista duplamente encadeada para simular uma rede social de pessoas conhecidas, 
implemente todas as funções basicas, e adicione uma função adicional para contar quantas pessoas 
são necessarias para uma pessoa A, conhecer uma pessoa B somente atraves da navegação dos encadeamentos.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
  char nome [30];
  struct pessoa *anterior;
  struct pessoa *proximo;
} Pessoa;

typedef struct lista{
    Pessoa *primeiro;
} Lista ;

void ligarPessoas(Lista *lista, char* pessoaA, char* pessoaB){
    
}

void colocarNoFim(Lista *lista, char* nome)
{
	printf("colocarNoFim %s\n", nome);
	Pessoa *novo=(Pessoa*)malloc(sizeof(Pessoa));
	novo->nome = nome;
	novo->anterior = NULL;
	novo->proximo = NULL;  
	
	if(lista->primeiro==NULL){
		lista->primeiro = novo;	
	} else {
		Pessoa *aux = lista->primeiro;
		while(aux->proximo != NULL){
			aux = aux->proximo;
		}
		novo->anterior = aux;
		aux->proximo = novo;
	}
}


void colocarNoInicio(Lista *lista, char* nome)
{
	printf("colocarNoInicio %s\n", nome);
	Pessoa *novo=(Pessoa*)malloc(sizeof(Pessoa));
	novo->nome = nome;
	novo->proximo = NULL;  
	novo->anterior = NULL;
	
	if(lista->primeiro==NULL){
		lista->primeiro = novo;	
	} else {
		Pessoa *antigo = lista->primeiro;
		
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
		Pessoa *aux = lista->primeiro;
		printf("%s\n", aux->nome);
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
		Pessoa *aux = lista->primeiro;
		while(aux->proximo!=NULL){
			aux = aux->proximo;
		}
		Pessoa *penultimo = aux->anterior;
		penultimo->proximo = NULL;
		printf("%s \n", aux->nome);
		free(aux);
	}
}

void removerPesquisa(Lista *lista, char* nome){
	printf("\nremoverPesquisa=");
	if(lista->primeiro==NULL){
		printf("Lista vazia\n");	
	} else {
		Pessoa *aux = lista->primeiro;
		while(aux->proximo!=NULL){
			if(nome==aux->nome){
				if(aux->anterior==NULL){ //quando for o primeiro elemento
					lista->primeiro = aux->proximo;
					lista->primeiro->anterior = NULL;	
				} else {
					aux->anterior->proximo = aux->proximo;
				}
				printf("%s \n", aux->nome);
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
   	Pessoa *aux = lista->primeiro;
	while(aux != NULL){
		printf("Pessoa %x %s \n", aux, aux->nome);
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


