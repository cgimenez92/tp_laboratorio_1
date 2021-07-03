/*
 * brand.h
 *
 *  Created on: Jul 2, 2021
 *      Author: Administrador
 */

#ifndef BRAND_H_
#define BRAND_H_

#define TRUE 1
#define FALSE 0
#define MIN_ID_BRAND 0
#define STRING_SIZE_DSC_BRAND 25
#define ARRAY_SIZE_BRANDS 200

typedef struct
{
	int idBrand;
	int isEmpty;
	char brandDescription[STRING_SIZE_DSC_BRAND];
} Brand;


int brand_force_init(Brand* list, int len, char* brandDescription);
int brand_init(Brand* list, int len);
int brand_freePosition(Brand* list, int len);
int brand_freePositionIndex(Brand* list, int len, int* pIndex);
int brand_searchId(Brand* list, int len, int id);
int brand_create(Brand* listBrand, int lenBrand);

#endif /* BRAND_H_ */
