/*
 * Controller.c
 *
 *  Created on: Jul 21, 2021
 *      Author: Administrador
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Customer.h"
#include "Service.h"
#define ATTEMPTS 2

int controller_deleteListCustomer(LinkedList* this)
{
    int ret = -1;
    int len;
    int i;
    Customer* pCustomer;
    if(this != NULL)
    {
        len = ll_len(this);
        if(len > 0)
        {
            for(i=0; i<len; i++)
            {
            	pCustomer = ll_get(this, i);
                customer_delete(pCustomer);
            }
            ll_deleteLinkedList(this);
            ret = 0;
        }
    }
    return ret;
}

int controller_deleteListService(LinkedList* this)
{
    int ret = -1;
    int len;
    int i;
    Service* pService;
    if(this != NULL)
    {
        len = ll_len(this);
        if(len > 0)
        {
            for(i=0; i<len; i++)
            {
            	pService = ll_get(this, i);
                service_delete(pService);
            }
            ll_deleteLinkedList(this);
            ret = 0;
        }
    }
    return ret;
}

int controller_ListCustomer(LinkedList* this)
{
    int i;
    Customer* pCustomer;

	if(this != NULL)
	{
		printf("\n|    Id     |       Pais       |        Genero       |       Nombre       |       Apellido       |     servicio     |\n\n");

		for(i=0;i<ll_len(this);i++)
		{
			pCustomer=ll_get(this,i);
			customer_print(pCustomer);
		}
	}

    return 1;
}

