#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "menu.h"
#include "service.h"
#include "work.h"
#include "wheel.h"
#include "reports.h"

int main(void)
{
	setbuf(stdout, NULL);
	char resume='s';
	int flagWork=0;
	int flagService=0;
	int flagBike=0;
	int indexNewWork;
	float auxTotalValue;

	Service listServices[ARRAY_SIZE_SRV];
	service_init(listServices, ARRAY_SIZE_SRV);

	Work listWorks[ARRAY_SIZE_WORK];
	work_init(listWorks, ARRAY_SIZE_WORK);

	Bike listBikes[ARRAY_SIZE_BIKES];
	bike_init(listBikes, ARRAY_SIZE_BIKES);

	Wheel listWheel[ARRAY_SIZE_WHEELS];
	wheel_init(listWheel, ARRAY_SIZE_WHEELS);

	controller_force_init(listServices, ARRAY_SIZE_SRV, listWorks, ARRAY_SIZE_WORK, listBikes, ARRAY_SIZE_BIKES, listWheel, ARRAY_SIZE_WHEELS, &flagWork, &flagService, &flagBike);

	do
	{
		switch (menu())
		{
											///////////***************TRABAJOS***********************//////////////
			case 1:
				indexNewWork = work_create(listWorks, ARRAY_SIZE_WORK, listServices, ARRAY_SIZE_SRV, listBikes, ARRAY_SIZE_BIKES, listWheel, ARRAY_SIZE_WHEELS);

					//work_printArray(listWorks, ARRAY_SIZE_WORK, listBikes, ARRAY_SIZE_BIKES);
					flagWork++;

				break;

			case 2:
				if(flagWork>0)
				{
					if(!work_update(listWorks, ARRAY_SIZE_WORK, listServices, ARRAY_SIZE_SRV, listBikes, ARRAY_SIZE_BIKES, listWheel, ARRAY_SIZE_WHEELS))
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
						printf("\nNo se ingreso ningun trabajo\n");
					}
				break;

			case 3:
				if(flagWork>0)
				{
					if(!work_delete(listWorks, ARRAY_SIZE_WORK, listServices, ARRAY_SIZE_SRV, listBikes, ARRAY_SIZE_BIKES, listWheel, ARRAY_SIZE_WHEELS))
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
						printf("\nNo se ingreso ningun trabajo\n");
					}
				break;

			case 4:
				if(flagWork>0)
				{
					work_printArraySortByYear(listWorks, ARRAY_SIZE_WORK, listServices, ARRAY_SIZE_SRV, listBikes, ARRAY_SIZE_BIKES, listWheel, ARRAY_SIZE_WHEELS);
				}
				else
					{
						printf("\nNo se ingreso ningun trabajo\n");
					}
				break;

			case 5:
				if(flagService>0)
				{
					service_printArray(listServices, ARRAY_SIZE_SRV);
				}
				else
					{
						printf("\nNo se ingreso ningun service\n");
					}
				break;

			case 6:
				if(flagService>0 && !priceTotalPerService(listWorks, ARRAY_SIZE_WORK, listServices, ARRAY_SIZE_SRV, &auxTotalValue))
				{
					printf("\nEl valor total de los servicios realizados es de: %.2f", auxTotalValue);
				}
				else
					{
						printf("\nNo se ingreso ningun service\n");
					}
				break;

			case 7:
				if(flagWork>0)
				{
					report_worksByBrand(listWorks, ARRAY_SIZE_WORK, listServices, ARRAY_SIZE_SRV, listBikes, ARRAY_SIZE_BIKES, listWheel, ARRAY_SIZE_WHEELS);
				}
				else
					{
						printf("\nNo se ingreso ningun trabajo\n");
					}
				break;

			case 8:
				if(flagWork>0)
				{
					report_servicesWithMoreWorks(listWorks, ARRAY_SIZE_WORK);
				}
				else
					{
						printf("\nNo se ingreso ningun trabajo\n");
					}
				break;

			case 9:
				if(flagWork>0)
				{
					report_servicesBikes(listWorks, ARRAY_SIZE_WORK, listServices, ARRAY_SIZE_SRV, listBikes, ARRAY_SIZE_BIKES, listWheel, ARRAY_SIZE_WHEELS);
				}
				else
					{
						printf("\nNo se ingreso ningun trabajo\n");
					}
				break;

			case 10:
				if(flagWork>0)
				{
					report_qBikesPerService(listWorks, ARRAY_SIZE_WORK, listServices, ARRAY_SIZE_SRV, listBikes, ARRAY_SIZE_BIKES, "Rojo");
				}
				else
					{
						printf("\nNo se ingreso ningun trabajo\n");
					}
				break;

			case 11:
				if(flagWork>0)
				{
					report_wheelsWithMoreWorks(listWorks, ARRAY_SIZE_WORK, listWheel, ARRAY_SIZE_WHEELS);
				}
				else
					{
						printf("\nNo se ingreso ningun trabajo\n");
					}
				break;

			case 12:
				if(flagWork>0)
				{
					report_wheelsBikes(listWorks, ARRAY_SIZE_WORK, listServices, ARRAY_SIZE_SRV, listBikes, ARRAY_SIZE_BIKES, listWheel, ARRAY_SIZE_WHEELS);
				}
				else
					{
						printf("\nNo se ingreso ningun trabajo\n");
					}
				break;

			case 13:
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
