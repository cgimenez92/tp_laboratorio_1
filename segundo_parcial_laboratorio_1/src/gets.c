#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "is_valid.h"
#include "gets.h"


static int myGets(char* string, int arraySize);
static int getCharToInt (int* pResult);
static int getCharToFloat (float* pResult);

static int myGets(char* string, int arraySize)
{
	fflush(stdin);
	fgets (string, arraySize, stdin);
	string[strlen (string) - 1] = '\0';
	return 0;
}

static int getCharToInt (int* pResult)
{
	int ret = -1 ;
	char buffer[BUFFER_SIZE];
	if (!myGets(buffer,sizeof(buffer)) && isValidInt(buffer))
	{
		ret = 0;
		*pResult = atoi(buffer);
	}
	return ret;
}

static int getCharToFloat (float* pResult)
{
	int ret = -1 ;
	char buffer[BUFFER_SIZE];
	if (!myGets(buffer,sizeof(buffer)) && isValidFloat(buffer,sizeof(buffer)))
	{
		*pResult = atof(buffer);
		ret = 0;
	}
	return ret;
}

static int getArrayChar(char* pResult)
{
	int ret = -1;
	char buffer[BUFFER_SIZE];
	if (!myGets(buffer,sizeof(buffer)))
	{
		strncpy(pResult,buffer,sizeof(buffer)-1);
		ret = 0;
	}
	return ret;
}

int getName(char* message, char* errorMessage, char* pResult, int attempts, int stringSize)
{
	char buffer[BUFFER_SIZE];
	int ret = -1;

	if(	message != NULL &&
		errorMessage != NULL &&
		pResult != NULL &&
		attempts >= 0 &&
		stringSize > 0)
	{
		do
		{
			printf("%s\n",message);
			if( !myGets(buffer,BUFFER_SIZE) &&
				strnlen(buffer,sizeof(buffer)-1) <= stringSize &&
				isValidName(buffer,stringSize) != 0)
			{
				ret = 0;
				strncpy(pResult,buffer,stringSize);
				break;
			}
			else
			{
				printf("%s\n",errorMessage);
				attempts--;
			}
		}while(attempts >= 0);

	}
	return ret;
}


int getInt(char* message, char* firstErrorMessage, char* secondErrorMessage, char* thirdErrorMessage, int* pResult, int attempts, int min, int max)
{
	int ret = -1;
	int bufferInt;
	int answerGet;
	if(message != NULL && firstErrorMessage != NULL && secondErrorMessage != NULL && thirdErrorMessage != NULL && pResult != NULL && attempts >= 0 && max >= min)
	{
		do
		{
			printf("%s",message);
			fflush(stdin);
			answerGet = getCharToInt(&bufferInt);

			if(answerGet == 0 && bufferInt >= min && bufferInt <= max)
			{
				ret = 0;
				*pResult = bufferInt;
				break;
			}
			else
			{
				if(bufferInt < min)
					{
						printf("\n***%s***\n\n",firstErrorMessage);
						attempts--;
						ret = -2;
						continue;
					}

				if(bufferInt > max)
					{
						printf("\n***%s***\n\n",secondErrorMessage);
						attempts--;
						ret = -3;
						continue;
					}

				if(answerGet != 0)
					{
						printf("\n***%s***\n\n",thirdErrorMessage);
						attempts--;
						ret= -4;
						continue;
					}
			}

		}while(attempts >= 0);
	}
	return ret;
}

int getFloat (char* message, char* firstErrorMessage, char* secondErrorMessage, char* thirdErrorMessage, float* pResult, int attempts, float min, float max)
{

	int ret = -1;
	float bufferFloat;
	int answerGet;
	if (pResult != NULL && message != NULL && firstErrorMessage != NULL && secondErrorMessage != NULL && thirdErrorMessage != NULL && max>min && attempts>=0) {
	do
	{
		printf("%s\n", message);
		fflush(stdin);
		answerGet = getCharToFloat(&bufferFloat);
		if (answerGet == 0 && bufferFloat >= min && bufferFloat <= max)
		{
			*pResult = bufferFloat;
			ret = 0;
			break;
		}
		else
		{
			if(bufferFloat < min)
					{
						printf("\n***%s***\n\n",firstErrorMessage);
						attempts--;
						ret = -2;
						continue;
					}

				if(bufferFloat > max)
					{
						printf("\n***%s***\n\n",secondErrorMessage);
						attempts--;
						ret = -3;
						continue;
					}

				if(answerGet != 0)
					{
						printf("\n***%s***\n\n",thirdErrorMessage);
						attempts--;
						ret= -4;
						continue;
					}
		}
	} while (attempts >= 0 );

	}
	return ret;
}

int getOperation(char* message, char* errorMessage, char* operation, int attempts)
{
	int ret = 0;

	printf(message);
	fflush(stdin);
	scanf("%c", operation);

	while(attempts >= 0 && (*operation != '+' && *operation != '-' && *operation != '/' && *operation != '*'))
		{
			printf(errorMessage);
			fflush(stdin);
			scanf("%c", operation);
			attempts--;

			if(attempts==0)
			{
				ret = -1;
			}
		}
	return ret;
}

int getCuit(char* message, char* firstErrorMessage, char* secondErrorMessage, char* pResult, int attempts, int stringSize)
{
	char buffer[BUFFER_SIZE];
	int ret = -1;

	if(	message != NULL &&
		firstErrorMessage != NULL &&
		secondErrorMessage != NULL &&
		pResult != NULL &&
		attempts >= 0 &&
		stringSize > 0)
	{
		do
		{
			printf("%s\n",message);
			if( !myGets(buffer,stringSize) &&
				strnlen(buffer,sizeof(buffer)-1) <= stringSize &&
				isValidCuit(buffer,stringSize)>0)
			{
				strncpy(pResult,buffer,stringSize);
				ret = 0;
				break;
			}
			else
			{
                if (isValidCuit(buffer,stringSize)== -1)
                {
                    printf("%s\n", firstErrorMessage);
                }

                if (isValidCuit(buffer,stringSize)== -2)
                {
                    printf("%s\n", secondErrorMessage);
                }
                attempts--;
			}
		}while(attempts >= 0);
	}
	return ret;
}

int getString(char* message, char* errorMessageLenght, char* pResult, int attempts, int stringSize)
{
    int ret=-1;
    char buffer[BUFFER_SIZE];

	if(	message != NULL &&
		errorMessageLenght != NULL &&
		pResult != NULL &&
		attempts >= 0 &&
		stringSize > 0)
	{
		do
		{
			printf("%s\n", message);
			if(!getArrayChar(buffer) && strnlen(buffer, stringSize))
			{
				strncpy(pResult,buffer,stringSize);
				ret = 0;
				break;
			}
			else
			{
				if(strlen(buffer)>stringSize)
				{
					printf ("%s\n", errorMessageLenght);
				}
				attempts--;
			}
		}while(attempts >= 0);
	}
    return ret;
}





