//Fatorial
#include <stdio.h>
#include <stdlib.h>

int fatorialR(int num)
{
  int ret;	
  printf("num=%i \n", num);
  if(num == 0) 
  {
  	printf("saida=1 \n");
    return 1;
  }
  else 
  {
  	ret = fatorialR(num-1);
  	printf("%i x %i = %i \n", num, ret, (num*ret));
    return num * ret;
  }
}

int pow(int n, int e){
	int ret;	
    printf("e=%i \n", e);
	
	if(e==0){
		printf("saida =>1 \n");
		return 1;
	} 
	else 
	{
		ret = pow(n, e-1);
		printf("%i x %i = %i \n", n, ret, (n*ret));
		return n*ret;	
	}		
}



int main(int argc, char *argv[]) {
	int x = fatorialR(5);
	printf("Fatorial de 5 = %i \n",x);
	int y = pow(2,5);
	printf("2 elevado a 5 = %i \n", y);
	return 0;
}


