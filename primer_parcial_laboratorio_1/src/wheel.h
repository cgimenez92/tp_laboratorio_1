/*
 * wheel.h
 *
 *  Created on: Jul 4, 2021
 *      Author: Administrador
 */

#ifndef WHEEL_H_
#define WHEEL_H_

#define TRUE 1
#define FALSE 0
#define STRING_SIZE_COND 8
#define MIN_ID_WHEEL 0
#define MAX_ID_WHEEL 499
#define  ARRAY_SIZE_WHEELS 500

typedef struct
{
	int idWheel;
	int isEmpty;
	int wheelSize;
	//Poner altura o edad recomendada para rodado ;)
} Wheel;

/** \brief adds in a existing list, a list of Wheel with  the values received as parameters
 * \param Customer* list
 * \param int len
 * \param int wheelSize
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int wheel_force_init(Wheel* list, int len, int wheelSize);

/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
 * \param Wheel* list Pointer to array of Wheels
 * \param int len Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int wheel_init(Wheel* list, int len);

/** \brief print the content of Wheel array
 * \param list Wheel*
 * \param length int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
 */
int wheel_printArray(Wheel* list , int len);

/** \brief find a empty position in Wheel array.
 * \param list Wheel*
 * \param len int
 * \return Return Customer index position or (-1) if [Invalid length or NULL pointer received or Customer not found] - (i --> Index of position free) if Ok
 */
int wheel_freePosition(Wheel* list, int len);

/** \brief find a empty position in Wheel array and returns the index position in array.
 * \param list Wheel*
 * \param len int
 * \param int* pIndex
 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
 */
int wheel_freePositionIndex(Wheel* list, int len, int* pIndex);

/** \brief find an Wheel by Id and returns the index position in array.
 * \param list Wheel*
 * \param len int
 * \param id int
 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
 */
int wheel_searchId(Wheel* list, int len, int id);

#endif /* WHEEL_H_ */
