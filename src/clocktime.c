#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clocktime.h"

#pragma region conts
#define UNDEFINED -1
#define TO_SUM_YEAR 1900
#define TO_SUM_MON 1
#pragma endregion conts
/*--------------------*/
#pragma region structs

#pragma endregion structs
/*--------------------*/
#pragma region implementation

CDATE_Date getDateNow()
{
    CDATE_Date convert;
    time_t currentTime = time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    convert.day = localTime->tm_mday;
    convert.month = localTime->tm_mon + TO_SUM_MON;
    convert.year = localTime->tm_year + TO_SUM_YEAR;
    convert.hour = localTime->tm_hour;
    convert.min = localTime->tm_min;
    convert.sec = localTime->tm_sec;
    return convert;
}
pDATE getDateAsString_dynamic()
{
    time_t currentTime;
    time(&currentTime);

    // Convert time to the tm structure
    struct tm *localTime = localtime(&currentTime);

    // Allocate space for the formatted date string
    char *formattedDate = (char *)malloc(11 * sizeof(char)); // 10 characters for the date + 1 for the null terminator

    // Check if the allocation was successful
    if (formattedDate == NULL)
    {
        fprintf(stderr, "[clocktime-runtime-err]: Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }

    // Adjust month and year as needed
    localTime->tm_mon += TO_SUM_MON;
    localTime->tm_year += TO_SUM_YEAR;

    // Format the date string
    snprintf(formattedDate, 11, "%02d/%02d/%d", localTime->tm_mday, localTime->tm_mon, localTime->tm_year);

    return formattedDate;
}
pDATE getFullDateAsString()
{
    CDATE_Date dateNow = getDateNow();

    char *ret = (char *)malloc(22 * sizeof(char *));

    sprintf(ret, "%02d/%02d/%d %02d:%02d:%02d", dateNow.day, dateNow.month, dateNow.year, dateNow.hour, dateNow.min, dateNow.sec);
    return ret;
}
#pragma endregion implementation