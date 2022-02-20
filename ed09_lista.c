/*Lista - é bidirecional, pode-se navegar pela lista em qualquer direção.
A lista permite a inserção e remoção de elementos. Os elementos são criados 
dinâmicamente*/

#include <stdio.h>
#include <stdlib.h>

// TAD lista
typedef struct item{ //nome do struct
    int valor;
    struct item *proximo;
} Item; // nome do TAD

typedef struct lista{ //nome do struct
    Item *primeiro;
} Lista; // nome do TAD

// método lista colocar no início
void colocarNoInicio(Lista *lista, int valor){
    
    printf("Colocar no Início %i\n", valor);
        
    Item *novo = (Item*)malloc(sizeof(Item));
    novo->valor = valor;
    novo->proximo = NULL;
    
    if(lista->primeiro == NULL){
        lista->primeiro = novo;
    } else {
        novo->proximo = lista->primeiro;
        lista->primeiro = novo;
    }
}

// método lista colocar no fim
void colocarNoFim(Lista *lista, int valor){
    
    printf("Colocar no Fim %i \n", valor);
    
    Item *novo = (Item*)malloc(sizeof(Item));
    novo->valor = valor;
    novo->proximo = NULL;
    
    if(lista->primeiro == NULL){
        lista->primeiro = novo;
    } else {
        Item *aux = lista->primeiro;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

// método para remover o primeiro valor.
void removerInicio(Lista *lista){
    
    if(lista->primeiro == NULL){
        printf("Lista vazia\n");
    } else {
        Item *aux = lista->primeiro;
        printf("Removendo o inicio = %i\n", aux->valor);
        lista->primeiro = aux->proximo; // transformando o segundo em primeiro.
        free(aux); // removendo o primeiro
    }
}

// método para remover o último valor
void removerFim(Lista *lista){

    if(lista->primeiro == NULL){
        printf("Lista vazia\n");
    } else {
        Item *aux = lista->primeiro;
        Item *penultimo = aux;
        while(aux->proximo != NULL){
            penultimo = aux;
            aux = aux->proximo;
        }
        penultimo->proximo = NULL; // penultimo vira último
        printf("Removendo o fim = %i\n", aux->valor);
        free(aux); // removendo o ultimo
    }
}

// método para remover a partir do valor informado
void removerPesquisa(Lista *lista, int valor){
    
    if(lista->primeiro == NULL){
        printf("Lista vazia\n");
    } else {
        Item *aux = lista->primeiro;
        Item *penultimo = aux;
        while(aux->proximo != NULL){
            if(valor == aux->valor){
                if(aux == penultimo){ //quando for o primeiro elemento
                    lista->primeiro = aux->proximo;
                } else {
                    penultimo->proximo = aux->proximo;
                }
                printf("Removendo Pesquisa = %i\n", aux->valor);
                free(aux); // removendo pesquisa
                break;
            } else {
                penultimo = aux;
                aux = aux->proximo;
            }
        }
    }
}

// método listar
void listar(Lista *lista){
    Item *aux = lista->primeiro;
    while (aux != NULL){
        printf("Item (%x) %i \n", aux, aux->valor);
        aux = aux->proximo;
    }
}

int main(){
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
    
    removerPesquisa(&l1, 3412); // não irá acontecer nada, pois não existe esse valor.
    
    removerPesquisa(&l1, 21);
    listar(&l1);    
     
    removerPesquisa(&l1, 34);
    removerPesquisa(&l1, 56);
    removerPesquisa(&l1, 16);
    listar(&l1);  
    
    return 0;
}


