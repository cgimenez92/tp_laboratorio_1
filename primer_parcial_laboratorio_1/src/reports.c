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
#include "gets.h"
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

//G. Listado de todos los trabajos ordenados por marca de la bicicleta.

int work_sortArrayByBrand (Work* listWork, int lenWork, Bike* listBike, int lenBike, int order)
{
	int ret = -1;
	int flagSwap;
	int indexBike;
	int secondIndexBike;

	if(listWork != NULL && lenWork > 0 && (order == 0 || order == 1))
	{
		work_sortArrayByIdBike (listWork, lenWork, order);
		do
		{
			flagSwap = 0;
			for(int i=0; i<lenBike; i++)
			{
				if(listBike[i].isEmpty==FALSE)
				{
					for(int j=0; j<lenWork; j++)
					{
						if(listWork[j].isEmpty==FALSE && listWork[j+1].isEmpty==FALSE)
						{
							indexBike = bike_searchId(listBike, lenBike, listWork[j].idBike);
							secondIndexBike = bike_searchId(listBike, lenBike, listWork[j+1].idBike);

							if (order == 0
								&& listWork[j].idBike == listBike[i].idBike
								&& strcmp(listBike[indexBike].brandBike, listBike[secondIndexBike].brandBike)>0)
							{
								work_swapPostionInArray (listWork, j);
								flagSwap = 1;
							}
							else if ((order == 1
									&& listWork[j].idBike == listBike[i].idBike
									&& strcmp(listBike[indexBike].brandBike, listBike[secondIndexBike].brandBike)<0))
							{
								work_swapPostionInArray (listWork, j);
								flagSwap = 1;
							}
						}
					}
				}
			}
		}while(flagSwap);
		ret = 0;
	}
	return ret;
}

int work_printArraySortByBrand(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel)
{
	int ret = -1;

	if(listWork != NULL && lenWork >0 && listService != NULL && lenService >0 && listBike != NULL && lenBike >0)
	{
		if(!work_sortArrayByBrand(listWork, lenWork, listBike, lenBike, ASC))
		{

			work_printArray(listWork, lenWork, listService, lenService, listBike, lenBike, listWheel, lenWheel);
			ret =0;
		}
	}
	return ret;
}

//int report_worksByBrand(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel)
//{
//	int ret = -1;
//	int j;
//	int i;
//
//	if (listWork != NULL && lenWork>0 && listBike != NULL && lenBike>0)
//	{
//		bike_sortArrayByBrand(listBike, lenBike, DSC);
//		for(i=0; i<lenBike; i++)
//		{
//			for(j=0; j<lenWork; j++)
//			{
//				if(listWork[j].isEmpty == FALSE && listBike[i].idBike == listWork[j].idBike)
//				{
//					work_printArray(listWork, lenWork, listService, lenService, listBike, lenBike, listWheel, lenWheel);
//					ret = 0;
//				}
//			}
//		}
//		printf("\n");
//	}
//	return ret;
//}

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
				printf("************ ID de Servicio: %d - Cantidad de Trabajos: %d ***********\n", listWork[i].idService, maxValue);
			}
		}
		ret = 0;
	}
	return ret;
}

//Listado de servicios con los datos de las bicicletas que se lo realizaron.

int report_servicesBikes(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel)
{
	int ret = -1;
	int indexBike;
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
					indexWheel = wheel_searchId(listWheel, lenWheel, listWork[j].idWheel);

					if(listWork[j].isEmpty == FALSE && listService[i].id == listWork[j].idService)
					{
						printf("\nMarca Bicicleta: %s - Rodado: %d - Color: %s\n\n",
								listBike[indexBike].brandBike, listWheel[indexWheel].wheelSize, listBike[indexBike].colour);
					}
				}
				//Ver de cambiar el segundo For por una funcion. Actualmente funciona.
			}
		}
		ret = 0;
	}
return ret;
}

//La cantidad de biciletas de color Rojo que realizaron un servicio elegido por el usuario.

int report_qBikesPerService(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, char* colour)
{
	int ret = -1;
	int flagsBikes=0;
	int i;
	int indexService;
	Work buffer;

	if(!service_printArray(listService, lenService)
		&& !getInt("\nIngrese ID de Service a analizar:", "Ingresar unicamente numeros", &buffer.idService, 2, MIN_ID_SERVICE, MAX_ID_SERVICE)
		&& (indexService=service_searchId(listService, lenService, buffer.idService))>=0
		&& !service_print(listService, indexService))
	{
		if(listWork != NULL && lenWork >0 && listService != NULL && lenService >0 && listBike != NULL && lenBike >0)
		{
			ret = 0;
			for(i=0; i<lenWork; i++)
			{
				for(int j=0; j<lenBike; j++)
				{
					if(listWork[i].isEmpty == FALSE
					  && listWork[i].idService == buffer.idService
					  && listWork[i].idBike == listBike[j].idBike
					  && strcmp(listBike[j].colour, colour) == 0)
					{
						flagsBikes++;
					}
				}
			}
		    printf("\n*******************************************************************\n");
		    printf("******* CANTIDAD DE BICICLETAS COLOR ROJO CON SERVICE %s: %d ******\n", listService[indexService].description, flagsBikes);
		    printf("*******************************************************************\n");
			printf("*******************************************************************\n");

			//Imprimir trabajo/s que hace referencia el Q.

		}
	}
	return ret;
}

//Rodados con mas trabajos realizados

int maxWorkPerWheelSize(Work* listWork, int lenWork, int* maxValue)
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
				if(listWork[i].idWheel == listWork[j].idWheel)
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

int report_wheelsWithMoreWorks (Work* listWork, int lenWork, Wheel* listWheel, int lenWheel)
{
	int ret = -1;
	int maxValue=0;
	int flagWorks=0;
	int indexWheel;
	int i;
	int j;

	if(!maxWorkPerWheelSize(listWork, lenWork, &maxValue))
	{
		work_sortArrayByIdWheel(listWork, lenWork, ASC);
		for(i=0; i<lenWork; i++)
		{
			flagWorks = 0;
			for(j=0; j<lenWork; j++)
			{
				if(listWork[i].isEmpty == FALSE && listWork[i].idWheel == listWork[j].idWheel)
				{
					flagWorks++;
				}
			}

			if(flagWorks == maxValue && listWork[i].idWheel != listWork[i+1].idWheel)
			{
				indexWheel=wheel_searchId(listWheel, lenWheel, listWork[i].idWheel);
				printf("************ Rodado: %d - Cantidad de Trabajos: %d ***********\n", listWheel[indexWheel].wheelSize, maxValue);
			}
		}
		ret = 0;
	}
	return ret;
}

//Cantidad de bicicletas atendidas por rodados

int report_wheelsBikes(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel)
{
	int ret = -1;
	int indexBike;
	int indexWheel;
	int flagWorks=0;

	if (listWork != NULL && lenWork >0 && listService != NULL && lenService >0 && listBike != NULL && lenBike >0 && listWheel != NULL && lenWheel >0)
	{
		for (int i=0 ; i<lenWheel ; i++)
		{
			if(listWheel[i].isEmpty == FALSE)
			{
				flagWorks = 0;
				printf("**************************************************\n");
				printf("***************** ID %d - RODADO %d ***************\n", listWheel[i].idWheel, listWheel[i].wheelSize);
				printf("**************************************************");

				for (int j=0 ; j<lenWork ; j++)
				{
					indexBike = bike_searchId(listBike, lenBike, listWork[j].idBike);
					indexWheel = wheel_searchId(listWheel, lenWheel, listWork[j].idWheel);

					if(listWork[j].isEmpty == FALSE && listWheel[i].idWheel == listWork[j].idWheel)
					{
						printf("\nMarca Bicicleta: %s - Rodado: %d - Color: %s\n",
								listBike[indexBike].brandBike, listWheel[indexWheel].wheelSize, listBike[indexBike].colour);
						flagWorks++;
					}
				}
				printf("\n******************* CANTIDAD %d *******************\n\n\n\n", flagWorks);
				//Ver de cambiar el segundo For por una funcion. Actualmente funciona.
			}
		}
		ret = 0;
	}
return ret;
}
