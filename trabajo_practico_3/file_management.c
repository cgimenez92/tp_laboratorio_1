/*
 * file_management.c
 *
 *  Created on: Jun 14, 2021
 *      Author: Administrador
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#define BUFFER_SIZE 4096
#define ATTEMPTS 2

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int file_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pToFile;
    char idAux[BUFFER_SIZE];
    char nameAux[BUFFER_SIZE];
    char workedHoursAux[BUFFER_SIZE];
    char salaryAux[BUFFER_SIZE];
    int i = -1;
    Employee* employeeAux;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pToFile = fopen(path,"r");

        if(pToFile != NULL)
        {
            while(!feof(pToFile))
            {
            	fscanf(pToFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nameAux, workedHoursAux, salaryAux);

                if(i != -1)
                {

                    employeeAux = employee_newParameters(idAux,nameAux,workedHoursAux,salaryAux);

                    if(employeeAux != NULL)
                    {

                        ll_add(pArrayListEmployee, employeeAux);
                    }
                    else
                    {
                        printf("\n ERROR EN EL ARCHIVO\n");
                        controller_deleteListEmployee(pArrayListEmployee);
                        i = 0;
                        break;
                    }
                }
                i++;
            }
            fclose(pToFile);
        }
        else
        {
            printf("No existe el archivo\n");
        }
    }
    return i;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int file_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pToFile;
    Employee* employeeAux;
    int i = 0;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pToFile = fopen(path,"rb");
        if(pToFile != NULL)
        {
            while(!feof(pToFile))
            {
                employeeAux = (Employee*) malloc(sizeof(Employee));
                fread(employeeAux,sizeof(Employee), 1, pToFile);
                if(feof(pToFile))
                {
                    break;
                }
                if(employeeAux != NULL)
                {
                    ll_add(pArrayListEmployee, employeeAux);
                    i++;
                }
                else
                {
                    printf("\nERROR AL AnADIR UN ELEMENTO A LA LISTA\n");
                }
            }
            fclose(pToFile);
        }
    }

    return i;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int file_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* pToFile;
    Employee* employeeAux;
    int i;
    int listLen;
    int* idAux;
    char* nameAux;
    int* salaryAux;
    int* workedHoursAux;
    if(pArrayListEmployee != NULL && path != NULL)
    {
        idAux = malloc(sizeof(int));
        nameAux = malloc(sizeof(char)* BUFFER_SIZE);
        salaryAux = malloc(sizeof(int));
        workedHoursAux = malloc(sizeof(int));

        pToFile = fopen(path,"w");
        listLen = ll_len(pArrayListEmployee);
        fprintf(pToFile,"id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i<listLen; i++)
        {
            employeeAux = ll_get(pArrayListEmployee,i);
            employee_getId(employeeAux,idAux);
            employee_getSalary(employeeAux,salaryAux);
            nameAux = employee_getName(employeeAux);
            employee_getWorkedHours(employeeAux,workedHoursAux);
            fprintf(pToFile,"%d,%s,%d,%d\n",*idAux,nameAux,*salaryAux,*workedHoursAux);
        }
        free(nameAux);
        free(idAux);
        free(salaryAux);
        free(workedHoursAux);
        fclose(pToFile);
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int file_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* pToFile;
    Employee* employeeAux;
    int i = 0;
    int listLen;
    if(pArrayListEmployee != NULL && path != NULL)
    {

        pToFile = fopen(path,"wb");
        listLen = ll_len(pArrayListEmployee);
        for(i=0; i< listLen; i++)
        {
            employeeAux = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(employeeAux, sizeof(Employee),1,pToFile);
        }
        fclose(pToFile);
    }
    return ret;
}

