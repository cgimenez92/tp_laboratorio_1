/*
 ============================================================================
 Name        : segundo_parcial_laboratorio_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Customer.h"
#include "file_management.h"
#include "reports.h"

/****************************************************
    Menu:
     1. Cargar los datos desde los archivos customers.csv - services.csv (modo texto).
     2. Listar datos relacionados.
     3. Muestra ll_filter
     4. Muestra ll_count
     5. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     6. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);
    int addCustomers = 0;
    int addServices = 0;
    int option;
    int flagLoad = 0;
    int saveText = 0;
    int validationExit;
    LinkedList* customerList = ll_newLinkedList();
    LinkedList* serviceList = ll_newLinkedList();
    LinkedList* filterList = ll_newLinkedList();

    do
    {
    	option = menu();
        switch(option)
        {

        case 1:
        	if(addCustomers < 1)
        	{
        		addCustomers = file_loadCustomersFromText("customers.csv", customerList);
        		if(addCustomers != -1)
        		{
        			printf("Se cargaron %d Clientes\n", addCustomers);
        			flagLoad++;
        		}
        		else
        		{
        			printf("Error al cargar la lista de clientes\n");
        		}
        	}
        	else
        	{
        		printf("Lista de clientes ya cargada...\n");
        	}

            if(addServices < 1)
            {
            	addServices = file_loadServicesFromText("services.csv", serviceList);
                if(addServices != -1)
                {
                    printf("Se cargaron %d Servicios\n", addServices);
                    flagLoad++;
                }
                else
                {
                    printf("Error al cargar la lista de servicios\n");
                }
            }
            else
            {
                printf("Lista de servicios ya cargada...\n");
            }

            break;

        case 2:
            if(flagLoad>1)
            {
            	report_printRelationData(customerList, serviceList);
            }
            else
            {
                printf("Primero debe cargar las lista al sistema!\n");
            }
            break;

        case 3:
            if(flagLoad>1)
            {
            	report_filterCustomerByGender(customerList);
            	filterList = report_filterCustomerByUSCountry(customerList);
            }
            else
            {
                printf("\nPrimero debe cargar las lista al sistema!\n\n");
            }
            break;

        case 4:
            if(flagLoad>1)
            {
            	report_countByCountry(customerList);
            	report_avgByService(serviceList);
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            break;

        case 5:
            if(flagLoad>1)
            {
            	file_saveAsText("filterData.csv", filterList);
            	saveText = 1;
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            break;
        case 6:
            if(saveText !=1)
            {
                validationExit = menuValidationExit();
                if(validationExit!=2)
                {
                    printf("\nVolviendo...\n\n");
                    option = menu();
                    continue;
                }
                else
                {
                    exit(0);
                }
            }
            else
            {
                printf("\nHasta luego!\n");
                exit(0);
            }
            break;

        default:
            printf("No ingreso una opcion Valida\n");
            break;
        }
    }
    while(option != 10);

    controller_deleteListCustomer(customerList);
    controller_deleteListService(serviceList);
    controller_deleteListCustomer(filterList);
    return EXIT_SUCCESS;
}


