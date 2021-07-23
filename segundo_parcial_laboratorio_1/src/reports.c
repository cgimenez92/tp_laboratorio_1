/*
 * reports.c
 *
 *  Created on: 23 jul. 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Customer.h"
#include "Service.h"
#include "LinkedList.h"

int report_printRelationData(LinkedList* pArrayListCustomer, LinkedList* pArrayListService)
{
	int ret = -1;
	Customer* pCustomer;
	Service* pService;

	if (pArrayListCustomer != NULL && pArrayListService != NULL)
	{
		for (int i=0 ; i<ll_len(pArrayListCustomer) ; i++)
		{
			pCustomer=ll_get(pArrayListCustomer,i);

			for (int j=0 ; j<ll_len(pArrayListService) ; j++)
			{
				pService=ll_get(pArrayListService,j);

				if(pCustomer->idContractedService == pService->serviceId)
				{
					printf("Pais: %s - Genero: %s - Nombre: %s - Apellido: %s - Fecha de nacimiento: %s - Tipo de servicio contratado: %s - Precio %.2f\n",
							pCustomer->country, pCustomer->gender, pCustomer->firtsName, pCustomer->lastName, pCustomer->birthDate, pService->serviceType, pService->price);
				}
			}
		}
		ret = 0;
	}
return ret;
}

int report_countByCountry(LinkedList* this)
{
	int ret=-1;

	if(this != NULL)
	{
		ret = ll_count(this, customer_filterByUSCountry);

		printf("\nLa cantidad de clientes provenientes de US son %d\n", ret);
	}

	return ret;
}

//precio promedio por servicio.

int report_avgByService(LinkedList* this)
{
	int ret=0;
	int qServices;
	float auxCollect;
	float avgPrice;

	if(this != NULL)
	{
		auxCollect = ll_count(this, service_getPrice);
		printf("\ncollect %.2f\n", auxCollect);
		qServices = ll_len(this);

		if(auxCollect>-1 && qServices>-1)
		{
			avgPrice = auxCollect/(float)qServices;
			printf("\nPrecio promedio de los paquetes de servicios es %.2f\n", avgPrice);
			ret=1;
		}
	}
	return ret;
}

LinkedList* report_filterCustomerByGender(LinkedList* this)
{
	LinkedList* auxList = NULL;

	if(this != NULL)
	{
		auxList = ll_newLinkedList();
		auxList = ll_filter(this, customer_filterByGender);
		controller_ListCustomer(auxList);
	}

	return auxList;
}

LinkedList* report_filterCustomerByUSCountry(LinkedList* this)
{
	LinkedList* auxList = NULL;

	if(this != NULL)
	{
		auxList = ll_newLinkedList();
		auxList = ll_filter(this, customer_filterByUSCountry);
		controller_ListCustomer(auxList);
	}

	return auxList;
}


