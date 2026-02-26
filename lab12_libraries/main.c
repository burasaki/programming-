#include "flight.h"
#define N 10

int main(){
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    int n = N;
    flight_t *flights = generate_flights(n);

    int size = sizeof(flight_t)*n;

    print_flights(flights, n);
    flight_t *flights_sorted = buble_sort(flights, n, by_number);

    gettimeofday(&end, NULL);

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;

    double elapsed = seconds + microseconds * 1e-6;

    printf("\n");
    print_flights(flights_sorted, n);
    printf("Размер данных: %d байт, время сортировки: %f\n", size, elapsed);
    free(flights);
}