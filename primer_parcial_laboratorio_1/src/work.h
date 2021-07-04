#ifndef WORK_H_
#define WORK_H_

#define TRUE 1
#define FALSE 0
#define ASC 1
#define DSC 0
//#define ACTIVE 0
//#define PAUSED 1
//#define ALL_MAX 2
//#define ALL_MIN 3
//#define CUIT_SIZE 15
//#define LIMIT_TEXT 64
#define STRING_SIZE_DATE 10
#define ARRAY_SIZE_WORK 20000
//#define MIN_LIMIT_CLIENT 1
//#define MAX_LIMIT_CLIENT 100
//#define ARRAY_SIZE_CUSTOMER 100
//#define MIN_LIMIT_PUBLICATION 1
//#define MAX_LIMIT_PUBLICATION 1000
//#define MIN_LIMIT_ITEM_NUMBER 1
//#define MAX_LIMIT_ITEM_NUMBER 50
#include "service.h"
#include "bike.h"
#include "date.h"

	typedef struct
	{
		int id;
		int isEmpty;
		int idBike;
		int idBrand;
		int idService;
		Date ddmmyyyy;
	} Work;

	int work_force_init(Work* list, int len, int idBike, int idService, int day, int month, int year);
	int work_init(Work* list, int len);
	int work_create(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike);
	//int work_update(Work* listWork, int lenWork, Service* listService, int lenService);
	int work_delete(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike);
	int work_print(Work* listWork, Service* listService, int lenService, Bike* listBike, int lenBike, int index);
	int work_printArray(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike);
	int work_freePosition(Work* list, int len);
	int work_freePositionIndex(Work* list, int len, int* pIndex);
	int work_searchId(Work* list, int len, int id);
	int work_sortArray(Work* list, int len, int order, Bike* listBike, int lenBike);
	int work_printArraySortByYear(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike);

#endif /* WORK_H_ */
