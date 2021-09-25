/*1. O que é e como funciona uma estrutura do tipo fila? ´
É uma estrutura de dados dinâmica que admite remoção de elemntos e inserção de novos objetos.
Ou seja, o primeiro objeto inserido na fila é também o primeiro a ser removido.

2. Em que situações uma fila pode ser utilizada?
Pode ser utilizada na situação de um atendimento, por exemplo, imagine a fila de uma chat online, 
onde a primeira pessoa da fila será a primeira a ser atendidade e consequentemente a primeira a sair. 
Chamando assim, a próxima pessoa da fila.

3. Implemente uma fila dinamica de nomes char[100]. 
O módulo deve conter as funções  criafila,  colocanafila,  tiradafila,  filavazia .  

4. Escreva uma função que devolva o comprimento (ou seja, o número de elementos) da fila.*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int num;
    struct Node *prox;
};

typedef struct Node node;

int tam;

int menu(void);
void opcao(node *FILA, int op);
void inicia(node *FILA);
int vazia(node *FILA);
node *aloca();
void insere(node *FILA);
node *retira(node *FILA);
void exibe(node *FILA);
void libera(node *FILA);

int menu(void)
{
    int opt;
    
    printf("Escolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Zerar fila\n");
    printf("2. Exibir fila\n");
    printf("3. Adicionar Elemento na Fila\n");
    printf("4. Retirar Elemento da Fila\n");
    printf("Opcao: "); scanf("%d", &opt);
    
    return opt;
}

void opcao(node *FILA, int op)
{
    node *tmp;
    switch(op){
        case 0:  	
            libera(FILA);
            break;
        case 1:    	
            libera(FILA);
            inicia(FILA);
            break;
        case 2:   	
            exibe(FILA);
            break;
        case 3:	
            insere(FILA);
            break;
        case 4:   	
            tmp= retira(FILA);
            if(tmp != NULL){
                printf("Retirado: %3d\n\n", tmp->num);
        	    libera(tmp);
        }
        break;
        default:
            printf("Comando invalido\n\n");
 }
}

void inicia(node *FILA)
{
    FILA->prox = NULL;
    tam=0;
}

int vazia(node *FILA)
{
    if(FILA->prox == NULL)
        return 1;
    else
        return 0;
}

node *aloca()
{
    node *novo=(node *) malloc(sizeof(node));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }else{
        printf("Novo elemento: "); scanf("%d", &novo->num);
        return novo;
    }
}

void insere(node *FILA)
{
    node *novo=aloca();
    novo->prox = NULL;

    if(vazia(FILA))
        FILA->prox=novo;
    else{
        node *tmp = FILA->prox;

    while(tmp->prox != NULL)
        tmp = tmp->prox;

        tmp->prox = novo;
    }
    tam++;
}

node *retira(node *FILA)
{
    if(FILA->prox == NULL){
        printf("Fila ja esta vazia\n");
    return NULL;
    }else{
        node *tmp = FILA->prox;
        FILA->prox = tmp->prox;
        tam--;
        return tmp;
    }
}

void exibe(node *FILA)
{
    if(vazia(FILA)){
        printf("Fila vazia!\n\n");
    return ;
    }
    node *tmp;
    tmp = FILA->prox;
    printf("Fila :");
    while( tmp != NULL){
        printf("%5d", tmp->num);
    tmp = tmp->prox;
    }
    printf("\n        ");
    int count;
    for(count=0 ; count < tam ; count++)
        printf("  ^  ");
        printf("\nOrdem:");
    for(count=0 ; count < tam ; count++)
        printf("%5d", count+1);
        printf("\n\n");
}

void libera(node *FILA)
{
    if(!vazia(FILA)){
    node *proxNode,
        *atual;

    atual = FILA->prox;
        while(atual != NULL){
            proxNode = atual->prox;
            free(atual);
            atual = proxNode;
        }
    }  
}

int main(int arg){
    node *FILA = (node *) malloc(sizeof(node));
    if(!FILA){
        printf("Sem memoria disponivel!\n");
    exit(1);
    }else{
        inicia(FILA);
    int opt;

    do{
        opt=menu();
        opcao(FILA,opt);
    }while(opt);

    free(FILA);
    
    return 0;
    }
}

/* Outro jeito
struct itemDaFila {
	char nome[100];
	struct itemDaFila *proximo; 		
} typedef itemDaFila;

int tamanho; 

void criaFila(itemDaFila *fila){
	fila->proximo = NULL;
	tamanho = 0;
}

int filaVazia(itemDaFila *fila){
	if(fila->proximo == NULL){
		return 1;
	}else{
		return 0;
	}
}

itemDaFila *aloca(){
	itemDaFila *novo=(itemDaFila *) malloc(sizeof(itemDaFila));
	if(!novo){
		printf("Memoria Indisponivel!\n");
		exit(1);
	}else{
		printf("Informe o nome: "); scanf("%s", &novo->nome);
		return novo;
	}
}
	
void colocaNaFila(itemDaFila *fila){
	itemDaFila *novoItem = aloca();
	novoItem->proximo = NULL;
	if(filaVazia(fila)){
		fila->proximo= novoItem;
	}else{
		itemDaFila *aux = fila->proximo;
		
		while(aux->proximo != NULL)
		aux = aux->proximo;
		aux->proximo = novoItem;
	}
	tamanho++;
}

// Apaga um item da fila
itemDaFila *tiraDaFila (itemDaFila *fila){
	if(fila->proximo == NULL){
		printf("Fila vazia\n");
		return NULL;
	}else{
		itemDaFila *aux = fila->proximo;
		fila->proximo = aux->proximo;
		tamanho--;
		return aux;		
	}
}

// listar a fila
void listar(itemDaFila *fila){
	if(filaVazia(fila)){
		printf("Fila Vazia\n");
		return ;
	}itemDaFila *aux;
	aux = fila->proximo;
	printf("Fila: ");
	
	while(aux != NULL){
		printf("%4s ", aux->nome);
		aux = aux->proximo;
	}printf(" \n");
	int contador;
	for(contador = 0; contador < tamanho; contador++)
		for(contador = 0; contador < tamanho; contador++)
		printf("%8d", contador +1);
		printf("        \n");
}



void limpaFila(itemDaFila *fila){
	if(!filaVazia(fila)){
		itemDaFila *proximoItem, *itemAtual;
		
		itemAtual = fila->proximo;
		while(itemAtual != NULL){
			proximoItem = itemAtual->proximo;
			free(itemAtual);
			itemAtual = proximoItem;
		}
	}
}

void comprimentoFila(itemDaFila *fila){
	if(filaVazia(fila)){
		printf("Fila Vazia\n");
		return ;
	}
	int contador;
	for(contador = 0; contador < tamanho; contador++){
		for(contador = 0; contador < tamanho; contador++);
	}
		printf("Comprimento atual da fila: %i", tamanho);
}

int main(){
    itemDaFila *fila = (itemDaFila *)malloc(sizeof(itemDaFila));
	if(!fila){
		printf("Memoria insuficiente\n");
		exit(1);
	}else{
	criaFila(fila);
    colocaNaFila(fila); 
    colocaNaFila(fila);
    colocaNaFila(fila);
    colocaNaFila(fila);
    colocaNaFila(fila);
    printf("\n\nTodos os dados da fila (FIFO):\n");
    listar(fila);
    printf("\n\nA fila depois do delete (FIFO):\n");
    tiraDaFila(fila); // Apaga a primeira entrada da fila
    tiraDaFila(fila);
    listar(fila);
    
    //printf("\n\nNumero de elementos restantes na fila: %i \n", tamanho);
    comprimentoFila(fila);
    free(fila);
    return 0;
	}
}
*/
