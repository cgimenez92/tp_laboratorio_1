#include "bike.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gets.h"
#include "menu.h"

static int bike_newId (void);

static int bike_newId(void)
{
	static int id = MIN_ID_BIKE;
	id = id+1;
	return id;
}

int bike_force_init(Bike* list, int len, char* brandBike, int wheeledBike,  char* colour)
{
    int ret = -1;
    int i;

    if(len > 0 && list != NULL)
    {
        i = bike_freePosition(list,len);
        if(i >= 0)
        {
        	list[i].idBike=bike_newId();
        	list[i].isEmpty=FALSE;
        	strncpy(list[i].brandBike, brandBike, STRING_SIZE_BRAND);
			list[i].wheeledBike=wheeledBike;
			strncpy(list[i].colour, colour, STRING_SIZE_COLOUR);
        }
        ret = 0;
    }

    return ret;
}

int bike_init(Bike* list, int len)
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

int bike_freePosition(Bike* list, int len)
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

int bike_freePositionIndex(Bike* list, int len, int* pIndex)
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

int bike_searchId(Bike* list, int len, int id)
{
    int ret = -1;
    int i;

    if (list!=NULL && len>0 && id>=0)
    {
        for (i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE && list[i].idBike == id)
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

int bike_searchBrand(Bike* list, int len, char* brandBike)
{
    int ret = -1;
    int i;

    if (list!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE && !stricmp(list[i].brandBike, brandBike))
            {
				ret = i;
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

int bike_printArray(Bike* list , int len)
{
	int ret = -1;
	if (list != NULL && len >0)
	{
		for (int i=0 ; i<len ; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\nID: %d - Marca: %s - Rodado: %d - Color: %s",
					  list[i].idBike, list[i].brandBike, list[i].wheeledBike, list[i].colour);
			}
		}
		ret = 0;
	}
return ret;
}

int bike_create(Bike* listBike, int lenBike)
{
	int ret = -1;
	int index;
	Bike buffer;

	if (listBike != NULL && lenBike >0)
	{
		if (!bike_freePositionIndex (listBike, lenBike, &index))
		{
			if (!getString("\nMarca de la bicicleta: ", "\nSupera a la cantidad de cartacteres permitidos", buffer.brandBike, 2, STRING_SIZE_BRAND) &&
				!getInt ("\nIngrese rodado: ", "\nLos caracteres ingresados no son un numero", &buffer.wheeledBike, 2, 12, 29) &&
				!getString("\nColor de la bicicleta: ", "\nSupera a la cantidad de cartacteres permitidos", buffer.colour, 2, STRING_SIZE_COLOUR) )
			{
				listBike[index]=buffer;
				listBike[index].idBike=bike_newId();
				listBike[index].isEmpty=FALSE;
				ret = listBike[index].idBike;
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
