#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char nome[50];
    struct item *proximo;
} typedef item;

struct pilha {
    struct item *primeiro;
} typedef pilha;

void push(pilha *p, char *n){
    printf("push %s \n", n);
    item *novo = (item*)malloc(sizeof(item));
    strcpy(novo->nome, n); //utiliza-se o strcpy pois trata-se de um vetor de caracteres, então precisa copiar o vetor para a outr aposição
    novo->proximo = NULL;
    //pilha vazia
    if(vazia(p)){
        p->primeiro = novo;
    } else {
        novo->proximo = p->primeiro;
        p->primeiro = novo;
    }
}

void pop(pilha *p){
    printf("pop \n");
    if(vazia(p)){
        printf("Pilha vazia \n");
    } else {
        item *novoTopo = p->primeiro->proximo;
        free(p->primeiro);
        p->primeiro = novoTopo;
    }
}

void contar(pilha *p){
    int cont=1; //contador
    if(vazia(p)){
        printf("Pilha vazia \n");
    } else {
        item *aux = p->primeiro;
        while(aux->proximo!=NULL){ //enquanto o proximo for diferente de nulo
            cont++;
            aux=aux->proximo;
        }
        printf("Total de Itens da pilha: %i \n", cont);
    }
}

int vazia(pilha *p){
    if(p->primeiro==NULL){
        return 1; //true
    } else{
        return 0; //false
    }
}

void mostrar(pilha *p){
    printf("Topo da pilha=%s %x \n", p->primeiro->nome, p->primeiro);
}

int main(int argc, char *argv[]) {
    pilha p;

    push(&p, "maria"); //passa o endereço da pilha seguido do valor que irá receber
    push(&p, "Joao");
    push(&p, "ana");
    push(&p, "jose");
    contar(&p);
    mostrar(&p);
    pop(&p);
    mostrar(&p);
    pop(&p);
    mostrar(&p);
    push(&p, "julia");
    mostrar(&p);
    contar(&p);
    return 0;
}


