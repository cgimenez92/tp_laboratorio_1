#ifndef BIKE_H_
#define BIKE_H_

#define TRUE 1
#define FALSE 0
#define ASC 1
#define DSC 0
#define STRING_SIZE_BRAND 25
#define STRING_SIZE_COLOUR 30
#define MIN_ID_BIKE 25
#define  ARRAY_SIZE_BIKES 500

typedef struct
{
	int idBike;
	int isEmpty;
	char brandBike[STRING_SIZE_BRAND];
	char colour[STRING_SIZE_COLOUR];
} Bike;


int bike_force_init(Bike* list, int len, char* brandBike, char* colour);
int bike_init(Bike* list, int len);
int bike_printArray(Bike* list , int len);
int bike_freePosition(Bike* list, int len);
int bike_freePositionIndex(Bike* list, int len, int* pIndex);
int bike_searchBrand(Bike* list, int len, char* brandBike);
int bike_searchId(Bike* list, int len, int id);
int bike_sortArrayByBrand (Bike* list , int len, int order);
//int bike_create(Bike* listBike, int lenBike);

#endif /* BIKE_H_ */

