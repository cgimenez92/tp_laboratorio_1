/*
 * file_management.c
 *
 *  Created on: Jun 14, 2021
 *      Author: Administrador
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Customer.h"
#include "Service.h"
#define BUFFER_SIZE 4096
#define ATTEMPTS 2

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int file_loadCustomersFromText(char* path , LinkedList* this)
{
    FILE* pToFile;
    char customerID[BUFFER_SIZE];
    char country[BUFFER_SIZE];
    char gender[BUFFER_SIZE];
    char firtsName[BUFFER_SIZE];
    char lastName[BUFFER_SIZE];
    char birthDate[BUFFER_SIZE];
    char idContractedService[BUFFER_SIZE];
    int i = -1;
    Customer* customerAux;

    if(this != NULL && path != NULL)
    {
        pToFile = fopen(path,"r");

        if(pToFile != NULL)
        {
            while(!feof(pToFile))
            {
            	fscanf(pToFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", customerID, country, gender, firtsName, lastName, birthDate, idContractedService);

                if(i != -1)
                {

                	customerAux = customer_newParameters(customerID, country, gender, firtsName, lastName, birthDate, idContractedService);

                    if(customerAux != NULL)
                    {

                        ll_add(this, customerAux);
                    }
                    else
                    {
                        printf("\n ERROR EN EL ARCHIVO\n");
                        controller_deleteListCustomer(this);
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

int file_loadServicesFromText(char* path , LinkedList* this)
{
    FILE* pToFile;
    char serviceId[BUFFER_SIZE];
    char serviceType[BUFFER_SIZE];
    char price[BUFFER_SIZE];
    int i = -1;
    Service* serviceAux;

    if(this != NULL && path != NULL)
    {
        pToFile = fopen(path,"r");

        if(pToFile != NULL)
        {
            while(!feof(pToFile))
            {
            	fscanf(pToFile, "%[^,],%[^,],%[^\n]\n", serviceId, serviceType, price);

                if(i != -1)
                {

                	serviceAux = service_newParameters(serviceId, serviceType, price);

                    if(serviceAux != NULL)
                    {

                        ll_add(this, serviceAux);
                    }
                    else
                    {
                        printf("\n ERROR EN EL ARCHIVO\n");
                        controller_deleteListService(this);
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
//
///** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
// *
// * \param path char*
// * \param pArrayListEmployee LinkedList*
// * \return int
// *
// */
int file_saveAsText(char* path , LinkedList* this)
{

    int ret = -1;
    FILE* pToFile;
    Customer* customerAux;

    int* customerIdAux;
    char* countryAux;
    char* genderAux;
    char* firtsNameAux;
    char* lastNameAux;
    char* birthDateAux;
    int* idContractedServiceAux;


    if(this != NULL && path != NULL)
    {
    	customerIdAux = malloc(sizeof(int));
    	countryAux = malloc(sizeof(char)* BUFFER_SIZE);
    	genderAux = malloc(sizeof(char)* BUFFER_SIZE);
    	firtsNameAux = malloc(sizeof(char)* BUFFER_SIZE);
    	lastNameAux = malloc(sizeof(char)* BUFFER_SIZE);
    	birthDateAux = malloc(sizeof(char)* BUFFER_SIZE);
        idContractedServiceAux = malloc(sizeof(int));

        pToFile = fopen(path,"w");

        fprintf(pToFile,"idCustomer,pais,genero,nombre,apellido,idServicio\n");

        for(int i=0; i<ll_len(this); i++)
        {
        	customerAux = ll_get(this,i);
        	customer_getCustomerId(customerAux,customerIdAux);
            countryAux = customer_getCountry(customerAux);
            genderAux = customer_getGender(customerAux);
            firtsNameAux = customer_getFirtsName(customerAux);
            lastNameAux = customer_getLastName(customerAux);
            birthDateAux = customer_getBirthDate(customerAux);
            customer_getIdContractedService(customerAux,idContractedServiceAux);
            fprintf(pToFile,"%d,%s,%s,%s,%s,%s,%d\n",*customerIdAux,countryAux,genderAux,firtsNameAux,lastNameAux,birthDateAux,*idContractedServiceAux);
        }

        free(customerIdAux);
		free(countryAux);
		free(genderAux);
		free(firtsNameAux);
		free(lastNameAux);
		free(birthDateAux);
        free(idContractedServiceAux);
        fclose(pToFile);
    }
    return ret;
}
