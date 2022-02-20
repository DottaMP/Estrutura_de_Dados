/*Dada a seguinte TAD  Ficha{int codigo,  char nome[50],  char telefone[30], int idade}    
Implemente uma pilha com esta TAD*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ficha {
	int codigo;
	char nome[50]; 
	char telefone[30];
	int idade;
	struct Ficha *proximo;
} typedef Ficha;

struct pilha {
    struct Ficha *topo;
} typedef pilha;

int vazia(pilha *p){
    if(p->topo==NULL){
        return 1; //true
    } else{
        return 0; //false
    }
}

void push(pilha *p){
    Ficha *novo = (Ficha*)malloc(sizeof(Ficha)); //criar novo item
	printf("Informe o código: ");
	scanf("%i", &novo->codigo);
	printf("Informe o nome: ");
	scanf("%s", &novo->nome);
	printf("Informe o telefone: ");
	scanf("%s", &novo->telefone);
	printf("Informe a idade: ");
	scanf("%i", &novo->idade);

    novo->proximo = NULL;
    
    //pilha vazia
    if(vazia(p)){
        p->topo = novo;
    } else { //quando já temos cartas no baralho
        Ficha *aux = p->topo;
        novo->proximo = aux;
        p->topo = novo;
    }
    printf("Novo Item: %i, %s, %s, %i => %x \n", novo->codigo, novo->nome, novo->telefone, novo->idade, novo);
}

void pop(pilha *p){
    //printf("pop \n");
    if(vazia(p)){
        printf("Pilha Vazia \n");
    } else {
        printf("Item removido: Código: %i. Nome: %s . Telefone: %s. Idade: %i. => %x \n", p->topo->codigo, p->topo->nome, p->topo->telefone, p->topo->idade, p->topo);
        Ficha *aux = p->topo->proximo;
        free(p->topo);
        p->topo = aux;
    }
}

void contar(pilha *p){
    int cont=1; //contador
    if(vazia(p)){
        printf("Pilha Vazia \n");
    } else {
        Ficha *aux = p->topo;
        while(aux->proximo!=NULL){ //enquanto o proximo for diferente de nulo
            cont++;
            aux=aux->proximo;
        }
        printf("Total de itens na pilha: %i \n", cont);
    }
}

void listar(pilha *p){
    printf("Topo da pilha = Código: %i. Nome: %s . Telefone: %s. Idade: %i. => %x \n", p->topo->codigo, p->topo->nome, p->topo->telefone, p->topo->idade, p->topo);
}

int main(int argc, char *argv[]) {
    pilha p;
    push(&p);
    push(&p);
    push(&p);
    pop(&p);
    pop(&p);

    listar(&p);
    contar(&p);
   
    return 0;
}
