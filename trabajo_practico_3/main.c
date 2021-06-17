#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"
#include "gets.h"
#include "file_management.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);
    int addElements = 0;
    int option;
    int flagLoad = 0;
    int saveText = 0;
    int saveBinary = 0;
    int validationExit;
    LinkedList* employeeList = ll_newLinkedList();

    do
    {
    	option = menu();
        switch(option)
        {

        case 1:
            if(addElements < 1)
            {
                addElements = file_loadFromText("data.csv", employeeList);
                if(addElements != -1)
                {
                    printf("Se cargaron %d Empleados\n", addElements);
                    flagLoad=1;
                }
                else
                {
                    printf("Error Al cargar la lista\n");
                }
            }
            else
            {
                printf("Esta lista ya fue cargada...\n");
            }
            break;
        case 2:
            if(addElements < 1)
            {
                addElements = file_loadFromBinary("data.dat", employeeList);
                printf("Se cargaron %d Empleados\n", addElements);
                flagLoad=1;
            }
            else
            {
                printf("Esta lista ya fue cargada...\n");
            }
            break;
        case 3:
            if(flagLoad)
            {
                controller_addEmployee(employeeList);
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            break;
        case 4:
            if(flagLoad)
            {
                controller_editEmployee(employeeList);
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            break;

        case 5:
            if(flagLoad)
            {
                controller_removeEmployee(employeeList);
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            break;
        case 6:
            if(flagLoad)
            {
                controller_ListEmployee(employeeList);
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            break;
        case 7:
            if(flagLoad)
            {
                controller_sortEmployee(employeeList);
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            break;
        case 8:
            if(flagLoad)
            {
            	file_saveAsText("data.csv",employeeList);
                printf("\nGuardado en lista de TEXTO exitosamente!\n\n");
                saveText=1;
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");

            }
            break;
        case 9:
            if(flagLoad)
            {
                file_saveAsBinary("data.bin",employeeList);
                printf("\nGuardado en lista BINARIA exitosamente!\n\n");
                saveBinary=1;
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            break;
        case 10:
            if(saveText !=1 || saveBinary !=1)
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

    controller_deleteListEmployee(employeeList);
    return EXIT_SUCCESS;
}


