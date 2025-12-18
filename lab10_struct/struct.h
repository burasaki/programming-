#ifndef __STRUCT_H
#define __STRUCT_H 1
#include <stdlib.h>

typedef struct rhomb rhomb_t;
struct rhomb{
    int d1;
    int d2;
};

rhomb_t* generate_rhombs(int count);

int find_squares(rhomb_t *rhomb_arr, int count);

int min(int a, int b);

int find_area(int a, int b);

int find_min_area(rhomb_t *rhomb_arr, int count);
#endif