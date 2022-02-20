/*1-O que é TAD e qual a sua aplicação? Dê um exemplo de uma implementação em linguagem C de um TAD
    R: TAD - Tipo Abstrato de Dados, são tipos que podem ser criados pelo próprio programador C, para conseguir
    representar informações de uma forma mais direta. se concretiza através de um tipo de dado(em geral uma struct) 
    que define variáveis que armazenam dos dados e de um conjunto de funções que operam sobre estas variáveis. 
    Exemplo: Uma agenda, onde nossa variável "agenda" teria essas informações:teria o nome, endereço e telefone das pessoas.
    
2-Defina os conceitos de FILAS e PILHAS, exemplifique possíveis implementações de cada uma.
    R:_FILA ou FIFO (First In - First Out)- É uma estrutura de dados dinâmica que admite remoção de elementos e inserção de novos objetos.
    Onde o primeiro objeto inserido na fila é também o primeiro a ser removido. 
    Pode ser utilizada na situação de um atendimento, por exemplo, imagine a fila de uma chat online, 
    onde a primeira pessoa da fila será a primeira a ser atendidade e consequentemente a primeira a sair. 
    Chamando assim, a próxima pessoa da fila.
    _PILHAS ou LIFO (Last In, First Out) - É uma estrutura de dados dinâmica que possuí a ideia fundamental de que todo o seu acesso é 
    feito pelo topo. Ou seja, quando um elemento novo é inserido na pilha esse passa a ser o elemento do topo, e o único que pode ser removido
    da pilha é o topo, sendo assim os elementos são retirados da pilha em ordem inversa. O último que entra será o primeiro a sair.

3-Implemente uma fila dinâmica em um programa que simule o controle de uma pista de decolagem de aviões em um aeroporto. 
Neste programa, o usuário deve ser capaz de realizar as seguintes tarefas:
a) Listar o número de aviões aguardando na fila de decolagem;
b) Autorizar a decolagem do primeiro avião da fila;
c) Adicionar um avião à fila de espera;
d) Listar todos os aviões na fila de espera;
e) Listar as características do primeiro avião da fila.
Considere que os aviões possuem um nome e um número inteiro como identificador. Adicione outras características conforme 
achar necessário.*/

#include <stdio.h>
#include <stdlib.h>
struct aviao{
	char nome[50]; //Nome do avião
	char destino [50]; //Destino do voo
	int codigo; //código cia
	char cia[50]; //nome da cia aérea
	struct item *proximo;
};
typedef struct aviao item;

item *criaFila(){
	item *fila=(item*)malloc(sizeof(item));
	fila->proximo = NULL;
	return fila;
}

int filaVazia(item *p)
{
 	if(p->proximo==NULL){
 		return 1;	
	} else {
		return 0;
	}
}

//colocaNaFila
//Adicionar um avião à fila de espera
void queue(item *fila)
{
	item *novo=(item*)malloc(sizeof(item));
	printf("Informe o nome do aviao: ");
	scanf("%s", &novo->nome);
	printf("Informe o código: ");
	scanf("%i", &novo->codigo);
	printf("Informe a cia aérea: ");
	scanf("%s", &novo->cia);
	printf("Informe o destino: ");
	scanf("%s", &novo->destino);
	novo->proximo = NULL;  
	
	if(filaVazia(fila)==1){
		fila->proximo=novo;	
	} else {
		item *aux = fila->proximo;
		while(aux->proximo != NULL){
			aux = aux->proximo;
		}
		aux->proximo = novo;
	}
}

//Autorizar a decolagem do primeiro avião da fila
//tiraDaFila
void unqueue(item *fila)
{
   if(filaVazia(fila)==0){
   		item *aux = fila->proximo; 	
   		fila->proximo = aux->proximo;
		printf("Dados do aviao autorizado: \n Nome: %s. Código: %i. Cia: %s. Destino: %s \n", aux->nome, aux->codigo, aux->cia, aux->destino);
		free(aux);    
   }
}

//Listar as características do primeiro avião da fila
void primeiro(item *fila)
{
   if(filaVazia(fila)==0){
   		item *aux = fila->proximo; 	
		printf("Dados avião (primeiro da fila): %s. Código: %i. Cia: %s. Destino: %s \n", aux->nome, aux->codigo, aux->cia, aux->destino);
   }
}

//Listar o número de aviões aguardando na fila de decolagem
void mostrar(item *fila)
{
   	item *aux = fila->proximo;
	while (aux != NULL)
	{
	printf("Avião: %s. Código: %i. Cia: %s. Destino: %s \n", aux->nome, aux->codigo, aux->cia, aux->destino);
    aux = aux->proximo;
	}
}

void contar(item *fila)
{
	int contador = 0;
   	item *aux = fila->proximo;
	while(aux != NULL){
		contador++;
		aux = aux->proximo;
	}
	printf("Numero de Avioes na Fila de espera : %i \n", contador);
}

int main(int menu, int opcao) {
	item *fila = criaFila(); 
	
	printf("**Simulação de controle de uma pista de decolagem**");
	do
	{
	printf("\n-------------------------------------------------------------");
	printf("\n[1] Add um avião na fila de espera\n");
	printf("[2] Mostrar os aviões aguardando na fila de espera\n");
	printf("[3] Autorizar a decolagem do primeiro aviao\n");
	printf("[4] Numero de avioes aguardando na fila de decolagem. \n");
	printf("[5] Dados do primeiro aviao da fila.");
	printf("\n\nInsira a opção desejada: ");
	scanf("%i", &menu);
	switch(menu)
	{
	case 1: queue(fila); break;
	case 2: mostrar(fila); break;
	case 3: unqueue(fila); break;
	case 4: contar(fila); break;
	case 5: primeiro(fila); break;
	default: printf("Opcao Invalida\n"); break;
	}
	printf("Deseja continuar? [1] Sim [2] Nao:");
	scanf("%i", &opcao);
	}
	while(opcao == 1);
	return 0;
}

/*
4-Implemente uma pilha dinamica que simule o historico de navegação de um browser, onde a cada pagina acessada uma nova 
url e adicionada ao topo da pilha, implemente as seguintes funções:
a)adicionar nova url ao topo da pilha
b)mostrar url atual
c)voltar, removendo o topo da pilha 
d)quantidade de urls adicionadas a pilha*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct item {
    char historico[20]; 
    char dia[20];
    struct item *proximo; //elemento atual vai ter o endereço do próximo item.
} typedef item;

struct pilha {
    struct item *topo; //url que está no topo da pilha
} typedef pilha;

pilha *criarPilha(){
	pilha *p = (pilha*)malloc(sizeof(pilha));
 	p->topo = NULL;
 	return p;
}

//adicionar nova url ao topo da pilha
void push(pilha *p){

    item *novo = (item*)malloc(sizeof(item)); //criar novo item
    printf("Informe a url: ");
    scanf("%s", &novo->historico);
	printf("Informe o dia de acesso (dd/mm/yyyy):");
	scanf("%s", &novo->dia);
    novo->proximo = NULL;
    
    //pilha vazia
	if(p->topo==NULL){
		p->topo = novo;
	}else{
		item *aux =  p->topo;
		novo->proximo = aux;
		p->topo = novo;
	} printf("Nova url %s, %s => %x \n", novo->historico, novo->dia, novo);
}

//voltar, removendo o topo da pilha 
void pop(pilha *p){
	if(p->topo==NULL){
	printf("Pilha vazia.\n");
	}else{
		printf("URL Removida: %s, Data de Acesso: %s => %x \n", p->topo->historico, p->topo->dia, p->topo);
     	item *aux = p->topo->proximo;
     	free(p->topo); //remove da memoria
     	p->topo = aux; 
     }
}
//mostrar url atual
void mostrar(pilha *p){
    printf("Topo do histórico: %s, Data de Acesso: %s => %x \n", p->topo->historico, p->topo->dia, p->topo);
}

//quantidade de urls adicionadas a pilha
void contar(pilha *p){
	int contador = 1;
	if(p->topo==NULL){
		printf("Historico Vazio \n");
	}else{
		item*aux = p->topo;
		while(aux->proximo!=NULL){
			contador++;
			aux = aux->proximo;
		}printf("Total de URLs: %i\n", contador);
	}
}

int main(int menu, int opcao) {
	pilha *p = criarPilha();
	
	printf("**Simulação do Histórico de Navegacao**");
	do{
	printf("\n------------------------------------------------------------------");
	printf("\n[1] Adicionar uma url: \n");
	printf("[2] URL Atual: \n");
	printf("[3] Remover ultima url: \n");
	printf("[4] Quantidade de urls: \n");
	printf("\nInsira a opcao desejada: ");
	scanf("%i", &menu);
	
	switch(menu){
	case 1: push(p); break;
	case 2: mostrar(p); break;
	case 3: pop(p); break;
	case 4: contar(p); break;
	default: printf("Opcao Invalida\n"); break;
	}
	printf("\n\nDeseja continuar? [1] Sim [2] Não: ");
	scanf("%i", &opcao);
	}
	while(opcao == 1);
   
    return 0;
}

