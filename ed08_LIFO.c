#include <stdio.h>

void push(int *v, int *t);
void pop(int *v, int *t);
void top(int *v, int *t);
int isEmpty(int *t);
int isFull(int *v, int *t);
int max = 20;

int main()
{
    int pilha[max];
    int *p = pilha;
    int t = -1;
    
    push(p, &t);
    top(p, &t);
    push(p, &t);
    push(p, &t);
    top(p, &t);
    pop(p, &t);
    top(p, &t);

    return 0;
}

void push(int *v, int *t){
    int aux;
    printf("Informe o valor:");
    scanf("%i", &aux);
    (*t)++; //isfull
    if(isFull(v, t)) {
        printf("Pilha cheia !!! \n");
    } else {
        v[(*t)] = aux;     
    }
}

void pop(int *v, int *t){
    if(isEmpty(t)) {
        printf("Pilha vazia !!! \n");
    } else {
        (*t)--;
    }
}

void top(int *v, int *t){
    if(isEmpty(t)) {
        printf("Pilha vazia !!! \n");
    } else {
        printf("O topo = %i \n", v[(*t)]);   
    }
}

int isEmpty(int *t){
    if((*t)<0) {
        return 1;
    }  else {
        return 0;
    }  
}

int isFull(int *v, int *t){
    if(max<(*t)) {
        return 1;
    }  else {
        return 0;
    }  
}