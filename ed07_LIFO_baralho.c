/*Implemente uma pilha de um TAD que represente as cartas 
de um baralho Naipe+Carta. exemplo: 9 de Ouros
Utilizando os metodos POP e PUSH  distribua as cartas de 
cima para baixo LIFO (Last In, First Out)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char naipe[20];
    char carta[20];    
    struct item *proximo; //elemento atual vai ter o endereço do próximo item.
} typedef item;

struct pilha {
    struct item *topo; //carta que está no topo da pilha
} typedef pilha;

int vazia(pilha *p){
    if(p->topo==NULL){
        return 1; //true
    } else{
        return 0; //false
    }
}

void push(pilha *p){
    //printf("push %s \n", n);
    item *novo = (item*)malloc(sizeof(item)); //criar novo item
    printf("Informe o Naipe: ");
    scanf("%s", novo->naipe);
        printf("Informe o número: ");
    scanf("%s", novo->carta);
    novo->proximo = NULL;
    
    //pilha vazia
    if(vazia(p)){
        p->topo = novo;
    } else { //quando já temos cartas no baralho
        item *aux = p->topo;
        novo->proximo = aux;
        p->topo = novo;
    }
    printf("Nova carta %s, %s => %x \n", novo->naipe, novo->carta, novo);
}

void pop(pilha *p){
    //printf("pop \n");
    if(vazia(p)){
        printf("Sem cartas \n");
    } else {
        printf("Carta removida %s, %s => %x \n", p->topo->naipe, p->topo->carta, p->topo);
        item *aux = p->topo->proximo;
        free(p->topo);
        p->topo = aux;
    }
}

void contar(pilha *p){
    int cont=1; //contador
    if(vazia(p)){
        printf("Sem cartas \n");
    } else {
        item *aux = p->topo;
        while(aux->proximo!=NULL){ //enquanto o proximo for diferente de nulo
            cont++;
            aux=aux->proximo;
        }
        printf("Total de cartas do baralho: %i \n", cont);
    }
}

void mostrar(pilha *p){
    printf("Topo do Baralho = %s, %s => %x \n", p->topo->naipe, p->topo->carta, p->topo);
}

int main(int argc, char *argv[]) {
    pilha p;
    push(&p);
    push(&p);
    push(&p);
    pop(&p);
    pop(&p);
    pop(&p);

    mostrar(&p);
    contar(&p);
   
    return 0;
}


