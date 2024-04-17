#include "temp_api.h"
#include <getopt.h>

#define MAX_SIZE 10

int main(int argc, char* argv[]) {

    temperatureData_t records[MAX_SIZE] = {0};
    int numRecords = addInfo(records);
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
    if(month > 0) {
        calculateMonthlyStatisticsForMonth(records, numRecords, month);
    }
    else if (month < 0) {
        calculateMonthlyStatistics(records, numRecords);
        calculateYearlyStatistics(records, numRecords);
    }    
}