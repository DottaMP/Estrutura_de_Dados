/*Crie um TAD que implemente o controle de uma conta bancaria, 
implemente funções para inicializar, deposito, sacar e imprimir o saldo.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numero;
    float saldo;
} ContaBancaria;


void Inicializar(ContaBancaria* conta, int numero, float saldo){
    printf("Entre com a sua conta: ");
    scanf("%i", &numero);
    printf("Informe o valor inicial do saldo em conta: R$ ");
    scanf("%f", &saldo);
    (*conta).numero = numero;
    (*conta).saldo = saldo;
}

void Deposito (ContaBancaria* conta, float valor){
    printf("Informe o valor para deposito: R$ ");
    scanf("%f", &valor);
    (*conta).saldo += valor;
    printf("\nDeposito realizado com sucesso!\n");
    
}

void Saque (ContaBancaria* conta, float valor){
    printf("Informe o valor para saque: R$ ");
    scanf("%f", &valor);
    if((*conta).saldo >=valor){
        (*conta).saldo -= valor;

        printf("\nSaque realizado com sucesso!\n");
    } else{
        printf("\nSaldo Insuficiente!\n");
    }

}

void Imprime (ContaBancaria conta){
    printf("Número da conta: %i\n", conta.numero);
    printf("Saldo: %f\n", conta.saldo);
}

int main (int argc, char **argv){
    ContaBancaria conta1;
    int opcao;  
    
    Inicializar(&conta1, 0, 0);
    printf("\nAntes da transação:\n");
    Imprime(conta1);
	
    
    do{ 
        printf("\nEscolha a operação que deseja realizar: ");
    	printf("\n[1] - Saldo: ");
    	printf("\n[2] - Saque: ");
    	printf("\n[3] - Depósito: ");
    	printf("\nDigite a opção desejada: ");
    	scanf("%i", &opcao);
    	printf("\n");
    	switch(opcao){
    	    case 1:{
                Imprime(conta1);
                break;
            }
            case 2:{
                Saque(&conta1, 0);
                break;
            }
            case 3:{
                Deposito(&conta1, 0);
                break;
            }
            default: {
                printf("Opção Inválida!");
            }
        }
        printf("\nAperte 1 para continuar a fazer operações ou 0 para sair: ");
        scanf("%i", &opcao);
	}while(opcao==1);
    
    printf("\nInformações Finais:\n");
    Imprime (conta1);


    return 0;
}
