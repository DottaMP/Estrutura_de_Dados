#include <stdio.h>
#include <stdlib.h>

/* 
Os programas (trechos de código) abaixo possuem erros. Qual(is)?
Como deveriam ser?
a)
void main() {
int x, *p;
x = 100;
p = x;
printf(“Valor de p: %d.\n”, *p);}
b)
void troca (int *i, int *j) {
int *temp;
*temp = *i;
*i = *j;
*j = *temp;}

c)
char *a, *b;
a = “abacate”;
b = “uva”;
if (a < b)
printf (“%s vem antes de %s no dicionário”, a, b);
else
printf (“%s vem depois de %s no dicionário”, a, b);

*/
int main(int argc, char *argv[]) {
	/*
	int x, *p;
	x = 100;
	p = x;
	printf(“Valor de p: %d.\n”, *p);
	*/
	
	int x, *p;
	x = 100;
	p = &x; // p = x;
	printf("Valor de p: %d.\n", *p);
	
	int n=6, m=9;
	troca(&n, &m); //troca(a, b);
	printf("n=%i, m=%i \n", n, m);
	
	char *a, *b;
	b = "abacate";
	a = "uva";
	if(*a < *b) // a<b
		printf ("%s vem antes de %s no dicionario", a, b);
	else
		printf ("%s vem depois de %s no dicionario", a, b);
	
	return 0;
}

void troca(int *i, int *j) {
	int temp; //int *temp; 
	temp = *i;
	*i = *j;
	*j = temp; //j = *temp;
}

