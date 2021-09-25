#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item{
    char nome[100];
    struct item *proximo;
}typedef item;

struct fila{
    struct item *primeiro;
}typedef fila;

int filaVazia(fila *f){
    if(f->primeiro==NULL){
        return 1;
    } else{
        return 0;
    }
}

fila *criaFila(){
    fila *f = (fila*)malloc(sizeof(fila));
    return f;
}

void colocaNaFila(fila *f, char *n){
    printf("coloca %s \n", n);
    item *novo = (item*)malloc(sizeof(item));
    strcpy(novo->nome, n);
    novo->proximo = NULL;
    if(filaVazia(f)){
        f->primeiro = novo;
    } else{
        item *aux = f->primeiro; //ponteiro auxiliar que começa como primeiro, e vai perguntar se tem alguém atrás dele
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

void tiraDaFila(fila *f){ //remove sempre o primeiro
    printf("tira \n");
    if(filaVazia(f)){
        printf("fila está vazia!");
    } else{
        item *aux = f->primeiro->proximo; //pega o endereço do segundo da fila e armazena no proximo.
        free(f->primeiro); //limpa da memória o primeiro
        f->primeiro = aux; //o segundo da fila se torna o primeiro
    }
}

void comprimento(fila *f){ //contar
    int cont=1;
    if(filaVazia(f)){
        printf("fina está vazia!\n");
    } else{
        item *aux = f->primeiro;
        while(aux != NULL){
            cont++;
            aux = aux->proximo;
        }
        printf("Total de itens: %i \n", cont);
    }
}

void mostrar(fila *f){
    printf("Topo da pilha=%s %x \n", f->primeiro->nome, f->primeiro);
}

int main(int argc, char *argv[]){
    fila f;
    
    colocaNaFila(&f, "Maria");
    colocaNaFila(&f, "João");
    colocaNaFila(&f, "José");
    colocaNaFila(&f, "Ana");
    mostrar(&f);
    comprimento(&f);
    tiraDaFila(&f);
    tiraDaFila(&f);
    mostrar(&f);
    comprimento(&f);    
    return 0;
}

