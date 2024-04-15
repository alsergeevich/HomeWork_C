#pragma once
#include <stdint.h>
#include <stdio.h>

typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;

} temperatureData_t;

void calculateMonthlyStatistics(temperatureData_t arraySensors[], int numRecords);                              //статистика по месяцам
void calculateMonthlyStatisticsForMonth(const temperatureData_t arraySensors[], int numRecords, uint8_t month); //статистика по конкретному месяцу
void calculateYearlyStatistics(const temperatureData_t arraySensors[], int numRecords);                         //статистика за год

