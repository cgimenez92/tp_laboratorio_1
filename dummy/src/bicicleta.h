#ifndef BICICLETA_H_
#define BICICLETA_H_

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
	int wheeledBike;
	char colour[STRING_SIZE_COLOUR];
} Bike;


int bike_force_init(Bike* list, int len, char* brandBike, int wheeledBike,  char* colour);
int bike_init(Bike* list, int len);
int bike_freePosition(Bike* list, int len);
int bike_freePositionIndex(Bike* list, int len, int* pIndex);
int bike_searchId(Bike* list, int len, int id);
int bike_create(Bike* listBike, int lenBike);

#endif /* BICICLETA_H_ */

