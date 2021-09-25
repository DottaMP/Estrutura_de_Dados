#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*estrutura de dados heterogenea */

struct {
	float p1;
	float p2;
	float p3;
	float media;
} typedef avaliacoes;

struct {
	char nome[50];
	int idade;
	avaliacoes notas; 
} typedef aluno;

int main(int argc, char *argv[]) {
	aluno aluno1 = {"maria da silva", 22, {5,6,7,0}};
	aluno aluno2, alunox;
	int x = sizeof(aluno);
	printf("Qtd Bytes para o tipo aluno=%i \n", x);
	aluno *p;
	p = &aluno1;
	
	printf("Informe a idade do aluno 2:");
	scanf("%i", &aluno2.idade);
	
	aluno1.idade = 22;
	aluno1.notas.p1 = 8.5;
	aluno1.notas.p2 = 9;
	aluno1.notas.media = (aluno1.notas.p1 + aluno1.notas.p2) /2;
	
	//maria.nome = "maria da silva";
	printf("Aluna maria end na memoria=%x \n", p);
	
	
	printf("Idade=%i, media=%f nome=%s \n", aluno1.idade, aluno1.notas.media, aluno1.nome);
	
	
	return 0;
}
