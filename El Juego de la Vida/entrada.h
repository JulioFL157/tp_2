/*
 * entrada.h
 *
 *  Created on: 19 may. 2021
 *      Author: lp1-2021
 */

#ifndef ENTRADA_H_
#define ENTRADA_H_

#define N 10 // tamaño del universo
// El universo. Los puntos indican células muertas y los asteriscos
// células vivas
char universo[N][N] = {
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '*', '*', '.', '.', '.', '.', '.', '.', '.'},
{'.', '*', '*', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '*', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '*', '.', '.', '.', '*', '.'},
{'.', '.', '.', '.', '*', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '*', '.', '.', '.'},
{'.', '.', '*', '.', '.', '*', '.', '*', '.', '.'},
{'.', '.', '.', '.', '.', '.', '*', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
};
// reglas para la vida – muerte y nacimiento
char reglas[] = "23/3";
// cantidad de iteraciones
int iteraciones = 10;

#endif /* ENTRADA_H_ */
