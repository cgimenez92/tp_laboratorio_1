/*
 * reports.c
 *
 *  Created on: Jul 4, 2021
 *      Author: Administrador
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reports.h"
#include "work.h"
#include "service.h"

int priceTotalPerService(Work* listWork, int lenWork, Service* listService, int lenService, float* totalValue)
{
	int ret = -1;
	int buffer=0;
	int indexService;
	int i;

	if(listWork != NULL && lenWork > 0 && listService != NULL && lenService > 0)
	{
		ret = 0;
		for (i=0; i<lenWork && listWork[i].isEmpty == FALSE; i++)
		{
			indexService = service_searchId(listService, lenService, listWork[i].idService);
			buffer += listService[indexService].price;
		}
	}

	*totalValue = buffer;
	return ret;
}


//El o los servicios con más trabajos realizados.
int maxServicePerWork (Work* listWork, int lenWork, int* maxValue)
{
	int ret = -1;
	int qWorks;
	int i;
	int j;

	if(listWork!=NULL && lenWork>0)
	{
		for(i=0; i<lenWork ; i++)
		{
			qWorks = 0;
			for(j=0; j<lenWork; j++)
			{
				if(listWork[i].idService == listWork[j].idService)
				{
					qWorks++;
				}

				if((!i || qWorks > *maxValue) && listWork[i].isEmpty ==  FALSE)
				{
					*maxValue = qWorks;
					ret=0;
				}
			}
		}
	}
	return ret;
}

int report_servicesWithMoreWorks (Work* listWork, int lenWork)
{
	int ret = -1;
	int maxValue=0;
	int flagWorks=0;
	int i;
	int j;

	if(!maxServicePerWork(listWork, lenWork, &maxValue))
	{
		work_sortArrayByIdService (listWork, lenWork, ASC);
		for(i=0; i<lenWork; i++)
		{
			flagWorks = 0;
			for(j=0; j<lenWork; j++)
			{
				if(listWork[i].isEmpty == FALSE && listWork[i].idService == listWork[j].idService)
				{
					flagWorks++;
				}
			}

			if(flagWorks == maxValue && listWork[i].idService != listWork[i+1].idService)
			{
				printf("************ ID: %d - Cantidad de publicaciones: %d ***********\n", listWork[i].idService, maxValue);
			}
		}
		ret = 0;
	}
	return ret;
}

int report_test(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel)
{
	int ret = -1;
	int indexBike;
	int indexService;
	int indexWheel;

	if (listWork != NULL && lenWork >0 && listService != NULL && lenService >0 && listBike != NULL && lenBike >0 && listWheel != NULL && lenWheel >0)
	{
		for (int i=0 ; i<lenService ; i++)
		{
			if(listService[i].isEmpty == FALSE)
			{
				printf("***************************************************************\n");
				printf("********* ID SERVICE %d - DESCRIPCION SERVICE %s *******\n", listService[i].id, listService[i].description);
				printf("***************************************************************\n");

				for (int j=0 ; j<lenWork ; j++)
				{
					indexBike = bike_searchId(listBike, lenBike, listWork[j].idBike);
					indexService = service_searchId(listService, lenService, listWork[j].idService);
					indexWheel = wheel_searchId(listWheel, lenWheel, listWork[j].idWheel);

					if(listWork[j].isEmpty == FALSE && listService[i].id == listWork[j].idService)
					{
						printf("\nMarca Bicicleta: %s - Rodado: %d - Color: %s\n\n",
								listBike[indexBike].brandBike, listWheel[indexWheel].wheelSize, listBike[indexBike].colour);
					}
				}
			}
		}
		ret = 0;
	}
return ret;
}

