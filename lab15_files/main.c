#include "staff.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s file.csv\n", argv[0]);
        exit(1);
    }


    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }

    node_t *head = parse_file(file);
    fclose(file);
    print_list(head);

    file = fopen("database.dat", "wb");
    if (file == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }

    int count_writes = write_list_to_file(file, head);
    fclose(file);


    file = fopen("database.dat", "rb");
    if (file == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }
    printf("\n\n\n");
    
    int search_id;
    printf("Введите ID для поиска: ");
    scanf("%d", &search_id);
    read_from_bin_file(file, count_writes, search_id);
    
    
    fclose(file);

    char file_name[20];

    printf("Введите имя файла который нужно сжать: ");
    scanf("%s", file_name);
    printf("%s\n", file_name);

    file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }
    printf("До сжатия ");
    print_size(file);
    fclose(file);



    char* compressed_file_name = compress(file_name);

    file = fopen(compressed_file_name, "rb");
    if (file == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }
    printf("После сжатия ");
    print_size(file);
    fclose(file);


    char* decompressed_file_name = decompress(file_name);

    file = fopen(decompressed_file_name, "rb");
    if (file == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }
    printf("После распаковки");
    print_size(file);
    fclose(file);
}