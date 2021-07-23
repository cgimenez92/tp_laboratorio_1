#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Customer.h"
#include "Service.h"


Service* service_new()
{
    Service* newService;
    newService = (Service*)malloc(sizeof(Service));
    if(newService != NULL)
    {
        newService->serviceId = 0;
        strncpy(newService->serviceType, " ", STRING_SIZE);
        newService->price = 0;
    }
    return newService;
}


///Destructor///
void service_delete(Service* this)
{
    if(this != NULL)
    {
        free(this);
    }
}


/////////Setters (Asigno el valor a la propiedad del objeto)////////////
int service_setServiceId(Service* this, int ServiceId)
{
    int ret = -1;
    if(this != NULL)
    {
        if(ServiceId > 0)
        {
            this->serviceId = ServiceId;
            ret = 0;
        }
    }
    return ret;
}

int service_setServiceType(Service* this, char* serviceType)
{
    int ret = -1;
    int len;

    if(this != NULL && serviceType != NULL)
    {
        len = strlen(serviceType);

        if(len > 0 && len < STRING_SIZE)
		{
			strncpy(this->serviceType, serviceType, STRING_SIZE);
			ret = 0;
		}
     }
    return ret;
}

int service_setPrice(Service* this, float price)
{
    int ret = -1;
    if(this != NULL)
    {
        if(price > 0)
        {
            this->price = price;
            ret = 0;
        }
    }
    return ret;
}

Service* service_newParameters(char* ServiceIdStr, char* serviceTypeStr, char* priceStr)
{
    Service* newService;
    int aux;
    int errorFlag;
    newService = service_new();

    if(newService != NULL && ServiceIdStr != NULL && serviceTypeStr != NULL && priceStr != NULL)
    {
        aux = atoi(ServiceIdStr);
        if(service_setServiceId(newService, aux))
        {
            errorFlag = 1;
        }

        if(service_setServiceType(newService, serviceTypeStr))
        {
            errorFlag = 1;
        }

        aux = atof(priceStr);
        if(service_setPrice(newService, aux))
        {
            errorFlag = 1;
        }

        if(errorFlag == 1)
        {
            free(newService);
            newService = NULL;
        }
    }
    return newService;
}

int service_getPrice(Service* this)
{
	int price;
    if(this != NULL)
    {
        price = this->price;
    }
    return price;
}
