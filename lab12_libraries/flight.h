#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct flight flight_t;

struct flight{
    int number;
    int time;
    int price;
    char* destination;
};




flight_t* generate_flights(int count);
void print_flights(flight_t flights_arr[], int n);

int by_number(flight_t flight_first, flight_t flight_second);
int by_destination(flight_t flight_first, flight_t flight_second);
int by_price(flight_t flight_first, flight_t flight_second);
int by_time(flight_t flight_first, flight_t flight_second);

flight_t* buble_sort(flight_t flights_arr[], int n, int  (*it_more) (flight_t, flight_t));
