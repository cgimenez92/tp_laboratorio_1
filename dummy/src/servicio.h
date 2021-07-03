#ifndef SERVICE_H_
#define SERVICE_H_

#define TRUE 1
#define FALSE 0
//#define ASC 1
//#define DSC 0
//#define ACTIVE 0
//#define PAUSED 1
//#define ALL_MAX 2
//#define ALL_MIN 3
//#define CUIT_SIZE 15
//#define LIMIT_TEXT 64
#define STRING_SIZE 25
#define MIN_ID_SERVICE 20000
#define MAX_ID_SERVICE 21000
#define ARRAY_SIZE_SRV 1000
//#define MIN_LIMIT_CLIENT 1
//#define MAX_LIMIT_CLIENT 100S
//#define ARRAY_SIZE_Service 100
//#define MIN_LIMIT_PUBLICATION 1
//#define MAX_LIMIT_PUBLICATION 1000
//#define MIN_LIMIT_ITEM_NUMBER 1
//#define MAX_LIMIT_ITEM_NUMBER 50

typedef struct
{
	int id;
	int isEmpty;
	char description[STRING_SIZE];
	float price;
}  Service;

int service_force_init(Service* list, int len, char* description, float price);

int service_init(Service* list, int len);

int service_create(Service* list, int len);


int service_update(Service* list, int len);

int service_delete(Service* list, int len);

int service_print(Service* list, int index);

int service_printArray(Service* list , int len);
int service_freePosition(Service* list, int len);

int service_freePositionIndex(Service* list, int len, int* pIndex);

int service_searchId(Service* list, int len, int id);

int priceTotalPerService(Service* list,  int len, float* totalValue);


#endif /* SERVICE_H_ */
