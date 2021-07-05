#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "bike.h"
#include "service.h"
#include "wheel.h"
#include "work.h"

void controller_force_init(Service* listService, int lenService, Work* listWork, int lenWork, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel, int* flagWork, int* flagService, int* flagBike, int* flagWheel);

#endif /* CONTROLLER_H_ */
