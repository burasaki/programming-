#include "flight.h"

int number = 1;

flight_t* generate_flight(){
    char *destinations[] = {"Moscow", "Tomsk", "Novosibirsk", "St.Petersburg", "Omsk", "Krasnoyarsk"};
    
    flight_t *flight = malloc(sizeof(flight_t));

    flight->number = number++;
    flight->destination = destinations[rand() % (sizeof(destinations) / sizeof(destinations[0]))];
    flight->price = ((rand() % 10) + 10) * 120;
    flight->time = (rand() % 10) * 15 + 40;

    return flight;
}

node_t* generate_node(){
    node_t *node = malloc(sizeof(node_t));
    node->data = generate_flight();
    node->down = NULL;
    node->next = NULL;


    return node;
}





node_t* generate_arr_flights(int n, int k){
    if (n == 0){
        return NULL;
    }
    
    node_t *head = NULL;


    while (n !=0 || k !=0 )
    {
        if(n!=0 && k!=0){
            head = append_pair(head);
            n--;
            k--;
        } else{
            number++;

            head = append_back(head);
            k--;
        }
    }
    

    return head;
}

void print_flights(node_t *head, node_t* S){
    node_t *cur = head;
    while(cur){

        if (cur == S){
            printf("*");
        }
        printf("%3d->", cur->data->number);
        cur = cur->next;

    }
    printf("NULL\n");


    cur = head;
    while(cur){
        printf("  ↓  ");
        cur = cur->next;
    }
    printf("\n");


    cur = head;
    while(cur){
        if (cur->down == S){
            printf("*");
        }
        if (cur->down){
            printf("%3d->", cur->down->data->number);
        } else{
            printf("NULL ");
        }
        cur = cur->next;
    }
    printf("NULL\n");
    printf("number: %d time: %d price: %d destination: %s\n", S->data->number, S->data->time, S->data->price, S->data->destination);
}

node_t* append_pair(node_t *head){

    node_t *node_down = generate_node();
    node_t *node_top = generate_node();

    node_top->down = node_down;

    if (head == NULL){
        return node_top;
    }

    
    node_top->next = head;
    node_down->next = head->down;

    return node_top;
}

node_t* append_back(node_t *head){

    node_t *new_flight = generate_node();

    new_flight->next = head;


    return new_flight;
}

node_t* move_right(node_t *head, node_t* S){
    if(S->next){
        return S->next;
    }

    printf("Нельзя перейти\n");

    return S;
}

node_t* move_down(node_t *head, node_t* S){
    if(S->down){
        return S->down;
    }

    printf("Нельзя перейти\n");
    
    return S;
}