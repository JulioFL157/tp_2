/*
 * elJuegoDeLaVida.c
 *
 *  Created on: 19 may. 2021
 *      Author: lp1-2021
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "delaraciones.h"
#include "entrada.h"

void rules(char reglas[], int sub, int vida_muerte[sub], int nacimiento[sub]){
	char auxiliar;
	for(int i = 0; i < sub; i++){
		vida_muerte[i] = 9;
		nacimiento[i] = 9;
	}
	for(int i = 0; i < sub; i++){
		if(reglas[i] ==  '/'){
			for(int j = i+1; j < strlen(reglas);j++ ){
				auxiliar = reglas[j];
				nacimiento[j] = atoi(&auxiliar);
			}
			break;
		}else{
			auxiliar = reglas[i];
			vida_muerte[i] = atoi(&auxiliar);
		}
	}

}

void universe(char universo[N][N], int vida_muerte[], int nacimiento[]){
	int i, j, m, aux = 0, aux1 = 0;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(universo[i][j] == '.'){//celula muerta
				for(m = 0; m < strlen(reglas); m++){
					if(nacimiento[m] == evaluacion_de_estado(i, j, universo)){
						aux1++;
						break;
					}
				}
//si aux es igual a 0 significa que no cumple la regla para que nazca la celula, entonces permanece muerte
				if(aux1 == 0) parallel_universe[i][j] = 0;//celula muere
				//pero si es diferente a 0 entonces su estado cambia a viva
				if(aux1 != 0) parallel_universe[i][j] = 1;//celula permanece con vida
				aux1 = 0;
			}
			if(universo[i][j] == '*'){//celula viva
				for(m = 0; m < strlen(reglas); m++){
					if(vida_muerte[m] == evaluacion_de_estado(i, j, universo)){
						aux++;//cuenta cuantas veces se entro en este if
						break;
					}
				}
//si el aux es igual a 0 significa que ninguna vez entro y no cumple la regla del universo para que la celula continue con vida
				if(aux == 0) parallel_universe[i][j] = 0;//celula muere
				//pero si es diferente a 0 entonces la
				if(aux != 0) parallel_universe[i][j] = 1;//celula permanece con vida
				aux = 0;
			}
		}
	}
}

int evaluacion_de_estado(int i, int j, char universo[N][N]){
	n = 0;
	//le condicionamos para que no lea fuera de la matriz, suponiendo que en esas posiciones de memoria puede haber
	//una celula viva o muerta
	//diagonales
	if(universo[i-1][j+1] == '*' && i-1 > -1 && j+1 < N) n++;
	if(universo[i-1][j-1] == '*' && i-1 > -1 && j-1 > -1) n++;
	if(universo[i+1][j+1] == '*' && j+1 < N && j+1 < N) n++;
	if(universo[i+1][j-1] == '*' && i+1 < N && j-1 > -1) n++;
	//horizontales y verticales
	if(universo[i-1][j] == '*' && i-1 > -1) n++;
	if(universo[i][j-1] == '*' && j-1 > -1) n++;
	if(universo[i][j+1] == '*' && j+1 < N) n++;
	if(universo[i+1][j] == '*' && i+1 < N) n++;

	return n;
}
void act_universe(int parallel_universe[N][N]){
	int i, j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(parallel_universe[i][j] == 1){//celula viva
				universo[i][j] = '*';//se introduce una celula viva en la matriz
			}
			if(parallel_universe[i][j] == 0){//celula muerta
				universo[i][j] = '.';//se introduce una celula muerta en la matriz
			}
		}
	}
	//imprime la actualizacion de la matriz
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf(" %c |", universo[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	int i, j;
	int ite = 0;//auxiliar de iteraciones
	//longitud del vector reglas para que sea la longitud de los vectores nacimiento y vida-muerte
	int sub = strlen(reglas);
	//vectores donde van a contener los nros para la condicion de vida-muerte y nacimiento
	int vida_muerte[sub], nacimiento[sub];
	//imprime el estado inicial de la matriz
	printf("Universo inicial\n");
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf(" %c |", universo[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	rules(reglas, sub, vida_muerte, nacimiento);
	//loop para que realice estas funciones dependiendo de la cantidad de iteraciones
	while(ite < iteraciones){
		printf("Universo %d\n", ite+1);
		universe(universo, vida_muerte, nacimiento);
		act_universe(parallel_universe);
		printf("\n");
		ite++;
	}

	return 0;
}

