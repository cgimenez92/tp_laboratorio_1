/*
 ============================================================================
 Name        : trabajo_practico_2.c
 Author      : cgimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "employee.h"
#include "menu.h"
#define ARRAY_SIZE 1000
#define ASC 1
#define DSC 0

int main(void)
{
	setbuf(stdout, NULL);
	char seguir='s';
	int flag=0;
	float avg;
	float totalSalary;
	Employee listEmployees[ARRAY_SIZE];
	employee_init(listEmployees, ARRAY_SIZE);
//BORRAR Para probar un listado de empleados

	if(!employee_force_init(listEmployees, ARRAY_SIZE, "Mariela", "Gomez",20000,2))
	{
		employee_force_init(listEmployees, ARRAY_SIZE, "Juan", "Martinez", 30000 ,3);
		employee_force_init(listEmployees, ARRAY_SIZE, "Mauro", "Gomez", 18000, 1);
		employee_force_init(listEmployees, ARRAY_SIZE, "Yolanda", "Alberdi", 32000, 1);
		employee_force_init(listEmployees, ARRAY_SIZE, "Fabio", "Benitez", 45000, 2);
		flag++;
	}

	do
	{
		switch (menu())
		{
			case 1:
				employee_create(listEmployees, ARRAY_SIZE);
				flag++;
				break;
			case 2:
				if(flag>0)
				{
					if(!employee_update(listEmployees, ARRAY_SIZE))
					{
						printf("\nSe pudo modificar correctamente");
					}
					else
					{
						printf("\nNo se pudo modificar");
					}
				}
				else
				{
					printf("\nNo se ingreso ningun empleado\n");
				}
				break;
			case 3:
				if(flag>0)
				{
					if(!employee_delete(listEmployees, ARRAY_SIZE))
					{
						printf("\nSe borro empleado correctamente");
					}
					else
					{
						printf("\nNo se pudo borrar empleado\n");
					}
				}
				else
				{
					printf("\nNo se ingreso ningun empleado\n");
				}

				break;
			case 4:
				if(flag>0)
				{
					if(!employee_sortArray(listEmployees, ARRAY_SIZE, ASC))
					{
						employee_printArray(listEmployees, ARRAY_SIZE);

						if(!employee_avgSalary(listEmployees, ARRAY_SIZE, &avg))
						{
							printf("\nA - El promedio salarial es: %.2f\n", avg);
						}

						employee_aboveAvgSalary(listEmployees, ARRAY_SIZE);

						if(!employee_sumSalary(listEmployees, ARRAY_SIZE, &totalSalary))
						{
							printf("\nC - La suma total de la masa salarial es de:  %.2f\n", totalSalary);
						}
					}
				}
				else
				{
					printf("\nNo se ingreso ningun empleado\n");
				}
				break;
			case 5:
				printf("\nAdios!\n");
				seguir='n';
				break;

			default:
				printf("\nIngrese opcion correcta\n\n");
				break;
	        }
	         fflush(stdin);
		}while (seguir=='s');

	return 0;
}

