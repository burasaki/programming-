#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct flight flight_t;

typedef struct node node_t;

struct flight{
    int number;
    int time;
    int price;
    char  *destination;
    
};

struct node{
    flight_t *data;
    node_t *next;
    node_t *down;
};




flight_t* generate_flight();
void print_flights(node_t *head, node_t* S);
node_t* generate_arr_flights(int n, int k);
node_t* move_down(node_t *head, node_t* S);
node_t* move_right(node_t *head, node_t* S);

node_t* append_pair(node_t *head);
node_t* append_back(node_t *head);

int by_number(flight_t flight_first, flight_t flight_second);
int by_destination(flight_t flight_first, flight_t flight_second);
int by_price(flight_t flight_first, flight_t flight_second);
int by_time(flight_t flight_first, flight_t flight_second);

flight_t* buble_sort(flight_t flights_arr[], int n, int  (*it_more) (flight_t, flight_t));
