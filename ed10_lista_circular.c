/*1-Implemente uma lista circular que represente o gerenciamento de processamento de um sistema operacional, 
além das funções para adicionar, remover e listar, implemente uma função chamada de processar, que fara 
um laço enquanto tiver elementos na lista e deduzira -1 do atributo carga do TAD processo, quando 
carga for igual a 0 chame o metodo para remover o item da lista. Removendo todos os processos da lista encerre o laço*/

#include <stdio.h>
#include <stdlib.h>

typedef struct processo {
  int pid;
  int carga;
  struct processo *prox;
} Processo;

typedef struct lista{
 Processo *primeiro;
} Lista ;

void atualizaUltimo(Lista *lista, Processo *novo){
	Processo *aux = lista->primeiro;
	while(aux->prox != lista->primeiro){
		aux = aux->prox;
	}
	aux->prox = novo;
}

void colocarNoFim(Lista *lista, int pid, int carga){
	printf("\nColocar no Fim: PID = %i e CARGA = %i", pid, carga);
	Processo *novo = (Processo*)malloc(sizeof(Processo));
	novo->pid = pid;
	novo->carga = carga;
	novo->prox = lista->primeiro;  
	
	if(lista->primeiro==NULL){
		lista->primeiro = novo;
		novo->prox = novo;	
	} else {
		Processo *aux = lista->primeiro;
		while(aux->prox != lista->primeiro){ // não se compara mais com NULL e sim com o primeiro, pois ao chegar no fim, volta para o começo.
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

void colocarNoInicio(Lista *lista, int pid, int carga){
	printf("\nColocar no Início: PID = %i e CARGA = %i", pid, carga);
	Processo *novo=(Processo*)malloc(sizeof(Processo));
	novo->pid = pid;
	novo->carga = carga;
	novo->prox = NULL;  
	
	if(lista->primeiro==NULL){
		lista->primeiro = novo;	
		novo->prox = novo;
	} else {
		atualizaUltimo(lista, novo);
		novo->prox = lista->primeiro;
		lista->primeiro = novo;
	}
}

void removerInicio(Lista *lista){
	printf("\nRemovendo o Início = ");
	if(lista->primeiro==NULL){
		printf("Lista vazia\n");	
	} else {
		Processo *aux = lista->primeiro;
		atualizaUltimo(lista, aux->prox);
		printf("PID = %i e CARGA = %i", aux->pid, aux->carga);
		lista->primeiro = aux->prox;	//transformado o segundo em primeiro
		free(aux);
	}
}

void removerFim(Lista *lista){
	printf("\nRemovendo o Fim = ");
	if(lista->primeiro==NULL){
		printf("Lista vazia\n");	
	} else {
		Processo *aux = lista->primeiro;
		Processo *aux2 = aux;
		while(aux->prox != lista->primeiro){
			aux2 = aux;
			aux = aux->prox;
		}
		aux2->prox = lista->primeiro;
	    printf("PID = %i e CARGA = %i\n", aux->pid, aux->carga);
		free(aux);
	}
}

void removeItem(Lista *lista, int pid, int carga){
	printf("\nRemovendo Item = ");
	if(lista->primeiro==NULL){
		printf("Lista vazia\n");	
	} else {
	   Processo *aux = lista->primeiro;
        Processo *penultimo = aux;
        while(aux->prox != NULL){
            if(pid == aux->pid && carga == aux->carga){
                if(aux == penultimo){ //quando for o primeiro elemento
                    atualizaUltimo(lista, aux->prox);
                    lista->primeiro = aux->prox;
                } else {
                    penultimo->prox = aux->prox;
                }
                printf("PID = %i e CARGA = %i\n", aux->pid, aux->carga);
                free(aux); // removendo pesquisa
                break;
            } else {
                penultimo = aux;
                aux = aux->prox;
            }
        }
	}
}
/*processar, que fara 
um laço enquanto tiver elementos na lista e deduzira -1 do atributo carga do TAD processo, quando 
carga for igual a 0 chame o metodo para remover o item da lista. Removendo todos os processos da lista encerre o laço*/
void processar(Lista *lista){
    printf("\nProcessando:");
    Processo *aux = lista->primeiro;
	if(lista->primeiro==NULL){
		printf("Lista vazia\n");	
	} else {
	    do{
	        while(aux->prox != lista->primeiro ){
                if(aux->carga != 0){
                    aux->carga--;
                    printf("\nPID = %i e CARGA = %i", aux->pid, aux->carga);
                    break;
                } 
            }
	    }while(aux->carga != 0);
	}
	printf("\nCarga Zarada!");
	removeItem(lista, aux->pid, aux->carga);
}

void listar(Lista *lista){
    if(lista->primeiro==NULL){
		printf("Lista vazia\n");	
	} else {
       	Processo *aux = lista->primeiro;
       	printf("\nLista de Processos: \n");
    	do {
    	    printf("Processo: PID = %i e CARGA = %i\n", aux->pid, aux->carga);
    		// printf("Processo (%x) %i \n", aux, aux->valor);
    		aux = aux->prox;
    	} while(aux != lista->primeiro);
	}
}

int main(int argc, char *argv[]) {
	Lista l1 = {NULL};
	
	
	colocarNoFim(&l1, 1, 6);
	colocarNoFim(&l1, 2, 1);
	colocarNoFim(&l1, 3, 4);
	colocarNoFim(&l1, 4, 3);
	listar(&l1);
	
	colocarNoInicio(&l1, 9, 2);
	colocarNoInicio(&l1, 8, 1);
	listar(&l1);
	
	removerInicio(&l1);
	listar(&l1);
	
	removerFim(&l1);
	listar(&l1);
		
	removeItem(&l1, 2, 1);
	listar(&l1);
	
	processar(&l1);
	processar(&l1);
	listar(&l1);	
	
	return 0;
}

