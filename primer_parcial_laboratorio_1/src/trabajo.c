#include "trabajo.h"
#include "servicio.h"
#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gets.h"
#include "menu.h"

static int work_swapPostionInArray (Work* list, int positionToSwap);
static int work_newId (void);

static int work_newId(void)
{
	static int id = 1;
	id = id+1;
	return id;
}

int work_force_init(Work* list, int len, char* brandBike, float wheeledBike, int idService, char* date)
{
    int ret = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        i = work_freePosition(list,len);
        if(i >= 0)
        {
        	list[i].id = work_newId();
        	list[i].isEmpty = FALSE;
        	strncpy(list[i].brandBike, brandBike, STRING_SIZE_BRAND);
			list[i].wheeledBike = wheeledBike;
			list[i].idService = idService;
			strncpy(list[i].date, date, STRING_SIZE_DATE);
        }
        ret = 0;
    }
    return ret;
}

int work_init(Work* list, int len)
{
	int ret = -1;
	if (list != NULL && len >0)
    {
		for (int i = 0; i<len; i++ )
		{
			list[i].isEmpty=TRUE;
		}
		ret = 0;
	}

	return ret;
}

int work_create(Work* listWork, int lenWork, Service* listService, int lenService)
{
int ret = -1;
int index;
int indexService;
Work buffer;

	if (listWork != NULL && lenWork >0 && listService != NULL && lenService >0)
	{
		if (!work_freePositionIndex (listWork, lenWork, &index))
		{
			if (!getString("\nMarca de la bicicleta: ", "\nSupera a la cantidad de cartacteres permitidos", buffer.brandBike, 2, STRING_SIZE_BRAND) &&
				!getInt ("\nIngrese rodado: ", "\nLos caracteres ingresados no son un numero", &buffer.wheeledBike, 2, 12, 29) &&
				!service_printArray(listService, lenService) &&
				!getInt("\nIngrese id de Service del trabajo:", "Ingresar unicamente numeros", &buffer.idService, 2, MIN_ID_SERVICE, MAX_ID_SERVICE) &&
				(indexService=service_searchId(listService, lenService, buffer.idService))>=0 )
				//&& !getDate("\nFecha: ", "\nSupera a la cantidad de cartacteres permitidos", buffer.date, 2, STRING_SIZE_DATE))
			{
				listWork[index]=buffer;
				listWork[index].id=work_newId();
				listWork[index].isEmpty=FALSE;
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


int work_update(Work* listWork, int lenWork, Service* listService, int lenService)
{
	int ret = -1;
	int aux;
	int auxIndex;
	int indexService;
	char auxMenu='s';
	Work buffer;

	if (listWork != NULL && lenWork >0 && listService != NULL && lenService >0)
	{
		work_printArray(listWork, lenWork);
		if(!getInt("\nIngrese el id del usuario que desea cambiar: ", "\nIngresar unicamente numeros", &aux, 2, 1, 1000))
		{
			auxIndex=work_searchId(listWork, lenWork, aux);
			if(listWork[auxIndex].isEmpty==FALSE)
			{
				work_print(listWork,auxIndex);
				buffer = listWork[auxIndex];
				do
				{
					switch (menuChangeParameterWork())
					{
						case 1:
							if(!getString("\nMarca de la bicicleta: ", "\nSupera a la cantidad de cartacteres permitidos", buffer.brandBike, 2, STRING_SIZE_BRAND))
							{
								strncpy(listWork[auxIndex].brandBike, buffer.brandBike, STRING_SIZE_BRAND);
								work_print(listWork,auxIndex);
							}
							break;
						case 2:
							if(!getInt("\nIngrese id service: ", "\nLos caracteres ingresados no son un numero", &buffer.idService, 2, MIN_ID_SERVICE, MAX_ID_SERVICE) &&
							  (indexService=service_searchId(listService, lenService, buffer.idService))>=0)
							{
								listWork[auxIndex].idService = buffer.idService;
								work_print(listWork,auxIndex);
							}
							else
								{
									printf("\nNo existe id Service\n\n");
								}
							break;
						case 3:
							auxMenu='n';
							break;

						default:
							printf("\nIngrese opcion correcta\n\n");
							break;
					}
				}while (auxMenu=='s');
				work_print(listWork,auxIndex);
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

int work_delete(Work* list, int len)
{
	int ret = -1;
	Work buffer;

	if (list != NULL && len>0)
	{
		work_printArray(list, len);
		getInt("\nIngrese el id del trabajo que desea borrar: ", "\nIngresar unicamente numeros", &buffer.id, 2, 1, 30000);

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

int work_print(Work* list, int index)
{
	int ret = -1;

	if(list != NULL && index >= 0)
	{
		if(list[index].isEmpty==FALSE)
		{
			printf("\nID: %d - Marca de la Bicicleta: %s - Rodado: %d - ID del Servicio: %d - Fecha: %s",list[index].id, list[index].brandBike, list[index].wheeledBike, list[index].idService, list[index].date);
			ret = 0;
		}
		else
		{
			printf("\n/****Error - No existe el cliente****/\n");
		}
	}
	return ret;
}

int work_printArray(Work* list , int len)
{
	int ret = -1;
	if (list != NULL && len >0){
		for (int i=0 ; i<len ; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\nID: %d - Marca de la Bicicleta: %s - Rodado: %d - ID del Servicio: %d - Fecha: %s",list[i].id, list[i].brandBike, list[i].wheeledBike, list[i].idService, list[i].date);
			}
		}
		ret = 0;
	}
return ret;
}

int work_freePosition(Work* list, int len)
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

int work_freePositionIndex(Work* list, int len, int* pIndex)
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

int work_searchId(Work* list, int len, int id)
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


static int work_swapPostionInArray (Work* list, int positionToSwap)
{
	int ret = -1;
	Work buffer;

	if(list != NULL && positionToSwap >= 0)
	{
		ret = 0;
		buffer = list[positionToSwap];
		list[positionToSwap] = list[positionToSwap+1];
		list[positionToSwap+1] = buffer;
	}

	return ret;
}

int work_sortArray(Work* list, int len, int order)
{
	int ret = -1;
	int flagSwap;

	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		do
		{
			flagSwap = 0;
			for(int i=0; i<(len-1); i++)
			{
				if (order == 0 && (strncmp(list[i].date, list[i+1].date, STRING_SIZE_DATE)>0 ||
								  (strncmp(list[i].date, list[i+1].date, STRING_SIZE_DATE)==0 && strncmp(list[i].brandBike, list[i+1].brandBike, STRING_SIZE_BRAND)>0)))
				{
					work_swapPostionInArray (list, i);
				}
				else if(order == 1 && (strncmp(list[i].date, list[i+1].date, STRING_SIZE_DATE)<0 ||
									  (strncmp(list[i].date, list[i+1].date, STRING_SIZE_DATE)==0 && strncmp(list[i].brandBike, list[i+1].brandBike, STRING_SIZE_BRAND)<0)))
					{
						work_swapPostionInArray (list, i);
					}
			}
		}while(flagSwap);
		ret = 0;
	}
	return ret;
}


int work_printArraySortByYear(Work* list , int len)
{
	int ret = -1;
	int order = DSC;

	if(list != NULL && len > 0)
	{
		if (!work_sortArray(list, len, order))
		{

			work_printArray(list, len);
			ret =0;
		}
	}
	return ret;
}
