#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gets.h"
#include "menu.h"
#include "brand.h"

static int brand_newId (void);

static int brand_newId (void)
{
	static int id = MIN_ID_BRAND;
	id = id+1;
	return id;
}

int brand_force_init(Brand* list, int len, char* brandDescription)
{
    int ret = -1;
    int i;

    if(len > 0 && list != NULL)
    {
        i = brand_freePosition(list,len);
        if(i >= 0)
        {
        	list[i].idBrand=brand_newId();
        	list[i].isEmpty=FALSE;
        	strncpy(list[i].brandDescription, brandDescription, STRING_SIZE_DSC_BRAND);
        }
        ret = 0;
    }

    return ret;
}

int brand_init(Brand* list, int len)
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

int brand_freePosition(Brand* list, int len)
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

int brand_freePositionIndex(Brand* list, int len, int* pIndex)
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

int brand_searchId(Brand* list, int len, int id)
{
    int ret = -1;
    int i;

    if (list!=NULL && len>0 && id>=0)
    {
        for (i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE && list[i].idBrand == id)
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

int brand_create(Brand* listBrand, int lenBrand)
{
	int ret = -1;
	int index;
	Brand buffer;

	if (listBrand != NULL && lenBrand >0)
	{
		if (!brand_freePositionIndex (listBrand, lenBrand, &index))
		{
			if (!getString("\nMarca de la bicicleta: ", "\nSupera a la cantidad de cartacteres permitidos", buffer.brandDescription, 2, STRING_SIZE_DSC_BRAND))
			{
				listBrand[index]=buffer;
				listBrand[index].idBrand=brand_newId();
				listBrand[index].isEmpty=FALSE;
				ret = listBrand[index].idBrand;
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
