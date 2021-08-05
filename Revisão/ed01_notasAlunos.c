/*Crie um program em linguagem C que crie uma matriz de 10,3 armazene a nota P1, P2 e MEDIA 
nas respectivas colunas, crime uma função passando a matriz como parametro para identificar a 
maiorNotaP1, a maiorNotaP2 e a maiorMedia e mediaSala*/

#include <stdio.h>
#include <stdlib.h>

int indiceLinha;

void notasMedias(int l, int c, float notas[l][c]){
    
	float p1 = 0, p2 = 0, media= 0, maiorMedia = 0, mediaSala = 0;
	
	for(l = 0; l < 10; l++){
		
		media = (notas[l][0] + notas[l][1])/2;
		notas[l][2] = media;
		
		printf("\nAluno %iº: P1: %.2f, P2: %.2f, Media: %.2f", l+1, notas[l][0], notas[l][1], notas[l][2]);
		
		if(p1 < notas[l][0]){
			p1 = notas[l][0];
		}
		
		if(p2 < notas[l][1]){
			p2 = notas[l][1];
		}
		
		if(maiorMedia < notas[l][2]){
			maiorMedia = notas[l][2];
		}
		
		mediaSala += notas[l][2];
		
	}
	
	mediaSala = mediaSala/10;
	printf("\n\nMaior nota P1: %.2f\nMaior nota P2: %.2f \nMaior Media: %.2f \nMedia da sala: %.2f", p1, p2, maiorMedia, mediaSala);
	
}

int main(){
    
    float notas[10][3];
	
	for(indiceLinha = 0; indiceLinha < 10; indiceLinha++){
		printf("\nInforme a nota P1 e P2 do [%i]° aluno: ", indiceLinha+1);
		scanf("%f %f", &notas[indiceLinha][0], &notas[indiceLinha][1]);
	}
    
    notasMedias(10, 3, notas);
    
    return 0;
};
