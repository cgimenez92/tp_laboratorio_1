/*
 * service.h
 *
 *  Created on: 23 jul. 2021
 *      Author: u607158
 */

#ifndef SERVICE_H_
#define SERVICE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_SIZE 128

typedef struct
{
    int serviceId;
    char serviceType[STRING_SIZE];
    float price;
}Service;



Service* service_new();
void service_delete(Service* this);
int service_setServiceId(Service* this, int ServiceId);
int service_setServiceType(Service* this, char* serviceType);
int service_setPrice(Service* this, float price);
Service* service_newParameters(char* ServiceIdStr, char* serviceTypeStr, char* priceStr);

int service_getPrice(Service* this);

#endif /* SERVICE_H_ */
