#include "wheel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gets.h"
#include "menu.h"

static int wheel_newId (void);

static int wheel_newId(void)
{
	static int id = 0;
	id = id+1;
	return id;
}

int wheel_freePosition(Wheel* list, int len)
{
	int ret = -1;
	int i ;

	if (list != NULL && len>0)
	{
		for (i = 0; i<len; i++)
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

int wheel_force_init(Wheel* list, int len, int wheelSize, char* wheelCondition)
{
    int ret = -1;
    int i;

    if(len > 0 && list != NULL)
    {
        i = wheel_freePosition(list,len);
        if(i >= 0)
        {
        	list[i].idWheel=wheel_newId();
        	list[i].isEmpty=FALSE;
        	strncpy(list[i].wheelCondition, wheelCondition, STRING_SIZE_COND);
			list[i].wheelSize=wheelSize;
        }
        ret = 0;
    }
    return ret;
}

int wheel_init(Wheel* list, int len)
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


int wheel_freePositionIndex(Wheel* list, int len, int* pIndex)
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

int wheel_searchId(Wheel* list, int len, int id)
{
    int ret = -1;
    int i;

    if (list!=NULL && len>0 && id>=0)
    {
        for (i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE && list[i].idWheel == id)
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

int wheel_printArray(Wheel* list , int len)
{
	int ret = -1;
	if (list != NULL && len >0)
	{
		for (int i=0 ; i<len ; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\nID: %d - Rodado: %d - Condicion del rodado: %s",
					  list[i].idWheel, list[i].wheelSize, list[i].wheelCondition);
			}
		}
		ret = 0;
	}
return ret;
}
