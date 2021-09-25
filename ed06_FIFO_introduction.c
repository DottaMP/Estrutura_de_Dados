/*FILA OR FIFO (- First In - First Out)
Estrutura dinâmica de dados composta por itens.

FILA/PILHA vai sempre chamar o próximo elemento/endereço da fila*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{ //TAD próximo
    float numero;
    struct item *proximo; // tipo do ponteiro do tipo item vai dizer qual o próximo elemento da fila, vai definir qual o próximo endereço.
} item;

typedef struct { //TAD topo da fila
    item *primeiro;
} fila;

//queue
void inserirItem(fila *pFila, float numero){
    item *itm = (item*)malloc(sizeof(item)); //ponteiro itm do tipo item, vai receber o endereço do espaço de memória onde o malloc vai retornar um ponteiro do tipo item com o espaço da memória.
    // estrutura do malloc: ex.: float *p1 = (float*)malloc(sizeof(float))
    // malloc é uma alocação dinâmica da memória, pega um endereço da memória e cria um espaço - pega o endereço do espaço de um tipo específico.
    // para conseguir fazer o malloc precisa saber o tamamho em bytes do elemento que quer criar.
    // utiliza-se o sizeof para contar quantos bytes vai precisar alocar na memória.
    itm->numero = numero; //associando itm ao número
    itm->proximo = NULL;
    if(pFila->primeiro==NULL){
        printf("endereço atual %x \n", itm);  
        pFila->primeiro = itm; //associar o endereço de itm (o ponteiro itm sem o * significa que está acessando o endereço)
      //pFila -> primeiro = endereço da fila
    } else{ //se a fila não estiver vazia cai no else, vai perguntar de um em um até achar o fim da fila
        printf("endereço atual %x \n", itm);  
        item *aux = pFila->primeiro; //ponteiro aux do tipo item, pFila pega o primeiro elemento/endereço e joga no ponteiro aux
        while(aux->proximo != NULL){ 
            aux = aux->proximo; //enquanto o próximo não for nulo (ou seja, não for o fim da fila), vai atualizar o aux com o próximo elemento/endereço
        }
        aux->proximo = itm; // quando chegar no fim da fila vai atualizar o próximo com o endereço 
    }
}

//unqueue
void removerItem(fila *pFila){ //ponteiro do tipo fila
    if(pFila->primeiro==NULL){
        printf("fila esta vazia");
    } else{
        printf("removendo endereço %x \n", pFila->primeiro);
        item *aux = pFila->primeiro->proximo; //pega o primeiro elemento o próximo e joga no aux.
        free(pFila->primeiro); //limpa o endereço do primeiro para atualizar o endereço com o conteúdo do aux.
        pFila->primeiro = aux; // o primeiro recebe o aux.
        printf("primeiro end. %x \n", pFila->primeiro);
    }
}

void listar(fila *pFila){ //ponteiro do tipo fila
	if(pFila->primeiro==NULL){
		printf("Lista vazia !!");	
	} else {
		item *aux = pFila->primeiro; // pega o primeiro da lista e joga no aux para ir imprimindo.
		do{
			printf("%x %f \n", aux, aux->numero);
			aux = aux->proximo;	
		} while(aux != NULL); 	
	}
}

int main(int arg){
    fila f; //fila dinâmica
    inserirItem(&f, 5);//passar endereço da fila, vai receber como ponteiro, ou seja, vai receber o endereço.
    inserirItem(&f, 15);
    inserirItem(&f, 8);
	listar(&f);
	removerItem(&f);
	removerItem(&f);
	listar(&f);

    
    return 0;
}




