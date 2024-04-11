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

float monthlyAverageTemperature(temperatureData_t arraySensors[], int size, uint8_t month);
int minTemperatureCurrentMonth(temperatureData_t arraySensors[], int size, uint8_t month);
int maxTemperatureCurrentMonth(temperatureData_t arraySensors[], int size, uint8_t month);
float averageAnnualTemperature(temperatureData_t arraySensors[], int size);
int minimumTemperatureForTheYear(temperatureData_t arraySensors[], int size);
int maximumTemperatureForTheYear(temperatureData_t arraySensors[], int size); 
