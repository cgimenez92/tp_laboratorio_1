#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Customer.h"

///Construtor///
Customer* customer_new()
{
    Customer* newCustomer;
    newCustomer = (Customer*)malloc(sizeof(Customer));
    if(newCustomer != NULL)
    {
        newCustomer->customerId = 0;
        strncpy(newCustomer->country, " ", STRING_SIZE);
        strncpy(newCustomer->gender, " ", STRING_SIZE);
        strncpy(newCustomer->firtsName, " ", STRING_SIZE);
        strncpy(newCustomer->lastName, " ", STRING_SIZE);
        strncpy(newCustomer->birthDate, " ", STRING_SIZE);
        newCustomer->idContractedService = 0;
    }
    return newCustomer;
}


///Destructor///
void customer_delete(Customer* this)
{
    if(this != NULL)
    {
        free(this);
    }
}


/////////Setters (Asigno el valor a la propiedad del objeto)////////////
int customer_setCustomerId(Customer* this, int customerId)
{
    int ret = -1;
    if(this != NULL)
    {
        if(customerId > 0)
        {
            this->customerId = customerId;
            ret = 0;
        }
    }
    return ret;
}

int customer_setCountry(Customer* this, char* country)
{
    int ret = -1;
    int len;

    if(this != NULL && country != NULL)
    {
        len = strlen(country);

        if(len > 0 && len < STRING_SIZE)
		{
			strncpy(this->country, country, STRING_SIZE);
			ret = 0;
		}
     }
    return ret;
}

int customer_setGender(Customer* this, char* gender)
{
    int ret = -1;
    int len;

    if(this != NULL && gender != NULL)
    {
        len = strlen(gender);

        if(len > 0 && len < STRING_SIZE)
		{
			strncpy(this->gender, gender, STRING_SIZE);
			ret = 0;
		}
     }
    return ret;
}

int customer_setFirtsName(Customer* this, char* firtsName)
{
    int ret = -1;
    int len;

    if(this != NULL && firtsName != NULL)
    {
        len = strlen(firtsName);

        if(len > 0 && len < STRING_SIZE)
		{
			strncpy(this->firtsName, firtsName, STRING_SIZE);
			ret = 0;
		}
     }
    return ret;
}

int customer_setLastName(Customer* this, char* lastName)
{
    int ret = -1;
    int len;

    if(this != NULL && lastName != NULL)
    {
        len = strlen(lastName);

        if(len > 0 && len < STRING_SIZE)
		{
			strncpy(this->lastName, lastName, STRING_SIZE);
			ret = 0;
		}
     }
    return ret;
}

int customer_setBirthDate(Customer* this, char* birthDate)
{
    int ret = -1;
    int len;

    if(this != NULL && birthDate != NULL)
    {
        len = strlen(birthDate);

        if(len > 0 && len < STRING_SIZE)
		{
			strncpy(this->birthDate, birthDate, STRING_SIZE);
			ret = 0;
		}
     }
    return ret;
}

int customer_setIdContractedService(Customer* this, int idContractedService)
{
    int ret = -1;
    if(this != NULL)
    {
        if(idContractedService > 0)
        {
            this->idContractedService = idContractedService;
            ret = 0;
        }
    }
    return ret;
}

Customer* customer_newParameters(char* customerIDStr, char* countryStr, char* genderStr, char* firtsNameStr, char* lastNameStr, char* birthDateStr, char* idContractedServiceStr)
{
    Customer* newCustomer;
    int aux;
    int errorFlag;
    newCustomer = customer_new();

    if(newCustomer != NULL && customerIDStr != NULL && countryStr != NULL && genderStr != NULL && firtsNameStr != NULL
      && lastNameStr != NULL && birthDateStr != NULL && idContractedServiceStr  != NULL)
    {
        aux = atoi(customerIDStr);
        if(customer_setCustomerId(newCustomer, aux))
        {
            errorFlag = 1;
        }

        if(customer_setCountry(newCustomer, countryStr))
        {
            errorFlag = 1;
        }

        if(customer_setGender(newCustomer, genderStr))
        {
            errorFlag = 1;
        }

        if(customer_setFirtsName(newCustomer, firtsNameStr))
        {
            errorFlag = 1;
        }

        if(customer_setLastName(newCustomer, lastNameStr))
        {
            errorFlag = 1;
        }

        if(customer_setBirthDate(newCustomer, birthDateStr))
        {
            errorFlag = 1;
        }

        aux = atoi(idContractedServiceStr);
        if(customer_setIdContractedService(newCustomer, aux))
        {
            errorFlag = 1;
        }

        if(errorFlag == 1)
        {
            free(newCustomer);
            newCustomer = NULL;
        }
    }
    return newCustomer;
}

/////////Getters (Obtengo el valor de la propiedad del objeto)////////////

int customer_getCustomerId(Customer* this, int* customerId)
{
    int ret = -1;
    if(this != NULL && customerId != NULL)
    {
        *customerId = this->customerId;
        ret = 0;
    }
    return ret;
}

char* customer_getCountry(Customer* this)
{
    char* country = NULL;

    if(this != NULL)
    {
    	country = (char*)malloc(sizeof(char)* STRING_SIZE);
        strncpy(country, this->country, STRING_SIZE);
    }
    return country;
}

char* customer_getGender(Customer* this)
{
    char* gender = NULL;

    if(this != NULL)
    {
        gender = (char*)malloc(sizeof(char)* STRING_SIZE);
        strncpy(gender, this->gender, STRING_SIZE);
    }
    return gender;
}

char* customer_getFirtsName(Customer* this)
{
    char* firtsName = NULL;

    if(this != NULL)
    {
    	firtsName = (char*)malloc(sizeof(char)* STRING_SIZE);
        strncpy(firtsName, this->firtsName, STRING_SIZE);
    }
    return firtsName;
}

char* customer_getLastName(Customer* this)
{
    char* lastName = NULL;

    if(this != NULL)
    {
    	lastName = (char*)malloc(sizeof(char)* STRING_SIZE);
        strncpy(lastName, this->lastName, STRING_SIZE);
    }
    return lastName;
}

char* customer_getBirthDate(Customer* this)
{
    char* birthDate = NULL;

    if(this != NULL)
    {
    	birthDate = (char*)malloc(sizeof(char)* STRING_SIZE);
        strncpy(birthDate, this->birthDate, STRING_SIZE);
    }
    return birthDate;
}

int customer_getIdContractedService(Customer* this, int* idContractedService)
{
    int ret = -1;
    if(this != NULL && idContractedService != NULL)
    {
        *idContractedService = this->idContractedService;
        ret = 0;
    }
    return ret;
}

///Print///
int customer_print(Customer* this)
{
    int ret = -1;

    int customerId;
    int idContractedService;

    if(this != NULL)
    {
    	customer_getCustomerId(this,&customerId);
        customer_getIdContractedService(this,&idContractedService);
        printf("\n|     %d      |       %s      |       %s      |       %s      |       %s      |       %s      |   %d  |",
        		customerId,
				customer_getCountry(this),
				customer_getGender(this),
				customer_getFirtsName(this),
				customer_getLastName(this),
				customer_getBirthDate(this),
        		idContractedService);
        ret = 0;
    }
    return ret;
}

///Filter///

int customer_filterByGender(Customer* this)
{
	int ret=0;

	if(this != NULL)
	{
		if(strcmp(customer_getGender(this), "M")==0)
		{
			ret =1;
		}
	}
	return ret;
}

int customer_filterByUSCountry(Customer* this)
{
	int ret=0;

	if(this != NULL)
	{
		if(strcmp(customer_getCountry(this), "US")==0)
		{
			ret =1;
		}
	}
	return ret;
}

