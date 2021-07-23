#ifndef customer_H_INCLUDED
#define customer_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_SIZE 128

typedef struct
{
    int customerId;
    char country[STRING_SIZE];
    char gender[STRING_SIZE];
    char firtsName[STRING_SIZE];
    char lastName[STRING_SIZE];
    char birthDate[STRING_SIZE];
    int idContractedService;
}Customer;

/** \brief Crea un nuevo objecto Customer
 *
 * \param void
 * \return  (NULL) si no hay memoria para crear el elemento.
 *          Customer* si TODO OK;
 *
 */
Customer* customer_new(void);

/** \brief Crea un nuevo empleado cargando los campos con informacion
 *
 * \param char* idStr string que contiene el ID
 * \param char* nameStr el name
 * \param char* salaryStr string que contiene el salary
 * \param char* horasStr string que contiene las Horas Trabajadas
 * \return (NULL): si los Parameters son nulos, los Parameters son incorrectos o no hay espacio disponible
 *         Customer*: TODO OK
 */
 // nota Se usaron char* por respetar la funcion recibida.
Customer* customer_newParameters(char* customerIDStr, char* countryStr, char* genderStr, char* firtsNameStr, char* lastNameStr, char* birthDateStr, char* idContractedServiceStr);

/** \brief Elimina un empleado de memoria
 *
 * \param this Customer* el empleado a eliminar
 * \return void
 */
void customer_delete(Customer* this);

/** \brief establece el id de un empleado
 * \param this Customer* empleado a modificar
 * \param id int nuevo Id
 * \return int  (-1) ERROR: Customer* es NULL o Id incorrecto.
 *               (0) TODO BIEN
 */
int customer_setId(Customer* this, int id);

/** \brief establece el name del empleado
 * \param this Customer* empleado a modificar
 * \param name char* nuevo name
 * \return int (-1) ERROR: Customer* es NULL o name incorrecto.
 *               (0) TODO BIEN
 */
int customer_setCountry(Customer* this, char* country);

/** \brief se obtiene valor de la carga horaria de un empleado
 *
 * \param this Customer* Empleado objectivo
 * \param id int* dirrecion donde se copia el valor de las horas trabajadas
 * \return int (-1) ERROR: si los Parameters son NULL
 *              (0) TODO BIEN.
 */
int customer_setGender(Customer* this, char* gender);

/** \brief se obtiene valor del salary de un empleado
 *
 * \param this Customer* Empleado objectivo
 * \param id int* dirrecion donde se copia el valor del salary
 * \return int (-1) ERROR: si los Parameters son NULL
 *              (0) TODO BIEN.
 *
 */
int customer_setFirtsName(Customer* this, char* firtsName);

int customer_setLastName(Customer* this, char* lastName);


int customer_setBirthDate(Customer* this, char* birthDate);

int customer_setIdContractedService(Customer* this, int idContractedService);

int customer_getCustomerId(Customer* this, int* customerId);

char* customer_getCountry(Customer* this);

char* customer_getGender(Customer* this);

char* customer_getFirtsName(Customer* this);

char* customer_getLastName(Customer* this);

char* customer_getBirthDate(Customer* this);

int customer_getIdContractedService(Customer* this, int* idContractedService);

int customer_print(Customer* this);

int customer_filterByGender(Customer* this);

int customer_filterByUSCountry(Customer* this);

#endif // customer_H_INCLUDED
