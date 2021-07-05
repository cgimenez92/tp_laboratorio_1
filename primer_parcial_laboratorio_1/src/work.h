#ifndef WORK_H_
#define WORK_H_

#define TRUE 1
#define FALSE 0
#define ASC 1
#define DSC 0
#define ARRAY_SIZE_WORK 20000

#include "service.h"
#include "bike.h"
#include "date.h"
#include "wheel.h"

	typedef struct
	{
		int id;
		int isEmpty;
		int idBike;
		int idWheel;
		int idService;
		Date ddmmyyyy;
	} Work;


	int work_swapPostionInArray (Work* list, int positionToSwap);

	/** \brief adds in a existing list, a list of Work with the values received as parameters
	 * \param Work* list
	 * \param int len
	 * \param int idBike
	 * \param int idWheel
	 * \param int idService
	 * \param iint day
	 * \param int month
	 * \param int year
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
	 */
	int work_force_init(Work* list, int len, int idBike, int idWheel, int idService, int day, int month, int year);

	/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
	 * \param Work* list Pointer to array of Customers
	 * \param int len Array length
	 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	 */
	int work_init(Work* list, int len);

    /** \brief create a new Customer in list
     * in the first empty position
     * \param Work* listWork
     * \param int lenWork
     * \param Service* listService
     * \param int lenService
     * \param Bike* listBike
     * \param int lenBike
     * \param Wheel* listWheel
     * \param int lenWheel
     * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (index) if Ok
     */
	int work_create(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel);

    /** \brief chooses parameter you want to change in Customer list
     * in the first empty position
     * \param Customer* list
     * \param int len
     * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
     */
	int work_update(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel);

	/** \brief Remove a Customer by Id (put isEmpty Flag in 1)
	 * \param list Customer*
	 * \param len int
	 * \param id int
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
	int work_delete(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel);

	/** \brief prints the content of Customers received on index parameter
	 * \param list Customer*
	 * \param length int
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
	int work_print(Work* listWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel, int index);

	/** \brief print the content of Customers array
	 * \param list Customer*
	 * \param length int
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
	int work_printArray(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel);

	/** \brief find a empty position in customer array and returns the index position in array.
	 * \param list Customer*
	 * \param len int
	 * \param id int
	 * \return Return Customer index position or (-1) if [Invalid length or NULL pointer received or Customer not found] - (i --> Index of position free) if Ok
	 */
	int work_freePosition(Work* list, int len);

	/** \brief find a empty position in customer array and returns the index position in array.
	 * \param list Customer*
	 * \param len int
	 * \param int* pIndex
	 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
	int work_freePositionIndex(Work* list, int len, int* pIndex);

	/** \brief find an Customer by Id and returns the index position in array.
	 * \param list Customer*
	 * \param len int
	 * \param id int
	 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
	int work_searchId(Work* list, int len, int id);


	int work_sortArray(Work* list, int len, int order, Bike* listBike, int lenBike);
	int work_sortArrayByIdService (Work* list, int len, int order);
	int work_sortArrayByIdWheel (Work* list, int len, int order);
	int work_sortArrayByIdBike (Work* list, int len, int order);
	int work_printArraySortByYear(Work* listWork, int lenWork, Service* listService, int lenService, Bike* listBike, int lenBike, Wheel* listWheel, int lenWheel);

#endif /* WORK_H_ */
