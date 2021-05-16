/*
 * is_valid.c
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */

#include <stdio.h>
#include <stdlib.h>

int isValidInt(char*string)
{
	int ret = 1;
	int i = 0;

	for (i = 0 ; string[i] != '\0'; i++)
	{
		if (string[i] > '9' || string[i] < '0')
		{
			ret = 0;
			break;
		}
	}
	return ret;
}

