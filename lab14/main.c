#include "flight.h"
#define N 10

int main(){
    srand(time(NULL));

    node_t *head = generate_arr_flights(5,7);
    node_t *S = head;

    

    char input;
    do
    {
        print_flights(head, S);
        printf("Введите действие\n");
        scanf(" %c",&input);

        printf("\n\n");
        if(input == 'd'){
            S = move_down(head, S);
        } else if(input == 'r'){
            S = move_right(head, S);
        } else if (input == 's'){
            S = head;
        }
    } while (input != 'q');
    
}