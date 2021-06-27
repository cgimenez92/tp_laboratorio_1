/*
 * calculator_operations.c
 *
 *  Created on: 8 sep. 2020
 *      Author: cgimenez
 */

#include <stdio.h>
#include <stdlib.h>

int fSumOperation(float firstOperator, float secondOperator, float* pResult)
{
	int ret = -1;

	if(pResult != NULL)
	{
		*pResult = firstOperator + secondOperator;
		ret = 0;
	}

return ret;
}

int fRestOperation(float firstOperator, float secondOperator, float* pResult)
{
	int ret = -1;

	if(pResult != NULL)
	{
		*pResult = firstOperator - secondOperator;
		ret = 0;
	}

return ret;
}


int fDivideOperation(float firstOperator, float secondOperator, float* pResult)
{
	int ret = -1;

	if (pResult != NULL && secondOperator != 0)
	{
		*pResult = firstOperator / secondOperator;
		ret =0;
	}

	if(secondOperator == 0)
	{
		ret =-2;
	}

	return ret;
}


int fMultiplyOperation(float firstOperator, float secondOperator, float* pResult)
{
	int ret = -1;

	if(pResult != NULL)
	{
		*pResult = firstOperator * secondOperator;
		ret = 0;
	}

return ret;
}


int fFactorial(float operator, unsigned long int* pResult)
{
	int ret = -1;

	if(pResult != NULL && operator >= 0)
	{
		for(*pResult=1; operator>0; operator--)
			{
				*pResult = (unsigned long int)*pResult * ((unsigned long int)operator);
			}
		ret = 0;
	}
	else
		{
			if(operator < 0)
			{
				ret = -2;
			}
		}

	return ret;
}
