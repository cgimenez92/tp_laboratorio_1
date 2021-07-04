#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "gets.h"

int menu()
{
	int option;
	getInt("1-Alta Trabajo\n2-Modificar Trabajo\n3-Baja Trabajo\n4-Listar Trabajos\n5-Listar Servicios"
			"\n6-Total"
			"\n7-Listado de todos los trabajos ordenados por marca de la bicicleta"
			"\n8-El o los servicios con más trabajos realizados"
			"\n9-Listado de servicios con los datos de las bicicletas que se lo realizaron"
			"\n10-La cantidad de biciletas de color Rojo que realizaron un servicio elegido por el usuario"
			"\n13-Salir\n\nIngrese opcion: ", "\n/****Error  - Ingresar opcion de 1-7****/\n", &option, 2, 1, 13);
	fflush(stdin);
    return option;
}

int menuChangeParameterService()
{
	int option;
	getInt("\n1-Modificar descripcion\n2-Modificar precio\n3-Salir\n\nIngrese opcion: ", "\n/****Error - Ingresar opcion de 1-4****/\n", &option, 2, 1, 3);
	fflush(stdin);
    return option;
}

int menuChangeParameterWork()
{
	int option;
	getInt("\n1-Modificar marca de la bicicleta\n2-Modificar id servicio\n3-Salir\n\nIngrese opcion: ", "\n/****Error - Ingresar opcion de 1-3****/\n", &option, 2, 1,3);
	fflush(stdin);
    return option;
}
