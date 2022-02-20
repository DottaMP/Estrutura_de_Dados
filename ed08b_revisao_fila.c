#include <stdio.h>
#include <stdlib.h>

/* FIFO - First in First out */
struct item{
	int pid;
	char programa[20]; 
	struct item *proximo;
} typedef item;

struct fila{
	item *primeiro;
} typedef fila;

//queue
void colocarFila(fila *f){
	item *novo = (item*)malloc(sizeof(item));
	printf("Informe o PID:");
	scanf("%i", &novo->pid);
	printf("Informe o nome do programa:");
	scanf("%s", &novo->programa);
	novo->proximo = NULL;
	if(f->primeiro==NULL){
		f->primeiro = novo;
		printf("Primeiro da fila %x \n", novo);
	} else {
		//procurando o fim da fila o ultimo item tem o atributo proximo = NULL
		item *aux = f->primeiro;
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
		printf("Item removido %i, %s => %x \n", f->primeiro->pid, f->primeiro->programa, f->primeiro);
		item *aux = f->primeiro->proximo; 	
		free(f->primeiro);
		f->primeiro = aux;
	}
}

void listar(fila *f){
	if(f->primeiro==NULL){
		printf("Fila Vazia !!");
	} else {
		item *aux = f->primeiro;
		do {
			printf("Item %i, %s => %x \n", aux->pid, aux->programa, aux);
			aux = aux->proximo;
		} while(aux != NULL);	
	}
}



int main(int argc, char *argv[]) {
	fila f;
	colocarFila(&f);
	colocarFila(&f);
	colocarFila(&f);
	listar(&f);
	tirarFila(&f);
	tirarFila(&f);
	listar(&f);
	return 0;
}




