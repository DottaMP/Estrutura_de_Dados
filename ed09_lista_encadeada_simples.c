/*1- O que são listas e quais suas utilizações?
Uma lista encadeada, e uma estrutura de armazenamento de dados dinamica e nao contigua, 
o espaço total de memória gasto pela estrutura é proporcional ao número de elementos nela armazenado. 
Por nao ser contíguo, não temos acesso direto aos elementos da lista. Para que
seja possível percorrer todos os elementos da lista, devemos explicitamente guardar o
encadeamento dos elementos, o que é feito armazenando-se, junto com a informação de
cada elemento, um ponteiro para o próximo elemento da lista. 

2- Qual a diferença entre lista simplesmente ligada, circular e duplamente ligada ?
Lista simplesmente ligada - A estrutura consiste numa seqüência encadeada de elementos, em geral chamados de
nós da lista. A lista é representada por um ponteiro para o primeiro elemento (ou nó).
Do primeiro elemento, podemos alcançar o segundo seguindo o encadeamento, e assim
por diante. O último elemento da lista aponta para NULL, sinalizando que não existe um
próximo elemento.
Listas circulares
Algumas aplicações necessitam representar conjuntos cíclicos. 
Numa lista circular, o último elemento tem como próximo o primeiro elemento da lista,
formando um ciclo. A rigor, neste caso, não faz sentido falarmos em primeiro ou último
elemento. A lista pode ser representada por um ponteiro para um elemento inicial
qualquer da lista.
Listas duplamente encadeadas
Neste caso cada elemento tem um ponteiro para o próximo
elemento e um ponteiro para o elemento anterior. Desta forma, dado um elemento,
podemos acessar ambos os elementos adjacentes: o próximo e o anterior. Se tivermos
um ponteiro para o último elemento da lista, podemos percorrer a lista em ordem
inversa, bastando acessar continuamente o elemento anterior, até alcançar o primeiro
elemento da lista, que não tem elemento anterior (o ponteiro do elemento anterior vale
NULL).

3-Escreva um programa de lista encadeada simples que armazene dois valores no tad minimo e maximo 

4-Crie uma função para listar a menor valor para minimo de todas as ocorrencias e o maior valor para o maximo de todas as ocorrencias*/

#include <stdio.h>
#include <stdlib.h>


typedef struct no {
  int min;
  int max;
  struct no* prox;
} No;

typedef struct lista{
	No *primeiro;
} Lista;


void imprimir(Lista *lista) {
  printf("Imprimir=========>\n");    
  No *aux = lista->primeiro;
  while(aux != NULL) {
    printf("%x %i %i \n", aux, aux->min, aux->max);
    aux = aux->prox;
  }
}

void inserir(Lista *lista, int min, int max) {
  No *novo = (No*)malloc(sizeof(No));
  novo->max  = max;
  novo->min  = min;
  novo->prox = NULL;  // Ultimo elemento da lista
  if (lista->primeiro == NULL) { 
    lista->primeiro = novo; //lista vazia 
  } else {
   	No *aux = lista->primeiro;
	while(aux->prox != NULL) {
		aux = aux->prox;
	}
	aux->prox = novo;
	}
}

void inserirInicio(Lista *lista, int min, int max) {
  No *novo = (No*)malloc(sizeof(No));
  novo->max  = max;
  novo->min  = min;
  novo->prox = NULL;  // Ultimo elemento da lista
  
  if (lista->primeiro == NULL) { 
    lista->primeiro = novo; //lista vazia 
  } else {
   	No *aux = lista->primeiro;
	novo->prox = aux;
	lista->primeiro = novo;  
  }
}

void remover(Lista *lista) {
  if(lista->primeiro == NULL){
  	printf("lista vazia");
  } else {
  	No *aux = lista->primeiro->prox; //end. do segundo elemento
  	printf("remover inicio %x %i %i \n", lista->primeiro, lista->primeiro->min, 
	  	lista->primeiro->max);
	free(lista->primeiro); //remove item da memoria
  	lista->primeiro = aux;
  }
}
 
 
 void removerFim(Lista *lista) {
  if(lista->primeiro == NULL){
  	printf("lista vazia");
  } else {
  	No *aux = lista->primeiro;
  	No *anterior;
	while(aux->prox != NULL) {
		anterior = aux;
		aux = aux->prox;
	}
	anterior->prox = NULL;
	printf("remover fim %x %i %i \n", aux, aux->min, 
	  	aux->max);
	free(aux);
  }
}
 
 
 
void imprimirMenorMaior(Lista *lista) {
  int minimo, maximo;
  printf("Imprimir=========>\n");    
  No *aux = lista->primeiro;
  minimo = aux->min;
  maximo = aux->max;
  while(aux != NULL) {
		if(aux->min<minimo) minimo = aux->min;
		if(aux->max>maximo) maximo = aux->max;
        aux = aux->prox;
  }
  printf("min=%i max=%i \n", minimo, maximo);
}
   
int main(int argc, char *argv[]) {
  Lista lista = {NULL};
  inserir(&lista, 1, 5);
  inserir(&lista, 3, 52);
  inserir(&lista, 54, 57);
  inserir(&lista, 123, 523);
  imprimir(&lista);
  imprimirMenorMaior(&lista);
  remover(&lista);
  remover(&lista);
  inserir(&lista, 154, 2257);
  imprimir(&lista);
  removerFim(&lista);
  imprimirMenorMaior(&lista);  
  return 0;
}
