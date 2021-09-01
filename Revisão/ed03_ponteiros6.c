#include <stdio.h>
#include <stdlib.h>

/* 
Escreva uma função mm que receba um vetor inteiro v[0..n-1] e os
endereçosde duas variáveis inteiras, digamos min e max, e deposite nessas
variáveis o valor de um elemento mínimo e o valor de um elemento máximo do
vetor.Escreva também uma função main que use a função mm.
 */

int main(int argc, char *argv[]) {
	int min, max;
	int v[] = {1,3,6,8,2,9,3,7,12,87};
	mm(v, &min, &max);
	printf("Min=%i, Max=%i \n", min, max);
	return 0;
}

void mm(int *p, int *pMin, int *pMax){
	int x;
	*pMin = *p;
	*pMax = *p;
	for(x=0; x<10; x++){
		if(*(p+x)<*pMin) *pMin = *(p+x); //v[x]
		if(*(p+x)>*pMax) *pMax = *(p+x); 
	}
}