#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee{
    unsigned int id;
    char name[32];
    char surname[32];
    char level[32];
} employee_t;

typedef struct node node_t;


struct node{
    employee_t *data;
    node_t* next;
    
};

node_t *create_node(employee_t *data);
node_t *append_node(node_t *head, employee_t *data);

void print_list(node_t *head);
node_t *parse_file(FILE *file);
int write_list_to_file(FILE *file, node_t *head);
void read_from_bin_file(FILE *file, int count_writes, int search_id);
char *compress(char *file_name);
char *decompress(char *file_name);
void print_size(FILE *file);