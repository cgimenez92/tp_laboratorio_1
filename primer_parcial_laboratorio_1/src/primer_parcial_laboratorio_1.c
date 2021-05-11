#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"
#include "trabajo.h"
#include "controller.h"
#include "menu.h"
// #include "report.h"

int main(void)
{
	setbuf(stdout, NULL);
	char resume='s';
	int flagWork=0;
	int flagService=0;
	int indexNewWork;
	float auxTotalValue;

	Service listServices[ARRAY_SIZE_SRV];
	service_init(listServices, ARRAY_SIZE_SRV);
	Work listWorks[ARRAY_SIZE_WORK];
	work_init(listWorks, ARRAY_SIZE_WORK);

	controller_force_init(listServices, ARRAY_SIZE_SRV, listWorks, ARRAY_SIZE_WORK, &flagWork, &flagService);

	do
	{
		switch (menu())
		{
											///////////***************TRABAJOS***********************//////////////
			case 1:
				indexNewWork = work_create(listWorks, ARRAY_SIZE_WORK, listServices, ARRAY_SIZE_SRV);
				if(indexNewWork)
				{
					work_printArray(listWorks, ARRAY_SIZE_WORK);
					flagWork++;
				}
				else
				{
					printf("\nNo se pudo crear el trabajo");
				}
				break;

			case 2:
				if(flagWork>0)
				{
					if(!work_update(listWorks, ARRAY_SIZE_WORK, listServices, ARRAY_SIZE_SRV))
					{
						printf("\nSe pudo modificar correctamente");
					}
					else
					{
						printf("\nNo se pudo modificar");
					}
				}
				else
				{
					printf("\nNo se ingreso ningun cliente\n");
				}
				break;

			case 3:
				if(flagWork>0)
				{
					if(!work_delete(listWorks, ARRAY_SIZE_WORK))
					{
						printf("\nSe borro cliente correctamente");
					}
					else
					{
						printf("\nNo se pudo borrar cliente\n");
					}
				}
				else
				{
					printf("\nNo se ingreso ningun cliente\n");
				}

				break;

			case 4:
				if(flagWork>0)
				{
					work_printArraySortByYear(listWorks, ARRAY_SIZE_WORK);
				}
				break;

			case 5:
				if(flagService>0)
				{
					service_printArray(listServices, ARRAY_SIZE_SRV);
				}
				break;

			case 6:
				if(flagService>0 && !priceTotalPerService(listServices, ARRAY_SIZE_SRV, &auxTotalValue))
				{
					printf("\nSe pudo modificar correctamente %.2f", auxTotalValue);
				}
				break;



//									/////////////***************************INFORMES**********************************//////////////
//			case 8:
//				do
//				{
//					switch (menuReports())
//					{
//					case 1:
//						if(flagCustomer>0)
//						{
//							report_customerCountPublications(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER, ALL_MAX);
//						}
//						break;
//					case 2:
//						if(flagCustomer>0)
//						{
//							report_qPublicationsPaused(listPublications, ARRAY_SIZE_ADS);
//						}
//						break;
//					case 3:
//						if(flagCustomer>0)
//						{
//							report_itemNumberWithMorePublications(listPublications, ARRAY_SIZE_ADS);
//						}
//						break;
//					case 4:
//						if(flagCustomer>0)
//						{
//							report_customerCountPublications(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER, ACTIVE);
//						}
//						break;
//					case 5:
//						if(flagCustomer>0)
//						{
//							report_customerCountPublications(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER, PAUSED);
//						}
//						break;
//					case 6:
//						if(flagCustomer>0)
//						{
//							report_sortArrayByItemNumber(listPublications, ARRAY_SIZE_ADS);
//						}
//						break;
//					case 7:
//						if(flagCustomer>0)
//						{
//							report_qPublications(listPublications, ARRAY_SIZE_ADS, &bufferPublication);
//						}
//						break;
//					case 8:
//						if(flagCustomer>0)
//						{
//							report_customerCountPublications(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER, ALL_MIN);
//						}
//						break;
//					case 9:
//						if(flagCustomer>0)
//						{
//							report_qPublicationsPerItemNumber(listPublications, ARRAY_SIZE_ADS,  &bufferItemNumber, &bufferPublication);
//						}
//						break;
//
//					case 10:
//						if(flagCustomer>0)
//						{
//							report_qPublicationsPerCustomer(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER, &bufferPublication);
//						}
//						break;
//					case 11:
//						resumeReports='n';
//						break;
//					}
//				}while (resumeReports=='s');
//				break;

			case 7:
				resume='n';
				break;

			default:
				printf("\nIngrese opcion correcta\n\n");
				break;
	        }
	         fflush(stdin);
		}while (resume=='s');

	return 0;
}
