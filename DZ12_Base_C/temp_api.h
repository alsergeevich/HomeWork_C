#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;

} temperatureData_t;



void calculateMonthlyStatistics(temperatureData_t arraySensors[], int numRecords);                                                            //статистика по месяцам
void calculateMonthlyStatisticsForMonth(const temperatureData_t arraySensors[], int numRecords, uint8_t month);                               //статистика по конкретному месяцу
void calculateYearlyStatistics(const temperatureData_t arraySensors[], int numRecords);                                                       //статистика за год
static int  compareByTemperature(const void* a, const void* b);                                                                               //функция сравнения для сортировки по температуре
void sortByTemperature(temperatureData_t arraySensors[], int numRecords);                                                                     //функция сортировки по температуре
static void addRecord(temperatureData_t arraySensors[], int numRecords, int year, int month, int day, int hour, int minute, int temperature); //функция добавления записей в структуру
int  addInfo(temperatureData_t arraySensor[]);                                                                                                //функция добавления структуры в массив
void print_help();