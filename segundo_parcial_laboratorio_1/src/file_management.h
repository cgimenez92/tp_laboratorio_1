/*
 * file_management.h
 *
 *  Created on: Jun 14, 2021
 *      Author: Administrador
 */

#ifndef FILE_MANAGEMENT_H_
#define FILE_MANAGEMENT_H_



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int file_loadCustomersFromText(char* path , LinkedList* this);

int file_loadServicesFromText(char* path , LinkedList* this);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int file_saveAsText(char* path , LinkedList* this);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

#endif /* FILE_MANAGEMENT_H_ */
