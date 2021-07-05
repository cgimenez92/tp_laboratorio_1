#include "bike.h"
#include "service.h"
#include "wheel.h"
#include "work.h"

void controller_force_init(Service* listService, int lenService, Work* listWork, int lenWork, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel, int* flagWork, int* flagService, int* flagBike, int* flagWheel)
{
	if(!service_force_init(listService, lenService, "Limpieza", 250.00)
	   && !bike_force_init(listBike, lenBike, "Toto", "Amarillo"))
	{
		*flagWork=*flagWork+1;
		*flagService=*flagService+1;
		*flagBike=*flagBike+1;
		*flagWheel=*flagWheel+1;
	}

	service_force_init(listService, lenService, "Parche", 300.00);
	service_force_init(listService, lenService, "Centrado", 400.00);
	service_force_init(listService, lenService, "Cadena", 350.00);

	bike_force_init(listBike, lenBike, "UTN", "Rojo");
	bike_force_init(listBike, lenBike, "Best Bike", "Azul");
	bike_force_init(listBike, lenBike, "Stanley", "Rojo");
	bike_force_init(listBike, lenBike, "AyR", "Purpura");

	wheel_force_init(listWheel, lenWheel, 14);
	wheel_force_init(listWheel, lenWheel, 16);
	wheel_force_init(listWheel, lenWheel, 18);
	wheel_force_init(listWheel, lenWheel, 20);
	wheel_force_init(listWheel, lenWheel, 22);
	wheel_force_init(listWheel, lenWheel, 24);;

	work_force_init(listWork, lenWork,26, 2, 20001, 23,12,1990);
	work_force_init(listWork, lenWork,27, 1, 20002, 12,01,1994);
	work_force_init(listWork, lenWork,28, 3, 20002, 03,07,2020);
	work_force_init(listWork, lenWork,30, 1, 20003, 26,05,2020);
	work_force_init(listWork, lenWork,29, 2, 20003, 21,12,2020);
}
