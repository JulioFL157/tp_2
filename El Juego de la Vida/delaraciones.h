/*
 * datos.h
 *
 *  Created on: 19 may. 2021
 *      Author: lp1-2021
 */

#ifndef DELARACIONES_H_
#define DELARACIONES_H_


#include "entrada.h"
/*
 * universo pararelo donde se van a ir cargando las actualizaciones del universo actual
 * en este universo las celulas vivas se cargan con el 1 y las muertas con el 0
 */
int parallel_universe[N][N];

//variable auxiliar donde se pasa la cantidad de celulas vivas que hay en las casillas adyacentes
int n;

//FUNCIONES
/*
 * funcion que saca las reglas del universo
 * parametros char reglas. auxiliares
 * retorna el valor de las auxiliares que celulas vivas tiene que haber alrededor de una celula muerta
 * para que viva o cuantas celulas vias tienen que haber para que una celula nazca o muera
 */
void rules(char reglas[], int sub, int vida_muerte[sub], int nacimiento[sub]);
/*
 * funcion en el cual se lee la matriz universo[N][N] y dependiendo de las reglas del universo actualiza
 * la matriz parallel_universe[N][N]
 * recibe como parametros los vectores vida_muerte y nacimiento, donde se encuentran las reglas
 * del universo
 * retorna la matriz parallel_universe
 */
void universe(char universo[N][N], int vida_muerte[], int nacimiento[]);
/* funcion que evalua el estado de las celulas de la matriz universo para ir actualizando su estado en la matriz parallel_universe
 * recibe como parametros las posiciones de las celulas de la matriz universo
 * cuenta cuantas celulas vivas hay en las posiciones adyacentes a la posicion de la celula
 * retornando la cantidad de celulas vivas que hay al rededor de la celula en la posicion i,j.
 */
int evaluacion_de_estado(int i, int j, char universo[N][N]);
/* funcion donde se actualiza la matriz universo usando la matriz parallel_universe
 * parametros la matriz del universo paralelo
 * retorna la matriz universo
 *
 */
void act_universe(int parallel_universe[N][N]);

#endif /* DELARACIONES_H_ */
