#include "struct.h"
#include <stdio.h>
#include <time.h>

rhomb_t* generate_rhombs(int count){
    
    rhomb_t *rhomb_array = malloc(count * sizeof(*rhomb_array));
    srand(time(NULL));
    for(int i = 0; i < count; i++){
        rhomb_array[i].d1 = (rand() % 10)+1;
        rhomb_array[i].d2 = (rand() % 10)+1;
        printf("%d %d\n", rhomb_array[i].d1, rhomb_array[i].d2);
    }
    return rhomb_array;
}

int find_squares(rhomb_t *rhomb_arr, int count){
    int count_squares = 0;
    for(int i = 0; i < count; i++){
        if(rhomb_arr[i].d1 == rhomb_arr[i].d2){
            count_squares++;
        }
    }
    printf("Количество квадратов: %d\n",count_squares);
}

int min(int a, int b){
    return a < b ? a : b;
}

int find_area(int a, int b){
    return a * b;
}

int find_min_area(rhomb_t *rhomb_arr, int count){
    int min_area = 999999;
    for(int i = 0; i < count; i++){
        int area_rhomb = find_area(rhomb_arr[i].d1, rhomb_arr[i].d2);
        min_area = min(min_area, area_rhomb);
    }
    printf("Минимальная площадь ромбов %d\n", min_area);
}