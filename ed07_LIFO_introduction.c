/*PILHA / LIFO (Last In, First Out)
Métodos POP e PUSH*/

#include <stdio.h>
#include <stdlib.h>

struct item { //TAD ITEM
float numero;
struct item *proximo; // ponteiro do tipo item
} typedef item;

struct pilha { //TAD PILHA, vai ter o endereço do primeiro item
struct item *primeiro; // ponteiro do tipo item
} typedef pilha;

//método push add elementos
void push(pilha *p, float n){ //ponteiro do tipo pilha e numero tipo float
    printf("push %f \n", n);
    item *novo = (item*)malloc(sizeof(item)); //ponteiro do tipo item com nome de novo, para criar novo item dinamicamente na memória utiliza-se o malloc
    novo->numero = n;//novo acessa o numero que recebe a variável n, precisa do endereço da variável criada dinâmicamente
    novo->proximo = NULL; //associou o null ao próximo para limpar o lixo da memória
    
    if(p->primeiro==NULL){ //verificar se a pilha está vazia, pois caso esteja irá associar o endereço do novo elemento ao ponteiro primeiro na pilha p.
        p->primeiro = novo;
    } else{

        novo->proximo = p->primeiro; //se não estiver vazia, pegará o endereço do atual e jogará no próximo
        p->primeiro = novo;//o novo item será o primeiro topo da pilha
    }
}

//método pop remover elementos
void pop(pilha *p){ //quando fala em pilha, pode-se apenas remover  o topo da pilha
    printf("pop \n");
    if(p->primeiro==NULL){//primeira coisa verificar se a pilha está vazia, pois caso esteja não é possível remover nada
        printf("Pilha vazia \n");
    } else{
        item *novoTopo = p->primeiro->proximo;//pega o primeiro e depois o próximo
        free(p->primeiro); //vai limpar da memóra o endereço primeiro
        p->primeiro = novoTopo; //depois atualiza o primeiro com o novoTopo
        
    }
}

//mostrar, sempre mostra o topo, pois não faz sentido listar uma pilha.
void mostrar(pilha *p){
    printf("Topo da pilha=%f %x \n", p->primeiro->numero, p->primeiro);
}

int main(int arg, char *argv[]){
    pilha p; //variável p do tipo pilha
    
    push(&p, 23); //add item a pilha 
    push(&p, 15);
    push(&p, 12);
    push(&p, 68);
    
    mostrar(&p);
    pop(&p);
    mostrar(&p);
    pop(&p);
    mostrar(&p);
    push(&p, 568);
    mostrar(&p);
    
    return 0;
}

