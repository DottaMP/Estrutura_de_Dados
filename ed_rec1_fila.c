/*Dada a seguinte TAD  Ficha{int codigo,  char nome[50],  char telefone[30], int idade}    
Implemente uma fila com esta TAD*/

#include <stdio.h>
#include <stdlib.h>
struct Ficha{
	int codigo;
	char nome[50]; 
	char telefone[30];
	int idade;
	struct Ficha *proximo;
} typedef Ficha;
struct fila{
	Ficha *primeiro;
} typedef fila;

//queue
void colocarFila(fila *f){
	Ficha *novo = (Ficha*)malloc(sizeof(Ficha));
	printf("Informe o código: ");
	scanf("%i", &novo->codigo);
	printf("Informe o nome: ");
	scanf("%s", &novo->nome);
	printf("Informe o telefone: ");
	scanf("%s", &novo->telefone);
	printf("Informe a idade: ");
	scanf("%i", &novo->idade);
	novo->proximo = NULL;
	if(f->primeiro==NULL){
		f->primeiro = novo;
		printf("Primeiro da fila %x \n", novo);
	} else {
		//procurando o fim da fila o ultimo item tem o atributo proximo = NULL
		Ficha *aux = f->primeiro;
		while(aux->proximo != NULL){
			aux = aux->proximo;
		}
		aux->proximo = novo;
		printf("Ultimo da fila %x \n", novo);
	}
}
//unqueue
void tirarFila(fila *f){
	if(f->primeiro == NULL){
		printf("Fila vazia \n");
	} else {
		printf("Item removido: Código: %i. Nome: %s . Telefone: %s. Idade: %i. => %x \n", f->primeiro->codigo, f->primeiro->nome, f->primeiro->telefone, f->primeiro->idade, f->primeiro);
		Ficha *aux = f->primeiro->proximo; 	
		free(f->primeiro);
		f->primeiro = aux;
	}
}

void contar(fila *f){ //contar
    int cont=1;
    if(f->primeiro == NULL){
        printf("Fila Vazia!\n");
    } else{
        Ficha *aux = f->primeiro;
        while(aux != NULL){
            cont++;
            aux = aux->proximo;
        }
        printf("Total de itens: %i \n", cont);
    }
}

void listar(fila *f){
	if(f->primeiro==NULL){
		printf("\nFila Vazia !!");
	} else {
		Ficha *aux = f->primeiro;
		do {
			printf("\nCódigo: %i. Nome: %s . Telefone: %s. Idade: %i. => %x \n", aux->codigo, aux->nome, aux->telefone, aux->idade, aux);
			aux = aux->proximo;
		} while(aux != NULL);	
	}
}
int main(int argc, char *argv[]) {
	fila f;
	colocarFila(&f);
	colocarFila(&f);
	listar(&f);
	tirarFila(&f);
	listar(&f);
	contar(&f);
	return 0;
}

