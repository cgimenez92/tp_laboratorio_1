#include <stdio.h>
#include "gets.h"
#include "menu.h"
#include "work.h"

static int work_newId (void);

static int work_newId(void)
{
	static int id = 0;
	id = id+1;
	return id;
}

int work_force_init(Work* list, int len, int idBike, int idWheel, int idService, int day, int month, int year)
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
        	list[i].idBike = idBike;
        	list[i].idWheel = idWheel;
			list[i].idService = idService;
			list[i].ddmmyyyy.dd = day;
			list[i].ddmmyyyy.mm = month;
			list[i].ddmmyyyy.yyyy = year;
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

int work_create(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel)
{
int ret = -1;
int index;
int indexService;
int indexBike;
int indexWheel;
char bufferBrand[STRING_SIZE_BRAND];
Work buffer;

	if (listWork != NULL && lenWork >0 && listService != NULL && lenService >0 && listBike != NULL && lenBike >0)
	{
		if (!work_freePositionIndex (listWork, lenWork, &index))
		{
			//idBike = bike_create(listBike, lenBike);
			if (!service_printArray(listService, lenService)
				&& !getInt("\nIngrese ID de Service del trabajo:", "Ingresar unicamente numeros", &buffer.idService, 2, MIN_ID_SERVICE, MAX_ID_SERVICE)
				&& (indexService=service_searchId(listService, lenService, buffer.idService))>=0
				&& !bike_printArray(listBike, lenBike)
				&& !getString("\nIngrese la Marca de la Bicicleta:", "\nMarca supera la cantidad de caracteres permitidos", bufferBrand, 2, STRING_SIZE_BRAND)
				&& (indexBike=bike_searchBrand(listBike, lenBike, bufferBrand))>=0
				&& !wheel_printArray(listWheel, lenWheel)
				&& !getInt("\nIngrese el ID del rodado y estado de las cubiertas de la bicicleta:", "Ingresar unicamente numeros", &buffer.idWheel, 2, MIN_ID_WHEEL, MAX_ID_WHEEL)
				&& (indexWheel=wheel_searchId(listWheel, lenWheel, buffer.idWheel))>=0
				&& !getDate("\nIngresar Fecha - DD/MM/YYYY: ", &buffer.ddmmyyyy, 2))
			{
				listWork[index].idService = buffer.idService;
				//printf("\nidService %d\n", listWork[index].idService);
				listWork[index].idBike = listBike[indexBike].idBike;
				//printf("\nidBike %d\n", listWork[index].idBike);
				listWork[index].idWheel = buffer.idWheel;
				listWork[index].id = work_newId();
				//printf("\nid %d\n", listWork[index].id);
				listWork[index].isEmpty = FALSE;
				//printf("\nisEmpty %d\n", listWork[index].isEmpty);
				listWork[index].ddmmyyyy = buffer.ddmmyyyy;
				ret = index;
				//printf("\nret %d\n", ret);
				work_printArray(listWork, lenWork, listService, lenService, listBike, lenBike, listWheel, lenWheel);
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

int work_update(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel)
{
	int ret = -1;
	int aux;
	int auxIndex;
	int indexService;
	int indexBike;
	char bufferBrand[STRING_SIZE_BRAND];
	char auxMenu='s';
	Work buffer;

	if (listWork != NULL && lenWork >0 && listService != NULL && lenService >0)
	{
		work_printArray(listWork, lenWork, listService, lenService, listBike, lenBike, listWheel, lenWheel);
		if(!getInt("\nIngrese el id del trabajo que desea cambiar: ", "\nIngresar unicamente numeros", &aux, 2, 1, 1000))
		{
			auxIndex=work_searchId(listWork, lenWork, aux);
			if(listWork[auxIndex].isEmpty==FALSE)
			{
				work_print(listWork, listService, lenService, listBike, lenBike, listWheel, lenWheel, auxIndex);
				buffer = listWork[auxIndex];
				do
				{
					switch (menuChangeParameterWork())
					{
						case 1:
							if(!bike_printArray(listBike, lenBike)
								&& !getString("\nIngrese la Marca de la Bicicleta:", "\nMarca supera la cantidad de caracteres permitidos", bufferBrand, 2, STRING_SIZE_BRAND)
								&& (indexBike=bike_searchBrand(listBike, lenBike, bufferBrand))>=0)
							{
								listWork[auxIndex].idBike = listBike[indexBike].idBike;
								work_print(listWork, listService, lenService, listBike, lenBike, listWheel, lenWheel, auxIndex);
							}
							break;
						case 2:
							if(!service_printArray(listService, lenService)
								&& !getInt("\nIngrese ID de Service del trabajo:", "Ingresar unicamente numeros", &buffer.idService, 2, MIN_ID_SERVICE, MAX_ID_SERVICE)
								&& (indexService=service_searchId(listService, lenService, buffer.idService))>=0)
							{
								listWork[auxIndex].idService = buffer.idService;
								work_print(listWork, listService, lenService, listBike, lenBike, listWheel, lenWheel, auxIndex);
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
				work_print(listWork, listService, lenService, listBike, lenBike, listWheel, lenWheel, auxIndex);
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

int work_delete(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel)
{
	int ret = -1;
	Work buffer;

	if (listWork != NULL && lenWork >0 && listService != NULL && lenService >0 && listBike != NULL && lenBike >0)
	{
		work_printArray(listWork, lenWork, listService, lenService, listBike, lenBike, listWheel, lenWheel);
		getInt("\nIngrese el id del trabajo que desea borrar: ", "\nIngresar unicamente numeros", &buffer.id, 2, 1, 30000);

		for (int i = 0 ; i<lenWork ;  i++)
		{
			if (buffer.id == listWork[i].id)
			{
				listWork[i].isEmpty = TRUE;
				ret =0;
			}
		}
	}
	return ret;
}

int work_print(Work* listWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel, int index)
{
	int ret = -1;
	int indexBike;
	int indexService;
	int indexWheel;

	if(listWork != NULL && listService != NULL && lenService >0 && listBike != NULL && lenBike >0 && listWheel != NULL && lenWheel >0 && index >= 0)
	{
		indexBike = bike_searchId(listBike, lenBike, listWork[index].idBike);
		indexService = service_searchId(listService, lenService, listWork[index].idService);
		indexWheel=wheel_searchId(listWheel, lenWheel, listWork[index].idWheel);

		if(listWork[index].isEmpty == FALSE)
		{
			printf("\nID del Trabajo: %d - Fecha: %d/%d/%d - Descripcion del Service: %s - Precio: %.2f - Marca Bicicleta: %s - Rodado: %d - Color: %s",
					listWork[index].id, listWork[index].ddmmyyyy.dd, listWork[index].ddmmyyyy.mm, listWork[index].ddmmyyyy.yyyy,
					listService[indexService].description, listService[indexService].price,
					listBike[indexBike].brandBike, listWheel[indexWheel].wheelSize, listBike[indexBike].colour);
			ret = 0;
		}
		else
		{
			printf("\n/****Error - No existe el trabajo****/\n");
		}
	}
	return ret;
}

int work_printArray(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel)
{
	int ret = -1;
	int indexBike;
	int indexService;
	int indexWheel;

	if (listWork != NULL && lenWork >0 && listService != NULL && lenService >0 && listBike != NULL && lenBike >0 && listWheel != NULL && lenWheel >0)
	{
		for (int i=0 ; i<lenWork ; i++)
		{
			indexBike = bike_searchId(listBike, lenBike, listWork[i].idBike);
			indexService = service_searchId(listService, lenService, listWork[i].idService);
			indexWheel = wheel_searchId(listWheel, lenWheel, listWork[i].idWheel);

			if(listWork[i].isEmpty == FALSE)
			{
				printf("\nID del Trabajo: %d - Fecha: %d/%d/%d - Descripcion del Service: %s - Precio: %.2f - Marca Bicicleta: %s - Rodado: %d - Color: %s",
						listWork[i].id, listWork[i].ddmmyyyy.dd, listWork[i].ddmmyyyy.mm, listWork[i].ddmmyyyy.yyyy,
						listService[indexService].description, listService[indexService].price,
						listBike[indexBike].brandBike, listWheel[indexWheel].wheelSize, listBike[indexBike].colour);
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


int work_swapPostionInArray (Work* list, int positionToSwap)
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

int work_sortArray(Work* list, int len, int order, Bike* listBike, int lenBike)
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
				if ((order == 0 && (list[i].ddmmyyyy.yyyy > list[i+1].ddmmyyyy.yyyy))
				   || (list[i].ddmmyyyy.yyyy == list[i+1].ddmmyyyy.yyyy  && list[i].idBike > list[i+1].idBike))
				{
					work_swapPostionInArray (list, i);
					flagSwap = 1;
				}
				else if ((order == 1 && (list[i].ddmmyyyy.yyyy < list[i+1].ddmmyyyy.yyyy))
						|| (list[i].ddmmyyyy.yyyy == list[i+1].ddmmyyyy.yyyy  && list[i].idBike > list[i+1].idBike))
					{
						work_swapPostionInArray (list, i);
						flagSwap = 1;
					}
			}
		}while(flagSwap);
		ret = 0;
	}
	return ret;
}

int work_sortArrayByIdService (Work* list, int len, int order)
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
				if (order == 0 && list[i].idService > list[i+1].idService)
				{
					work_swapPostionInArray (list, i);
					flagSwap = 1;
				}
				else if (order == 1 && list[i].idService < list[i+1].idService)
					{
						work_swapPostionInArray (list, i);
						flagSwap = 1;
					}
			}
		}while(flagSwap);
		ret = 0;
	}
	return ret;
}

int work_sortArrayByIdBike (Work* list, int len, int order)
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
				if (order == 0 && list[i].idBike > list[i+1].idBike)
				{
					work_swapPostionInArray (list, i);
					flagSwap = 1;
				}
				else if (order == 1 && list[i].idBike < list[i+1].idBike)
					{
						work_swapPostionInArray (list, i);
						flagSwap = 1;
					}
			}
		}while(flagSwap);
		ret = 0;
	}
	return ret;
}

int work_sortArrayByIdWheel (Work* list, int len, int order)
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
				if (order == 0 && list[i].idWheel > list[i+1].idWheel)
				{
					work_swapPostionInArray (list, i);
					flagSwap = 1;
				}
				else if (order == 1 && list[i].idWheel < list[i+1].idWheel)
					{
						work_swapPostionInArray (list, i);
						flagSwap = 1;
					}
			}
		}while(flagSwap);
		ret = 0;
	}
	return ret;
}



int work_printArraySortByYear(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel)
{
	int ret = -1;

	if(listWork != NULL && lenWork >0 && listService != NULL && lenService >0 && listBike != NULL && lenBike >0)
	{
		if(!work_sortArray(listWork, lenWork, ASC,  listBike, lenBike))
		{

			work_printArray(listWork, lenWork, listService, lenService, listBike, lenBike, listWheel, lenWheel);
			ret =0;
		}
	}
	return ret;
}
