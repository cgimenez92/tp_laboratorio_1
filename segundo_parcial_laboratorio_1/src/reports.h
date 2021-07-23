/*
 * reports.h
 *
 *  Created on: 23 jul. 2021
 */

#ifndef REPORTS_H_
#define REPORTS_H_

int report_printRelationData(LinkedList* pArrayListCustomer, LinkedList* pArrayListService);
int report_countByCountry(LinkedList* this);
LinkedList* report_filterCustomerByGender(LinkedList* this);
LinkedList* report_filterCustomerByUSCountry(LinkedList* this);
int report_avgByService(LinkedList* this);

#endif /* REPORTS_H_ */
