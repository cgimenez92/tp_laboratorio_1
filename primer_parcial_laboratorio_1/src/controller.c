#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"
#include "trabajo.h"
#include "menu.h"


void controller_force_init(Service* listService, int lenService, Work* listWork, int lenWork, int* flagWork, int* flagService)
{
	if(!work_force_init(listWork, lenWork, "CHINACAPUCHINA", 18, 1003, "10/05/2021") &&
	   !service_force_init(listService, lenService, "Limpieza", 250.23))
	{
		*flagWork=*flagWork+1;
		*flagService=*flagService+1;
	}

	service_force_init(listService, lenService, "Parche", 300.00);
	service_force_init(listService, lenService, "Centrado", 400.32);
	service_force_init(listService, lenService, "Cadena", 350.76);
}
