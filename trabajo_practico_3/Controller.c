#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "input.h"
#include "gets.h"
#include "menu.h"
#define ATTEMPTS 2

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_getNextID(LinkedList* pArrayListEmployee)
{
    int id = 0;
    int previousId;
    int aux;
    Employee* employeeAux;
    int listLenght;
    int i;

    if(pArrayListEmployee != NULL)
    {
    	listLenght = ll_len(pArrayListEmployee);
        if(listLenght > 0)
        {
            for(i = 0; i<listLenght; i++)
            {
                employeeAux = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(employeeAux,&aux);
                if(aux > id)
                {
                	previousId = id;
                    id = aux;
                    if(previousId + 1 != id)
                    {
                        id = previousId;
                        break;
                    }
                }
            }
            id++;
        }
        else
        {
            id = 1;
        }
    }
    return id;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    Employee* pEmployee;
    printf("\nID      |       NOMBRE       |   HORAS   |   SUELDO  |\n\n");
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        pEmployee=ll_get(pArrayListEmployee,i);
        employee_print(pEmployee);
    }

    return 1;
}


Employee* controller_findById(int id, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int i;

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        pEmployee=ll_get(pArrayListEmployee,i);
        if(pEmployee!=NULL)
        {
            if(pEmployee->id==id)
            {
                break;
            }
            else
            {
                pEmployee=NULL;
            }
        }
    }
    return pEmployee;
}

int controller_findIndexById(int id, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int index=-1;
    int i;

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        pEmployee=ll_get(pArrayListEmployee,i);
        if(pEmployee!=NULL)
        {
            if(pEmployee->id==id)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    Employee* newEmployee;
    int idAux;

    if(pArrayListEmployee != NULL)
    {
        newEmployee = employee_new();
        input_name(newEmployee);
        input_salary(newEmployee);
        input_workedHours(newEmployee);
        idAux = controller_getNextID(pArrayListEmployee);
        employee_setId(newEmployee,idAux);

        if(ll_add(pArrayListEmployee,newEmployee))
        {
            printf("El empleado no se pudo agregar a la lista \n");
        }
        else
			{
				ret = 0;
			}
    }
    return ret;
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int option;
    Employee* pEmployee;

    controller_ListEmployee(pArrayListEmployee);
    getInt ("\n--EDICION DE EMPLEADO--\n\nIngrese el id del empleado que desea modificar: \n", "ID menor a 0: \n", "ID mayor a 900000: \n", "No es un numero valido: \n", &id, ATTEMPTS, 0, 900000);
    pEmployee=controller_findById(id,pArrayListEmployee);

    if(pEmployee!=NULL)
    {
        do
        {
        	option = menuChangeParameter(pEmployee);
			switch(option)
			{
				case 1:
					input_name(pEmployee);
					printf("\nNombre cambiado con exito!\n\n");
					break;
				case 2:
					input_salary(pEmployee);
					printf("\nSueldo cambiado con exito!\n\n");
					break;
				case 3:
					input_workedHours(pEmployee);
					printf("\nhoras trabajadas cambiadas con exito!\n\n");
					break;
				case 4:
					("\nVolviendo a menu principal...\n\n");
					break;
				default:
					printf("\nERROR. Opcion incorrecta\n\n");
					break;
			}
        } while(option != 4);
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int id;
    int option;
    int index;

    controller_ListEmployee(pArrayListEmployee);
    getInt ("\n--ELIMINACION DE EMPLEADO--\n\nIngrese el id del empleado que desea eliminar: /n", "ID menor a 0: \n", "ID mayor a 900000: \n", "No es un numero valido: \n", &id, ATTEMPTS, 0, 900000);
    pEmployee=controller_findById(id,pArrayListEmployee);
    index=controller_findIndexById(id,pArrayListEmployee);

    if(pEmployee!=NULL && index>-1)
    {
		do
		{
			option = menuDelete(pEmployee);
			switch(option)
			{
				case 1:
					employee_delete(pEmployee);
					ll_remove(pArrayListEmployee,index);
					printf("\nEmpleado eliminado con exito!\n\n");
					break;
				case 2:
					("\nVolviendo a menu principal...\n\n");
					break;
				default:
					printf("\nERROR. Opcion incorrecta\n\n");
					break;
			}
		}while(option != 2);
    }
    else
	{
		printf("\nNo se encontro el empleado con ese id.\n\n");
	}
    return 1;
}


int controller_deleteListEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    int len;
    int i;
    Employee* pEmployee;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        if(len > 0)
        {
            for(i=0; i<len; i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                employee_delete(pEmployee);
            }
            ll_deleteLinkedList(pArrayListEmployee);
            ret = 0;
        }
    }
    return ret;

}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option;
    int order;

    controller_ListEmployee(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
		do
		{
			option = menuSortList();
			switch(option)
			{
				case 1:
					if(!getInt ("\nIngrese una opcion: \n- 0)Descendente\n- 1)Ascendente\n", "Opcion menor a 0: \n", "Opcion mayor a 1: \n", "No es un numero valido: \n", &order, ATTEMPTS, 0, 1))
					{
						ll_sort(pArrayListEmployee, employee_sortByHours, order);
						controller_ListEmployee(pArrayListEmployee);
					}
					break;
				case 2:
					if(!getInt ("\nIngrese una opcion: \n- 0)Descendente\n- 1)Ascendente\n", "Opcion menor a 0: \n", "Opcion mayor a 1: \n", "No es un numero valido: \n", &order, ATTEMPTS, 0, 1))
					{
						ll_sort(pArrayListEmployee, employee_sortBySalary, order);
						controller_ListEmployee(pArrayListEmployee);
					}
					break;
				case 3:
					if(!getInt ("\nIngrese una opcion: \n- 0)Descendente\n- 1)Ascendente\n", "Opcion menor a 0: \n", "Opcion mayor a 1: \n", "No es un numero valido: \n", &order, ATTEMPTS, 0, 1))
					{
						ll_sort(pArrayListEmployee, employee_sortByName, order);
						controller_ListEmployee(pArrayListEmployee);
					}
					break;
				case 4:
					("\nVolviendo a menu principal...\n\n");
					break;
				default:
					printf("\nERROR. Opcion incorrecta\n\n");
					break;
			}

		} while(option != 4);
    }
    return 1;
}
