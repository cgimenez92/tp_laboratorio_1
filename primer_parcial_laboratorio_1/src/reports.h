/*
 * reports.h
 *
 *  Created on: Jul 4, 2021
 *      Author: Administrador
 */

#ifndef REPORTS_H_
#define REPORTS_H_

#define TRUE 1
#define FALSE 0
#include "work.h"
#include "service.h"

int priceTotalPerService(Work* listWork, int lenWork, Service* listService, int lenService, float* totalValue);
int report_worksByBrand(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel);
int report_servicesBikes(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel);
int maxValueQProduct(Work* listWork, int lenWork, int* maxValue);
int report_servicesWithMoreWorks (Work* listWork, int lenWork);
int report_qBikesPerService(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, char* colour);
int maxWorkPerWheelSize(Work* listWork, int lenWork, int* maxValue);
int report_wheelsWithMoreWorks (Work* listWork, int lenWork, Wheel* listWheel, int lenWheel);
int report_wheelsBikes(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel);
#endif /* REPORTS_H_ */
