#include <stdio.h>
#include <stdlib.h>

/* 
Suponha que os elementos do vetor v são do tipo int e cada int
ocupa 8 bytes no seu computador. Se o endereço de v[0] é 55000, qual o
valor daexpressão v + 3?
 */

int main(int argc, char *argv[]) {
	int vet[10], *p;
	p = vet;
	printf("pos. 0 %x \n", p);
	printf("pos. 3 %x \n", (p + 3));
	printf("pos. 0 %x \n", vet);
	printf("pos. 3 %x \n", (vet + 3));
	return 0;
}