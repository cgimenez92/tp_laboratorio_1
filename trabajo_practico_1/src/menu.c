/*
 * menu.c
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "calculator_operations.h"

int menu(float* firstOperator, float* secondOperator)
{
	int option;

	printf("\n1- Ingresar 1er operando (A=%.2f)", *firstOperator);
	printf("\n1- Ingresar 1er operando (B=%.2f)", *secondOperator);
	getIntWithLimits(
	"\n3- Calcular todas las operaciones"
	"\n a) Calcular la suma (A+B)"
	"\n b) Calcular la resta (A-B)"
	"\n c) Calcular la division (A/B)"
	"\n d) Calcular la multiplicacion (A*B)"
	"\n e) Calcular el factorial (A!)"
	"\n4- Informar resultados"
	"\n a) El resultado de A+B es: r"
	"\n b) El resultado de A-B es: r"
	"\n c) El resultado de A/B es: r o No es posible dividir por cero"
	"\n d) El resultado de A*B es: r"
	"\n e) El factorial de A es: r1 y El factorial de B es: r2"
	"\n5- Salir"
	"\n\nSeleccione una opcion: ",
	"Ingresar una opcion entre [1-5]", "Ingresar un caracter numerico", &option, 3, 1, 5);
	fflush(stdin);
    return option;
}
