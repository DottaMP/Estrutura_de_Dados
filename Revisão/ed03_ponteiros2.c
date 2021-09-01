#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int y, *p, x;
	y = 0;
	p = &y;
	x = *p;
	x = 4;
	++(*p);
	x--;
	(*p) += x++;
	printf ("y = %d\n", y);
		
	p++; //movimento 4bytes na memoria  &00  => &04
 	(*p)++; //acessando o valor do end. referenciado e somando + 1
	*(++p); //movimentando 4bytes do end. na memoria
	//b) O que quer dizer *(p+10)?
		
	return 0;
}
