/*
 ============================================================================
 Name        : trabajo_practico_1.c
 Author      : cgimenez
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculator_operations.h"
#include "utn.h"
#include "menu.h"

int main(void)
{
		setbuf(stdout,NULL);
	    int option;
	    int flagFirstOperator=-1;
	    int flagSecondOperator=-1;
	    int flagOperations=-1;

	    float firstOperator;
	    float secondOperator;

		float sumResult;
		float restResult;
		float divideResult;
		float multiplyResult;
	    unsigned long int firstResultFactorial;
	    unsigned long int secondResultFactorial;

	    do
	    {
	    	option = menu(&firstOperator, &secondOperator);

			switch(option)
			{
			case 1:
				flagFirstOperator = getFloat ("Ingrese primer numero: ", "Ingrese un caracter numerico: ", &firstOperator, 3);
				break;

			case 2:
				flagSecondOperator = getFloat ("Ingrese segundo numero: ", "Ingrese un caracter numerico: ", &secondOperator, 3);
				break;

			case 3:

			    if(flagFirstOperator == -1 || flagSecondOperator == -1)
			    {
			    	 printf("\n\nNo se puede realizar la opcion sin ingresar los dos operandos, ingreselos y vuelva a intentar\n\n");
			    }
			    else
					{
						fSumOperation(firstOperator, secondOperator, &sumResult);
						fRestOperation(firstOperator, secondOperator, &restResult);
						fDivideOperation(firstOperator, secondOperator, &divideResult);
						fMultiplyOperation(firstOperator, secondOperator, &multiplyResult);
						fFactorial(firstOperator,  &firstResultFactorial);
						fFactorial(secondOperator,  &secondResultFactorial);
						flagOperations = 0;
						printf("\n\nSe ha realizado el calculo de las operaciones\n\n");
					}
			    break;

			case 4:
				if(flagOperations != 0)
				{
					printf("\n No se pueden mostrar los resultados sin realizar anteriormente el calculo de las operaciones (3- Calcular todas las operaciones) \n");
				}
				else
					{
						//Suma
						printf("\na) El resultado de A+B es: %.2f \n", sumResult);
						//Resta
						printf("b) El resultado de A-B es: %.2f \n", restResult);
						//Division
						if(secondOperator == 0)
						{
							printf("\nNo es posible realizar Division por 0\nFavor de ingresar el segundo operando distinto de 0\n\n");
						}
						else
							{
								printf("c) El resultado de A/B es: %.2f \n", divideResult);
							}

						//Multiplicacion
						printf("d)El resultado de la multiplicacion es %.2f \n", multiplyResult);

						//Factorial
						if(firstOperator >= 0 && firstOperator <= 12)
						{
							printf("e) El factorial de A es: %ld\n", firstResultFactorial);
						}
						else
							{
								printf("e) No se puede calcular el factorial de A \n");
							}

						if(secondOperator >= 0 && secondOperator <= 12)
						{
							printf("e) El factorial de B es: %ld\n", secondResultFactorial);
						}
						else
							{
								printf("e) No se puede calcular el factorial de B \n");
							}
					}
				break;

			case 5:
				printf("\n *** Adios! *** \n");
				break;
			}

	    } while(option != 5);

	    return EXIT_SUCCESS;
}
