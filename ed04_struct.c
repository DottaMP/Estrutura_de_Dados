#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
/* 
2- Crie um vetor de 10 posições de um struct com os 
dados de um aluno{ra, nome, idade}  
atraves de um ponteiro passe o parametro por 
referencia para a função adicionar 
que ira adicionar um novo struct dentro do vetor;
*/


typedef struct{
	int ra;
	char nome[61];
	int idade;
} tAluno;

int adicionar(tAluno *p, int i);
void mostrar(tAluno *p, int i);

int main(int argc, char *argv[]) {
	tAluno vetor[10];
	tAluno *p;
	p = vetor;
	int x = 0;
	x = adicionar(p, x);
	x = adicionar(p, x);
	mostrar(p,0);
	mostrar(p,1);
	return 0;
}

int adicionar(tAluno *p, int i){
	tAluno t1;
	printf("Informe o ra:");
	scanf("%i", &t1.ra);
	printf("Informe a idade:");
	scanf("%i", &t1.idade);
	printf("Informe o nome:");
	gets(t1.nome);
	p[i] = t1; // *(p+i) = t1;
	return i + 1;
}

void mostrar(tAluno *p, int i){
	printf("ra: %i \n", p[i].ra);
	printf("nome: %s \n", p[i].nome);
	printf("idade: %i \n", p[i].idade);
}

