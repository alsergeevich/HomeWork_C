#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;

} temperatureData_t;


int readFileCsv(const char* filename, temperatureData_t **arraySensors);                                        //чтение файла
void calculateMonthlyStatistics(temperatureData_t arraySensors[], int numRecords);                              //статистика по месяцам
void calculateMonthlyStatisticsForMonth(const temperatureData_t arraySensors[], int numRecords, uint8_t month); //статистика по конкретному месяцу
void calculateYearlyStatistics(const temperatureData_t arraySensors[], int numRecords);                         //статистика за год
void print_help();
