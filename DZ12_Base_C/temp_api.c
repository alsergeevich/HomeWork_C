#include "temp_api.h"


void calculateMonthlyStatistics(temperatureData_t arraySensors[], int numRecords) {
    // Создадим массив для хранения статистики по месяцам
    int monthlyTemperatures[12] = {0}; // Индекс 0 соответствует январю

    // Создадим массивы для минимальной и максимальной температур по месяцам
    int minTemperature[12] = {0}; 
    int maxTemperature[12] = {0}; 
    int countRecords[12] = {0};
    for(int i = 0; i < 12; ++i) {
        minTemperature[i] = 99;  // Инициализируем максимальными значениями
        maxTemperature[i] = -99; // Инициализируем минимальными значениями
    }
    // Пройдемся по всем записям о температуре
    for (int i = 0; i < numRecords; i++) {
        int month = arraySensors[i].month - 1; // Преобразуем номер месяца в индекс массива       
        monthlyTemperatures[month] += arraySensors[i].temperature; // Обновим сумму температур для текущего месяца
        countRecords[month] += 1;
        // Обновим минимальную и максимальную температуры
        if (arraySensors[i].temperature < minTemperature[month]) {
            minTemperature[month] = arraySensors[i].temperature;
        }
        if (arraySensors[i].temperature > maxTemperature[month]) {
            maxTemperature[month] = arraySensors[i].temperature;
        }
    }

    // Выведем статистику по месяцам
    printf("Статистика по месяцам:\n");
    for (int month = 0; month < 12; month++) {
        if(countRecords[month] <= 0 ) continue;
        double averageTemperature = (double)monthlyTemperatures[month] / countRecords[month];
        
        printf("Месяц %3d: Среднемесячная температура %10.1lf°C,  Минимальная температура %4d°C,  Максимальная температура %4d°C, Количество записей %4d\n",
               month + 1, averageTemperature, minTemperature[month], maxTemperature[month], countRecords[month]);
               
    }
    
}

void calculateMonthlyStatisticsForMonth(const temperatureData_t arraySensors[], int numRecords, uint8_t month) {
    if(month <= 0 || month > 12) {
        printf("Некорректный номер месяца\n");
        return;
    }
    int validator = 0;
    for(int i = 0; i < numRecords; ++i) {
        if(arraySensors[i].month == month) {
            ++validator;
        }
    }
    if(validator <= 0) {
        printf("Такого месяца нет в записях\n");
        return;
    }
    // Инициализируем переменные для статистики за указанный месяц
    int totalTemperature = 0;
    int minTemperature = 99;  // Инициализируем максимальными значениями
    int maxTemperature = -99; // Инициализируем минимальными значениями
    int count = 0;            // Количество записей за указанный месяц

    // Пройдемся по всем записям о температуре
    for (int i = 0; i < numRecords; i++) {
        if(arraySensors[i].month == month) {
            totalTemperature += arraySensors[i].temperature; // Обновим сумму температур за указанный месяц

            if(arraySensors[i].temperature < minTemperature) {
                minTemperature = arraySensors[i].temperature;
            }
            if(arraySensors[i].temperature > maxTemperature) {
                maxTemperature = arraySensors[i].temperature;
            }
            count++;
        }
    }
    
    // Вычислим среднемесячную температуру
    double averageTemperature = (double)totalTemperature / count;

    // Выведем статистику за указанный месяц
    printf("Статистика за месяц %2d:\n", month);
    printf("Среднемесячная температура: %4.1lf°C, Минимальная температура: %4d°C, Максимальная температура: %4d°C\n",
           averageTemperature, minTemperature, maxTemperature);

    
}

void calculateYearlyStatistics(const temperatureData_t arraySensors[], int numRecords) {

    int totalTemperature = 0;
    int minTemperature = 99;                             // Инициализируем максимальными значениями
    int maxTemperature = -99;                            // Инициализируем минимальными значениями

    // Пройдемся по всем записям о температуре
    for(int i = 0; i < numRecords; ++i) {
        totalTemperature += arraySensors[i].temperature;

        if(arraySensors[i].temperature < minTemperature) { //найдём минимальную температуру
            minTemperature = arraySensors[i].temperature;
        }
        if(arraySensors[i].temperature > maxTemperature) { //найдём максимальную температуру
            maxTemperature = arraySensors[i].temperature;
        }
    }

    double averageTemperature = (double)totalTemperature / numRecords; //вычислим среднюю температуру за год
    // Выведем статистику за год
    printf("Среднегодовая температура %4.2lf°C, Минимальная температура %4d°C, Максимальная температура %4d°C\n",
           averageTemperature, minTemperature, maxTemperature);

}

static int  compareByTemperature(const void* a, const void* b) {
    const temperatureData_t* dataA = (const temperatureData_t*)a;
    const temperatureData_t* dataB = (const temperatureData_t*)b;
    return dataA->temperature - dataB->temperature;
}
void sortByTemperature(temperatureData_t arraySensors[], int numRecords) {
    qsort(arraySensors, numRecords, sizeof(temperatureData_t), compareByTemperature);
}

static void addRecord(temperatureData_t arraySensors[], int numRecords, int year, int month, int day, int hour, int minute, int temperature) {
    arraySensors[numRecords].year = year;
    arraySensors[numRecords].month = month;
    arraySensors[numRecords].day = day;
    arraySensors[numRecords].hour = hour;
    arraySensors[numRecords].minute = minute;
    arraySensors[numRecords].temperature = temperature;
}

int  addInfo(temperatureData_t arraySensor[]) {
    int counter = 0;
    addRecord(arraySensor,counter++, 2021,1,16,9,1,-23);
    addRecord(arraySensor,counter++, 2021,1,16,9,1,-43);
    addRecord(arraySensor,counter++, 2021,2,16,9,1,-23);
    addRecord(arraySensor,counter++, 2021,2,16,9,1,-13);
    addRecord(arraySensor,counter++, 2021,3,16,9,1,3);
    addRecord(arraySensor,counter++, 2021,3,16,9,1,5);
    return counter;
}
void print_help() {
    printf("Program information:\n");
    printf("-h for help.\n");
    printf("-f <filename.csv> for loading the specified file.\n");
    printf("-m <month number> to display statistics for the specified month.\n");
    
}