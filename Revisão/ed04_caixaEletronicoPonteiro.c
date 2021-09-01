/*Faça um programa de caixa eletrônico utilizando ponteiro de funções.
Faça um algoritmo que simule o funcionamento de um caixa eletrônico, onde será apresentado uma lista de operações:
1-Saldo
2-Saque
3-Deposito
Ao iniciar o programa determine um valor inicial para a variável saldo (utilize um ponteiro para manter o valor do saldo), 
se o cliente escolher a opção 1 mostre o valor do saldo, caso escolha o valor 2 leia o valor a ser sacado e verifique se 
existe saldo suficiente, se o saldo for maior ou igual , deduza da variável saldo o valor solicitado, caso não haja saldo 
suficiente mostre a mensagem “Saldo Insuficiente”, caso a opção 3 seja escolhida adicione o valor informado de deposito ao saldo. 
Implemente um laço faça enquanto que verifique se o usuário deseja continuar, caso a variável coletada for igual 1 reinicie o 
laço, mantendo o valor do saldo.*/
#include <stdio.h>
int main(int argc, char *argv[]){
    int opcao;
    float saldo, saque, deposito;
    
    printf("Informe o valor do saldo em conta: R$ ");
    scanf("%f", &saldo);
        
    float *p = &saldo;
    

	
	do{
	    printf("Escolha a operação que deseja realizar: ");
	    printf("\n[1] - Saldo: ");
	    printf("\n[2] - Saque: ");
	    printf("\n[3] - Depósito: ");
	    printf("\nDigite a opção desejada: ");
	    scanf("%i", &opcao);
	    
	    switch(opcao){
	        case 1:{
	            printf("O valor do seu saldo é: R$ %2.2f\n", *p);
	            break;
	        }
	        case 2:{
	            printf("Informe o valor para saque: R$ ");
                scanf("%f", &saque);
                if(*p >=saque){
                    *p = *p - saque;
                    printf("Saque realizado com sucesso!\nSaldo Atualizado: R$ %2.2f\n", *  p);
                } else{
                    printf("Saldo Insuficiente!");
                }
	            break;
	        }
	        case 3:{
	            printf("Informe o valor para deposito: R$ ");
                scanf("%f", &deposito);
                *p = *p + deposito;
                printf("Deposito realizado com sucesso!\nSaldo Atualizado: R$ %2.2f\n", saldo);
	            break;
	        }
	        default: {
	            printf("Opção Inválida!");
	        }
	    }
	    printf("\nAperte 1 para continuar a fazer operações ou 0 para sair: ");
	    scanf("%i", &opcao);
	}while(opcao==1);

    return 0;
}

/*
void saldo(float *saldoAtual){
	printf("\nO saldo atual = %.2f", *saldoAtual);
}

void deposito(float *saldoAtual){
	float valor;
	printf("\nInforme o valor a ser depositado:");
	scanf("%f", &valor);
	*saldoAtual = *saldoAtual + valor;
	printf("\ndeposito realizado com sucesso !");  
}


void saque(float *saldoAtual){
	float valor;
	printf("\nInforme o valor a ser sacado:");
	scanf("%f", &valor);
	if(valor > *saldoAtual){
		printf("\nSaldo insuficiente !!");	
	} else {
		*saldoAtual = *saldoAtual - valor;
		printf("\nSaque realizado com sucesso !");  
	}
}


int main(int argc, char *argv[]) {
	float s=100;
	float *p;
	int op;
	p = &s;
    
	do{
		printf("\nInforme a op. a ser realizada\n1-saldo\n2-saque\n3-deposito\n4-sair\n");
		scanf("%i", &op);	
		switch(op){
		    case 1:{
		    	saldo(p);
				break;
			}
			case 2:{
				saque(p);
				break;
			}
			case 3:{
				deposito(p);
				break;
			}
			case 4:{
				printf("Sair !!");
				break;
			}
			default:{
				printf("Op. Invalida !");
				break;
			}
		}
	}while(op<4);
	
	
	return 0;
}
*/