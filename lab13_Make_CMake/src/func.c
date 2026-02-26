#include "flight.h"
#include <time.h>



flight_t* generate_flights(int count){
    char *destinations[] = {"Moscow", "Tomsk", "Novosibirsk", "St.Petersburg", "Omsk", "Krasnoyarsk"};
    
    flight_t *flight_array = malloc(count * sizeof(*flight_array));
    srand(time(NULL));
    for(int i = 0; i < count; i++){
        flight_array[i].number = (rand() % 1000) + 1;
        flight_array[i].destination = destinations[rand() % (sizeof(destinations) / sizeof(destinations[0]))];
        flight_array[i].price = ((rand() % 10) + 10) * 120;
        flight_array[i].time = (rand() % 10) * 15 + 40;
    }
    return flight_array;
}

void print_flights(flight_t flights_arr[], int n){
    printf("%-5s| %-20s | %-18s | %8s\n", "№ рейса", "Пункт назначения", "Время пути, мин", "Цена");
    for(int i = 0; i < n; i++){
        printf("%-7d| %-16s | %-15d | %-5d₽\n", flights_arr[i].number, flights_arr[i].destination, flights_arr[i].time, flights_arr[i].price);
    }
}

int by_number(flight_t flight_first, flight_t flight_second){
    return (flight_first.number - flight_second.number) > 0;
}

int by_price(flight_t flight_first, flight_t flight_second){
    return (flight_first.price - flight_second.price) > 0;
}

int by_destination(flight_t flight_first, flight_t flight_second){
    return (flight_first.destination - flight_second.destination) > 0;
}

int by_time(flight_t flight_first, flight_t flight_second){
    return (flight_first.time - flight_second.time) > 0;
}


flight_t* buble_sort(flight_t flights_arr[], int n, int  (*it_more) (flight_t, flight_t)){
    flight_t temp;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (it_more(flights_arr[j], flights_arr[j+1])){
                temp = flights_arr[j];
                flights_arr[j] = flights_arr[j+1];
                flights_arr[j+1] = temp;
            }
        }
    }
    return flights_arr;
}
