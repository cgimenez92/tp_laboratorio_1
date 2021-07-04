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
//#define ASC 1
//#define DSC 0
#define STRING_SIZE_COND 8
//#define STRING_SIZE_COLOUR 30
#define MIN_ID_WHEEL 0
#define MAX_ID_WHEEL 499
#define  ARRAY_SIZE_WHEELS 500

typedef struct
{
	int idWheel;
	int isEmpty;
	int wheelSize;
	char wheelCondition[STRING_SIZE_COND];
} Wheel;

int wheel_force_init(Wheel* list, int len, int wheelSize, char* wheelCondition);
int wheel_init(Wheel* list, int len);
int wheel_printArray(Wheel* list , int len);
int wheel_freePosition(Wheel* list, int len);
int wheel_freePositionIndex(Wheel* list, int len, int* pIndex);
int wheel_searchId(Wheel* list, int len, int id);
int wheel_create(Wheel* listWheel, int lenWheel);

#endif /* WHEEL_H_ */
