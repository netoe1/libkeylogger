#ifndef CLOCKTIME_H
#define CLOCKTIME_H

#pragma region namespaces

#define pDATE char *
#define freeDate free

#pragma endregion namespaces

#pragma region structs

typedef struct
{
	int day;
	int month;
	int year;
	int hour;
	int min;
	int sec;
} CDATE_Date;

#pragma endregion structs

#pragma region functions

CDATE_Date getDateNow();
pDATE getDateAsString_dynamic(); // Dinamic ptr allocation, free memory with free() or freeDate() namespace.
pDATE getFullDateAsString();	 // Dinamic pointer allocation, free memory with free() or freeDate() namespace.

#pragma endregion functions

#endif
