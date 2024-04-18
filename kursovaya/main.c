#include "temp_api.h"
#include <getopt.h>

int main(int argc, char* argv[]) {

    temperatureData_t* records = NULL;   
    int opt;
    char* filename = NULL;
    int month = -1;
    
    if (argc == 1) {
        print_help();
        return 0;
    }

    while ((opt = getopt(argc, argv, "hf:m:")) != -1) {
        switch (opt)
        {
        case 'h':
            print_help();
            return 0;
        case 'f':
            filename = optarg;
            break;
        case 'm':
            month = atoi(optarg);
        default:
            break;
        }
    }
    int numRecords = readFileCsv(filename, &records);
    if(numRecords <= 0) {
        print_help();
        return 0;
    }
    if(month > 0) {
        calculateMonthlyStatisticsForMonth(records, numRecords, month);
    }
    else if (month < 0) {
        calculateMonthlyStatistics(records, numRecords);
        calculateYearlyStatistics(records, numRecords);
    }
    free(records);
    
}