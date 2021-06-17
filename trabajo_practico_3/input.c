/*
 * input.c
 *
 *  Created on: Jun 11, 2021
 *      Author: Administrador
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "gets.h"
#include "Employee.h"
#define ATTEMPTS 2

int input_name(Employee* employee)
{
    int ret = -1;
    char name[STRING_SIZE];

    if(employee != NULL)
    {
    	if(!getName("Ingrese el nombre del empleado: \n", "No es un nombre valido: \n", name, ATTEMPTS, STRING_SIZE))
        {
    		employee_setName(employee, name);
    		ret = 0;
        }
    }
    return ret;
}

int input_salary(Employee* employee)
{
    int ret = -1;
    float salary;

    if(employee != NULL)
    {
    	if(!getFloat ("Ingrese el salario del empleado: \n", "Numero menor a 0: \n", "Numero mayor a 900000: \n", "No es un numero valido: \n", &salary, ATTEMPTS, 0, 900000))
        {
    		employee_setSalary(employee, salary);
    		ret = 0;
        }
    }
    return ret;
}

int input_workedHours(Employee* employee)
{
    int ret = -1;
    int workedHours;

    if(employee != NULL)
    {
    	if(!getInt ("Ingrese el horas trabajadas del empleado: \n", "Numero menor a 0: \n", "Numero mayor a 9: \n", "No es un numero valido: \n", &workedHours, ATTEMPTS, 0, 9))
        {
    		employee_setWorkedHours(employee, workedHours);
    		ret = 0;
        }
    }
    return ret;
}
