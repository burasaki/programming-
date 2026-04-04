#include "staff.h"


node_t *create_node(employee_t *data){

    node_t *new_node = malloc(sizeof(new_node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}



node_t *append_node(node_t *head, employee_t *data){

    node_t *new_flight = create_node(data);
    new_flight->next = head;

    return new_flight;
}

void print_list(node_t *head){
    node_t *cur = head;
    printf("ID   Имя        Фамилия    Уровень\n");
    while (cur != NULL){
        printf("%-4d %-10s %-10s %-10s\n", cur->data->id, cur->data->name, cur->data->surname, cur->data->level);
        cur = cur->next;
    }
    
}

node_t *parse_file(FILE *file){
    char buffer[100];
    char name_emp[32];
    char surname_emp[32];
    char level_emp[32];
    int unsigned id_emp;


    node_t *head = NULL;
    
    while (fgets(buffer, sizeof(buffer), file) != NULL){
        employee_t *emp_data = malloc(sizeof(employee_t));
        sscanf(buffer, "%[^ ] %[^;];%d;%s", name_emp, surname_emp, &id_emp, level_emp);

        strncpy(emp_data->name, name_emp, 32);
        strncpy(emp_data->surname, surname_emp, 32);
        strncpy(emp_data->level, level_emp, 32);
        emp_data->id = id_emp;
        head = append_node(head, emp_data);
    }
    return head;
}

int write_list_to_file(FILE *file, node_t *head){
    int count_writes = 0;
    if(head == NULL){
        return 0;
    }
    
    node_t *cur = head;
    while (cur != NULL){
        fwrite(cur->data, sizeof(employee_t), 1, file);
        count_writes++;
        cur = cur->next;
    }
    return count_writes;
}

void read_from_bin_file(FILE *file, int count_writes, int search_id){
    node_t *head = NULL;

    employee_t buffer[count_writes];

    fread(buffer, sizeof(employee_t), count_writes, file);
    for(int i = 0; i < count_writes; i++){
        if (buffer[i].id == search_id){
            printf("%-4d %-10s %-10s %-10s\n", buffer[i].id, buffer[i].name, buffer[i].surname, buffer[i].level);
            return;
        }
    }
    printf("Сотрудник не найден\n");
}

char* compress(char *file_name){
    FILE *db = fopen(file_name, "rb");
    if (db == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }

    char *compress_file_name = malloc(sizeof(char)*20);
    sprintf(compress_file_name, "%s.compressed", file_name);


    FILE *compressed_db = fopen(compress_file_name, "wb");
    if (compressed_db == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }

    int current;
    int next;
    int count;

    current = fgetc(db);
    while (current != -1) {
        count = 1;
        while ((next = fgetc(db)) != -1) {
            if (next == current) {
                count++;
            } else {
                ungetc(next, db);
                break;
            }
        }

        if ( fputc(count, compressed_db) == -1){
            abort();
        }
        if ( fputc(current, compressed_db) == -1){
            abort;
        }
        current = fgetc(db);
    }
    

    fclose(db);
    fclose(compressed_db);

    return compress_file_name;
}

char* decompress(char *file_name) {

    char compress_file_name[50];
    sprintf(compress_file_name, "%s.compressed", file_name);

    char *decompress_file_name = malloc(sizeof(char)*50);

    sprintf(decompress_file_name, "decompressed.%s", file_name);

    FILE *decompress_db = fopen(decompress_file_name, "wb");
    if (decompress_db == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }
    FILE *compressed_db = fopen(compress_file_name, "rb");

    if (compressed_db == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }
    

    int count;
    int value;


    while ((count = fgetc(compressed_db)) != -1) {
        value = fgetc(compressed_db);
        if (value == -1) break; 
        
        for (int i = 0; i < count; i++) {
            fputc(value, decompress_db);
        }
    }


    fclose(compressed_db);
    fclose(decompress_db);

    return decompress_file_name;
}

void print_size(FILE *file){
    fseek(file, 0L, SEEK_END);

    printf("размер файла: %ld\n", ftell(file));
}