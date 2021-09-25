#include <stdio.h>

struct item {
 float info;
 struct no* prox;
};
typedef struct item Item;

struct pilha {
 	Item* prim;
};
typedef struct pilha Pilha;

Pilha* criar()
{
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
 	p->prim = NULL;
 	return p;
}

void push(Pilha *p, float v)
{
    Item *pAux = (Item*)malloc(sizeof(Item));
    pAux->info = v;
    pAux->prox = p->prim;
 	p->prim = pAux;
}

float pop(Pilha *p)
{
	float v;
 	if(vazia(p)) {
		printf("Pilha vazia.\n");
 		exit(1); /* aborta programa */
 	}
 	v = p->prim->info;
	
	Item *pAux = p->prim->prox;
    free(p->prim);
	p->prim = pAux;
	return v;
}

int vazia (Pilha *p)
{
 	return (p->prim==NULL);
}

void libera (Pilha *p)
{
     Item* q = p->prim;
     while (q!=NULL) {
     	Item* t = q->prox;
     	free(q);
     	q = t;
     }
     free(p);
}

void imprime(Pilha *p)
{
 	Item* q;
	 for (q=p->prim; q!=NULL; q=q->prox)
		 printf("%f\n",q->info);
}

int main()
{
   Pilha *p = criar();
   push(p, 45);
   push(p, 70);
   push(p, 5);
   imprime(p);
   pop(p);
   printf("\nPOP========>\n");
   imprime(p);
   push(p, 15);
   printf("\nPOP========>\n");
   imprime(p);
   
   return 0;
}
