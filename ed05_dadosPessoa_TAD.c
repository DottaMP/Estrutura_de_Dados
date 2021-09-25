#include <stdio.h>
#include <stdlib.h>

struct {
	int ddd;
	int numero;
} typedef telefone;

struct {
	char rua[100];
	int numero;
	char cidade[100];
	int cep;
} typedef end;

struct {
	char nome[100];
	int idade;
	end residencial;
	end comercial;
	telefone telefones[10];
} typedef pessoa;

void inserirEnd(end *p){
	  printf("%x \n", p);
	  
	printf("informe rua do end.:");
	scanf("%s", p->rua);

	printf("informe a cidade do end.:");
	scanf("%s", p->cidade);
			
	printf("informe o numero do end.:");
	scanf("%i", &p->numero);		

	printf("informe o numero do cep:");
	scanf("%i", &p->cep);				
}

void inserirTelefone(telefone *p){
  printf("%x \n", p);
	printf("informe o ddd:");
	scanf("%i", &p->ddd);		

	printf("informe o numero:");
	scanf("%i", &p->numero);	
}

void imprimirTelefone(telefone *p){
	printf("(%i) %i \n", p->ddd, p->numero);
}

int main(int argc, char *argv[]) {

	pessoa p1;
	
	printf("Informe o nome da pessoa::");
	scanf("%s", &p1.nome);
	printf("Informe a idade:");
	scanf("%i", &p1.idade);

	inserirTelefone(&p1.telefones[0]);
	inserirTelefone(&p1.telefones[1]);
	inserirTelefone(&p1.telefones[2]);

//& obtemos o end de memoria de uma varivel 
	inserirEnd(&p1.residencial);
	inserirEnd(&p1.comercial);
	
	printf("%s %i \n %s %s %i, %i", p1.nome, p1.idade, 
	p1.residencial.cidade, p1.residencial.rua, p1.residencial.numero,
	p1.residencial.cep);
	
	imprimirTelefone(&p1.telefones[0]);
	imprimirTelefone(&p1.telefones[1]);
	imprimirTelefone(&p1.telefones[2]);
	
	return 0;
}
