#include "struct.h"

#define K 10



int main(){
    rhomb_t *rhombs_arr = generate_rhombs(K);
    find_squares(rhombs_arr, K);
    find_min_area(rhombs_arr,K);
    free(rhombs_arr);
}