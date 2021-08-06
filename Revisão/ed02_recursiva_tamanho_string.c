/*Escrever uma função recursiva que retorna o tamanho de um string, tamstring(char s[])*/

#include <stdio.h>

int tamstring(char s[]){
    if (s[0] == '\0'){
        return 0;
    }
    return 1+tamstring(&s[1]); }

int main(){
    char s[30];
    int tamanho;

    printf("\nDigite uma palavra: ");
    scanf("%s", s);
    
    tamanho = tamstring(s);
    
    printf("\nA palavra '%s' possuí %i letras", s, tamanho);
 
    return 0;
}