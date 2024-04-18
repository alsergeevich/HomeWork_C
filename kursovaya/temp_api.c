#include "temp_api.h"

int readFileCsv(const char* filename, temperatureData_t **arraySensors) {
    FILE* file = fopen(filename, "r"); //открываем файл
    if(!file) { //если ошибка открытия то выходим из функции и сообщаем об этом
        printf("Error open file\n");
        return -1;
    }
    char line[256]; //выделяем буфер под чтение строк
    int numErrorLine = 0; //для номера строки где ошибка
    int numRecords = 0; //для подсчёта количества записей
    while(fgets(line, sizeof(line), file)) { //читаем файл по строчно
        temperatureData_t newRecord; //создаём экземпляр структуры
        if(sscanf(line, "%d;%d;%d;%d;%d;%d", //форматированный ввод данных из строки
                &newRecord.year, &newRecord.month, &newRecord.day,
                &newRecord.hour, &newRecord.minute, &newRecord.temperature) == 6) { //если считали 6 параметров
            (*arraySensors) = realloc(*arraySensors, sizeof(temperatureData_t) * (numRecords + 1)); //увеличиваем выделенную память  на размер одной структуры
            if(!(*arraySensors)) { //если NULL то память не выделилась
                printf("Memory allocation error\n"); //сообщаем об ошибке
                fclose(file); //закрываем файл
                return -1;
            }
            (*arraySensors)[numRecords] = newRecord; //иначе добавляем структуру в массив
            numRecords++; //увеличиваем счётчик элементов в массиве
        }
        else {
            printf("================================================\n");
            printf(" Строка %d содержит ошибку %s", numRecords + 1, line);            //если считали не все данные значит в данных ошибка выводим номер строки и саму строку
            printf("================================================\n");
        }
    }
    fclose(file); //закрываем файл после того как считали его
    
    return numRecords; //возвращаем количество элементов массива
}


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
    printf("Статистика по месяцам за %d год:\n", arraySensors[0].year);
    for (int month = 0; month < 12; month++) {
        double averageTemperature = (double)monthlyTemperatures[month] / countRecords[month];
        printf("Месяц %3d: | Среднемесячная температура %10.1lf°C,  | Минимальная температура %4d°C,  | Максимальная температура %4d°C, | Количество записей %4d\n",
               month + 1, averageTemperature, minTemperature[month], maxTemperature[month], countRecords[month]);
               
    }
    
}

void calculateMonthlyStatisticsForMonth(const temperatureData_t arraySensors[], int numRecords, uint8_t month) {
    if(month <= 0 || month > 12) {
        printf("Некорректный номер месяца\n");
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
    printf("Статистика за %2d-й месяц %2d года:\n", month, arraySensors[0].year);
    printf("Среднемесячная температура: %4.1lf°C, Минимальная температура: %4d°C, Максимальная температура: %4d°C, Количество записей: %4d\n",
           averageTemperature, minTemperature, maxTemperature, count);

    
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
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Статистика за %2d год:\n", arraySensors[0].year);
    printf("Среднегодовая температура: %4.1lf°C, Минимальная температура: %4d°C, Максимальная температура: %4d°C, Количество записей: %4d\n",
           averageTemperature, minTemperature, maxTemperature, numRecords);
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");

}

void print_help() {
    printf("Program information:\n");
    printf("-h for help.\n");
    printf("-f <filename.csv> for loading the specified file.\n");
    printf("-m <month number> to display statistics for the specified month.\n");
    
}