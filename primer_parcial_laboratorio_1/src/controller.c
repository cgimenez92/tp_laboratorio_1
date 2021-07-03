#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "service.h"
#include "work.h"
#include "bike.h"


void controller_force_init(Service* listService, int lenService, Work* listWork, int lenWork, Bike* listBike, int lenBike, int* flagWork, int* flagService, int* flagBike)
{
	if(!service_force_init(listService, lenService, "Limpieza", 250.23)
		&& !bike_force_init(listBike, lenBike, "Toto", 20,  "Amarillo"))
	{
		*flagWork=*flagWork+1;
		*flagService=*flagService+1;
		*flagBike=*flagBike+1;
	}

	service_force_init(listService, lenService, "Parche", 300.00);
	service_force_init(listService, lenService, "Centrado", 400.32);
	service_force_init(listService, lenService, "Cadena", 350.76);

	bike_force_init(listBike, lenBike, "UTN", 25,  "Rojo");
	bike_force_init(listBike, lenBike, "Best Bike", 29,  "Azul");
	bike_force_init(listBike, lenBike, "Stanley", 26,  "Amarillo");
	bike_force_init(listBike, lenBike, "AyR", 22,  "Purpura");

}
