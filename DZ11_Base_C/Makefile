all: temperature_data

temperature_data: main.o temp_api.o
	gcc -o temperature_data main.o temp_api.o

main.o: main.c temp_api.h
	gcc -c -o main.o main.c

temp_api.o: temp_api.c
	gcc -c -o temp_api.o temp_api.c

clean:
	rm -rf *.o temperature_data