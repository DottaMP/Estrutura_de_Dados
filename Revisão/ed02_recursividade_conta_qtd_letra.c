/*Fazer uma função recursiva que conta o número de ocorrências de um determinado caracter, caract(char c, char s[])*/

#include <stdio.h>

int carac(char c,char s[]){
    if (s[0] == '\0'){
        return 0;
    }

    if (s[0]==c) {
        return (1+carac(c,++s));  
    }
    
    return carac(c,++s);
}

int main(){
    char s[30], caracter;
    int t;
    
    printf("\nDigite a palavra: ");
    fgets(s, 30, stdin);
    
    printf("\nDigite a letra que deseja procurar: ");
    caracter = getchar();
    
    t = carac(caracter,s);
    
    printf("\nA letra foi encontrada %i vez(es)", t);
 
    return 0;
}