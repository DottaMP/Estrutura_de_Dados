/*Escreva uma função recursiva para calcular o valor
de uma base x elevada a um expoente y.*/

#include <stdio.h>

int expoente(int x, int y){
    if (y == 0){
        return 1;
    } 
    
    if (y == 1){
        return x;
    }
    
    return x*expoente(x,y-1);
}

int main () {
    int x, y, resultado;
    
    printf("\nDigite um número inteiro para x:");
    scanf("%i", &x);
    
    printf("\nDigite um número inteiro para y:");
    scanf("%i", &y);
    
    if (y < 0) {
        printf("\ny NÃO pode ser negativo!!! Tente de novo!");
        
    } else{
        resultado = expoente(x,y);
        printf("\n%i elevado a %i é: %i", x, y, resultado);
    } 
    
    return 0;
}

