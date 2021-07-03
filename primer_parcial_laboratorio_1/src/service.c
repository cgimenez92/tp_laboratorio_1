#include "service.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gets.h"
#include "menu.h"

static int service_newId (void);

static int service_newId(void)
{
	static int id = MIN_ID_SERVICE;
	id = id+1;
	return id;
}

int service_force_init(Service* list, int len, char* description, float price)
{
    int ret = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        i = service_freePosition(list,len);
        if(i >= 0)
        {
        	list[i].id=service_newId();
        	list[i].isEmpty=FALSE;
        	strncpy(list[i].description, description, STRING_SIZE);
			list[i].price = price;
        }
        ret = 0;
    }
    return ret;
}

int service_init(Service* list, int len)
{
	int ret = -1;
	int i;

	if (list != NULL && len >0)
    {
		for (i = 0; i<len; i++ )
		{
			list[i].isEmpty=TRUE;
		}
		ret = 0;
	}

	return ret;
}

int service_create(Service* list, int len)
{
int ret = -1;
int index;
Service buffer;

	if (list != NULL && len >0)
	{
		if (!service_freePositionIndex (list, len, &index))
		{
			if (!getString("Descripcion: ", "Supera a la cantidad de cartacteres permitidos", buffer.description, 2, STRING_SIZE) &&
				!getFloat ("Ingrese precio: ", "Los caracteres ingresados no son un numero", &buffer.price, 2, 0, 1000000))
			{
				list[index]=buffer;
				list[index].id=service_newId();
				list[index].isEmpty=FALSE;
				ret = index;
			}
			else
				{
					printf("\n/****Error - Finalizaron la cantidad de intentos****/\n");
				}
		}
		else
			{
				printf("\n/****Error - No se encuentran espacios disponibles en el listado de clientes****/\n");
			}
	}
	return ret;
}


int service_update(Service* list, int len)
{
	int ret = -1;
	int aux;
	int auxIndex;
	char auxMenu='s';
	Service buffer;

	if(list != NULL && len > 0)
	{
		service_printArray(list, len);
		if(!getInt("Ingrese el id del usuario que desea cambiar: ", "Ingresar unicamente numeros", &aux, 2, 1, 1000))
		{
			auxIndex=service_searchId(list, len, aux);
			if(list[auxIndex].isEmpty==FALSE)
			{
				service_print(list,auxIndex);
				buffer = list[auxIndex];
				do
				{
					switch (menuChangeParameterService())
					{
						case 1:
							if(!getString("Descripcion: ", "Supera a la cantidad de cartacteres permitidos", buffer.description, 2, STRING_SIZE))
							{
								strncpy(list[auxIndex].description, buffer.description, STRING_SIZE);
							}
							break;
						case 2:
							if(!getFloat ("Ingrese precio: ", "Los caracteres ingresados no son un numero", &buffer.price, 2, 0, 1000000))
							{
								list[auxIndex].price = buffer.price;
							}
							break;
						case 4:
							auxMenu='n';
							break;

						default:
							printf("\nIngrese opcion correcta\n\n");
							break;
					}
				}while (auxMenu=='s');
				service_print(list,auxIndex);
				ret = 0;
			}
		}
		else
			{
				printf("\n/****Error - No se encuentran datos del Id ingresado****/\n");
			}
	}
	return ret;
}

int service_delete(Service* list, int len)
{
	int ret = -1;
	Service buffer;

	if (list != NULL && len>0)
	{
		service_printArray(list, len);
		getInt("Ingrese el id del servicio que desea borrar: ", "Ingresar unicamente numeros", &buffer.id, 2, 20000, 30000);

		for (int i = 0 ; i<len ;  i++)
		{
			if (buffer.id == list[i].id)
			{
				list[i].isEmpty = TRUE;
			}
		}
	}
	return ret;
}

int service_print(Service* list, int index)
{
	int ret = -1;

	if(list != NULL && index >= 0)
	{
		if(list[index].isEmpty==FALSE)
		{
			printf("\nID: %d - Descripcion: %s - Precio: %.2f",list[index].id, list[index].description, list[index].price);
			ret = 0;
		}
		else
		{
			printf("\n/****Error - No existe el cliente****/\n");
		}
	}
	return ret;
}

int service_printArray(Service* list , int len)
{
	int ret = -1;
	if (list != NULL && len >0){
		for (int i=0 ; i<len ; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\nID: %d - Descripcion: %s - Precio: %.2f",list[i].id, list[i].description, list[i].price);
			}
		}
		ret = 0;
	}
return ret;
}

int service_freePosition(Service* list, int len)
{
	int ret = -1;
	int i ;
		if (list != NULL && len>0)
        {
			for ( i = 0; i<len; i++)
            {
				if(list[i].isEmpty == TRUE)
				{
					ret = i;
					break;
				}
			}
		}
	return ret;
}

int service_freePositionIndex(Service* list, int len, int* pIndex)
{
	int ret = -1;
	int i;
		if (list != NULL && len >0 && pIndex != NULL)
        {
			for ( i = 0; i<len; i++)
			{
				if(list[i].isEmpty==TRUE)
				{
					*pIndex = i;
					ret = 0;
					break;
				}
			}
		}
	return ret;
}

int service_searchId(Service* list, int len, int id)
{
    int ret = -1;
    if (list!=NULL && len>0 && id>=0)
    {
        for (int i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE && list[i].id == id)
            {
				ret= i;
				break;
            }
        }
    }
    else
    {
        ret = 0;
    }
    return ret;
}

int priceTotalPerService(Service* list,  int len, float* totalValue)
{
	int ret = -1;
	int buffer=0;
	int i;

	if(list != NULL && len > 0)
	{
		ret = 0;
		for (i=0; i<len && list[i].isEmpty == FALSE; i++)
		{
			buffer += list[i].price;
		}
	}

	*totalValue = buffer;
	return ret;
}
