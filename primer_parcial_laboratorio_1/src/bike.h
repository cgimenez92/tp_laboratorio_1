#ifndef BIKE_H_
#define BIKE_H_

#define TRUE 1
#define FALSE 0
#define STRING_SIZE_BRAND 25
#define STRING_SIZE_COLOUR 30
#define MIN_ID_BIKE 24
#define ARRAY_SIZE_BIKES 500

typedef struct
{
	int idBike;
	int isEmpty;
	char brandBike[STRING_SIZE_BRAND];
	char colour[STRING_SIZE_COLOUR];
} Bike;

/** \brief adds in a existing list, a list of Bike with the values received as parameters
 * \param Bike* list
 * \param int len
 * \param char* brandBike
 * \param char* colour
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int bike_force_init(Bike* list, int len, char* brandBike, char* colour);


/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
 * \param Bike* list Pointer to array of Customers
 * \param int len Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int bike_init(Bike* list, int len);


/** \brief print the content of Bike array
 * \param list Bike*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
 */
int bike_printArray(Bike* list , int len);


/** \brief find a empty position in bike array and returns the index position in array.
 * \param list Bike*
 * \param len int
 * \return Return Customer index position or (-1) if [Invalid length or NULL pointer received or Customer not found] - (i --> Index of position free) if Ok
 */
int bike_freePosition(Bike* list, int len);


/** \brief find a empty position in bike array and returns the index position in array.
 * \param list Bike*
 * \param len int
 * \param int* pIndex
 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
 */
int bike_freePositionIndex(Bike* list, int len, int* pIndex);

/** \brief find an Bike by brandBike and returns the index position in array.
 * \param list Bike*
 * \param len int
 * \param  char* brandBike
 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
 */
int bike_searchBrand(Bike* list, int len, char* brandBike);

/** \brief find an Bike by Id and returns the index position in array.
 * \param list Customer*
 * \param len int
 * \param id int
 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
 */
int bike_searchId(Bike* list, int len, int id);


//int bike_sortArrayByBrand (Bike* list , int len, int order); // Ver si lo utilizo en otra funcion

#endif /* BIKE_H_ */

