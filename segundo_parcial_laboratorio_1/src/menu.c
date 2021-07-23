/*
 * menu.c
 *
 *  Created on: Jun 10, 2021
 *      Author: Administrador
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gets.h"

int menu()
{
	int option;

	getInt ("\n1. Cargar los datos desde los archivos customers.csv - services.csv (modo texto)."
			"\n2. Listar datos relacionados."
			"\n3. Muestra ll_filter"
			"\n4. Muestra ll_count"
			"\n5. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
			"\n6. Salir\n"
			"\nIngrese opcion: ", "Numero menor a 1: \n", "Numero mayor a 10: \n", "\nIngresar caracteres numericos", &option, 2, 1, 6);
	fflush(stdin);
    return option;
}
//
//int menuChangeParameter(Employee* this)
//{
//	int option;
//	getInt("\n1-Modificar nombre del empleado\n2-Modificar horas trabajadas del empleado\n3-Modificar sueldo del empleado\n4-Salir\n\nIngrese opcion: ",
//			"\n/****Error  - Ingresar opcion mayor a 0****/\n",
//			"\n/****Error  - Ingresar opcion menor a 5****/\n",
//			"\nIngresar caracteres numericos", &option, 2, 1, 4);
//	printf("\nEdicion de %s \n", this->name);
//	fflush(stdin);
//    return option;
//}
//
//int menuDelete(Employee* this)
//{
//	int option;
//	printf("\Eliminar empleado %s con id %d \n", this->name, this->id);
//	getInt("\n1-Si\n2-No\n\nIngrese opcion: ",
//			"\n/****Error  - Ingresar opcion mayor a 0****/\n",
//			"\n/****Error  - Ingresar opcion menor a 3****/\n",
//			"\nIngresar caracteres numericos", &option, 2, 1, 2);
//	fflush(stdin);
//    return option;
//}
//
//int menuSortList()
//{
//	int option;
//
//	getInt ("\n1.  Ordenamiento por Horas trabajadas.\n2.  Ordenamiento por Salario."
//			"\n3.  Ordenamiento por Nombre"
//			"\n4.  Salir\n"
//			"\nIngrese opcion: ", "Numero menor a 1: \n", "Numero mayor a 4: \n", "\nIngresar caracteres numericos", &option, 2, 1, 4);
//	fflush(stdin);
//    return option;
//}
//

int menuValidationExit()
{
	int option;
	getInt("\nCUIDADO! Falta guardar en una o en ambas listas. Si sales ahora NO se guardaran los cambios.\nDesea salir de todos modos?\n1-Volver\n2-Salir\nIngrese una opcion: "
			"\nIngrese opcion: ",
			"Numero menor a 1: \n",
			"Numero mayor a 2: \n",
			"\nIngresar caracteres numericos", &option, 2, 1, 2);
	fflush(stdin);
    return option;
}

