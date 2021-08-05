/*Crie um programa em linguagem C com 4 funções (somar, subtrair, multiplicar e dividir) 
recebendo os parametros do tipo float A e float B o retorno de cada função deve ser o valor da operação matemática*/

#include <stdio.h>

float somar(float a, float b){
    float soma = a + b;
    return soma;
}

float subtrair(float a, float b){
    float menos = a - b;
    return menos;
}

float multiplicar(float a, float b){
    float multi = a * b;
    return multi;
}

float divisao(float a, float b){
    float dividir = a / b;
    return dividir;
}

int main(){
    float a = 0, b = 0;
    int opcao;
    
    printf("Entre com dois números reais: ");
    scanf("%f %f", &a, &b);

	
	do {
	    printf("\nEscolha a operação que deseja realizar!\n");
        printf("[1] Somar\n");
        printf("[2] Subtrair\n");
        printf("[3] Multiplicação\n");
        printf("[4] Divisão\n");
        printf("[0] Para Sair\n");
        printf("\nDigite a opção desejada: ");
    	scanf("%i", &opcao);
	    switch (opcao){
        
    	case 1 : 
    	    printf("\nResultado da Soma: %.2f\n", somar(a, b));
    	    break;
    
    	case 2 : 
    	    printf("\nResultado da Subtração: %.2f\n", subtrair(a, b));
    	    break;
    
    	case 3 : 
    	    printf("\nResultado da Multiplicação: %.2f\n", multiplicar(a, b));
    	    break;
    
    	case 4 : 
        	if(a == 0 || b == 0){
        	    printf("\nNão é possível dividir por zero!\n");
        	    break;
                
            } else {
                printf("\nResultado da Divisão: %.2f\n", divisao(a, b)); 
    	        break;
            }
        default:
        printf ("Escolha Inválida!\n");
        
	    } 
	} while (opcao!=0);


    return 0;
}
