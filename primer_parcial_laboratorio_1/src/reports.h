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
//int work_sortArrayByBrand(Work* list, int len, int order, Bike* listBike, int lenBike);
//int work_printArraySortByBrand(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel);
int report_test(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel);
int maxValueQProduct(Work* listWork, int lenWork, int* maxValue);
int report_servicesWithMoreWorks (Work* listWork, int lenWork);

#endif /* REPORTS_H_ */
