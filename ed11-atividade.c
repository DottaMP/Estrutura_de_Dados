/*
1- O que é uma árvore binária e quais seus componentes?
Uma árvore binária (= binary tree) é um conjunto de registros que satisfaz certas condições.  As condições não serão dadas explicitamente, mas elas ficarão implicitamente claras no contexto.  Os registros serão chamados nós (poderiam também ser chamados células).  Cada nó tem um endereço.  Suporemos por enquanto que cada nó tem apenas três campos:  um número inteiro e dois ponteiros para nós. 
um árvore em que cada nó tem zero, um ou dois filhos
Termos:
• Nós contêm todos os itens armazenados na árvore.
• Raiz é o item do topo da árvore
• Filhos são os itens logo abaixo da raiz
• Folha é um nó que não tem filho, é o último item da árvore.

2-Qual a diferença entre uma AB e uma ABB ?
Uma Arvore Binaria (AB) tem seus nos organizado de forma aleatoria, ja uma arvore binaria de busca segue a seguinte logica: onde todos os nós da subárvore esquerda possuem um valor numérico inferior ao nó raiz e todos os nós da subárvore direita possuem um valor superior ao nó raiz (esta é a forma padrão, podendo as subárvores serem invertidas, dependendo da aplicação).
O objetivo desta árvore é estruturar os dados de forma a permitir busca binária.

3-Usando o primeiro exemplo de AB implemente uma função para contar a altura de uma arvore

4-Usando o segundo exemplo de ABB implemente uma função para buscar um elemento na arvore e diga em qual nivel este elemento esta
*/

#include <stdio.h>
typedef struct no {
      int valor; 
      struct no *direita;
      struct no *esquerda;
} No; 

No* inserirRecursivo(No *raiz, int num){
    if(raiz == NULL){
    	No *aux = malloc(sizeof(No));
        aux->valor = num;
		aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else if(num < raiz->valor){
        raiz->esquerda = inserirRecursivo(raiz->esquerda, num);
    }
    else{
        raiz->direita = inserirRecursivo(raiz->direita, num);
    	return raiz;
	}
}

No* buscaRecursiva(No *raiz, int num){
	if(raiz){
		if(num == raiz->valor) 
			return raiz;
		else if(num < raiz->valor)
			return buscaRecursiva(raiz->esquerda, num);
		else
			return buscaRecursiva(raiz->direita, num);
	}return NULL;
}

No* buscaIterativa(No *raiz, int num){
	while(raiz){
		if(num < raiz->valor) 
			raiz = raiz->esquerda; 
		else if(num > raiz->valor) 
			raiz = raiz->direita; 
		else
			return raiz;
	}return NULL;
}

int altura(No *raiz){
	if(raiz == NULL){ 
		return -1;
	}else{ 
		int esq = altura(raiz->esquerda);
		int dir = altura(raiz->direita);
		if(esq > dir)
			return esq + 1;
		else
			return dir + 1;
	}
}

int buscaArvore(No *raiz, int busca){
    if (raiz != NULL){
	    if(raiz->valor==busca){
	        printf("Elemento encontrado %i \n", busca); 
	        return 0;
	    } else {
	         int he, hd;
    	    if((raiz->valor)<busca){
    	        hd = buscaArvore(raiz->direita, busca);    
    	        return hd + 1;
    	    } else {
    	        he = buscaArvore(raiz->esquerda, busca);
    	        return he + 1;
    	    }  
	    } 
    } else{
    	printf("Valor nao encontrado\n");	
	}
    return 0;    
}


void imprimeArvore(No *raiz){
	if(raiz){
		printf("%d ", raiz->valor);
		imprimeArvore(raiz->esquerda);
		imprimeArvore(raiz->direita);
	}
}

void imprimeOrdenado(No *raiz){
	if(raiz){
		imprimeArvore(raiz->esquerda);
		printf("%d ", raiz->valor);
		imprimeArvore(raiz->direita);
	}
}


int main(){
	No *busca, *raiz = NULL;
	int opcao, valor;
	
	do{
		printf("\nDigite a opcao desejada:  \n\n[0] Sair \n[1] Inserir \n[2] Imprimir \n[3] Procurar\n[4] Altura da Arvore\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("\nDigite um numero: ");
				scanf("%d", &valor);
				raiz = inserirRecursivo(raiz, valor);
				break;
			case 2: 
				printf("\nImpressao: ");
				imprimeArvore(raiz);
				printf("\n");
				break;
			case 3:
				printf("\nDigite o valor procurado: ");
				scanf("%d", &valor);
				busca = buscaArvore(raiz, valor);		
				printf("Nivel: %d\n", busca);			
				break;
			case 4:
				printf("\nAltura da arvore: %d\n\n", altura(raiz));
				break; 			
			default:
				if(opcao != 0)
					printf("Opcao Invalida\n");
		}
	}while(opcao != 0);
	
	return 0;
}
