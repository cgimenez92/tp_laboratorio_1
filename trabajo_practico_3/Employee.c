#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "gets.h"
#include "is_valid.h"


///Construtor///
Employee* employee_new()
{
    Employee* newEmployee;
    newEmployee = (Employee*)malloc(sizeof(Employee));
    if(newEmployee != NULL)
    {
        newEmployee->workedHours = 0;
        newEmployee->salary = 0;
        newEmployee->id = 0;
        strncpy(newEmployee->name, " ", STRING_SIZE);
    }
    return newEmployee;
}


///Destructor///
void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}


/////////Setters (Asigno el valor a la propiedad del objeto)////////////
int employee_setId(Employee* this, int id)
{
    int ret = -1;
    if(this != NULL)
    {
        if(id > 0)
        {
            this->id = id;
            ret = 0;
        }
    }
    return ret;
}

int employee_setSalary(Employee* this, int salary)
{
    int ret = -1;
    if(this != NULL)
    {
        if(salary > 0)
        {
            this->salary = salary;
            ret = 0;
        }
    }
    return ret;
}

int employee_setWorkedHours(Employee* this, int workedHours)
{
    int ret = -1;
    if(this != NULL)
    {
        if(workedHours >= 0)
        {
            this->workedHours = workedHours;
            ret = 0;
        }
    }
    return ret;
}

int employee_setName(Employee* this, char* name)
{
    int ret = -1;
    int len;

    if(this != NULL && name != NULL)
    {
        len = strlen(name);

        if(len > 0 && len < STRING_SIZE)
		{
			strncpy(this->name, name, STRING_SIZE);
			ret = 0;
		}
     }
    return ret;
}

Employee* employee_newParameters(char* idStr, char* nameStr, char* workedHoursStr, char* salaryStr)
{
    Employee* newEmployee;
    int aux;
    int errorFlag;
    newEmployee = employee_new();

    if(newEmployee != NULL && idStr != NULL && nameStr != NULL && workedHoursStr != NULL && salaryStr != NULL)
    {
        if(employee_setName(newEmployee, nameStr))
        {
            errorFlag = 1;
        }
        aux = atoi(salaryStr);

        if(employee_setSalary(newEmployee, aux))
        {
            errorFlag = 1;
        }
        aux = atoi(workedHoursStr);

        if(employee_setWorkedHours(newEmployee, aux))
        {
            errorFlag = 1;
        }
        aux = atoi(idStr);

        if(employee_setId(newEmployee, aux))
        {
            errorFlag = 1;
        }

        if(errorFlag == 1)
        {
            free(newEmployee);
            newEmployee = NULL;
        }
    }
    return newEmployee;
}


/////////Getters (Obtengo el valor de la propiedad del objeto)////////////
int employee_getId(Employee* this, int* id)
{
    int ret = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        ret = 0;
    }
    return ret;
}

int employee_getSalary(Employee* this, int* salary)
{
    int ret = -1;
    if(this != NULL && salary != NULL)
    {
        *salary = this->salary;
        ret = 0;

    }
    return ret;
}

int employee_getWorkedHours(Employee* this, int* workedHours)
{
    int ret = -1;
    if(this != NULL && workedHours != NULL)
    {
        *workedHours = this->workedHours;
        ret = 0;
    }
    return ret;
}

char* employee_getName(Employee* this)
{
    char* name = NULL;

    if(this != NULL)
    {
        name = (char*)malloc(sizeof(char)* STRING_SIZE);
        strncpy(name, this->name, STRING_SIZE);
    }
    return name;
}


///Print///
int employee_print(Employee* this)
{
    int ret = -1;

    int id;
    int salary;
    int hours;

    if(this != NULL)
    {
        employee_getId(this,&id);
        employee_getWorkedHours(this,&hours);
        employee_getSalary(this,&salary);
        printf("\n%d      |       %s       |   %d   |   %d  |\n\n", id, employee_getName(this), hours, salary);
        ret = 0;
    }
    return ret;
}


///Sort///
///Revisar los ordenamientos si corresponden///
int employee_sortByHours(void* this1, void* this2)
{
    int ret = 0;
    Employee* employeeAuxA;
    Employee* employeeAuxB;
    int hoursA;
    int hoursB;
    if(this1 != NULL && this2 != NULL)
    {
        employeeAuxA = (Employee*) this1;
        employeeAuxB = (Employee*) this2;
        if(employeeAuxA != NULL && employeeAuxB != NULL)
        {
            employee_getWorkedHours(employeeAuxA,&hoursA);
            employee_getWorkedHours(employeeAuxB,&hoursB);

            if(hoursA > hoursB)
            {
                ret = 1;
            }
            else if(hoursA < hoursB)
            {
                ret = -1;
            }
        }
    }

    return ret;
}

int employee_sortBySalary(void* this1, void* this2)
{
    int ret = 0;
    Employee* employeeAuxA;
    Employee* employeeAuxB;
    int salaryA;
    int salaryB;
    if(this1 != NULL && this2 != NULL)
    {
        employeeAuxA = (Employee*) this1;
        employeeAuxB = (Employee*) this2;
        if(employeeAuxA != NULL && employeeAuxB != NULL)
        {
            employee_getSalary(employeeAuxA,&salaryA);
            employee_getSalary(employeeAuxB,&salaryB);

            if(salaryA > salaryB)
            {
                ret = 1;
            }
            else if(salaryA < salaryB)
            {
                ret = -1;
            }
        }
    }
    return ret;
}

int employee_sortByName(void* this1, void* this2)
{
    int ret = -2;
    Employee* employeeAuxA;
    Employee* employeeAuxB;
    char* nameA;
    char* nameB;
    if(this1 != NULL && this2 != NULL)
    {
        employeeAuxA = (Employee*) this1;
        employeeAuxB = (Employee*) this2;
        if(employeeAuxA != NULL && employeeAuxB != NULL)
        {
            nameA = employee_getName(this1);
            nameB = employee_getName(this2);

            ret = strcasecmp(nameA,nameB);
        }
    }
    return ret;
}









