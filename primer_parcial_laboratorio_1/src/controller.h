#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "service.h"
#include "work.h"
#include "bike.h"


void controller_force_init(Service* listService, int lenService, Work* listWork, int lenWork, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel, int* flagWork, int* flagService, int* flagBike);

#endif /* CONTROLLER_H_ */
