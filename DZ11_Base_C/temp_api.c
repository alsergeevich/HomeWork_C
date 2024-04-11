#include "temp_api.h"


float monthlyAverageTemperature(temperatureData_t arraySensors[], int size, uint8_t month) {
    
    int count = 0;
    int sumTemp = 0;
    for(int i = 0; i < size; ++i) {
        if(arraySensors[i].month == month) {
            ++count;
            sumTemp += arraySensors[i].temperature;
        }
    }

    return (float)sumTemp / count;
}

int minTemperatureCurrentMonth(temperatureData_t arraySensors[], int size, uint8_t month) {
    int minTemperature = 100;
    for(int i = 0; i < size; ++i) {
        if(arraySensors[i].month == month) {
            minTemperature = arraySensors[i].temperature < minTemperature ? arraySensors[i].temperature : minTemperature;
        }
    }
    return minTemperature;
}

int maxTemperatureCurrentMonth(temperatureData_t arraySensors[], int size, uint8_t month) {

    int maxTemperature = -100;
    for(int i = 0; i < size; ++i) {
        if(arraySensors[i].month == month) {
            maxTemperature = arraySensors[i].temperature > maxTemperature ? arraySensors[i].temperature : maxTemperature;
        }
    }
    return maxTemperature;
}

float averageAnnualTemperature(temperatureData_t arraySensors[], int size) {
    int totalTemperatureYear = 0;
    for(int i = 0; i < size; ++i) {
        totalTemperatureYear += arraySensors[i].temperature;
    }

    return (float)totalTemperatureYear / size;
}

int minimumTemperatureForTheYear(temperatureData_t arraySensors[], int size) {
    int minTemperature = 100;
    for (int i = 0; i < size; ++i) {
       minTemperature = arraySensors[i].temperature < minTemperature ? arraySensors[i].temperature : minTemperature; 
    }
    
    return minTemperature;
}

int maximumTemperatureForTheYear(temperatureData_t arraySensors[], int size) {

    int maxTemperature = -100;
    for (int i = 0; i < size; ++i) {
       maxTemperature = arraySensors[i].temperature > maxTemperature ? arraySensors[i].temperature : maxTemperature; 
    }
    
    return maxTemperature;
}