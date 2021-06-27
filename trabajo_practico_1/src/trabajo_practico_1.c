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
	  	char questionContinue = 'N';
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

	    float result;

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
				//Suma
				if(!fSumOperation(firstOperator, secondOperator, &result))
				{
					printf("\nEl resultado de la suma es %.2f \n", result);
				}
				else
					{
					printf("\nError\n");
					}

				//Resta
				if(!fRestOperation(firstOperator, secondOperator, &result))
				{
					printf("\nEl resultado de la resta es %.2f \n", result);
				}
				else
					{
					printf("\nError\n");
					}

				//Division
				if(secondOperator == 0)
				{
					printf("\nNo es posible realizar Division por 0\nFavor de ingresar el segundo operando distinto de 0\n\n");
				}
				else
					{
						fDivideOperation(firstOperator, secondOperator, &result);
						printf("\nEl resultado de la division es %.2f \n", result);
					}

				//Multiplicacion
				if(!fMultiplyOperation(firstOperator, secondOperator, &result))
				{
					printf("\nEl resultado de la multiplicacion es %.2f \n", result);
				}
				else
					{
					printf("\nError\n");
					}

				//Factorial
				if(!fFactorial(firstOperator,  &firstResultFactorial))
				{
					printf("\nEl resultado factorial del primer operador es %ld \n", firstResultFactorial);
					printf("\nEl resultado factorial del segundo operador es %ld \n", secondResultFactorial);
				}
				else
					{
						if(fFactorial(firstOperator,  &firstResultFactorial)== -2)
							printf("\nPrimer operador menor a 0, no es posible realizar el calculo\n");
						if(fFactorial(secondOperator,  &secondResultFactorial)== -3)
							printf("\nSegundo operador menor a 0, no es posible realizar el calculo \n");
					}
				break;

			case 5:
				printf("\n *** Adios! *** \n");
				break;
			}

	    } while(option != 5);

	    return EXIT_SUCCESS;
}
