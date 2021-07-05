#ifndef SERVICE_H_
#define SERVICE_H_

#define TRUE 1
#define FALSE 0
#define STRING_SIZE 25
#define MIN_ID_SERVICE 19999
#define MAX_ID_SERVICE 21000
#define ARRAY_SIZE_SRV 1000

typedef struct
{
	int id;
	int isEmpty;
	char description[STRING_SIZE];
	float price;
}  Service;

/** \brief adds in a existing list, a list of Service with  the values received as parameters
 * \param Service* list
 * \param int len
 * \param char* description
 * \param float price
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int service_force_init(Service* list, int len, char* description, float price);


/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
 * \param Service* list Pointer to array of Customers
 * \param int len Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int service_init(Service* list, int len);

//int service_create(Service* list, int len);
//
//
//int service_update(Service* list, int len);

/** \brief Remove a Service (put isEmpty Flag in 1)
 * \param list Service*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
 */
int service_delete(Service* list, int len);

/** \brief prints the content of Service received on index parameter
 * \param list Service*
 * \param int index
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
 */
int service_print(Service* list, int index);

/** \brief print the content of Service array
 * \param list Service*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
 */
int service_printArray(Service* list , int len);

/** \brief find a empty position in Service array and returns the index position in array.
 * \param list Customer*
 * \param len int
 * \return Return Customer index position or (-1) if [Invalid length or NULL pointer received or Customer not found] - (i --> Index of position free) if Ok
 */
int service_freePosition(Service* list, int len);

/** \brief find a empty position in Service array and returns the index position in array.
 * \param list Service*
 * \param len int
 * \param int* pIndex
 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
 */
int service_freePositionIndex(Service* list, int len, int* pIndex);

/** \brief find an Service by Id and returns the index position in array.
 * \param list Service*
 * \param len int
 * \param id int
 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
 */
int service_searchId(Service* list, int len, int id);

#endif /* SERVICE_H_ */
